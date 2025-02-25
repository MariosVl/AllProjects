<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0 ">
    <title>ReservationAction</title>
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


$firstNameError=$lastNameError=$phoneError=$emailError=$destinationError=$accomodationError=$foodError=$stay_daysError=$personal_idError="";
$result=0;
@$firstName=$_POST['name'];
@$lastName=$_POST['surname'];
@$phone=$_POST['phone'];
@$email=$_POST['email'];
@$destination=$_POST['Destination'];
@$accomodation=$_POST['Room'];
@$food=$_POST['Food'];
@$stay_days=$_POST['Days'];
@$personal_id=$_POST['password'];

if(empty($firstName))
{
   $firstNameError="**To όνομα είναι υποχρεωτικό";
}
else
{
   if(!preg_match("/^[a-zA-Z\p{Greek}]+$/u", $firstName))
   {
      
      $firstNameError="**Απαιτούνται μόνο γράμματα Ελληνικού/Αγγλικού αλφαβήτου για όνομα ";
   
   }
   else
   {
      $result++;
   }
}

if(empty($lastName))
{
   $lastNameError="**To επίθετο είναι υποχρεωτικό";

}
else
{
   if(!preg_match("/^[a-zA-Z\p{Greek}]+$/u", $lastName))
   {
      
      $lastNameError="**Απαιτούνται μόνο γράμματα Ελληνικού/Αγγλικού αλφαβήτου για επώνυμο ";
   
   }
   else
   {
      $result++;
   }
  
}


if(empty($phone))
{
   $phoneError="**Aπαιτείται το κινητό τηλέφωνο ";
}
else
{
   if(!preg_match('/^69[0-9]{8}+$/', $phone))
   {
      $phoneError="**Δώστε έγκυρο αριθμό ελληνικού κινητού τηλεφώνου";
   }
   else
   {
      $result++;
   }
}


