<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
$servername="localhost";
$username="root";
$password="";
$dbname="dai19273";



$conn = new mysqli($servername, $username, $password);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 

$sql = "CREATE DATABASE dai19273"; 
if ($conn->query($sql) !== TRUE)
 { 
 echo "Error creating database: " . $conn->error; 
} 
$conn = new mysqli($servername, $username, $password,$dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 


$sql = "CREATE TABLE dai19273 ( 
    id INT(3) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
    email VARCHAR(30) NOT NULL, 
    telephone VARCHAR(10) NOT NULL 
    )"; 

if ($conn->query($sql) !== TRUE) { 
 
    echo "Error creating table: " . $conn->error; 
   }

    ?>
    <a href="view.php">View </a>
    <a href="insert.php">Insert</a>
    <a href="select.php">Select </a>
</body>
</html>