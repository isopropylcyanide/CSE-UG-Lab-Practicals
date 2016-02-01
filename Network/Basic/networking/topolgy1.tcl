set ns [new Simulator]

set nt [open topology1.tr w]
$ns trace-all $nt

set nm [open topology1.nam w]
$ns namtrace-all $nm

for { set i 1} { $i <5} {incr i} {
 set n$i [$ns node]
}

$n1 shape "square"
$n2 shape "square"
$n3 shape "square"


$ns simplex-link $n0 $n2 3Mbps 15ms DropTail
$ns simplex-link $n1 $n2 1.5Mbps 15ms DropTail
$ns simplex-link $n3 $n4 2Mbps 20ms DropTail

#$ns queue-limit $n1 $n3 5
#$ns queue-limit $n2 $n3 7

#$ns simplex-link-op $n1 $n3 orient right-up 
#$ns simplex-link-op $n3 $n4 orient right
#$ns simplex-link-op $n2 $n3 orient right-down


set src1 [new Agent/UDP]
set src2 [new Agent/UDP]
set dest4 [new Agent/Null]

$ns attach-agent $n1 $src1
$ns attach-agent $n2 $src2
$ns attach-agent $n4 $dest4 


$ns connect $src1 $dest4
$ns connect $src2 $dest4




set traffic1 [new Application/Traffic/CBR]
set traffic2 [new Application/Traffic/CBR]

$traffic1 attach-agent $src1
$traffic2 attach-agent $src2

$traffic1 set packetsize_ 1000B
$traffic2 set packetsize_ 1000B
$traffic1 set interval_ 10ms
$traffic1 set interval_ 10ms 

#creating proc 
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam topology1.nam
exit 0
}

#event scheduler

$ns at 1.0 "$traffic1 start"
$ns at 4.0 "$traffic1 stop"
$ns at 4.5 "$traffic2 start"
$ns at 6.0 "$traffic2 stop"
$ns at 6.2 "finish"
$ns run
