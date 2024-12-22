function doGet(e) {
 var sheet = SpreadsheetApp.getActiveSpreadsheet().getSheetByName('Sheet1');

 var currentTime = new Date();
 var saoPauloTime = currentTime.toLocaleString("pt-BR", { timeZone: "America/Sao_Paulo" });
 Logger.log(typeof(saoPauloTime));
 Logger.log(saoPauloTime);
 var latestRow = sheet.getLastRow() + 1;
 sheet.getRange(latestRow, 1).setValue(saoPauloTime);

 if(e && e.parameter.cameraResponse)
 {
   var resposta = e.parameter.cameraResponse;
   sheet.getRange(latestRow, 2).setValue(resposta);
 }
 else
 {
   sheet.getRange(latestRow, 2).setValue('empty');
 }

 return ContentService.createTextOutput('I undestand it now');
}
