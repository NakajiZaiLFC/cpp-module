PROJECT_PATH="../../ex01/"
COMMAND_TXT_PATH="$(pwd)/command.txt"
cd "$PROJECT_PATH"

echo -e "Current commit hash: $(git log --oneline -n 1 | awk '{print $1}')\n"

echo -e "\n-----\nCompiling ...\n"
make re
echo -e "\nFinish  ...\n-----\n\n"

func_test(){
	printf "No: [%02d]\n" $1
	./phonebook < $COMMAND_TXT_PATH
}

func_test 1