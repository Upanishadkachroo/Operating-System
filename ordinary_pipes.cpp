#include<iostream>
#include<unistd.h>//pipe() & fork()
#include<string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(){
    char write_msg[BUFFER_SIZE]="Hi Upanishad Kachroo";
    char read_msg[BUFFER_SIZE];

    int fd[2];//store file descriptors from pipe

    if(pipe(fd)==-1){//if pipe creation fails
        cerr<<"Pipe failed"<<endl;
        return 1;
    }

    pid_t pid=fork();
    if(pid<0){
        cerr<<"Fork Failed"<<endl;
        return 1;
    }

    if(pid>0){//parent process
        close(fd[READ_END]);//parent only writes

        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);//write in pipe

        close(fd[WRITE_END]);//close the write end of the pipe
    }
    else{//child process
        close(fd[WRITE_END]);//child read only

        read(fd[READ_END], read_msg, BUFFER_SIZE);

        cout<<"Read: "<<read_msg<<endl;

        close(fd[READ_END]);
    }
    return 0;
}


// Parent Process                        Child Process
// write message  ->>-->> PIPE ->>-->>  Read Message
// fd([0])                                  fd([1])