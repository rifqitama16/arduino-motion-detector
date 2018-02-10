<?php
$MyUsername = "admin";  // mysql username
$MyPassword = "admin123";  // mysql password
$MyHostname = "202.150.213.3";      // Your Host
$Database = "admin_demo";    // Name of your database
$dbh = mysqli_connect($MyHostname , $MyUsername, $MyPassword, $Database);
if (!$dbh) {
    die("Connection failed: " . mysqli_connect_error());
}
?>