if(empty($email))
{
   $emailError="**Απαιτείται συμπλήρωση email";
}
else
{
   if(!filter_var($email, FILTER_VALIDATE_EMAIL))
   {
      $emailError="**Δώστε έγκυρο email(παγκόσμιες καταλήξεις/ όχι καταλήξεις ιδρυμάτων/οργανισμών) ";
   }
   else
   {
      $result++;
   }
}





   if(empty($destination))
   {
      $destinationError="**Eπέλεξε προορισμό";
   }
   else
   {
      $result++;
   }

   if(empty($accomodation))
   {
      $accomodationError="**Eπέλεξε Δωμάτιο";
   }
   else
   {
      $result++;
   }

   if(empty($food))
   {
      $foodError="**Eπέλεξε παρεχόμενο γεύμα";
   }
   else
   {
      $result++;
   }


    if(empty($stay_days))
    {
      $stay_daysError="**Παρακαλώ εισάγετε ημέρες διαμονής ";
    }
    else
    {
      if($stay_days<=0)
      {
         $stay_daysError="**Συμπληρώστε  τουλάχιστον 1 μέρα διαμονής";
      }
      else
      {
         $result++;
      }
    }
   
    if(empty($personal_id))
    {
          $personal_idError="**Δώστε προσωπικό κωδικό";
    }
    else
    {
        
      if(strlen($personal_id)<6)
      {
         $personal_idError="**Ελάχιστο μήκος κωδικού 6 χαρακτήρες";
      }
      else
      {
        $Hash_personal_id=md5($personal_id);
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
        $sql = "SELECT personal_id FROM  reservation WHERE personal_id='$Hash_personal_id'"; 
        $res = $conn->query($sql);
        if ($res->num_rows > 0)
        {
            $personal_idError="**Ο κωδικός που ορίσατε χρησιμοποιείται ήδη ,ορίστε νέο κωδικό";
        }
        else
        {
             $result++;
        }
       }
       $conn->close();
    }
   }

 if($result==9)
 {
   
   $price1=$price2=$min=0;
   $name1=$name2=$minName="";
   switch($destination)
   {   
   
       case 'Κέρκυρα':
           $name1='Corfu Beach';
           $name2='Ionian Paradise';
           if($accomodation=='Μονόκλινο'&& $food=='Πρωινό')
           {
               $price1=90;
               $price2=80;
               
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πρωινό')
           {
               $price1=130;
               $price2=170;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πρωινό')
           {
               $price1=280;
               $price2=310;
   
           }
           else  if($accomodation=='Μονόκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=200;
               $price2=260;
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=340;
               $price2=380;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=420;
               $price2=520;
           }
           break;
       case 'Ρόδος':
           $name1='Rodos Palace';
           $name2='Lindos Accomodation';
           if($accomodation=='Μονόκλινο'&& $food=='Πρωινό')
           {
               $price1=120;
               $price2=60;
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πρωινό')
           {
               $price1=170;
               $price2=100;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πρωινό')
           {
               $price1=340;
               $price2=160;
           }
           else if($accomodation=='Μονόκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=260;
               $price2=200;
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=390;
               $price2=240;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=460;
               $price2=310;
           }
          break;
       case 'Λειψοί':
           $name1='Λειψοί AppartMents';
           $name2='Λειψοί Hotel';
           if($accomodation=='Μονόκλινο'&& $food=='Πρωινό')
           {
               $price1=20;
               $price2=30;
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πρωινό')
           {
               $price1=25;
               $price2=35;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πρωινό')
           {
               $price1=30;
               $price2=40;
   
           }
           else if($accomodation=='Μονόκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=30;
               $price2=40;
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=35;
               $price2=45;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=40;
               $price2=50;
           }
        break;
        
       case 'Λευκάδα':
           $name1='Lefkada Resort';
           $name2='Nydri Pallas';
           if($accomodation=='Μονόκλινο'&& $food=='Πρωινό')
           {
               $price1=15;
               $price2=70;
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πρωινό')
           {
               $price1=40;
               $price2=120;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πρωινό')
           {
               $price1=45;
               $price2=150;
           }
           else if($accomodation=='Μονόκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=50;
               $price2=160;
   
           }
           else if($accomodation=='Δίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=55;
               $price2=220;
           }
           else if($accomodation=='Τρίκλινο'&& $food=='Πλήρης_Διατροφή')
           {
               $price1=60;
               $price2=340;
           }
          break;
   
       default :
        break;
   }
   $price1=$price1*$stay_days;
   $price2=$price2*$stay_days;

   $minArray=array
   (
    array($price1,$name1),
    array($price2,$name2),
   );
   $min=$minArray[0][0];
   $minName=$minArray[0][1];
   for($i=1;$i<2;$i++)
   {
      if($minArray[$i][0]<$min)
        {
            $min=$minArray[$i][0];
            $minName=$minArray[$i][1];
        }
    
   }

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
   $stmt = $conn->prepare("INSERT INTO reservation (personal_id,firstName,lastName,phone,email,destination,accomodation,food,stay_days,accom_min_value,hotel_name) 
   VALUES (?,?,?,?,?,?,?,?,?,?,?)"); 
   $stmt->bind_param("ssssssssiis",$Hash_personal_id, $firstName, $lastName, $phone,$email,$destination,$accomodation,$food,$stay_days,$min,$minName); 
   $stmt->execute(); 
   $stmt->close();
   $conn->close();
   echo"!!Επιτυχής καταχώρηση των στοιχείων σας";
   }
  
 }
 else
 {
   echo"
   $firstNameError</br>$lastNameError</br>$phoneError</br>$emailError</br>$destinationError</br>
   $accomodationError</br>$foodError</br>$personal_idError</br>$stay_daysError</br></br></br></br></br>
   !*Notice:'Αν θέλετε να επιστρέψετε στην συμπληρωμένη φόρμα κράτησης χρησιμοποιήστε το βέλος επιστροφής του browser, αλλιώς το κουμπί επιστροφής στην κράτηση το οποίο 
   και θα την αδειάσει'";
 }


?>
</span>
</body>
</html>