#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <system_error>
#include <charconv>
#include <string>
#include <stack>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}


bool is_floating(std::string const& s) {
    bool flottant{false};
    
    
    for (int i{0}; i < s.size(); i++) {
        if (std::isdigit(s[i]) || s[i] == '.') {
            if (s[i] == '.') {
                flottant = true;
            }
        } else {
            flottant = false;
            break;
        }
    }
    return flottant;
}

bool is_floating_verif(std::string const& s)
{
    float value;
    auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    return ec == std::errc() && p == s.data() + s.size();
}

std::string npi_evaluate(std::vector<std::string> const& tokens) {
    std::string reponse{};
    std::stack<float> stack{};
    for (int i{0}; i < tokens.size(); i++) {
        bool chiffre {is_floating(tokens[i])}; 
        if (chiffre == true) {
            float flottant {std::stof(tokens[i])};
            stack.push(flottant);
        } else {
            if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '*' || tokens[i] == '/') {
                float rightOperand { stack.top() };
                stack.pop();
                float leftOperand { stack.top() };
                stack.pop();
                float result{};
                if (tokens[i] == '+') {
                    result = leftOperand + rightOperand;
                }
                if (tokens[i] == '-') {
                    result = leftOperand - rightOperand;
                }
                if (tokens[i] == '*') {
                    result = leftOperand * rightOperand;
                }
                if (tokens[i] == '/') {
                    result = leftOperand / rightOperand;
                }
                stack.push(result);
            } else {
                reponse = "Probleme de caracteres speciaux. Votre operation NPI est incorrecte !";
                break;
            }

        }
    }
    if (stack.size() > 1) {
        reponse = "Probleme de stack. Votre operation NPI est incorrecte !"
    }
    else {
        float final_result{stack.top()};
        stack.pop();
        reponse = "Le resultat de votre operation NPI est "
    }
    
}

int main() {
    std::string NPI{};
    std::cout << "Entrez une formule NPI (avec des espaces entre chaque caractere)" << std::endl;
    std::getline (std::cin,NPI);
    std::vector<std::string> chaine {split_string(NPI)};
     for (int i{0}; i < chaine.size(); i++) {
         std::cout << chaine[i] << std::endl;
     }

    std::string resultat {npi_evaluate(chaine)};
    // bool flottant {is_floating(NPI)};
    // bool verif {is_floating_verif(NPI)};

    /*
    if (flottant == true) {
        std::cout << "Le nombre que vous avez entre est un flottant" << std::endl;
    } else {
        std::cout << "Le nombre que vous avez entre n'est pas un flottant" << std::endl;
    }

    if (verif == true) {
        std::cout << "Le nombre que vous avez entre est bien un flottant" << std::endl;
    } else {
        std::cout << "Le nombre que vous avez entre n'est surement pas un flottant" << std::endl;
    }
    */


    return 0;
}