#!/usr/bin/perl'

print "Content-type:text/html\n\n";
use CGI;
use DBI;

$cgi = new CGI;
$name = $cgi->param("name");
$age = $cgi->param("age");
print "$name $age";
$con = DBI->connect("DBI:mysql:lab10","root","tee89tuu");
$prep = $con->prepare("insert into user values('$name','$age');");
$prep->execute();
$res  = $con->prepare("select * from user;");
$res->execute();
print "<html><body><table border=1>";
print "<tr><td>Name</td><td>AGE</td></tr>";
while(@a=$res->fetchrow_array()){
	print "<tr><td>$a[0]</td><td>$a[1]</td></tr>";	
}
print "</table></body></html>";
