"use strict";
document.getElementById('but').addEventListener('click',()=>
{

    let a=parseInt(document.querySelector('input[name="synolo"]:checked').value);
    document.getElementById('order').innerText=`to fagito einai ${a}`
}

)