from threading import *
import time

lock=Lock()
count=0

def task():
    lock.acquire()
    global count
    for i in range(1000000):
        count+=1
    lock.release()

if __name__ == '__main__':
    t1=Thread(target=task)
    t2=Thread(target=task)

    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(count)


# The Lock() ensures only one thread modifies count at a time, preventing race conditions.

# Both threads execute task(), incrementing count 1,000,000 times each, while acquiring and releasing the lock.

# The final print(count) should output 2000000, ensuring thread safety due to the lock.