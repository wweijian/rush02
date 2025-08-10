#!/bin/zsh

# \033[1A → moves the cursor up one line.
# \033[2K → clears the entire line.

echo "ctrl + c to exit script"
echo
while true; do
	read input
	if [ "$input" = "exit" ]; then
		break
	fi;
	echo -ne "\033[1A\033[2K"
	format=$(echo -n "$input" | rev | sed 's/.\{3\}/& /g' | rev)
	echo $format
	valgrind ./rush-02 $input 2>valgrind_trace.txt
	echo
done