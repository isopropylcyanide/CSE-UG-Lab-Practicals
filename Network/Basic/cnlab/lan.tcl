set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nt [open trace1.tr w]
$ns trace-all $nt
set nf [open namfilelan.nam w]
$ns namtrace-all $nf
set outp [open congest.xg w]

proc finish {} {
global ns nf
$ns flush-trace
close $nf
exec nam namfilelan.nam
exit 0
}

set tcp [new Agent/TCP]
$tcp set window_ 15
proc plotwindow {tcp outp} {
global ns
set t1 [$ns now]
set cwnd [$tcp set cwnd_]
puts $outp "$t1 $cwnd"
$ns at [expr $t1 + 0.1] "plotwindow $tcp $outp"
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 0.5Mbps 10ms DropTail
$ns duplex-link $n1 $n2 0.5Mbps 10ms DropTail
$ns duplex-link $n2 $n3 0.5Mbps 10ms DropTail
#$ns duplex-link $n3 $n4 0.5Mbps 10ms DropTail
#$ns duplex-link $n4 $n5 0.5Mbps 10ms DropTail

$ns duplex-link-op $n0 $n2 queuePos 0.5
$ns duplex-link-op $n1 $n2 queuePos 0.5
$ns duplex-link-op $n2 $n3 queuePos 0.5
#$ns duplex-link-op $n4 $n5 queuePos 0.5

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
#$ns duplex-link-op $n3 $n4 orient right-down
#$ns duplex-link-op $n4 $n5 orient right-up

set src1 [new Agent/UDP]
$ns attach-agent $n0 $src1
set src2 [new Agent/TCP]
$ns attach-agent $n1 $src2
set dest1 [new Agent/Null]
$ns attach-agent $n4 $dest1
set dest2 [new Agent/TCPSink]
$ns attach-agent $n4 $dest2

$ns connect $src1 $dest1
$src1 set fid_ 2
$ns connect $src2 $dest2
$src2 set fid_ 1

set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic1 set packetSize 50
$traffic1 set interval 1.5ms

set traffic2 [new Application/FTP]
$traffic2 attach-agent $src2
$traffic2 set packetSize 50
$traffic2 set interval 1.5ms
set lan [$ns newLan "$n3 $n4 $n5" 0.5Mb 4ms DropTail LL MAC/CSMA/Cd Channel]

$ns at 0.0 "plotwindow $tcp $outp"
$ns at 0.5 "$traffic1 start"
$ns at 1.0 "$traffic2 start"
$ns at 2.0 "$traffic1 stop"
$ns at 2.5 "$traffic2 stop"

$ns at 3.0 "finish"
$ns run
