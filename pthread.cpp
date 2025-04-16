#include<iostream>
#include<pthread.h>
#include<cstdlib>

int sum=0;//shared data accesed by thread
void *runner(void *param);//thread function

int main(int argc, char *argv[]){
    if(argc!=2){
        cerr<<"Usage: "<<argv[0]<<"integer value"<<endl;
        return -1;
    }

    int n=atoi(argv[1]);
    if(n<=0){
        cerr<<Input must be positive<<endl;
        return -1;
    }

    pthread_t tid;//THread Identifier
    pthread_attr_t attr;

    pthread_attr_init(&attr);// Initialize thread attributes
    pthread_create(&tid, &attr, runner, &n);//creates a new thread to execute the runner
    pthread_join(tid, NULL);
    cout<<"Sum= "<<sum<<endl;
    return 0;
}

void *runner(void *param){
    int upper=*(int *)param;
    sum=0;

    for(int i=1; i<=upper; i++){
        sum+=i;
    }
    pthread_exit(0);
}
