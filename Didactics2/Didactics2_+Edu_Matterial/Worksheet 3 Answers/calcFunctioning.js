"use strict";
document.getElementById('sub').addEventListener('click',()=>
     {
         let first=parseFloat(document.querySelector('input[name="FirstNum"]').value);
         let sec=parseFloat(document.querySelector('input[name="SecNum"]').value);
         let action=document.querySelector('input[name="calc"]:checked').value;
         
         let sum;
         let result;
         if(action=='+')
         {
             sum=first+sec;
            
         }
         else if(action=='-')
         {
             sum=first-sec;
         }
         else if(action=='/')
         {
             sum=first/sec;
         }
         else if(action=='*')
         {
             sum=first*sec;
         }
         result=(sum).toFixed(2);
        
       document.getElementById('result').innerHTML="Το αποτέλεσμα είναι:"+result;
    
     })
    