"use strict";
document.getElementById('button1').addEventListener("click",()=>
{
    location.assign('index.html')
})

choose();
function choose()
{
   var select=document.getElementById('dest');
   var a=select.options[select.selectedIndex];

 if(a.value=="Rodos")
{
    let RodosJs=document.querySelector('body');
    RodosJs.setAttribute("style","background-image:url('images/rodos.jfif');")
     let RodosJs1=document.querySelector('#pict1');
     RodosJs1.style.display="none";
     let RodosJs2=document.querySelector("#pict2Circle");
     RodosJs2.style.display="none";

    
     let form=document.getElementById("hotels");
     form.innerHTML=`
     <br>
  
     <table class="priceTables4">
     <caption>"Rodos Palace"</caption>
        <tr>
        <th> Γεύματα </th>
        <th> 1Κλινο </th> 
        <th> 2Κλινο </th>
        <th> 3Κλινο </th>
        </tr>
        <tr>
        <td> Παροχή Πρωινού</td> 
        <td>  120 ευρώ/ημέρα  </td> 
        <td>  170 ευρώ/ημέρα  </td> 
        <td>  340 ευρώ/ημέρα  </td> 
        </tr>
        <tr>
        <td> Παροχή Πλήρους Διατροφής </td>
        <td>  260 ευρώ/ημέρα  </td>
        <td>  390 ευρώ/ημέρα  </td>
        <td>  460 ευρώ/ημέρα  </td>
        </tr>
     </table>
  
  
  
     <table id="priceTables4">
     <caption>"Lindos Accomodation"</caption>
        <tr>
        <th> Γεύματα </th>
        <th> 1Κλινο </th> 
        <th> 2Κλινο </th>
        <th> 3Κλινο </th>
        </tr>
        <tr>
        <td> Παροχή Πρωινού</td> 
        <td>  60 ευρώ/ημέρα  </td> 
        <td>  100 ευρώ/ημέρα  </td> 
        <td>  160 ευρώ/ημέρα  </td> 
        </tr>
        <tr>
        <td> Παροχή Πλήρους Διατροφής </td>
        <td>  200 ευρώ/ημέρα  </td>
        <td>  240 ευρώ/ημέρα  </td>
        <td>  310 ευρώ/ημέρα  </td>
        </tr>
     </table>`








}

else if (a.value=="Kerkira")
{
    document.body.style.backgroundImage="url('images/kerkira.jfif')"
    let KerkiraJs1=document.querySelector('#pict1');
    KerkiraJs1.style.display="none";
    let KerkiraJs2=document.querySelector("#pict2Circle");
    KerkiraJs2.style.display="none";



    let form=document.getElementById("hotels");
    form.innerHTML=`
    <br>
 
    <table class="priceTables3">
    <caption>"Corfu Beach"</caption>
       <tr>
       <th> Γεύματα </th>
       <th> 1Κλινο </th> 
       <th> 2Κλινο </th>
       <th> 3Κλινο </th>
       </tr>
       <tr>
       <td> Παροχή Πρωινού</td> 
       <td>  90 ευρώ/ημέρα  </td> 
       <td>  130 ευρώ/ημέρα  </td> 
       <td>  280 ευρώ/ημέρα  </td> 
       </tr>
       <tr>
       <td> Παροχή Πλήρους Διατροφής </td>
       <td>  200 ευρώ/ημέρα  </td>
       <td>  340 ευρώ/ημέρα  </td>
       <td>  420 ευρώ/ημέρα  </td>
       </tr>
    </table>
 
 
 
    <table id="priceTables3">
    <caption>"Ionian Paradise"</caption>
       <tr>
       <th> Γεύματα </th>
       <th> 1Κλινο </th> 
       <th> 2Κλινο </th>
       <th> 3Κλινο </th>
       </tr>
       <tr>
       <td> Παροχή Πρωινού</td> 
       <td>  80 ευρώ/ημέρα  </td> 
       <td>  170 ευρώ/ημέρα  </td> 
       <td>  310 ευρώ/ημέρα  </td> 
       </tr>
       <tr>
       <td> Παροχή Πλήρους Διατροφής </td>
       <td>  260 ευρώ/ημέρα  </td>
       <td>  380 ευρώ/ημέρα  </td>
       <td>  520 ευρώ/ημέρα  </td>
       </tr>
    </table>`
 
}
else if(a.value=="Leipsoi")

{
   
   let LeipsoiJs=document.querySelector('body');
   LeipsoiJs.style.backgroundImage="url('images/lipsoi.jpg')"
   LeipsoiJs.style.backgroundSize="115%";
   LeipsoiJs.style.backgroundAttachment="fixed";
   LeipsoiJs.style.backgroundRepeat="no-repeat";
    let LeipsoiJs1=document.querySelector('#pict1');
    LeipsoiJs1.style.display="none";
    let LeipsoiJs2=document.querySelector("#pict2Circle");
    LeipsoiJs2.style.display="none";
    let form=document.getElementById("hotels");
    form.innerHTML=`
    <br>
 
    <table class="priceTables1">
    <caption>"Λειψοί AppartMents"</caption>
       <tr>
       <th> Γεύματα </th>
       <th> 1Κλινο </th> 
       <th> 2Κλινο </th>
       <th> 3Κλινο </th>
       </tr>
       <tr>
       <td> Παροχή Πρωινού</td> 
       <td>  20 ευρώ/ημέρα  </td> 
       <td>  25 ευρώ/ημέρα  </td> 
       <td>  30 ευρώ/ημέρα  </td> 
       </tr>
       <tr>
       <td> Παροχή Πλήρους Διατροφής </td>
       <td>  30 ευρώ/ημέρα  </td>
       <td>  35 ευρώ/ημέρα  </td>
       <td>  40 ευρώ/ημέρα  </td>
       </tr>
    </table>



    <table id="priceTables1">
    <caption>"Λειψοί Hotel"</caption>
       <tr>
       <th> Γεύματα </th>
       <th> 1Κλινο </th> 
       <th> 2Κλινο </th>
       <th> 3Κλινο </th>
       </tr>
       <tr>
       <td> Παροχή Πρωινού</td> 
       <td>  30 ευρώ/ημέρα  </td> 
       <td>  35 ευρώ/ημέρα  </td> 
       <td>  40 ευρώ/ημέρα  </td> 
       </tr>
       <tr>
       <td> Παροχή Πλήρους Διατροφής </td>
       <td>  40 ευρώ/ημέρα  </td>
       <td>  45 ευρώ/ημέρα  </td>
       <td>  50 ευρώ/ημέρα  </td>
       </tr>
    </table>`

    
}
else if(a.value=="Lefkada")
{
    let LefkadaJs=document.querySelector('body');
   LefkadaJs.style.backgroundImage="url('images/lefkada.jpg')"
   LefkadaJs.style.backgroundSize="140%"
   LefkadaJs.style.backgroundAttachment="fixed";
   LefkadaJs.style.backgroundRepeat="no-repeat";
   let LefkadaJs1=document.querySelector('#pict1');
   LefkadaJs1.style.display="none";
   let LefkadaJs2=document.querySelector("#pict2Circle");
   LefkadaJs2.style.display="none";


   let form=document.getElementById("hotels");
   form.innerHTML=`
   <br>

   <table class="priceTables2">
   <caption>"Lefkada Resort"</caption>
      <tr>
      <th> Γεύματα </th>
      <th> 1Κλινο </th> 
      <th> 2Κλινο </th>
      <th> 3Κλινο </th>
      </tr>
      <tr>
      <td> Παροχή Πρωινού</td> 
      <td>  15 ευρώ/ημέρα  </td> 
      <td>  40 ευρώ/ημέρα  </td> 
      <td>  45 ευρώ/ημέρα  </td> 
      </tr>
      <tr>
      <td> Παροχή Πλήρους Διατροφής </td>
      <td>  50 ευρώ/ημέρα  </td>
      <td>  55 ευρώ/ημέρα  </td>
      <td>  60 ευρώ/ημέρα  </td>
      </tr>
   </table>



   <table id="priceTables2">
   <caption>"Nydri Pallas"</caption>
      <tr>
      <th> Γεύματα </th>
      <th> 1Κλινο </th> 
      <th> 2Κλινο </th>
      <th> 3Κλινο </th>
      </tr>
      <tr>
      <td> Παροχή Πρωινού</td> 
      <td>  70 ευρώ/ημέρα  </td> 
      <td>  120 ευρώ/ημέρα  </td> 
      <td>  150 ευρώ/ημέρα  </td> 
      </tr>
      <tr>
      <td> Παροχή Πλήρους Διατροφής </td>
      <td>  160 ευρώ/ημέρα  </td>
      <td>  220 ευρώ/ημέρα  </td>
      <td>  340 ευρώ/ημέρα  </td>
      </tr>
   </table>`

}
}




document.getElementById('reservationButton').addEventListener("click",()=>
{
   location.assign('reserve.html')

})
document.getElementById('Office').addEventListener("click",()=>{

   location.assign('OfficeInfo.html');
})