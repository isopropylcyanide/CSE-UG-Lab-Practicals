set ns [new Simulator]

set nt [open topology3.tr w]
$ns trace-all $nt

set nm [open topology3.nam w]
$ns namtrace-all $nm

for {set i 0} {$i < 6} {incr i} {
	set n$i [$ns node]	
}

$ns rtproto DV

$ns duplex-link $n0 $n1 2Mbps 10ms DropTail
$ns duplex-link $n1 $n2 3Mbps 15ms DropTail
$ns duplex-link $n2 $n3 1.5Mbps 15ms DropTail
$ns duplex-link $n3 $n4 2Mbps 20ms DropTail
$ns duplex-link $n4 $n5 2Mbps 25ms DropTail
$ns duplex-link $n5 $n0 1.5Mbps 20ms DropTail


$ns duplex-link-op $n0 $n1 orient right-down 
$ns duplex-link-op $n1 $n2 orient down
$ns duplex-link-op $n2 $n3 orient left-down
$ns duplex-link-op $n3 $n4 orient left-up
$ns duplex-link-op $n4 $n5 orient up
$ns duplex-link-op $n5 $n0 orient right-up




set srcudp0 [new Agent/UDP]
set srctcp1 [new Agent/TCP]
set desttcp3 [new Agent/TCPSink]
set destudp2 [new Agent/Null]

$ns attach-agent $n0 $srcudp0
$ns attach-agent $n1 $srctcp1
$ns attach-agent $n2 $destudp2
$ns attach-agent $n3 $desttcp3


$ns connect $srcudp0 $destudp2
$ns connect $srctcp1 $desttcp3

set traffic0 [new Application/Traffic/CBR]
set traffic1 [new Application/FTP]

$traffic0 attach-agent $srcudp0
$traffic1 attach-agent $srctcp1

$traffic0 set packetsize_ 1000B
$traffic1 set packetsize_ 1000B
$traffic0 set interval_ 10ms
$traffic1 set interval_ 10ms

#creating proc 
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam topology3.nam 
exit 0
}

#event scheduler

$ns at 0.0 "$traffic0 start"
$ns at 4.0 "$traffic0 stop"
$ns at 0.0 "$traffic1 start"
$ns at 4.0 "$traffic1 stop"
$ns rtmodel-at 2.0 down $n0 $n1
$ns rtmodel-at 3.0 up $n0 $n1
$ns at 4.1 "finish"
$ns run

