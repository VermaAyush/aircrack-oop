#/bin/sh

ifconfig $1 down
ip link set $1 name mon0
iwconfig mon0 mode monitor
ifconfig mon0 up
