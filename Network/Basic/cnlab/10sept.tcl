set ns [new Simulator]
set nt [open 10sept.tr w]
$ns trace-all $nt
set nm [open 10sept.nam w]
$ns namtrace-all $nm
#try with and without the following statement
$ns rtproto DV
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam 10sept.nam
exit 0
}
for {set i 0} {$i<6} {incr i} {
set n$i [$ns node]
}
#setting up duplex links
$ns duplex-link $n0 $n1 3Mbps 15ms DropTail
$ns duplex-link $n1 $n2 3Mbps 15ms DropTail
$ns duplex-link $n2 $n3 3Mbps 15ms DropTail
$ns duplex-link $n3 $n4 3Mbps 15ms DropTail
$ns duplex-link $n4 $n5 3Mbps 15ms DropTail
$ns duplex-link $n5 $n0 3Mbps 15ms DropTail
#setting up queue limits
$ns queue-limit $n0 $n1 5
$ns queue-limit $n1 $n2 5
$ns queue-limit $n2 $n3 5
$ns queue-limit $n3 $n4 5
$ns queue-limit $n4 $n5 5
$ns queue-limit $n5 $n0 5
#orientation
$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient down
$ns duplex-link-op $n2 $n3 orient left-down
$ns duplex-link-op $n3 $n4 orient left-up
$ns duplex-link-op $n4 $n5 orient up
$ns duplex-link-op $n5 $n0 orient right-up
#setting up source agents
set udpsrc0 [new Agent/UDP]
$ns attach-agent $n0 $udpsrc0
set tcpsrc1 [new Agent/TCP]
$ns attach-agent $n1 $tcpsrc1
#setting up destination agents
set udpdest2 [new Agent/Null]
$ns attach-agent $n2 $udpdest2
set tcpdest3 [new Agent/TCPSink]
$ns attach-agent $n3 $tcpdest3
#setting up traffic agents
set trafficudp0 [new Application/Traffic/CBR]
$trafficudp0 attach-agent $udpsrc0
set traffictcp1 [new Application/FTP]
$traffictcp1 attach-agent $tcpsrc1
#setting up type of traffic
$trafficudp0 set packetSize_ 100B
$trafficudp0 set interval_ 1ms
$traffictcp1 set packetSize_ 100B
$traffictcp1 set interval_ 1ms
#connecting source and destinations
$ns connect $tcpsrc1 $tcpdest3
$ns connect $udpsrc0 $udpdest2
#coloring the packets
$udpsrc0 set fid_ 0
$ns color 0 blue
$tcpsrc1 set fid_ 2
$ns color 2 red
$ns at 0.0 "$trafficudp0 start"
$ns at 8.0 "$trafficudp0 stop"
$ns at 0.0 "$traffictcp1 start"
$ns at 8.0 "$traffictcp1 stop"
$ns rtmodel-at 2.0 down $n0 $n1
$ns rtmodel-at 3.0 up $n0 $n1
$ns rtmodel-at 5.0 down $n2 $n3
$ns rtmodel-at 6.0 up $n2 $n3
$ns at 8 "finish"
$ns run

