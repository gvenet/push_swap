make
arg=10
if (($# != 0)); then
	unset arg
	arg=$1
fi
python3 pyviz.py `ruby -e "puts (1..$arg).to_a.shuffle.join(' ')"`
