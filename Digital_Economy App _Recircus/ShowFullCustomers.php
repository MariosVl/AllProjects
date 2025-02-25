<html>
<body>


<style>
   body
   {
       background-image:url("images/πελατες.jfif");
       background-attachment: fixed;
    background-repeat: no-repeat;
    background-position:center;
    background-size: 66%;  
   }
   table,th,td,tr
   {
    

    
    
    margin-left: 0px;
    margin-top: 5px;
    opacity: 0.94;
    width: 30%;
  



    border: 2px solid  rgb(205, 237, 240);
    background-color: #437ede;
    color: rgb(230, 211, 238);
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

if ($result->num_rows > 0)
{

    echo "<table><tr><th>ID</th><th>Name</th><th>RecyclePointsTotal</th></tr>";
   while($row = $result->fetch_assoc())
    {
        
        echo "<tr><td>".$row["id"]."</td><td>".$row["Name"]." </td><td>
" .$row["recycle_points"]."</td></tr>";
      
    }
    echo "</table>";

}
else
{
    echo "0 results"; 
}

$conn->close();

?>

</body>
</html>