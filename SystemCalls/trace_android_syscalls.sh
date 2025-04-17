#!/bin/bash

# trace_android_syscalls.sh
# Author: [Your Name]
# Description: Trace Android syscalls using Termux and show them on your Linux terminal via ADB.

# Set variables
LOGFILE="/sdcard/Download/trace.log"
DEFAULT_COMMAND="ls -la"
CAMERA_CMD="am start -n com.android.camera/com.android.camera.Camera"
GALLERY_CMD="am start -n com.android.gallery3d/com.android.gallery3d.app.Gallery"

echo "Android System Call Tracer"
echo "=============================="
echo "Default command to trace: $DEFAULT_COMMAND"
echo

# Step 1: Ask for custom command or use default
read -p "Enter the command you want to trace on your Android device (press Enter to use default, type 'camera' for Camera or 'gallery' for Gallery): " CMD
CMD=${CMD:-$DEFAULT_COMMAND}

# Run strace on Android (Termux)
if [ "$CMD" == "camera" ]; then
  CMD=$CAMERA_CMD
  echo "[1] Running Camera app via strace on your Android phone"
  adb shell "strace -o $LOGFILE $CMD"
elif [ "$CMD" == "gallery" ]; then
  CMD=$GALLERY_CMD
  echo "[1] Running Gallery app via strace on your Android phone"
  adb shell "strace -o $LOGFILE $CMD"
else
  echo "[1] Running command via strace on your Android phone: '$CMD'"
  adb shell "strace -o $LOGFILE $CMD"
fi

# Step 2: Fetch and show syscall output on Linux laptop
echo
echo "[2] Fetching syscall trace from Android and displaying it:"
echo "--------------------------------------------------------------"
adb shell cat $LOGFILE
echo "--------------------------------------------------------------"
echo "Done! You just traced syscalls from your Android phone."



#chmod +x trace_android_syscalls.sh - to make it to executable file