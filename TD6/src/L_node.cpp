#include <iostream>
#include "L node.hpp"

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

bool Node::is_leaf() const {
    bool is_leaf{};
    if (left == nullptr && right == nullptr) {
        is_leaf = true;
    } else {
        is_leaf = false;
    }
    return is_leaf;
}

void Node::insert(int value2) {
    if (value2 < value) {
        if (left == nullptr) {
            left = create_node(value2);
        } else {
            left->insert(value2);
        }
    } else {
        if (right == nullptr) {
            right = create_node(value2);
        } else {
            right->insert(value2);
        }
    }
}

/*
int Node::height() const {
    
}
*/