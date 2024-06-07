#include <iostream>
#include "L node.hpp"
#include <vector>

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
   if (right != nullptr) {
            right->delete_childs();
            right = nullptr;
    } 
    if (left != nullptr) {
            left->delete_childs();
            left = nullptr;
    } 


    
}


void Node::display_infixe() const {
    if (left != nullptr) {
        left->display_infixe(); 
    }

    std::cout << value << std::endl;

    if (right != nullptr) {
        right->display_infixe();
    }
}

void Node::display_prefixe() const {
    
    std::cout << value << std::endl;
    
    if (left != nullptr) {
        left->display_prefixe(); 
    }

    if (right != nullptr) {
        right->display_prefixe();
    }
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> nodes{};

    nodes.push_back(this);
    
    if (left != nullptr) {
        auto left_nodes {left->prefixe()};
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end()); 
    }

    if (right != nullptr) {
        auto right_nodes {right->prefixe()};
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end()); 
    }
    return nodes;
}


void Node::display_postfixe() const {
    
    
    if (left != nullptr) {
        left->display_postfixe(); 
    }

    if (right != nullptr) {
        right->display_postfixe();
    }

    std::cout << value << std::endl;
}


std::vector<Node const*> Node::postfixe() const {
    std::vector<Node const*> nodes{};

    
    
    if (left != nullptr) {
        auto left_nodes {left->prefixe()};
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end()); 
    }

    if (right != nullptr) {
        auto right_nodes {right->prefixe()};
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end()); 
    }

    nodes.push_back(this);

    return nodes;
}

Node*& most_left(Node*& node) {
    if (node == nullptr || node->left == nullptr) {
        return node;
    } else {
        return most_left(node->left);
    }
}




bool remove(Node*& node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (node->value == value) {
        bool is_leaf{node->is_leaf()};
        if (is_leaf == true) {
            delete node;
            node = nullptr;
            return true;
        } else if (node->left != nullptr && node->right == nullptr) {
            Node* node_suppression = node;
            node = node->left;
            delete node_suppression;
            return true;
        } else if (node->left == nullptr && node->right != nullptr) {
            Node* node_suppression = node;
            node = node->right;
            delete node_suppression;
            return true;
        } else if (node->left != nullptr && node->right != nullptr) { 
            Node* successor = most_left(node->right);
            node->value = successor->value;
            return remove(node->right, successor->value);
        }
    } else if (node->value < value) {
        return remove(node->right, value);
    } else {
        return remove(node->left, value);
    }
}




void delete_tree(Node* node) {
    
    node->delete_childs();
    delete node;
    node = nullptr;   
}


int Node::min() const {
    if (left == nullptr) {
        return value;
    } else {
        left->min();
    }
};

int Node::max() const {
    if (right == nullptr) {
        return value;
    } else {
        right->max();
    }
}