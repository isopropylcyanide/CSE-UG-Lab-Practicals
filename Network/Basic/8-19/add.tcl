set a 20
set b 30
set c [expr $a + $b]
puts "Addition is "
puts [set c]

proc add {a b} {
	puts "In method"
	puts $a
	puts [set b]
}

add $a $b
