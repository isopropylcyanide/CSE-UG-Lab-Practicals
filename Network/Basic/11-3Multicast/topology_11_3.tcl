#To implement a multicasting topology
#11-3-15

set ns [new Simulator]
$ns multicast

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

for { set i 1 } { $i <7} {incr i} {
	set n$i [$ns node]
}

#Give different color to source nodes
$n1 shape "square"
$n1 color Green
$n6 shape "square"
$n6 color Green

#Initialise duplex connections between all given links

$ns duplex-link $n1 $n2 2Mbps 5ms DropTail 
$ns duplex-link $n1 $n4 2Mbps 5ms DropTail
$ns duplex-link $n2 $n3 2Mbps 5ms DropTail
$ns duplex-link $n4 $n3 2Mbps 5ms DropTail
$ns duplex-link $n3 $n5 2Mbps 5ms DropTail
$ns duplex-link $n5 $n6 2Mbps 5ms DropTail

$ns duplex-link-op $n1 $n2 orient left-down
$ns duplex-link-op $n1 $n4 orient right-down
$ns duplex-link-op $n2 $n3 orient left-down
$ns duplex-link-op $n4 $n3 orient right-down
$ns duplex-link-op $n3 $n5 orient right
$ns duplex-link-op $n5 $n6 orient up

#Insert sources
set src1 [new Agent/UDP]
set src2 [new Agent/UDP]
$ns attach-agent $n1 $src1
$ns attach-agent $n6 $src2

#Set groups
set group1 [Node allocaddr]
set group2 [Node allocaddr]

#Set protocol
set mproto DM
set mrthandle [$ns mrtproto $mproto]
$ns color 30 Green
$ns color 31 Red

#Set destinations
set dest1 [new Agent/Null]
set dest2 [new Agent/Null]
$src1 set dst_addr_ $group1
$src2 set dst_addr_ $group2

#Initiate traffic from the two sources
set traffic1 [new Application/Traffic/CBR]
$traffic1 attach-agent $src1
$traffic1 set packetSize_ 150B
$traffic1 set interval_ 1ms

set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetSize_ 150B
$traffic2 set interval_ 1ms


#Simulate the topology

$ns at 1.0  "$traffic1 start"
$ns at 1.5  "$n2 join-group $dest1 $group1"
$ns at 5.0  "$n4 join-group $dest1 $group1"
$ns at 5.0  "$n3 join-group $dest1 $group1"
$ns at 7.0  "$traffic1 stop"
$ns at 8.0  "$traffic2 start"
$ns at 9.0  "$n5 join-group $dest2 $group2"
$ns at 15.0 "$traffic2 stop"
$ns at 16.0 "finish"
$ns run