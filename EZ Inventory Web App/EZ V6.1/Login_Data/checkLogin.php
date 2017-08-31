<?php


//connect to the database 
$mysql_db = mysqli_connect("localhost", "delga051", "testing123");;

//check if connection to database is made
if (!$mysql_db) // Check connection if statement
  {
    print "***** CONNECTION TO DATABASE: FAILED ***** ";exit;
  }
echo "***** CONNECTION TO DATABASE: PASS *****";

//select in the database and check if selection is succesful
$select_db= mysqli_select_db($mysql_db,"delga051");
if(!$select_db)
{
print "Error - unable to select from this database.";exit;
}

//Get values from login.php file
$username= $_POST['username'];
$password= $_POST['password'];

//to prevent mysql injection
$username = stripslashes($username);
$password = stripslashes($password);

//Query the database for user
$query= "select * from Employee where EmpID = '$username' and Password = '$password'";
$result = mysqli_query($mysql_db, $query) or die ("Failed to query database" .mysql_error());

$row = mysql_fetch_array($result);
if($row['EmpID'] == $username && $row['Password'] == $password)
{ header('Location:../html/index.html');
}
else
{ echo "Failed to login";
}

// close connection
mysqli_close($link);
?>