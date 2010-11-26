<?php
session_start();
session_register("view");
if(isset($_SESSION["view"])){
	$count = $_SESSION["view"];
	}
else{
	$count=1;
}
	print "The Number of Viewers till now is: $count";
	$_SESSION["view"]++;
?>
