

<html>
<body>
<style>

table,tr,th,td
{
    border:2px solid black;
    border-collapse:collapse;
}
</style>
<?php
$servername="localhost";
$username = "root"; 
$password = ""; 
$dbname = "dai19273"; 
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 
$sql = "SELECT id,email,telephone FROM dai19273 "; 
$result = $conn->query($sql); 

if ($result->num_rows > 0)
{

    echo "<table><tr><th>ID</th><th>Email</th><th>Telephone</th></tr>";
   while($row = $result->fetch_assoc())
    {
        
        if(str_ends_with($row["email"],'uom.edu.gr'))
        {

        echo "<tr><td>".$row["id"]."</td><td>".$row["email"]." </td><td>
" .$row["telephone"]."</td></tr>";
        }
        else
        {
            continue;
        }
      
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