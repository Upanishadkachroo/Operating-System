#!/bin/bash  #ensures that the script runs in the right environment (Bash shell) even if the user runs it from a different shell like zsh or fish.
while[true]
do
  echo "hello everyone!"
  sleep 1
done

# after running this a process is created
# This script is a simple example of an infinite loop in Bash that continuously prints a message every second. 

# Linux commands
# 1. to check it
#   ps -a
# 2. displays the output in a "long" format, providing more detailed information than the default.
#   ps -al

# 3.To kill it abruptly (user mode -> kernel mode and then killed)
#   kill -9 <PID>

# 4. more info
#   man kill
 