"use strict";
document.getElementById('sub').addEventListener('click',()=>
{

const arr=[0,0,0,0,0,0,0,0,0,0,0,0,0,0];

arr[0]=document.querySelector('input[name="Ancient_Greek_Language"]').value;
arr[1]=document.querySelector('input[name="Greek_Language"]').value;
arr[3]=document.querySelector('input[name="Algebra"]').value;
arr[4]=document.querySelector('input[name="Geometry"]').value;
arr[5]=document.querySelector('input[name="Physics"]').value;
arr[6]=document.querySelector('input[name="Chemistry"]').value;
arr[7]=document.querySelector('input[name="Biology"]').value;
arr[8]=document.querySelector('input[name="Religious"]').value;
arr[9]=document.querySelector('input[name="History"]').value;
arr[10]=document.querySelector('input[name="English"]').value;
arr[11]=document.querySelector('input[name="Second_Language"]').value;
arr[12]=document.querySelector('input[name="Gymnastics"]').value;
arr[13]=document.querySelector('input[name="Informatics"]').value;
arr[14]=document.querySelector('input[name="Political Education"]').value;
let sum=0;
let MO=0;
for(let i of arr)
{
    
    sum=sum+parseFloat(i);

}
MO=(sum/14).toFixed(2);
document.getElementById('result').innerHTML="Ο Μέσος Όρος είναι:"+MO;


})



