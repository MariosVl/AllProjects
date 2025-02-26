"use strict";

let sumR=0;
let sumBc=0;
document.getElementById('RE').addEventListener('click',()=>
{
    sumR++;
    document.getElementById('pR').innerHTML=sumR;
})

document.getElementById('BC').addEventListener('click',()=>
{

    sumBc++;
    document.getElementById('pB').innerHTML=sumBc;
}


)

