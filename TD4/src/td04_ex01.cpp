#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>      

int main() {
    int nombre{};
    std::vector<int> nombres{};
    std::srand(100); 

    for (int i{0}; i<20; i++) {
        nombres.push_back(rand() % 100);
    }    

    std::vector<int>::iterator debut_tableau { nombres.begin() };
    std::vector<int>::iterator fin_tableau { nombres.end() };

    std::sort(debut_tableau, fin_tableau);
    
    std::cout << "Quand on additionne toutes les valeurs du tableau, on obtient " << std::accumulate(debut_tableau, fin_tableau, 0);


    for (std::vector<int>::iterator tableau { nombres.begin() }; tableau != fin_tableau; ++tableau) {
    std::cout << *tableau << std::endl;
    }

    int valeur1{};
    std::cout << "Entrez la valeur que vous cherchez :" << std::endl;
    std::cin >> valeur1;

    auto recherche { std::find(debut_tableau, fin_tableau, valeur1)};

    if (recherche != fin_tableau)
    {
        std::cout << "Le nombre " << *recherche << " que vous cherchez est dans le tableau !" << std::endl;
    }
    else
    {
        std::cout << "Le nombre que vous cherchez n'est pas dans le tableau" << std::endl;
    }
    
    int valeur2{};
    std::cout << "Entrez la valeur pour laquelle vous voulez voir le nombre d'iterations :" << std::endl;
    std::cin >> valeur2;
    auto nb_iterations {std::count (debut_tableau, fin_tableau, valeur2)};
    std::cout << valeur2 << " apparait " << nb_iterations << " fois dans le tableau" << std::endl;

    


    return 0;
}