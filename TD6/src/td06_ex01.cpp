#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
};

Node* create_node(int value) {
    Node* root { new Node {value, nullptr, nullptr}};
    // if (value > 1) {
    //     for (int i{2}; i < value; i++) {
    //         if (i%2 == 0) {
    //             root->left = { new Node {i, nullptr, nullptr}};
    //         } else {
    //             root->right = { new Node {i, nullptr, nullptr}};
    //         }
    // }
    // }
    return root;
}

int main() {

    return 0;
}