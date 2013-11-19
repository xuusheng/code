#!/usr/bin/awk -f
#2012-12-06 
#related file: 1.awk.tst
#it can count the repeat times of each items located
#in the first field.

{count[$1]++;}
END {for (name in count) print name, count[name]}
