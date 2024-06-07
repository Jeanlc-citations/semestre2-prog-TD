#include <iostream>
#include <vector>
#include "L node.hpp"



int main() {

    
    Node* root { new Node {1, nullptr, nullptr}};
    root->insert(2);
    root->insert(10);
    root->insert(5);
    root->insert(9);
    root->insert(4);
    root->insert(8);
    root->insert(3);
    root->insert(6);
    root->insert(1);
    root->insert(7);
    root->insert(0);

    int hauteur {root->height()};

    std::cout << hauteur << std::endl;

    

    root->delete_childs();
    hauteur = root->height();
    std::cout << hauteur << std::endl;
    

    return 0;
}