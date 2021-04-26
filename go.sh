clear;make;
./push_swap $@ >a
cat a;<a wc -l | xargs
<a ./checker $@
rm a
