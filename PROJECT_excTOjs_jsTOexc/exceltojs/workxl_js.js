"use strict";
//You manage the input where the file is uploaded and the change event means that your file uploaded successfully
 const fileInput=document.getElementById("xls");
fileInput.addEventListener("change",function(event) {
    
    const file = event.target.files[0];//you take the file which is uploaded successfully
    
    if (file) {
        
      const reader = new FileReader();//You make a file reader object
      //You dont continue staight to the code but you must go the last line 
      /*This line means that the reader you made  read the file and if it finished successfully will be executed the onload function below 
      but if there is something wrong to the reading of the file will be executed the onerror function*/
      reader.onload = function(event) {
        
        const data = new Uint8Array(event.target.result);//i put the file that reader read inside a binary array 
        
        const workbook = XLSX.read(data, { type: 'array' });// i form all the binary array  as a whole excel workbook
        
        const sheetName = workbook.SheetNames[0];//i choose from which sheet i want take the real data 
        
        const worksheet = workbook.Sheets[sheetName];//i take them
        
        const jsonData = XLSX.utils.sheet_to_json(worksheet);//i convert them to json (not antigoni just json)
        //i do some tests 
        console.log(jsonData[0]['name ']);//which the name of the first line of j son 
        console.log(jsonData.length);//the length is about the whole rows of a json file

        const div = document.createElement('div');//i make a div 
       div.innerHTML='Double one withdraw ' + jsonData[0]['withdraw']*2 + ' the real is '+ jsonData[0]['withdraw'];/*here i do some more tests about the data i took 
      like a mathematical operation on them and some text which will be appeared in the div i made to the html file   */
       document.body.appendChild(div); // i add the div i made to the html body 
      }

      reader.onerror = function(event) {
        console.error('Error reading the file:', event.target.error);
    }

    reader.readAsArrayBuffer(file);// i told about this to the beginning
        
      }
    

});

    