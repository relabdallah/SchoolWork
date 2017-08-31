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
$t2ID = $_POST['ProductName'];
$t2ID = stripcslashes($t2ID);
$t2IDU = htmlspecialchars($t2ID);

$t3ID = $_POST['Size'];
$t3ID = stripcslashes($t3ID);
$t3IDU = htmlspecialchars($t3ID);

$t4ID = $_POST['ProductType'];
$t4ID = stripcslashes($t4ID);
$t4IDU = htmlspecialchars($t4ID);

$t5ID = $_POST['Quantity'];
$t5ID = stripcslashes($t5ID);
$t5IDU = htmlspecialchars($t5ID);

$t6ID = $_POST['Price'];
$t6ID = stripcslashes($t6ID);
$t6IDU = htmlspecialchars($t6ID);

$t7ID = $_POST['Cost'];
$t7ID = stripcslashes($t7ID);
$t7IDU = htmlspecialchars($t7ID);

$t8ID = $_POST['Manufacturer'];
$t8ID = stripcslashes($t8ID);
$t8IDU = htmlspecialchars($t8ID);

$t9ID = $_POST['Description'];
$t9ID = stripcslashes($t9ID);
$t9IDU = htmlspecialchars($t9ID);

$t10ID = $_POST['Category'];
$t10ID = stripcslashes($t10ID);
$t10IDU = htmlspecialchars($t10ID);

$t11ID = $_POST['VendorID'];
$t11ID = stripcslashes($t11ID);
$t11IDU = htmlspecialchars($t11ID);

$query = "INSERT INTO Item(ProductName,Size,ProductType,Quantity,Price,Cost,Manufacturer,Description,Category,VendorID) VALUES('$t2IDU','$t3IDU','$t4IDU','$t5IDU','$t6IDU','$t7IDU','$t8IDU','$t9IDU','$t10IDU','$t11IDU')";

if(mysqli_query($db, $query)){
  echo "New Record has been added. You are now able to see it in View Item or View All Items";
 } else{
  echo "ERROR: Could was not able to execute record addition." . mysqli_error($link);
 }


// close connection
mysqli_close($link);
?>
</body>
</html>
