set ns [new Simulator]

set nt [open duplex_link.tr w]
$ns trace-all $nt
set nm [open duplex_link.nam w]
$ns namtrace-all $nm

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 2Mbps 2ms DropTail

#creating udp agents
set src_n0 [new Agent/UDP] 
set src_n1 [new Agent/UDP]
set dest_n0 [new Agent/Null]
set dest_n1 [new Agent/UDP]

#attaching agents to the nodes
$ns attach-agent $n0 $src_n0
$ns attach-agent $n1 $src_n1
$ns attach-agent $n0 $dest_n0
$ns attach-agent $n1 $dest_n1

#connecting agents
$ns connect $src_n0 $dest_n1
$ns connect $src_n1 $dest_n0

#creating traffic 
set traffic1 [new Application/Traffic/CBR]
set traffic2 [new Application/Traffic/CBR]

#generating traffic

$traffic1 attach-agent $src_n0
$traffic2 attach-agent $src_n1
$traffic1 set packetsize_ 100B
$traffic2 set packetsize_ 100B
$traffic2 set interval_ 2ms
$traffic1 set interval_ 1ms


proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam duplex_link.nam
exit 0
}

$ns at 1.0 "$traffic1 start"
$ns at 1.0 "$traffic2 start"
$ns at 4.0 "$traffic1 stop"
$ns at 4.0 "$traffic2 start"
$ns at 4.5 "finish"
$ns run

 
