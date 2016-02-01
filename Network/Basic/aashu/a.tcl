set ns [new Simuxlator]

#create trace files
set nt [open trace1.tr w]
$ns trace-all $nt
set nf [open namfile.nam w]
$ns namtrace-all $nf


#create finish procedure
proc finish {} {
		global ns nf 
		$ns flush-trace
		close $nf
		
		exec nam namfile.nam
exit 0
}

#create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]


#create links
$ns simplex-link $n0 $n2 2.5Mbps 4ms DropTail 
$ns duplex-link $n1 $n2 1.5Mbps 3ms DropTail 
$ns duplex-link $n2 $n3 .5Mbps 3.5ms DropTail
$ns duplex-link $n3 $n5 .5Mbps 3.5ms DropTail
$ns duplex-link $n4 $n3 .5Mbps 3.5ms DropTail

$ns simplex-link-op $n0 $n2 color red
$ns duplex-link-op $n1 $n2 color blue
$ns duplex-link-op $n2 $n3 color green
$ns duplex-link-op $n3 $n5 color red
$ns duplex-link-op $n4 $n3 color red
#create agents

set src1 [new Agent/UDP]

$ns attach-agent $n0 $src1
set dest1 [new Agent/Null]
$ns attach-agent $n5 $dest1
$ns connect $src1 $dest1

set src2 [new Agent/TCP]

$ns attach-agent $n1 $src2
set dest2 [new Agent/TCPSink]
$ns attach-agent $n5 $dest2
$ns connect $src2 $dest2

set src3 [new Agent/TCP]

$ns attach-agent $n4 $src3
set dest3 [new Agent/TCPSink]
$ns attach-agent $n5 $dest3
$ns connect $src3 $dest3


#create traffic
set traffic [ new Application/Traffic/CBR]
$traffic attach-agent $src1
$traffic set packetSize_ 180B
$traffic set interval_ 2ms

set traffic2 [ new Application/FTP]
$traffic2 attach-agent $src2
$traffic2 set packetSize_ 180B
$traffic2 set interval_ 2ms

set traffic3 [ new Application/FTP]
$traffic3 attach-agent $src3
$traffic3 set packetSize_ 180B
$traffic3 set interval_ 2ms


$ns at 1.0 "$traffic start"
$ns at 1.5 "$traffic2 start"
$ns at 2.0 "$traffic3 start"
$ns at 4.0 "$traffic stop"
$ns at 4.5 "$traffic2 stop"
$ns at 4.9 "$traffic3 stop"
$ns at 5.0 "finish"
$ns run

























