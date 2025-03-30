#include<iostream>
#include<array>
#include<thread>
using namspace std;
constexpr int BUFFER_SIZE=5;

template <typename T>
class Boundedbuffer{
    private:
    array<T, BUFFER_SIZE> buffer;
    int in=0;
    int out=0;
    int cnt=0;

    mutex mt;
    condition_variable not_full;
    condition_variable not_empty;

    public:
    void produce(const T& item){
        unique_lock<mutex> lock(mtx);
    }
}

int main(){
    Boundedbuffer<int> buffer;

    thread producer([&buffer](){
        for(int i=1; i<=10; i++){
            buffer.produce(i);
            this.thread::sleep_for(chrono::milliseconds(200))l
        }
    });

    thread consumer([&buffer](){
        for(int i=0; i<10; i++){
            buffer.consume();
            this.thread::sleep_for(chrono::milliseconds(500));
        }
    });

    producer.join();
    consumer.join();
    return 0;
}