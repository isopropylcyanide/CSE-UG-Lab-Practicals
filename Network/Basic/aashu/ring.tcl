set ns [new Simulator]

set nt [open trace1.tr w]
$ns trace-all $nt

set nf [open namfile.nam w]
$ns namtrace-all $nf

proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam namfile.nam
	exit 0
}
######
$ns rtproto DV

for {set i 0} {$i<6} {incr i} {
	set n$i [$ns node]
}

$n0 color Green
$n2 color Green
$n1 color Blue
$n3 color Blue
$n4 color Red
$n5 color Red

$ns duplex-link $n0 $n1 2.5Mbps 4ms DropTail
$ns duplex-link-op $n0 $n1 orient left-down

$ns duplex-link $n1 $n2 2.5Mbps 4ms DropTail
$ns duplex-link-op $n1 $n2 orient down

$ns duplex-link $n2 $n3 2.5Mbps 4ms DropTail
$ns duplex-link-op $n2 $n3 orient right-down

$ns duplex-link $n3 $n4 2.5Mbps 4ms DropTail
$ns duplex-link-op $n3 $n4 orient right-up

$ns duplex-link $n4 $n5 2.5Mbps 4ms DropTail
$ns duplex-link-op $n4 $n5 orient up

$ns duplex-link $n5 $n0 2.5Mbps 4ms DropTail
$ns duplex-link-op $n5 $n0 orient left-up

set src [new Agent/UDP]
set dest [new Agent/Null]
$ns attach-agent $n0 $src
$ns attach-agent $n2 $dest
$ns connect $src $dest

set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 50B
$traffic set interval_ 2ms

set src1 [new Agent/TCP]
set dest1 [new Agent/TCPSink]
$ns attach-agent $n1 $src1
$ns attach-agent $n3 $dest1
$ns connect $src1 $dest1

set traffic1 [new Application/FTP]
$traffic1 attach-agent $src1
$traffic1 set packetSize_ 100B
$traffic1 set interval_ 2ms

$ns at 0.0 "$traffic start"
$ns at 0.0 "$traffic1 start"
$ns rtmodel-at 3.0 down $n1 $n2
$ns at 9.0 "$traffic stop"
$ns rtmodel-at 10.0 up $n1 $n2
$ns at 11.0 "$traffic1 stop"
$ns at 11.0 "finish"
$ns run
