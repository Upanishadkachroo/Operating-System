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
}

int main(){
    Boundedbuffer<int> buffer;
}