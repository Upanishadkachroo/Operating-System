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
# 2. The background sleep 1& processes complete quickly, but the parent script doesn't collect their exit statuses, causing them to become zombie processes.
# 3. Solution: To avoid zombies, add wait in the parent process to ensure it collects the status of child processes before it terminates