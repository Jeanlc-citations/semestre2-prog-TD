#include <iostream>
#include "L node.hpp"

Node* create_node(int value) {
    Node* root { new Node {value, nullptr, nullptr}};
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


int Node::height() const {
    int height{0};
    if (right == nullptr && left == nullptr) {
        height = 1;
        return height;
    } 
    else {
        int right_height{};
        int left_height{};
        if (right == nullptr) {
            right_height = 0;
        } else {
            right_height = right->height();
        }
        if (left == nullptr) {
            left_height = 0;
        } else {
            left_height = left->height(); 
        }
        if (right_height > left_height) {
            return right_height+1;
        }
            else {
                return left_height+1;
            }
        
    }
    
}

void Node::delete_childs() {
    /*
    if (right == nullptr && left == nullptr) {
        delete this;
    } 
    else {
        if (right != nullptr) {
            right->delete_childs();
        } 
        if (left != nullptr) {
            left->delete_childs();
        } 

    }
    */
   if (right != nullptr) {
            right->delete_childs();
            right = nullptr;
    } 
    if (left != nullptr) {
            left->delete_childs();
            left = nullptr;
    } 


    
}


void Node::delete_tree() {
    
    if (right == nullptr && left == nullptr) {
        delete this;
    } 
    else {
        if (right != nullptr) {
            right->delete_childs();
        } 
        if (left != nullptr) {
            left->delete_childs();
        } 

    }   
}