set ns [new Simulator]
set nt [open 0608.tr w]
$ns trace-all $nt
set nm [open 0608.nam w]
$ns namtrace-all $nm
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam 0608.nam
exit 0
}
set node1 [$ns node]
set node2 [$ns node]
$ns duplex-link $node1 $node2 8Mbps 1ms DropTail
set agent11 [new Agent/UDP]
$ns attach-agent $node1 $agent11
set agent12 [new Agent/Null]
$ns attach-agent $node2 $agent12
set agent21 [new Agent/UDP]
$ns attach-agent $node2 $agent21
set agent22 [new Agent/Null]
$ns attach-agent $node1 $agent22
$ns connect $agent11 $agent12
$ns connect $agent21 $agent22
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $agent11
$traffic1 set packetSize_ 50B
$traffic1 set interval_ 2ms
set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $agent22
$traffic2 set packetSize_ 100B
$traffic2 set interval_ 2ms
$ns at 1.0 "$traffic1 start"
$ns at 5.0 "$traffic1 stop"
$ns at 1.0 "$traffic2 start"
$ns at 5.0 "$traffic2 stop"
$ns at 5.5 "finish"
$ns run


