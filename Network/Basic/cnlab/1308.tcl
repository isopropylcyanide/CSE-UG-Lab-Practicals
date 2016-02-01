set ns [new Simulator]
set nt [open 1308.tr w]
$ns trace-all $nt
set nm [open 1308.nam w]
$ns namtrace-all $nm
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam 1308.nam
exit 0
}
for {set i 1} {$i<5} {incr i} {
set n$i [$ns node]
}
$n1 shape "square"
$n1 color "cyan"
$n2 shape "square"
$n2 color "cyan"
$n3 shape "circle"
$n3 color "blue"
$n4 shape "square"
$n4 color "cyan"
$ns duplex-link $n1 $n3 3Mbps 1.5ms DropTail
$ns queue-limit $n1 $n3 5
$ns duplex-link-op $n1 $n3 orient right-down
set src1 [new Agent/UDP]
$ns attach-agent $n1 $src1
$ns duplex-link $n2 $n3 1.5Mbps 2ms DropTail
$ns queue-limit $n2 $n3 7
$ns duplex-link-op $n2 $n3 orient right-up
set src2 [new Agent/UDP]
$ns attach-agent $n2 $src2
set traffic1 [new Application/Traffic/CBR]
set traffic2 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic2 attach-agent $src2
$traffic1 set packetSize_ 50B
$traffic2 set packetSize_ 50B
$traffic1 set interval_ 3ms
$traffic2 set interval_ 1ms
$ns duplex-link $n3 $n4 2Mbps 2ms DropTail
$ns duplex-link-op $n3 $n4 orient right
set dest [new Agent/Null]
$ns attach-agent $n4 $dest
$ns connect $src1 $dest
$ns connect $src2 $dest
$ns at 1.0 "$traffic1 start"
$ns at 5.0 "$traffic1 stop"
$ns at 1.0 "$traffic2 start"
$ns at 5.0 "$traffic2 stop"
$ns at 5.5 "finish"
$ns run

