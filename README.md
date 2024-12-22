### Participantes:

Arif Drumond  
John Wesley  
Maria Eduarda Almeida  
Nicolle Durães  
Pedro Henrique Pinto.  

### Descrição da ideia: Reconhecimento facial

**Necessidade:** Promover o reconhecimento facial de um determinado público.

**Projeto:** Um dashboard que receba data, hora e um ID para cada rosto coletado.

**Quais sensores estão sendo utilizados, quais dados são coletados?** Utilizando o ESP-32-S3 conectado ao HuskyLens, coletando um determinado padrão imagético (machine learning) e o associando a um código de identificação.

**Como os dados chegam até a planilha?** Através da internet, por meio de uma requisição POST.

**Qual o público alvo que você quer atingir?** Empresas que trabalham com um nível de confidencialidade de acesso por trabalhador.

**Quais são os planos para esse site?** Registrar na base de dados Data Studio os rostos salvos.


#### Desenvolvimento do projeto

 1. Teste do equipamento Husky Lens AI v1.0 e o chip arduino ESP32-S3  
 2. Configuração básica e aprendizagem para utilizar os sistemas da câmera  
 3. Primeira conexão entre o esp32s3 e a câmera, pelo uso da conexão UART e pinagem do HUSKY LENS  
 4. Implementação do web app (Script do Google) para ser acessado pelo circuito  
 5. Criação do código de conexão entre o arduino e a nuvem para passar os dados do HUSKY LENS  

##### Estimativa do material a ser utilizado:

 * ESP-32-S3;  
 * DFRobot HuskyLens;  
 * Alguns fios macho-macho, cabo USB.  

#### Referências:

https://wiki.dfrobot.com/HUSKYLENS_V1.0_SKU_SEN0305_SEN0336

https://forum.arduino.cc/

https://github.com/HuskyLens/HUSKYLENSArduino/

https://script.google.com/u/0/home/projects/12fSXurfrhdT72rZaDbQ9y-AaT7VLIhk8U3EI88AUdnt53Byu_1O-SIaZ/edit

https://docs.google.com/spreadsheets/d/1gUjsh9PE56Zpdze_CdMpoZdyOkcUfySwR5rQQPx65A4/edit?gid=0#gid=0

https://docs.arduino.cc/language-reference/pt/

https://riptutorial.com/google-apps-script

https://github.com/PacktPublishing/Google-Apps-Script-Complete-Course---Beginner-to-Advanced/blob/master/Apps-script.pdf

https://basescripts.com/wp-content/uploads/2023/02/Apps-Script-Book-V3.pdf

https://github.com/HuskyLens/HUSKYLENSArduino/blob/master/HUSKYLENS%20Arduino%20API.md

https://chatgpt.com/


### Pinagem e Configuração do circuito
PIN 10 -> TX (fio verde)

PIN 11 -> RX(fio vermelho)

PIN GND -> Negativo(fio preto)

PIN 5V -> Positivo(fio vermelho)

Os pinos 10 e 11 do ESP32-S3 WROOM2 serão utilizados para a conexão UART com o HuskyLens, conecte o pino 11 a entrada digital RX e o pino 10 ao TX do sensor, o GND e 5V do chip arduino alimentam o sensor, pois nesse modo, não é possível utilizar a entrada USB para energizar. Não é necessário remover o arduino do computador, então essas são as únicas conexões a serem feitas.
