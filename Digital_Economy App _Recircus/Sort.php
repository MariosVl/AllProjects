<html>
<body>
<style>
 body
   {
       background-image:url("images/statistics.jpg");
       background-attachment: fixed;
    background-repeat: no-repeat;
    background-position:center;
    background-size: 100%;  
    
   }
   table,th,td,tr
   {
    

    
    
    margin-left: 0px;
    margin-top: 5px;
    opacity: 0.94;
    width: 30%;
  



    border: 2px solid  rgb(205, 237, 240);
    background-color: #e8c866;
    color: blue;
    border-collapse: collapse;
    text-align: center;
    font-style: italic;
    font-weight: bolder;
    padding-left: 30px;
    font-size: 1.1em;


}


   }


</style>

<?php
$servername="localhost";
$username = "root"; 
$password = ""; 
$dbname = "Customer_Base"; 
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 
$sql = "SELECT id,Name,recycle_points FROM customers"; 
$result = $conn->query($sql); 
$minRec=array();
$minName=array();
if ($result->num_rows > 0)
{

  $i=0;
   while($row = $result->fetch_assoc())
    {
        
        $minRec[$i]=$row["recycle_points"];
        $minName[$i]=$row["Name"];
        $i++;
      
    }
}
$maxR=$minR=$minRec[0];
$maxN=$minN=$minName[0];
for($a=0;$a<$i;$a++)
{
    if($minRec[$a]<$minR)
    {  
        $minR=$minRec[$a];
        $minN=$minName[$a];
    
    }
    if($minRec[$a]>$maxR)
    {  
        $maxR=$minRec[$a];
        $maxN=$minName[$a];
    
    }
}
   

    sort($minRec);
    echo"<table><tr><th>Down->Up</th><th>CustomersPoints_Total(Sort)</th></tr>";
    for($a=0;$a<$i;$a++)
    {   echo"<tr><td>" .$a."</td><td>".$minRec[$a]."</td></tr>";
        
    }
    echo"</table>";
    echo"<table><tr><th>Max/Min</th><th>Name</th><th>RecyclePoints_Total(Max/Min)</th></tr>";
    echo "<tr><td>Min</td><td>".$minN."</td><td>".$minR."</td></tr>";
    echo "<tr><td>Max</td><td>".$maxN."</td><td>".$maxR."</td></tr>";
    echo"</table>";
   $conn->close();
  

    


?>
</body>
</html>