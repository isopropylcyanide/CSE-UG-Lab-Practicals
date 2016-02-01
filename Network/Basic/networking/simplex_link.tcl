#setting the simulator 
set ns [new Simulator]  

#opening the trace file in write mode
set nt [open simplex_link.tr w]

#tracing activity in trace file
$ns trace-all $nt

#opening namfile
set nf [open simplex_link.nam w]

#tracing activity in namfile
$ns namtrace-all $nf


#creating nodes
set n0 [$ns node]
set n1 [$ns node]
$ns simplex-link $n0 $n1 2Mbps 1ms DropTail

#creating agents
set src [new Agent/UDP]
$ns attach-agent $n0 $src
set dest [new Agent/Null]
$ns attach-agent $n1 $dest
$ns connect $src $dest

#generating traffic
set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 500B
$traffic set interval_ 2ms


#creating proc 
proc finish { } {
global ns nf
$ns flush-trace
close $nf
exec nam abc.nam
exit 0
}


#creating event scheduler
$ns at 1.0 "$traffic start"
$ns at 4.0 "$traffic stop"
$ns at 4.5 "finish"
$ns run



