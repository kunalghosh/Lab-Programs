#!/usr/bin/perl

print "Content-type:text/html\n\n";
print "<html><body><table border='1'><tr><td>Variable</td><td>Value</td></tr><tr>";
foreach $env (sort keys %ENV)
{
	print "<td>";
	print $env;
	print "</td>";
	print "<td>";
	print $ENV{$env};
	print "</td>";
}
print "</tr></table></body></html>";
