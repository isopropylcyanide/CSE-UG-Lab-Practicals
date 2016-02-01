set ns [new Simulator]

set nt [open congestion_window.tr w]
$ns trace-all $nt

set nm [open congestion_window.nam w]
$ns namtrace-all $nm

set out [open congestion_window.xg w]

for { set i 0} { $i <6} {incr i} {
 set n$i [$ns node]
}

#Lan setup
set lan [$ns newLan "$n3 $n5 $n4" 0.5Mb 40ms LL MAC/Csma/Cd Channel]

$ns duplex-link $n0 $n2 3Mbps 15ms DropTail
$ns duplex-link $n1 $n2 1.5Mbps 15ms DropTail
$ns duplex-link $n2 $n3 2Mbps 20ms DropTail

$ns duplex-link-op $n2 $n1 orient left-up 
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n2 $n0 orient left-down


set src0 [new Agent/UDP]
set src1 [new Agent/TCP]
set dest5 [new Agent/Null]
set dest5tcp [new Agent/TCPSink]

#for attaching agents to the sources
$ns attach-agent $n0 $src0
$ns attach-agent $n1 $src1
$ns attach-agent $n5 $dest5
$ns attach-agent $n5 $dest5tcp 


$ns connect $src0 $dest5
$ns connect $src1 $dest5tcp

#for generating traffic
set trafficudp [new Application/Traffic/CBR]
set traffictcp [new Application/FTP]


$trafficudp attach-agent $src0
$traffictcp attach-agent $src1

$trafficudp set packetsize_ 1000B
$traffictcp set packetsize_ 1000B
$trafficudp set interval_ 10ms
$traffictcp set interval_ 10ms 

$src1 set window_ 15

proc plotwindow {src1 out} {
	global ns
	set now1 [$ns now]
	set cwnd1 [$src1 set cwnd_]
	puts $out "$now1 $cwnd1"
	$ns at [expr $now1+0.1] "plotwindow $src1 $out"
}


#creating proc 
proc finish { } {
global ns nm
$ns flush-trace
close $nm
exec nam congestion_window.nam
exit 0
}

#event scheduler

$ns at 0.0 "plotwindow $src1 $out"
$ns at 1.0 "$trafficudp start"
$ns at 1.0 "$traffictcp start"
$ns at 4.5 "$trafficudp stop"
$ns at 6.0 "$traffictcp stop"
$ns at 6.2 "finish"
$ns run
