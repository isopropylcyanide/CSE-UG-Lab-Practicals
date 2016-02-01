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

#node creation
for {set i 0} {$i<4} {incr i} {
	set n$i [$ns node]
}

$n0 color Blue

$n1 color Green



#link b/w n0 and n2
$ns simplex-link $n0 $n2 2.5Mbps 4ms DropTail
$ns simplex-link-op $n0 $n2 color red
$ns queue-limit $n0 $n2 6

#link b/w n1 and n2
$ns simplex-link $n1 $n2 1.5Mbps 3ms DropTail
$ns simplex-link-op $n1 $n2 color red
$ns queue-limit $n1 $n2 5

#link b/w n2 and n3
$ns simplex-link $n2 $n3 0.5Mbps 3.5ms DropTail
$ns simplex-link-op $n2 $n3 color cyan
$ns queue-limit $n2 $n3 4

set src [new Agent/UDP]
set dest [new Agent/Null]
$src set fid_ 1
$ns attach-agent $n0 $src
$ns attach-agent $n3 $dest
$ns connect $src $dest

#traffic b/w n0 and n3
set traffic [new Application/Traffic/CBR]
$traffic attach-agent $src
$traffic set packetSize_ 50B
$traffic set interval_ 1.5ms

set src2 [new Agent/UDP]
$src2 set fid_ 2
$ns attach-agent $n1 $src2
$ns attach-agent $n3 $dest
$ns connect $src2 $dest

#traffic b/w n1 and n3
set traffic2 [new Application/Traffic/CBR]
$traffic2 attach-agent $src2
$traffic2 set packetSize_ 100B
$traffic2 set interval_ 2ms

$ns color 1 Green
$ns color 2 Orange

$ns at 1.0 "$traffic start"
$ns at 1.5 "$traffic2 start"
$ns at 4.5 "$traffic stop"
$ns at 4.5 "$traffic2 stop"
$ns at 5.0 "finish"
$ns run


