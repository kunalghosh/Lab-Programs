<html><body>
<center>
The Database contents are Shown Below<br />
<table border=1>
<tr><td>NAME</td><td>ADD1</td><td>ADD2</td><td>EMAIL</td></tr>
<?php

$name = $_GET["name"];
$add1 = $_GET["add1"];
$add2 = $_GET["add2"];
$email= $_GET["email"];

$con = mysql_connect("localhost","root","tee89tuu");
mysql_select_db("new");
$result = mysql_query("insert into details values('$name','$add1','$add2','$email')");
$result2= mysql_query("select * from details;");
while($a=mysql_fetch_row($result2)){
	print "<tr><td>$a[0]</td><td>$a[1]</td><td>$a[2]</td><td>$a[3]</td></tr>";
}
?>
</table>
</center>
