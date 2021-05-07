#!/bin/bash
clear
make
# while true ; do
# 3 7 5 10
arg=(22 6 4 99 5 11 2 1 3 77 8 7 9 0 50 60 -80 -90);
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
