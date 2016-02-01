set ns [new Simulator]
set nfile [open abc.tr w]
#to open file in write mode
$ns trace-all $nfile
set namfile [open namfi.nam w]
$ns namtrace-all $namfile
proc finish { } {
global ns nfile
$ns flush-trace
close $nfile
exec nam namfi.nam
exit 0
}
#object of simulator class created
#1.Create nodes
set n0 [$ns node]
#node created by object ns
set n1 [$ns node]
#node 2 created by object ns
#2.Connect them set parameters
$ns simplex-link $n0 $n1 1ms 2Mbps DropTail
#3.Create Agents
set agent1 [new Agent/UDP]
$ns attach-agent $n0 $agent1
#attaching agent to node n0
#now n0 acts as a source
set dest [new Agent/Null]
#Null because Simplex link , no agent needed because no need to go back to sender from reciever
$ns attach-agent $n1 $dest
$ns connect $agent1 $dest
#4.Traffic
set traffic [new Application/Traffic/CBR]
#CBR=constant bit rate it comes under UDP CBR is a class name
$traffic attach-agent $agent1
$traffic set packetSize_ 50B
$traffic set interval_ 2ms
$ns at 2.0 "$traffic start"
$ns at 3.0 "$traffic stop"
$ns at 5.0 "finish"
$ns run
#$ns namtrace-all $nfile #to trace the file
