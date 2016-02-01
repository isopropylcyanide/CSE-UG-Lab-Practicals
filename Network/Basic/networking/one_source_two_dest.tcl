set ns [new Simulator]

set nt [open one_source_two_dest.tr w]

$ns trace-all $nt

set nf [open one_source_two_dest.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns simplex-link $n0 $n1 1Mbps 10ms DropTail
$ns simplex-link $n0 $n2 1Mbps 10ms DropTail 

set src [new Agent/UDP]
set dest1 [new Agent/Null]
set dest2 [new Agent/Null]

$ns attach-agent $n0 $src
$ns attach-agent $n1 $dest1
$ns attach-agent $n2 $dest2

$ns connect $src $dest1


set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetsize_ 500B
$traffic set interval_ 100ms

set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src
$traffic1 set packetsize_ 500B
$traffic1 set interval_ 100ms


proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam demo2.nam 
exit 0
}

$ns at 1.0 "$traffic start"
$ns at 4.0 "$traffic stop"
$ns at 4.2 "$ns connect $src $dest2"
$ns at 4.3 "$traffic1 start"
$ns at 8.0 "$traffic1 stop"
$ns at 8.2 "finish"
$ns run



