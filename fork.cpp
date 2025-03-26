// Imagine you're cooking (parent process). You ask your sibling (child process) to go check what's in the fridge (ls command). You wait until they tell you what's there before you continue cooking. When they're done, you say "Okay, you're done checking".
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
    pid_t pid=fork(); // to store process IDs.

    if(pid<0){
        cerr<<"Fork failed"<<endl;//Standard error stream
        return 1;
    }

    else if(pid==0){ //The code is running in the child process.
        execlp("/bin/ls", "ls", nullptr);//to transform into ls.
    }
    else{ //The code is running in the parent process, and the return value is the child’s process ID
        wait(nullptr);
        cout<<"Child complete"<<endl;
    }
    return 0;
}
