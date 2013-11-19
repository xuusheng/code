#!/usr/bin/python
# 2013-06-04
# convert test.xml to rawstring.
from xml.etree import ElementTree
root=ElementTree.parse("z.xml")
msg=root.find("./msg")

es=msg.findall("./e")
fh=open('r','w')
for e in es:
    if int(e.find("./l").text) > 0:
        fh.write(e.find("./v").text)
        padding_len=int(e.find("./l").text) - len(e.find("./v").text.encode('utf8'))
        if padding_len > 0:
            for i in range(padding_len):
                fh.write(e.find("./p").text)
    else:
        len_form='%0'+ str(-int(e.find("./l").text)) + 'd'
        len_string=len_form % len(e.find("./v").text)
        fh.write(len_string)
        fh.write(e.find("./v").text)
fh.close()
