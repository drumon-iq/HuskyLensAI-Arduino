#include <WiFi.h>  
#include <HTTPClient.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

const char* ssid = "IoT";
const char* password = "coltec2022";

HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11); // RX, TX
             	//HUSKYLENS green line >> Pin 10; blue line >> Pin 11
String cameraGrabResponse(HUSKYLENSResult result);

void setup()
{
	Serial.begin(115200);
	mySerial.begin(9600);

	while (!huskylens.begin(mySerial))
	{
	Serial.println(F("Begin failed!"));
	Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
	Serial.println(F("2.Please recheck the connection."));
	delay(100);
	}

	WiFi.begin(ssid, password);
	Serial.println("Connecting");
	huskylens.customText("Connecting to Wifi", 0, 0);

	while(WiFi.status() != WL_CONNECTED)
	{
	delay(500);
	Serial.print(".");
	}

	Serial.println("");
	Serial.print("Connected to WiFi network with IP Address: ");
	huskylens.customText("Connected to Wifi", 0, 0);
	Serial.println(WiFi.localIP());
}


void loop()
{
	if (!huskylens.request())
	{
	Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
	}
	else if(!huskylens.isLearned())
	{
	Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
	}
	else if(!huskylens.available())
	{
	Serial.println(F("No block or arrow appears on the screen!"));
	}
	else
	{
	while (huskylens.available())
	{
    	HUSKYLENSResult result = huskylens.read();
    	String msg = "?cameraResponse=" + cameraGrabResponse(result);
    	PostMessage(msg);
    	delay(1000);
	}    
	}

	delay(100);
}


void PostMessage(String msg)
{
	HTTPClient http;
	msg = "https://script.google.com/macros/s/AKfycbykhvIgz-e6B2-m3DpcnH7ITJ4mdHV8tfB7pr-zAQ8yiJKJ9biatzzR5O5C8hMX9teD/exec" + msg;
	http.begin(msg);


	http.addHeader("Content-Type", "application/json");
	// Send HTTP POST request
	int httpResponseCode = http.GET();
	if (httpResponseCode == 200){
	Serial.print("Message sent successfully");
	Serial.print(msg);
	}
	else{
	Serial.print("HTTP response code: ");
	Serial.println(httpResponseCode);
	}
	// Free resources
	http.end();
}

String cameraGrabResponse(HUSKYLENSResult result)
{
	String resposta = String();

	if (result.command == COMMAND_RETURN_BLOCK)
	{
	resposta = String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID;
	huskylens.customText("Found Object", 0, 0);
	}
	else if (result.command == COMMAND_RETURN_ARROW)
	{
	resposta = String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID;
	huskylens.customText("Found Arrow", 0, 0);
	}
	else
	{
	resposta = "Object_Unknown!";
	}

	Serial.println(resposta);
	return resposta;
}
