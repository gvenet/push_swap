make
while TRUE; do
	python3 run_multiple.py $1;
	i=0
	while ((i<10));do
		ARG=$(<"results/$i"_in)
		#  echo
		#  echo $ARG
		./bin/push_swap $ARG >a
		# cat a
		# echo
		cat a | ./bin/checker $ARG
		cat -b a | wc -l | xargs
 		((i+=1))
		rm a
	done
	sleep 1
	clear
done
