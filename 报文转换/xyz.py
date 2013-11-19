#!/usr/bin/python

from xml.etree import ElementTree
x=ElementTree.parse("x.xml")
y=ElementTree.parse("y.xml")
z=open("z.xml", "w")

msgs=x.findall("./msg")
yes=y.findall("./e")
for msg in msgs:
    xes=msg.findall("./e")
    for xe in xes:
        for ye in yes:
            if int(ye.find("./i").text) == int(xe.find("./i").text):
                z.write("<e><i>")
                z.write(xe.find("./i").text)
                z.write("</i><v>")
                z.write(xe.find("./v").text)
                z.write("</v><l>")
                z.write(ye.find("./l").text)
                z.write("</l><t>")
                z.write(ye.find("./t").text)
                z.write("</t></e>")

z.close()
