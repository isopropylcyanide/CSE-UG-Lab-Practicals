#create object
set ns [new Simulator]
set nt [open demo1.tr w]
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


#set nodes	
set n0 [$ns node]
		set n1 [$ns node]
		$ns simplex-link $n0 $n1 2Mbps 1ms  DropTail


#set agents
  set src [new Agent/UDP]
	$ns attach-agent $n0 $src
set dest [new Agent/Null]
$ns attach-agent $n1 $dest
	$ns connect $src $dest
		set traffic [new Application/Traffic/CBR]

$traffic attach-agent $src
$traffic set packetSize_ 50B
$traffic set interval_ 2ms



$ns at 1.0 "$traffic start"
$ns at 4.0 "$traffic stop"
 $ns at 4.5 "finish"
$ns run

