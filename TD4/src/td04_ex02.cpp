#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <system_error>
#include <charconv>
#include <string>
#include <stack>


auto const is_space = [](char letter) { 
    
    return letter == ' '; 
    };


int count_letters(std::string & phrase) {
    std::string::iterator debut_tableau { phrase.begin() };
    std::string::iterator fin_tableau { phrase.end() };
    auto recherche_espace {std::find_if(debut_tableau, fin_tableau, is_space)};
    if (recherche_espace != fin_tableau) {
        return std::distance(debut_tableau, recherche_espace);
    } else if (recherche_espace == fin_tableau) {
        return -1;
    }

}

// La fonction que j'ai créé tout seul (comme un grand)
std::vector<std::string> split_string(std::string & str) {
    std::string::iterator fin_tableau { str.end() };
    std::string::iterator espace_precedent { str.begin() };
    std::string::iterator espace_suivant  {espace_precedent};
    std::vector<std::string> phrase {};
    while (espace_suivant != fin_tableau) {
        std::string mot{};
        espace_suivant = std::find_if(espace_precedent, fin_tableau, is_space);
        for (std::string::iterator taille_mot{espace_precedent}; taille_mot < espace_suivant; ++taille_mot) {
            mot.push_back(*taille_mot);
        }
        phrase.push_back(mot);
        if (espace_suivant != fin_tableau) {
            espace_precedent = espace_suivant+1;
        }
        
        
        
    }
    return phrase;
}



// La fonction plus efficace qu'Enguerrand m'a invité à essayer
std::vector<std::string> split_string2(std::string const& str) {
    auto end { str.end() };
    auto current { str.begin() };
    std::vector<std::string> words {};

    auto next_space { current };
    while(next_space != end) {
        next_space = std::find_if(current, end, is_space);
        std::string mot(current, next_space);
        words.push_back(mot);
        if(next_space != end) {
            current = next_space + 1;
        }
    }
    return words;
}



/*
for (std::vector<int>::iterator tableau { nombres.begin() }; tableau != fin_tableau; ++tableau) {
    std::cout << *tableau << std::endl;
    }
*/

int main() {
    
    std::string phrase {};
    std::cout << "Entrez une phrase" << std::endl;
    std::getline (std::cin,phrase);
    auto nombre {count_letters(phrase)};

    if (nombre == -1) {
        std::cout << "Votre phrase n'est constituee que d'un seul mot" << std::endl;
    } else { 
        std::cout << "Le premier mot de votre phrase est grand de " << nombre << " lettres" << std::endl;
    }
    
    
    
    
    std::vector<std::string> tableau_mots {split_string(phrase)}; 
    for (int i{0}; i < tableau_mots.size(); i++) {
        std::cout << tableau_mots[i] << std::endl;
    }
    
   

    return 0;
}