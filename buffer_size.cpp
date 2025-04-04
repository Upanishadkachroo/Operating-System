#include <iostream>
#include <array>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

constexpr int BUFFER_SIZE = 5; // Fixed-size circular buffer

template <typename T>
class BoundedBuffer {
private:
    array<T, BUFFER_SIZE> buffer; // Fixed-size array
    int in = 0;  // Next producer insert position
    int out = 0;  // Next consumer remove position
    int count = 0; // Current number of items

    mutex mtx; // Protects buffer access
    condition_variable not_full;  // Signal when buffer is not full
    condition_variable not_empty; // Signal when buffer is not empty

public:
    void produce(const T& item) {
        unique_lock<mutex> lock(mtx);
        
        // Wait until buffer is not full
        not_full.wait(lock, [this]() { return count < BUFFER_SIZE; });

        // Insert item
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE; // Circular increment
        ++count;

        cout << "Produced: " << item << " (Buffer size: " << count << ")\n";
        
        // Notify consumer that buffer is not empty
        not_empty.notify_one();
    }

    T consume() {
        unique_lock<mutex> lock(mtx);
        
        // Wait until buffer is not empty
        not_empty.wait(lock, [this]() { return count > 0; });

        // Extract item
        T item = buffer[out];
        out = (out + 1) % BUFFER_SIZE; // Circular increment
        --count;

        cout << "Consumed: " << item << " (Buffer size: " << count << ")\n";
        
        // Notify producer that buffer is not full
        not_full.notify_one();
        
        return item;
    }
};

// Example usage
int main() {
    BoundedBuffer<int> buffer;

    // Producer thread (produces numbers 1-10)
    thread producer([&buffer]() {
        for (int i = 1; i <= 10; ++i) {
            buffer.produce(i);
            this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
        }
    });

    // Consumer thread (consumes numbers)
    thread consumer([&buffer]() {
        for (int i = 0; i < 10; ++i) {
            buffer.consume();
            this_thread::sleep_for(chrono::milliseconds(500)); // Simulate work
        }
    });

    producer.join();
    consumer.join();

    return 0;
}