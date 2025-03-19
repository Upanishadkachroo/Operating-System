#!/bin/bash
for i in {1..100}
do 
   sleep 1&
done
exec sleep 100

# Terminal -> bash -> make sleep process for 1 sec and then exited
#              | exec
#              V
#             sleep 100 -> running 


# 1.to check any exisiting zombie process
#   ps -elf | grep Z