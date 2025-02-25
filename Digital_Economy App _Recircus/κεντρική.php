<!DOCTYPE html>
<html lang="el">
<head>
   <meta charset="UTF-8">
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>Document</title>
   
</head>
<body>
<form class="frm5">Recircus</form>
<style>
  body
  {
     background-image:url('images/anakiklosi.jpg');
     background-repeat:no-repeat;
     background-attachment: fixed;
    background-repeat: no-repeat;
    background-position:center;
    background-size: 100%;    
  }
  #frm{
 
   background-color: rgb(152, 192, 107);
    margin-top: 10px;
    opacity: 0.95;
    font-size: 1.7em;
    color: rgb(221, 52, 52);
    font-style: oblique;
    text-align:center;
    border-radius: 30%;
    width:40%;
    height: 330px;
    font-weight: bolder;
    padding-top:20px;
    padding-left:50px;
    margin-left:700px;
 
}
.frm2
{
   color: rgb(221, 52, 52);
   font-style: oblique;
   font-weight: bolder;
   background-color:rgb(152, 192, 107);
   border-radius: 40%;
   text-align: center;
   height: 50px;
   width: 30%;
   padding-top: 10px;
   margin-bottom: 30px;
   font-size: 1.7em;
   margin-left:550px;
   margin-top:5px;
}
.frm3
{
   color: rgb(221, 52, 52);
   font-style: oblique;
   font-weight: bolder;
   background-color:rgb(152, 192, 107);
   border-radius: 40%;
   text-align: center;
   height: 70px;
   width: 30%;
   padding-top: 20px;
   margin-bottom: 30px;
   font-size: 1.7em;
   margin-left:700px;
   margin-top:1px;

}
.frm4
{
   color: rgb(221, 52, 52);
   font-style: oblique;
   font-weight: bolder;
   background-color:rgb(152, 192, 107);
   border-radius: 40%;
   text-align: center;
   height: 70px;
   width: 30%;
   padding-top: 20px;
   margin-bottom: 30px;
   font-size: 1.3em;
   margin-left:900px;
   margin-top:20px;
}
.frm5
{
   display: inline-block;
    position: fixed;
    background-color:  #d5e8eb;
    border-radius: 50%;
    text-align: center;
    padding-top: 10px;
    top:0;
    margin-top: 30px;
    width: 20%;
    height:60px;
    color:#38ab70;
    margin-left:20px;
    font-size: 3em;
    font-weight: bold;
    font-style:italic;
    opacity:0.95;
}
span
{
   display: inline-block;
    position: fixed;
    background-color:  rgba(98, 223, 212, 0.76);
    border-radius: 70%;
    text-align: center;
    padding: 10px;
    top:10px;
    margin-top: 440px;
    margin-left:390px;
    width: 10%;
    font-size:2.0em;
    color:rgb(221, 52, 52);
    font-weight: bold;
    font-style:italic;
}
}
</style>
<form id="frm" method="post" action="<?php echo $_SERVER["PHP_SELF"]?>">
   Γεμίστε το καλάθι σας οικοΛΟΓΙΚΑ
  <table>
  <tr>
   <td>
   <input type="checkbox" name="ΔΕΛΤΑ" value="marios">
   </td>
   <td><img src="images/ΔΕΛΤΑ.jfif" alt="ΔΕΛΤΑ"style="height:100px;"></td>
   <td>
  <input type="checkbox" name="Crystal" >
  </td>
  <td><img src="images/sugar.jpg" alt="Sugar" style="height:100px;"></td>
  <td> <input type="checkbox"name="ΠΛΩΜΑΡΙ" ></td>
  <td><img src="images/ουζο πλωμαρι.jfif" alt="ΠΛΩΜΑΡΙ" style="height:100px;"></td>
  <td><input type="checkbox"name="Attiki" ></td>
  <td><img src="images/Attiki.jfif" alt="Attiki" style="height:100px;"></td>
   </tr>
   <tr>
   <td><input type="checkbox"name="Lays"></td>
   <td><img src="images/Lays.jfif" alt="Lays" style="height:100px;"></td>
   <td><input type="checkbox"name="Cheetos" ></td>
   <td><img src="images/chhetos.jfif" alt="Cheetos" style="height:100px;"></td>
   <td><input type="checkbox"name="NesCafe" ></td>
   <td><img src="images/nescafe.jpg" alt="NesCafe" style="height:100px;"></td>
   <td><input type="checkbox"name="NOYNOY" ></td>
   <td><img src="images\ΝΟΥΝΟΥ.jfif" alt="NOYNOY" style="height:100px;"></td>
   </tr>
   </table>
  Συμπληρώστε το όνομα σας <input style=" text-align:center;" type="text" name="FullName"><br>
  ΥouRecyclePoints <input type="submit" value="Points!">
   
</form>
<form class=" frm2"action="Sort.php" method="post" >
Δείτε τα συμπερασμάτα μας  <input type="submit" value="Αύξουσα">
</form>
<form class="frm3"action="ShowFullCustomers.php" method="post">
"Oι πελάτες μας ανακυκλώνουν...είσαι μαζί μας?" <input type="submit" value="Πελάτες">
</form>
<form class="frm4"action="ShowProdsValue.php" method="post">
"Bαθμός Δυσκολίας Ανακύκλωσης/προιόν"<br>
(ιδανικές οι χαμηλότερες τιμές)
  <input type="submit" value="RecValue!">
</form>
<?php
       /*  $check_prods=array();
         for($i;$i<8;$i++)
         {
            $check_prods[$i]="";
         }*/
         $check_prods=array("","","","","","","","");
       if(isset($_POST['ΔΕΛΤΑ'])?$check_prods[0]="ΔΕΛΤΑ":"off")
       
      if(isset($_POST['Crystal'])?$check_prods[1]="Crystal":"off")
       
       if(isset($_POST['ΠΛΩΜΑΡΙ'])?$check_prods[2]="ΠΛΩΜΑΡΙ":"off")
      
       if(isset($_POST['Attiki'])?$check_prods[3]="Attiki":"off")
       
       if(isset($_POST['Lays'])?$check_prods[4]="Lays":"off")
       
       if(isset($_POST['Cheetos'])?$check_prods[5]="Cheetos":"off")
       
       if(isset($_POST['NesCafe'])?$check_prods[6]="NesCafe":"off")
       
       if(isset($_POST['NOYNOY'])?$check_prods[7]="ΝΟΥΝΟΥ":"off")
      
       $servername = "localhost"; 
$username = "root"; 
$password = ""; 
$dbname = "Product_Base"; 
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 

 $sql = "SELECT id,Brand,category,recycle_points FROM products"; 
$result = $conn->query($sql); 
$sum=0;
if ($result->num_rows > 0)
{


   while($row = $result->fetch_assoc())
    {
        for($i=0;$i<count($check_prods);$i++)
      {
       if($row["Brand"]==$check_prods[$i])
       {
         
          $sum=$sum+$row["recycle_points"];
       }
      }
    }


}
else { 
    echo "0 results";}
    echo"<span > Your Recycle Points <br> $sum/239 </span>" ;
 $conn->close();
$dbname = "Customer_Base"; 
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 
$stmt = $conn->prepare("INSERT INTO customers (Name,recycle_points) 
VALUES (?,?)"); 
$stmt->bind_param("sd",$Name, $recycle_points);  
$recycle_points = $sum;
$Name=$_POST["FullName"];
$stmt->execute();
$stmt->close();
$conn->close();



  

?>
</body>
</html>