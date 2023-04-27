#include <iostream>
#include <string>

using namespace std;

// function to encrypt the message using the Caesar Cipher
string encrypt(string message, int shift) {
    string result = "";

    // iterate through each character in the message
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];

        // check if the character is an uppercase letter
        if (isupper(c)) {
            // shift the character by the specified amount
            c = (c + shift - 'A') % 26 + 'A';
        }
        // check if the character is a lowercase letter
        else if (islower(c)) {
            // shift the character by the specified amount
            c = (c + shift - 'a') % 26 + 'a';
        }

        // add the encrypted character to the result string
        result += c;
    }

    return result;
}

// function to decrypt the message using the Caesar Cipher
string decrypt(string message, int shift) {
    // to decrypt the message, simply shift the characters in the opposite direction
    // (i.e., by the opposite amount)
    return encrypt(message, 26 - shift);
}

int main() {
    string message = "Bhaskar Anand";
    int shift = 3;

    // encrypt the message
    string encrypted_message = encrypt(message, shift);

    // print the encrypted message
    cout << "Encrypted message: " << encrypted_message << endl;

    // decrypt the message
    string decrypted_message = decrypt(encrypted_message, shift);

    // print the decrypted message
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}
