clear
make
# while true ; do
# 3 7 5 10
declare -a arg=( 3 7 5 10 80 50);
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
