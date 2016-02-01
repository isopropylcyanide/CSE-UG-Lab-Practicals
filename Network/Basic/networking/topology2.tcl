set ns [new Simulator]

set nt [open topology2.tr w]
$ns trace-all $nt

set nm [open topology2.nam w]
$ns namtrace-all $nm

for {set i 0} {$i < 6} {incr i} {
	set n$i [$ns node]	
}

$n2 shape "square"
$n3 shape "square"
$n4 shape "square"
$n5 shape "square"


$ns simplex-link $n0 $n2 2Mbps 10ms DropTail
$ns duplex-link $n1 $n2 3Mbps 15ms DropTail
$ns duplex-link $n2 $n3 1.5Mbps 15ms DropTail
$ns duplex-link $n3 $n4 2Mbps 20ms DropTail
$ns duplex-link $n5 $n3 1.5Mbps 20ms DropTail

$ns simplex-link-op $n0 $n2 orient right-down 
$ns simplex-link-op $n2 $n3 orient rigt-middle
$ns simplex-link-op $n3 $n5 orient down
$ns simplex-link-op $n3 $n4 orient right
$ns simplex-link-op $n1 $n2 orient right-up


set src0 [new Agent/UDP]
set src1 [new Agent/TCP]
set src5 [new Agent/TCP]
set desttcp14 [new Agent/TCPSink]
set desttcp54 [new Agent/TCPSink]
set destudp04 [new Agent/Null]

$ns attach-agent $n0 $src0
$ns attach-agent $n1 $src1
$ns attach-agent $n5 $src5 
$ns attach-agent $n4 $desttcp14
$ns attach-agent $n4 $desttcp54
$ns attach-agent $n4 $destudp04

$ns connect $src0 $destudp04
$ns connect $src1 $desttcp14
$ns connect $src5 $desttcp54

set traffic0 [new Application/Traffic/CBR]
set traffic1 [new Application/FTP]
set traffic5 [new Application/FTP]

$traffic0 attach-agent $src0
$traffic1 attach-agent $src1
$traffic5 attach-agent $src5


$traffic0 set packetsize_ 1000B
$traffic1 set packetsize_ 1000B
$traffic5 set packetsize_ 1000B
$traffic0 set interval_ 10ms
$traffic1 set interval_ 10ms 
$traffic5 set interval_ 10ms 


#creating proc 
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam topology2.nam 
exit 0
}

#event scheduler

$ns at 1.0 "$traffic0 start"
$ns at 4.0 "$traffic0 stop"
$ns at 4.5 "$traffic1 start"
$ns at 6.0 "$traffic1 stop"
$ns at 6.2 "$traffic5 start"
$ns at 8.0 "$traffic5 stop"
$ns at 8.1 "finish"
$ns run

