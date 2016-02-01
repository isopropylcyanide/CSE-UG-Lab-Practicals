set ns [new Simulator]
set nt [open 1510.tr w]
$ns trace-all $nt
set nm [open 1510.nam w]
$ns namtrace-all $nm
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

set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 40ms LL MAC/Csma/cd Channel]
$ns duplex-link $n0 $n2 3Mbps 15ms DropTail
$ns duplex-link $n1 $n2 3Mbps 15ms DropTail
$ns duplex-link $n2 $n3 3Mbps 15ms DropTail
#setting up duplex links
#orientation
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
#setting up source agents
set tcpsrc0 [new Agent/TCP]
$ns attach-agent $n0 $tcpsrc0
set udpsrc1 [new Agent/UDP]
$ns attach-agent $n1 $udpsrc1
#setting up destination agents
set udpdest5 [new Agent/Null]
$ns attach-agent $n5 $udpdest5
set tcpdest5 [new Agent/TCPSink]
$ns attach-agent $n5 $tcpdest5
#setting up traffic agents
set trafficudp1 [new Application/Traffic/CBR]
$trafficudp1 attach-agent $udpsrc1
set traffictcp0 [new Application/FTP]
$traffictcp0 attach-agent $tcpsrc0
#coloring the packets
$tcpsrc0 set fid_ 0
$ns color 0 blue
$udpsrc1 set fid_ 2
$ns color 2 red
#making bonds
$ns connect $udpsrc1 $udpdest5
$ns connect $tcpsrc0 $tcpdest5
set out [open 1510.xg w]
$tcpsrc0 set window_ 15
 #tcp and out are parameters of plotwindow method
proc plotwindow {tcpsrc0 out} {
global ns
set now1 [$ns now]
set cwnd1 [$tcpsrc0 set cwnd_ ]
$ns at [expr $now1 + 0.1] "plotwindow $tcpsrc0 $out"
}
$ns at 0.0 "plotwindow $tcpsrc0 $out"
$ns at 0.0 "$trafficudp1 start"
$ns at 8.0 "$trafficudp1 stop"
$ns at 0.0 "$traffictcp0 start"
$ns at 8.0 "$traffictcp0 stop"
$ns at 8 "finish"

$ns run

