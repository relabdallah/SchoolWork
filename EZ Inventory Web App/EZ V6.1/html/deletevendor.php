<!DOCTYPE html>
<!--Item ID search Form  -->
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
$VendorID = $_POST['VendorID'];
$VendorID = stripcslashes($VendorID);
$VendorIDU = htmlspecialchars($VendorID);
//query to select info from Items
$query = "DELETE FROM Vendor WHERE VendorID = '$VendorIDU'";

//Variable to store query result
$Qresult = mysqli_query($db, $query);

if(!$Qresult)//if statement for checking query
  {
    print "Error - The query was not successful.";
    $error = mysql_error();//sql error
    print "<p>" . $error . "</p>";
    exit;
  }
 else{print "VENDOR DELETED";}
// Display the results in a table
print "<div>";
print "<table> <caption> <h1> Vendor Info: </h1>";
print" <h4> Vendor ID Entered: " . $VendorIDU . "</h4></caption>";
print "<tr align = 'center'>";
?>
</body>
</html>
