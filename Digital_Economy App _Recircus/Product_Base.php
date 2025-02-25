<?php
$servername="localhost";
$username="root";
$password="";
$dbname="Product_Base";



$conn = new mysqli($servername, $username, $password);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 

$sql = "CREATE DATABASE Product_Base"; 
if ($conn->query($sql) !== TRUE)
 { 
 echo "Error creating database: " . $conn->error; 
} 
$conn = new mysqli($servername, $username, $password,$dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 


$sql = "CREATE TABLE products ( 
    id INT(3) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
    Brand VARCHAR(30) NOT NULL, 
    category VARCHAR(30) NOT NULL, 
    recycle_points FLOAT(3) NOT NULL 
    )"; 

if ($conn->query($sql) !== TRUE) { 
 
    echo "Error creating table: " . $conn->error; 
   }

   $stmt = $conn->prepare("INSERT INTO products (Brand, category, recycle_points) 
   VALUES (?, ?, ?)"); 
   $stmt->bind_param("ssd", $Brand, $category, $recycle_points); 
   $Brand = "ΔΕΛΤΑ"; 
$category = "ΧΑΡΤI"; 
$recycle_points = 34; 
$stmt->execute(); 

$Brand = "Crystal"; 
$category = "ΧΑΡΤΙ"; 
$recycle_points = 32; 
$stmt->execute(); 

$Brand = "ΠΛΩΜΑΡΙ"; 
$category = "ΓΥΑΛΙ"; 
$recycle_points = 17; 
$stmt->execute(); 

$Brand = "Attiki"; 
$category = "ΓΥΑΛΙ"; 
$recycle_points = 14; 
$stmt->execute(); 

$Brand = "Lays"; 
$category = "ΠΛΑΣΤΙΚΟ"; 
$recycle_points = 45; 
$stmt->execute(); 

$Brand = "Cheetos"; 
$category = "ΠΛΑΣΤΙΚΟ"; 
$recycle_points = 48; 
$stmt->execute(); 


$Brand = "NesCafe"; 
$category = "ΑΛΟΥΜΙΝΙΟ"; 
$recycle_points = 22; 
$stmt->execute(); 


$Brand = "ΝΟΥΝΟΥ"; 
$category = "ΑΛΟΥΜΙΝΙΟ"; 
$recycle_points = 27; 
$stmt->execute(); 


$stmt->close();
$conn->close();

?>