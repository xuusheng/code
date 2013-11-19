s/^Bit \[/<e><i>/
s/\] =/<\/i>/
s/[	 ]\+\[/<v>/
s/\]\.\?$/<\/v><\/e>/
s/^BITMAP=\[/<e><i>1<\/i><v>/
s/^SysTransTime.*/<msg>/
s/\(<i>128.*\)$/\1<\/msg>/
s/^\([^<].*\)/<e><i>1<\/i><v>\1/
1i\
<root>
$a\
</root>


