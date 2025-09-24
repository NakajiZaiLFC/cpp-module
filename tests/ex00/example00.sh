#!/bin/bash

PROJECT_PATH="../../ex00/"

cd "$PROJECT_PATH"

make

func_test() {
  printf "No: [%02d]\n" $1
  shift
  if [[ -n $1 ]]; then
    echo "Param: $@"
    ./megaphone $@
  else
    ./megaphone
  fi
}

func_test 1 "abcd"
func_test 2 "ABCD"
func_test 3 "aBcD"
func_test 4 "1234"
func_test 5 "hoge"
func_test 6 "?K(TBA21360x$(echo -e "\r")"

func_test 7
func_test 8 a b c d ASDF LKJ ghghghhg
