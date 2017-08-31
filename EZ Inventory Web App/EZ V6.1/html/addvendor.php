<!DOCTYPE html>
<!--TransactionID search Form  -->
<html lang = "en">
   <head>
<title> PHP Script for Items Table </title>
<link rel="stylesheet" type="text/css" href="../Style/view.css">
   </head>
<body>
  <header align="center">
      <a href="home.html"><img src="../images/ez_inventory_80.png"/></a>
  </header>
<?php
                             // Create connection
$db = mysqli_connect("localhost","delga051","testing123");

//if (!$db) // Check connection if statement
//  {
//    print "***** CONNECTION TO DATABASE: FAILED ***** ";exit;
//  }
//echo "***** CONNECTION TO DATABASE: PASS *****";

$delga051 = mysqli_select_db($db, "delga051");

if (!$delga051)//if statement checks the database selected
  {
    print "Error - unable to select from this database.";exit;
  }

// Get the itemID entered by the user in the ID box
$t2ID = $_POST['Name'];
$t2ID = stripcslashes($t2ID);
$t2IDU = htmlspecialchars($t2ID);

$t3ID = $_POST['Description'];
$t3ID = stripcslashes($t3ID);
$t3IDU = htmlspecialchars($t3ID);

$t4ID = $_POST['Phone'];
$t4ID = stripcslashes($t4ID);
$t4IDU = htmlspecialchars($t4ID);

$query = "INSERT INTO Vendor(Name,Description,Phone) VALUES('$t2IDU','$t3IDU','$t4IDU')";

if(mysqli_query($db, $query)){
  echo "New Record has been added. You are now able to see it in View Vendor or View All Vendor";
 } else{
  echo "ERROR: Could was not able to execute record addition." . mysqli_error($link);
 }


// close connection
mysqli_close($link);
?>
</body>
</html>
