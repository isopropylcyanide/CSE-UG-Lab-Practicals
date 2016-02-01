#To implement a simple network topology
#8-19-15

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

#Initialise all nodes

for { set i 0 } { $i <5} {incr i} {
	set n$i [$ns node]
}

$n0 shape "square"
$n0 color Blue
$n1 shape "square"
$n1 color Green
$n2 color Red
$n3 shape "square"
$n3 color Black

#Initialise a simplex connection queue between no and n3 which will use n2

$ns simplex-link $n0 $n2 2.5Mbps 3.5ms DropTail    
$ns simplex-link-op $n0 $n2 queuePos 0.5
$ns simplex-link-op $n0 $n2 color Blue
$ns simplex-link-op $n0 $n2 orient right-down
$ns queue-limit $n0 $n2  5

set src1 [new Agent/UDP]		
set dest [new Agent/Null]
$ns attach-agent $n0 $src1
$ns attach-agent $n3 $dest
$ns connect $src1 $dest

set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic1 set packetSize_ 50B
$traffic1 set interval_ 1ms

#Initialise a simplex connection queue between n1 and n3 which will use n2

$ns simplex-link $n1 $n2 1.5Mbps 4.5ms DropTail    
$ns simplex-link-op $n1 $n2 queuePos 0.5
$ns simplex-link-op $n1 $n2 color Green
$ns simplex-link-op $n1 $n2 orient right-up
$ns queue-limit $n1 $n2 7

set src2 [new Agent/UDP]		
$ns attach-agent $n1 $src2
$ns connect $src2 $dest

set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetSize_ 100B
$traffic2 set interval_ 1ms

#Initialise a simplex connection queue between n2 and n3 with no traffic

$ns simplex-link $n2 $n3 1.5Mbps 4.5ms DropTail    
$ns simplex-link-op $n2 $n3 queuePos 0.5
$ns simplex-link-op $n2 $n3 color Black
$ns simplex-link-op $n2 $n3 orient right
$ns queue-limit $n2 $n3 5

#Simulate the topology

$ns at 1.0 "$traffic1 start"
$ns at 1.5 "$traffic2 start"
$ns at 5.0 "$traffic1 stop"
$ns at 5.0 "$traffic2 stop"
$ns at 7.0 "$traffic1 start"
$ns at 8.0 "$traffic2 start"
$ns at 14.5 "$traffic1 stop"
$ns at 15.0 "$traffic2 stop"
$ns at 16.0 "finish"
$ns run