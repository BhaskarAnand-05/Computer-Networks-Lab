#include <iostream>
#include <cmath>

using namespace std;

// function to check if a number is prime
bool isPrime(int n) {
    // 1 is not a prime number
    if (n == 1) {
        return false;
    }

    // check if n is divisible by any integer between 2 and sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

// function to generate the public and private keys for RSA encryption
void generateKeys(int p, int q, int& n, int& e, int& d) {
    // calculate n (the product of p and q)
    n = p * q;

    // calculate the totient of n ((p-1)*(q-1))
    int totient = (p - 1) * (q - 1);

    // choose an integer e such that 1 < e < totient and gcd(e, totient) = 1
    for (e = 2; e < totient; e++) {
        if (gcd(e, totient) == 1) {
            break;
        }
    }

    // calculate the integer d such that d*e mod totient = 1
    int k = 1;
    while ((k * totient + 1) % e != 0) {
        k++;
    }
    d = (k * totient + 1) / e;
}

// function to encrypt a message using RSA
int encrypt(int message, int n, int e) {
    // the ciphertext is the message raised to the power of e modulo n
    return int(pow(message, e)) % n;
}

// function to decrypt a message using RSA
int decrypt(int ciphertext, int n, int d) {
    // the message is the ciphertext raised to the power of d modulo n
    return int(pow(ciphertext, d)) % n;
}

int main() {
    // choose two prime numbers p and q
    int p = 17;
    int q = 19;

    // generate the public and private keys
    int n, e, d;
    generateKeys(p, q, n, e, d);

    // print the keys
    cout << "Public key: (" << n << ", " << e << ")" << endl;
    cout << "Private key: (" << n << ", " << d << ")" << endl;

    // encrypt a message using the public key
    int message = 123;
    int ciphertext = encrypt(message, n, e);

    // print the encrypted message
    cout << "Encrypted message: " << ciphertext << endl;

    // decrypt the message using the private key
    int decrypted_message = decrypt(ciphertext, n, d);

    // print the decrypted message
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}
