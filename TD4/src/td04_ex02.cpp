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


auto count_letters(std::string & phrase) {
    std::string::iterator debut_tableau { phrase.begin() };
    std::string::iterator fin_tableau { phrase.end() };
    auto recherche_espace {std::find_if(debut_tableau, fin_tableau, is_space)};
    if (recherche_espace != fin_tableau) {
        return std::distance(debut_tableau, recherche_espace);
    }

}

std::vector<std::string> split_string(std::string & str) {
    std::string::iterator debut_tableau { str.begin() };
    std::string::iterator fin_tableau { str.end() };
    std::vector<std::string> phrase {};
    auto espace = count_letters(str);
    while (espace < *fin_tableau) {
        std::string mot{};
        std::string nouvelle_phrase {};
        for (int i{0}; i < espace-1; i++) {
            mot.push_back(str[i]);
        }
        phrase.push_back(mot);
        for (auto j{espace+1}; j < *fin_tableau; j++) {
            mot.push_back(str[j]);
        }
        espace = count_letters(nouvelle_phrase);
    }
    return phrase;
}


int main() {
    
    std::string Jean {"Bonjour Jean Le Chaudelec"};
    std::vector<std::string> tableau_mots {split_string(Jean)}; 
    for (int i{0}; i < tableau_mots.size(); i++) {
        std::cout << tableau_mots[i] << std::endl;
    }

    return 0;
}