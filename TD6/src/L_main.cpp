#include <iostream>
#include <vector>
#include "L node.hpp"



int main() {

    
    Node* root { new Node {1, nullptr, nullptr}};
    root->insert(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    
    root->display_infixe();

    int min {root->min()};
    std::cout << min << std::endl;


    int max {root->max()};
    std::cout << max << std::endl;

    std::vector<Node const*> nodes {root->prefixe()};

    int somme_values{0};
    for (int i{0}; i < nodes.size(); i++) {
        somme_values += nodes[i]->value;
    }
    std::cout << somme_values << std::endl;

    
    int hauteur {root->height()};
    std::cout << hauteur << std::endl;

    return 0;
}