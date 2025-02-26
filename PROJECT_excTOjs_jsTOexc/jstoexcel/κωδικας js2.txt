"use strict";
//when you click the button
document.getElementById('download-btn').addEventListener('click', () => {
    const table = document.getElementById('data-table'); // take the table 
    const rows = table.querySelectorAll('tr');//take the rows of the table 
    
    const dataRows = [];//make an array 
    for (let i = 1; i < rows.length; i++) {//for each row of the html table 
        const row = rows[i].querySelectorAll('td');//i take the columns of each row 
        const name = row[0].textContent;//the first column of each row is the name 
        const withdraw = parseFloat(row[1].textContent);//the second the withdraw which i convert it to a number from string 
        dataRows.push([name, withdraw]);//i push the whole row in the table i made above (keep in mind that every new row is a new table inside a bigger table)
    }

    const ws = XLSX.utils.aoa_to_sheet([['Name', 'Withdraw'], ...dataRows]);//i make a whole worksheet and pass the whole table above (with the data) line by line ....
    const wb = XLSX.utils.book_new();//i make a whole workbook ;
    XLSX.utils.book_append_sheet(wb, ws, 'Sheet1');//i put the workshhet inside the workbook with the name sheet in but you can write whatever you want as a name
    
    XLSX.writeFile(wb, 'mywithdraws.xlsx');//i copy the whole workbook to an external file with xlsx extension and this copy bring  the download 
});
