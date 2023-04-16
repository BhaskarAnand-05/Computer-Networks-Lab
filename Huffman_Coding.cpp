#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }

    bool is_leaf() const {
        return left == nullptr && right == nullptr;
    }
};

struct Compare {
    bool operator()(const Node* a, const Node* b) const {
        return a->freq > b->freq;
    }
};

class Huffman {
public:
    void encode(string text) {
        unordered_map<char, int> freq_map;
        for (char c : text) {
            freq_map[c]++;
        }

        priority_queue<Node*, vector<Node*>, Compare> min_heap;
        for (auto pair : freq_map) {
            min_heap.push(new Node(pair.first, pair.second));
        }

        while (min_heap.size() > 1) {
            Node* left = min_heap.top();
            min_heap.pop();

            Node* right = min_heap.top();
            min_heap.pop();

            Node* parent = new Node('$', left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            min_heap.push(parent);
        }

        root = min_heap.top();

        unordered_map<char, string> huffman_map;
        encode_helper(root, "", huffman_map);

        cout << "Huffman codes are:\n";
        for (auto pair : huffman_map) {
            cout << pair.first << " " << pair.second << endl;
        }

        cout << "Encoded text is:\n";
        string encoded_text = "";
        for (char c : text) {
            encoded_text += huffman_map[c];
        }
        cout << encoded_text << endl;
    }

    void decode(string encoded_text) {
        string decoded_text = "";
        Node* curr = root;
        for (char c : encoded_text) {
            if (c == '0') {
                curr = curr->left;
            } else {
                curr = curr->right;
            }

            if (curr->is_leaf()) {
                decoded_text += curr->data;
                curr = root;
            }
        }
        cout << "Decoded text is:\n" << decoded_text << endl;
    }

private:
    Node* root;

    void encode_helper(Node* curr, string code, unordered_map<char, string>& huffman_map) {
        if (curr->is_leaf()) {
            huffman_map[curr->data] = code;
        } else {
            encode_helper(curr->left, code + "0", huffman_map);
            encode_helper(curr->right, code + "1", huffman_map);
        }
    }
};

int main() {
    Huffman huffman;

    string text = "hello world";
    huffman.encode(text);

    string encoded_text = "1010100111000110111110001100100110100";
    huffman.decode(encoded_text);

    return 0;
}
