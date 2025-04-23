#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    }
    else if (pid == 0) {
        sleep(7);
        execlp("/bin/ls", "ls", nullptr);
    }
    else {
        wait(nullptr);
        cout << "Child complete" << endl;
    }
    return 0;
}
