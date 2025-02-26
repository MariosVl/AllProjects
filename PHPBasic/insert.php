<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<style>
.error
{
    color:red;
}
</style>
<?php
$email=$phone=$employ="";
$emailErr=$phoneErr="";
function test_input($data) { 
    $data = trim($data); 
    $data = stripslashes($data); 
    $data = htmlspecialchars($data); 
    return $data; 
   } 
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    $test=2;
   /* if (empty($_POST["email"])) 
    { 
    $emailErr = "Email is required"; 
    $test--;
    
    }
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) 
    { 
    $emailErr = "Invalid email format"; 
    $test--;
   }
    else 
    { 
    $email = test_input($_POST["email"]);
    }*/

    
    
    if (empty($_POST["email"]))
    { 
        $emailErr = "Email is required";
        $test--;
        
    }
    else
    {
        $email=test_input($_POST["email"]);
        if(!filter_var($email, FILTER_VALIDATE_EMAIL))
        {
            $emailErr="Invalid email format";
            $test--;
        }
    }
   
   
   $employ= test_input($_POST["employee"]); 
   if (empty($_POST["phone"]))
   {
       $phoneErr = "Phone is required";
       $test--;
   }
   else if(strlen($_POST["phone"])!==10)
   {
       $phoneErr = "Invalid phone";
       $test--;
   }
   else
   {
       $phone = test_input($_POST["phone"]); 
   }
   
   

if($test==2)
{
    echo '<script> alert("Succesfull sumbition")</script>';
    
}

if($test==2)
{
    $servername = "localhost"; 
    $username = "root"; 
    $password = ""; 
    $dbname = "dai19273"; 
    $conn = new mysqli($servername, $username, $password, $dbname);
   if ($conn->connect_error) { 
     die("Connection failed: " . $conn->connect_error); 
    } 
    $stmt = $conn->prepare("INSERT INTO dai19273 (email,telephone) 
    VALUES (?,?)"); 
    $stmt->bind_param("ss",$EmaiL,$PhonE);  
    $EmaiL=$email;
    $PhonE=$phone;
    $stmt->execute();
    $stmt->close();
    $email=false;
    $phone=false;
    $conn->close();
}
  
}

?>


<form method="post" action="<?php echo $_SERVER["PHP_SELF"]?>">
E-mail: <input type="text" name="email" value="<?php echo $email;?>"> 
 <span class="error">* <?php echo $emailErr;?></span>
 <br><br>
 Phone
 <input type="text" name="phone" value="<?php echo $phone;?>"><span class="error">* <?php echo $phoneErr;?></span>
 <br><br>
 <select name="employee">
<option >manager</option>  
<option>recruiter</option>  
<option>programmer</option> 
</select><span class="error">*</span>
<br><br>
<input type="submit" value="Eισαγωγή">
 </form>

 <form action="view.php" method="post">
 <input type="submit"value="Δες">
 </form>

 <form action="select.php" method="post">
 <input type="submit"value="Bρες">
 </form>
</body>
</html>