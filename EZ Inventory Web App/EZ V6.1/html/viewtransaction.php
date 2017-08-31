<!DOCTYPE html>
<!-- InvoiceNum search Form  -->
<html lang = "en">
   <head>
<title> PHP Script for Transactions Table </title>
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

// Get the InvoiceNum entered by the user in the ID box
$InvoiceNum = $_POST['InvoiceNum'];
$InvoiceNum = stripcslashes($InvoiceNum);
$InvoiceIDU = htmlspecialchars($InvoiceNum);

//query to select info from Invoice
$query = "SELECT * FROM Transactions WHERE InvoiceNum = '$InvoiceIDU'";

//Variable to store query result
$Qresult = mysqli_query($db, $query);

if(!$Qresult)//if statement for checking query
  {
    print "Error - The query was not successful.";
    $error = mysql_error();//sql error
    print "<p>" . $error . "</p>";
    exit;
  }

// Display the results in a table
print "<div>";
print "<table> <caption> <h1> Item Info: </h1>";
print" <h4> Invoice Number Entered: " . $InvoiceIDU . "</h4></caption>";
print "<tr align = 'center'>";


$n_rows = mysqli_num_rows($Qresult);// Number of rows var

if($n_rows > 0)
  {
    // Get the first row of the result
    $firstRow = mysqli_fetch_assoc($Qresult);

    // Get the number of fields in the result
    $num_fields = mysqli_num_fields($Qresult);

    // Get the column names
    $CNames = array_keys($firstRow);

    // Display column names as appropriate column headers
    for($i = 0; $i < $num_fields; $i++)
      {
	print "<th>" . $CNames[$i] . "</th>";
      }
    print "</tr>";

    // Display the values of rows
    for($row_num = 0; $row_num < $n_rows; $row_num++)
      {
	print "<tr>";
	$values = array_values($firstRow);
	for($i = 0; $i < $num_fields; $i++)
	  {
	    $value = htmlspecialchars($values[$i]);
	    print "<td>" . $value . "</td>";
	  }
	print "</tr>";// End row
	$firstRow = mysqli_fetch_assoc($Qresult);//next row
      }
  }
 else//else statement if nothing is inputed or false
   {
     print "<td> *****ERROR: USER INPUT INVALID InvoiceNum FOR TRANSACTIONS TABLE*****.</td> <br />";
   }

// Close table
print "</table>";
print "</div>";
?>
</body>
</html>
