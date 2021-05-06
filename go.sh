clear
make
# while true ; do
declare -a arg=(9 6 3 8 5 2 7 4 1 0 12 13 14 52 41 87 99 66 33);
if (( $# != 0 ));then
	unset arg
	arg=$@
fi
echo "${arg[@]}"
echo >res.data
./bin/push_swap ${arg[@]} >mvs.data 3>stk.data 6>dev.data
<mvs.data ./bin/checker ${arg[@]} >res.data
<mvs.data wc -l | xargs >>res.data
# cat mvs.data
# cat stk.data
cat res.data
cat dev.data
# done
