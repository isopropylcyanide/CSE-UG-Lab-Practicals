set ns [new Simulator]

set nt [open demo7.tr w]
$ns trace-all $nt
set nf [open namfile7.nam w]
$ns namtrace-all $nf

proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec namfile7.nam
exit 0
}

$ns multicast

set n1 [$ns node]
$n1 color "red"
$n1 shape "square"

set n2 [$ns node]
$n2 color "yellow"
$n2 shape "square"

set n3 [$ns node]
$n3 color "blue"
$n3 shape "square"

set n4 [$ns node]
$n4 color "green"
$n4 shape "square"

set n5 [$ns node]
$n5 color "cyan"
$n5 shape "square"

set n6 [$ns node]
$n6 shape "square"

$ns duplex-link $n1 $n2 3Mbps 2ms DropTail
$ns duplex-link-op $n1 $n2 orient right-up

$ns duplex-link $n2 $n3 3Mbps 2ms DropTail
$ns duplex-link-op $n2 $n3 orient right-down

$ns duplex-link $n3 $n5 3Mbps 2ms DropTail
$ns duplex-link-op $n3 $n5 orient down

$ns duplex-link $n4 $n5 2Mbps 2ms DropTail
$ns duplex-link-op $n4 $n5 orient right

$ns duplex-link $n4 $n1 3Mbps 2ms DropTail
$ns duplex-link-op $n4 $n1 orient up

$ns duplex-link $n2 $n6 3Mbps 2ms DropTail
$ns duplex-link-op $n2 $n6 orient down

$ns duplex-link $n6 $n5 3Mbps 2ms DropTail
$ns duplex-link-op $n6 $n5 orient right-down


set mproto DM
set mrthandle [$ns mrtproto $mproto]

set group1 [Node allocaddr]
set group2 [Node allocaddr]


set src1 [new Agent/UDP]
$ns attach-agent $n1 $src1
set d1 [new Agent/Null]
$ns connect $src1 $d1

$src1 set fid_ 1
$ns color 1 green

set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic1 set packetSize_ 300B  
$traffic1 set interval_ 3ms

$ns at 0.0 "$traffic1 start"
$ns at 10.0 "$traffic1 stop"
$ns at 11.0 "finish"


set src2 [new Agent/UDP]
$ns attach-agent $n2 $src2
set d2 [new Agent/Null]
$ns connect $src2 $d2

$src2 set fid_ 3
$ns color 3 green

set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetSize_ 100B  
$traffic2 set interval_ 2ms

$ns at 0.0 "$traffic1 start"
$ns at 10.0 "$traffic1 stop"
$ns at 11.0 "finish"


$src1 set dst_addr_ $group1
$src2 set dst_addr_ $group2


$ns at 1.2 "$n4 join-group $d1 $group1"




$ns run


