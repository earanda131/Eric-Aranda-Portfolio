make clean
make
./maze maze_input.txt > maze_output.txt
if diff output.txt maze_output.txt >/dev/null ; then
	echo Success
else
	echo Fail
fi