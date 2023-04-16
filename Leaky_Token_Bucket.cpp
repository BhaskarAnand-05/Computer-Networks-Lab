#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class LeakyBucket {
public:
    LeakyBucket(int rate, int bucket_size) :
        rate_(rate),
        bucket_size_(bucket_size),
        last_time_(time(nullptr)),
        tokens_(bucket_size) {}

    bool Consume(int packet_size) {
        auto now = time(nullptr);
        int elapsed = now - last_time_;
        last_time_ = now;

        tokens_ += elapsed * rate_;
        if (tokens_ > bucket_size_) {
            tokens_ = bucket_size_;
        }

        if (packet_size > tokens_) {
            return false;
        }

        tokens_ -= packet_size;
        return true;
    }

private:
    int rate_;
    int bucket_size_;
    time_t last_time_;
    int tokens_;
};

class TokenBucket {
public:
    TokenBucket(int rate, int bucket_size) :
        rate_(rate),
        bucket_size_(bucket_size),
        last_time_(chrono::steady_clock::now()),
        tokens_(bucket_size) {}

    bool Consume(int packet_size) {
        auto now = chrono::steady_clock::now();
        int elapsed = chrono::duration_cast<chrono::milliseconds>(now - last_time_).count();
        last_time_ = now;

        tokens_ += elapsed * rate_;
        if (tokens_ > bucket_size_) {
            tokens_ = bucket_size_;
        }

        if (packet_size > tokens_) {
            return false;
        }

        tokens_ -= packet_size;
        return true;
    }

private:
    int rate_;
    int bucket_size_;
    chrono::steady_clock::time_point last_time_;
    int tokens_;
};

int main() {
    LeakyBucket leaky_bucket(10, 20);
    TokenBucket token_bucket(10, 20);

    for (int i = 0; i < 30; i++) {
        int packet_size = rand() % 10 + 1;
        cout << "Packet size: " << packet_size << endl;

        if (leaky_bucket.Consume(packet_size)) {
            cout << "Leaky Bucket: Packet transmitted." << endl;
        }
        else {
            cout << "Leaky Bucket: Packet dropped." << endl;
        }

        if (token_bucket.Consume(packet_size)) {
            cout << "Token Bucket: Packet transmitted." << endl;
        }
        else {
            cout << "Token Bucket: Packet dropped." << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}
