#!/bin/bash
sleep 200 &
#sleep 200


# Terminal -> orphan.sh -> sleep 200

# 1. orphan does not wait() for the sleep 200
# 2. therefore orphan.sh exit() and sleep 200 becomes orphan
# 3. sleep 200 gets attached to the init process