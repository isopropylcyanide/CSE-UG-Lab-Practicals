set ns [new Simulator]
set nt [open 2708.tr w]
$ns trace-all $nt
set nm [open 2708.nam w]
$ns namtrace-all $nm
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam 2708.nam
exit 0
}
for {set i 0} {$i<6} {incr i} {
set n$i [$ns node]
}
$n1 color "cyan"
$n2 shape "square"
$n2 color "cyan"
$n3 color "blue"
$n3 shape "square"
$n4 shape "square"
$n4 color "cyan"
$n0 color "cyan"
$n5 shape "square"
$n5 color "cyan"
$ns duplex-link $n0 $n2 3Mbps 1.5ms DropTail
$ns queue-limit $n0 $n2 5
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link $n1 $n2 2Mbps 2ms DropTail
$ns queue-limit $n1 $n2 7
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link $n2 $n3 7Mbps 5ms DropTail
$ns queue-limit $n2 $n3 3
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link $n5 $n3 3Mbps 1ms DropTail
$ns queue-limit $n5 $n3 10
$ns duplex-link-op $n5 $n3 orient up
$ns duplex-link $n4 $n3 3Mbps 1ms DropTail
$ns queue-limit $n4 $n3 10
$ns duplex-link-op $n4 $n3 orient left
set src0 [new Agent/UDP]
$ns attach-agent $n0 $src0
set src1 [new Agent/TCP]
$ns attach-agent $n1 $src1
set src5 [new Agent/TCP]
$ns attach-agent $n5 $src5
set dest0 [new Agent/Null]
$ns attach-agent $n4 $dest0
set dest1 [new Agent/TCPSink]
$ns attach-agent $n4 $dest1
set dest5 [new Agent/TCPSink]
$ns attach-agent $n4 $dest5
set traffic0 [new Application/Traffic/CBR]
$traffic0 attach-agent $src0
set traffic1 [new Application/FTP]
$traffic1 attach-agent $src1
set traffic5 [new Application/FTP]
$traffic5 attach-agent $src5
$traffic0 set packetSize_ 150B
$traffic0 set interval_ 1ms
$traffic1 set packetSize_ 150B
$traffic1 set interval_ 1ms
$traffic5 set packetSize_ 150B
$traffic5 set interval_ 1ms
$ns connect $src0 $dest0
$ns connect $src1 $dest1
$ns connect $src5 $dest5
$src0 set fid_ 0
$ns color 0 blue
$src1 set fid_ 1
$ns color 1 red
$src5 set fid_ 5
$ns color 5 green
$ns at 1.0 "$traffic0 start"
$ns at 8.0 "$traffic0 stop"
$ns at 1.0 "$traffic1 start"
$ns at 8.0 "$traffic1 stop"
$ns at 1.0 "$traffic5 start"
$ns at 8.0 "$traffic5 stop"
$ns at 8 "finish"
$ns run
