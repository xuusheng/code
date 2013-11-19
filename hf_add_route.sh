#!/bin/dash
#modify the route to connect to both internet and lan.
#2012-12-15
sudo route del default
sudo route add default gw 192.168.0.1 dev wlan0
sudo route add -net 192.168.100.0 netmask 255.255.255.0 gw 192.168.40.254 dev eth0
sudo route add -net 192.168.200.0 netmask 255.255.255.0 gw 192.168.40.254 dev eth0
