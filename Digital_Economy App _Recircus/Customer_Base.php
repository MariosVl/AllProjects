<?php
$servername="localhost";
$username="root";
$password="";
$dbname="Customer_Base";



$conn = new mysqli($servername, $username, $password);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 

$sql = "CREATE DATABASE Customer_Base"; 
if ($conn->query($sql) !== TRUE)
 { 
 echo "Error creating database: " . $conn->error; 
} 
$conn = new mysqli($servername, $username, $password,$dbname);
if ($conn->connect_error) { 
 die("Connection failed: " . $conn->connect_error); 
} 


$sql = "CREATE TABLE customers ( 
    id INT(3) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(30) NOT NULL,
    recycle_points FLOAT(3) NOT NULL
    )"; 

if ($conn->query($sql) !== TRUE) { 
 
    echo "Error creating table: " . $conn->error; 
   }

   $conn->close();
   ?>
  