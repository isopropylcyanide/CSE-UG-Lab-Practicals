set ns [new Simulator]

set nt [open trace1.tr w]
$ns trace-all $nt

set nf [open namfile.nam w]
$ns namtrace-all $nf

proc finish { } {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam namfile.nam
	exit 0
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
$ns duplex-link $n0 $n1 1Mbps 1ms DropTail
$ns duplex-link $n0 $n2 1Mbps 1ms DropTail


#Connect node 0 to 1
set src [new Agent/UDP]		
set dest [new Agent/Null]
$ns attach-agent $n0 $src
$ns attach-agent $n1 $dest
$ns connect $src $dest

set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 500KB
$traffic set interval_ 1ms

#Connect node 1 to 0
set src2 [new Agent/UDP]		
set dest2 [new Agent/Null]
$ns attach-agent $n1 $src2
$ns attach-agent $n0 $dest2
$ns connect $src2 $dest2

set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetSize_ 100KB
$traffic2 set interval_ 1ms

#Connect node 2 to 0
set src3 [new Agent/UDP]		
set dest3 [new Agent/Null]
$ns attach-agent $n2 $src3
$ns attach-agent $n0 $dest3
$ns connect $src3 $dest3

set traffic3 [new Application/Traffic/CBR]
$traffic3 attach-agent $src3
$traffic3 set packetSize_ 1000
$traffic3 set interval_ 1ms

$ns at 2.0 "$traffic start"
$ns at 3.0 "$traffic2 start"
$ns at 4.0 "$traffic3 start"
$ns at 6.0 "$traffic2 stop"
$ns at 8.0 "$traffic3 stop"
$ns at 9.0 "$traffic stop"
$ns at 9.0 "finish"
$ns run
