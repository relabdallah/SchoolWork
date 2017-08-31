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
$t2ID = $_POST['FName'];
$t2ID = stripcslashes($t2ID);
$t2IDU = htmlspecialchars($t2ID);

$t3ID = $_POST['LName'];
$t3ID = stripcslashes($t3ID);
$t3IDU = htmlspecialchars($t3ID);

$t4ID = $_POST['Password'];
$t4ID = stripcslashes($t4ID);
$t4IDU = htmlspecialchars($t4ID);

$t5ID = $_POST['Role'];
$t5ID = stripcslashes($t5ID);
$t5IDU = htmlspecialchars($t5ID);


$t6ID = $_POST['StoreNum'];
$t6ID = stripcslashes($t6ID);
$t6IDU = htmlspecialchars($t6ID);

$query = "INSERT INTO Employee(FName,LName,Password,Role,StoreNum) VALUES('$t2IDU','$t3IDU','$t4IDU','$t5IDU','$t6IDU')";

if(mysqli_query($db, $query)){
  echo "New Record has been added. You are now able to see it in View Employee or View All Employees";
 } else{
  echo "ERROR: Could was not able to execute record addition." . mysqli_error($link);
 }
// close connection
mysqli_close($link);
?>
</body>
</html>
