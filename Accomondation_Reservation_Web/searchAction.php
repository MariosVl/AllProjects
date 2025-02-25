<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0 ">
    <title>SearchAction</title>
</head>
<style>
body
{
    background-image: url("images/ReserveBack.jpg");
    background-repeat: no-repeat;
    background-attachment: fixed;
    background-position: center;
    background-size: 100%;


     color: whitesmoke;
    font-size: 2.0em;
    font-style: oblique;
    font-weight: bolder;
    text-align: center; 
}
table
{
    border: 2px solid  rgb(205, 237, 240);
    background-color: #437ede;
    border-collapse: collapse;
    padding: 2px;
    margin-right:1200px;
    

}
a
{
    color: rgb(230, 211, 238);
    text-align: center;
    font-style: italic;
    font-weight: bolder;
    font-size: 1.7em;
}
span
{
     background-color: rgb(84, 195, 195);
}

</style>
<body>

<table>
    <tr><td><a href="index.html">Επιστροφή στην Αρχική</a></td></tr>
    <tr><td><a  href="reserve.html">Επιστροφή στην Κράτηση</a></td></tr>
</table>
<span>
<?php


@$personal_id=$_POST['pass'];

$hostname="localhost";
$db="id19659168_reserveform";
$username="id19659168_zalas";
$password="U_ohRyUa@+~75(v(";

$conn = new mysqli($hostname, $username, $password,$db);
if ($conn->connect_error)
 { 
    die("Connection failed: " . $conn->connect_error); 
 } 

 else
 {
     $Hash_personal_id=md5($personal_id);
   $sql = "SELECT personal_id,firstName,lastName,phone,email,destination,accomodation,food,stay_days,accom_min_value,hotel_name FROM  reservation WHERE personal_id='$Hash_personal_id'"; 
  $res = $conn->query($sql);
  if ($res->num_rows > 0)
  {
   while($row = $res->fetch_assoc())
   {
      echo"H κράτηση αναφέρεται στον πελάτη ".$row['firstName']."  ".$row['lastName'].". </br>"
      ."Tα στοιχεία επικοινωνίας που δηλώθηκαν είναι:"."τηλέφωνο(".$row['phone'].")"." και email(".$row['email'].")</br>"
      ."O πελάτης επέλεξε διακοπές σε  ".$row['destination']." σε δωμάτιο ".$row['accomodation']." με ".$row['food']." διάρκειας ".$row['stay_days']." ημερών.</br>"
      ."Η διαμονή του κλείστηκε για  ".$row['hotel_name']."  με κόστος  ".$row['accom_min_value']." €";
        
   }
  }
  else
  {
    echo "</br>
    **Η αναζήτηση για το αναγνωριστικό που δώσατε δεν ηταν επιτυχής";
  }

 }

 $conn->close();




?>
</span>
</body>
</html>