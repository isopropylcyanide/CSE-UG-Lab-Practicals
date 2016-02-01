#/!bin/bash

function solve(){

	actual_value=63
	steps=0
	user_guess=0
	lo=1
	high=100

	echo 'Guess a number between 0 to 100'
	min_small=0
	min_large=100

	while [ $user_guess -ne $actual_value ]
		do
			steps=`expr $steps + 1 `
			read user_guess

			if [ $user_guess -eq $actual_value ]; then
				# echo 'Bazinga!. You have guessed it in : ' $steps steps
				:
			
			elif [ $user_guess -gt $actual_value ]; then
				hi=$user_guess
				
				if [ $hi -lt $min_large ]; then
					min_large=$hi
				fi
				# echo 'Your guess is larger. Search in ' $min_small to $min_large

			elif [ $user_guess -lt $actual_value ]; then
				lo=$user_guess

				if [ $lo -gt $min_small ]; then
					min_small=$lo
				fi

				# echo 'Your guess is smaller. Search in ' $min_small to $min_large

			fi

			echo $min_small $min_large $steps
		done
}


solve