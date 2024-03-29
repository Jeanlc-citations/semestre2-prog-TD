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
    bool flottant{true};
    
    
    for (int i{0}; i < s.size(); i++) {
        if (std::isdigit(s[i]) || s[i] == '.') {

        } else {
            flottant = false;
            break;
        }
    }
    return flottant;
}

float is_floating_verif(std::string const& s)
{
    float value;
    auto [p, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    return ec == std::errc() && p == s.data() + s.size();
}

void npi_evaluate(std::vector<std::string> const& tokens) {
    std::string reponse{};
    std::stack<float> stack{};
    bool erreur{false};
    for (int i{0}; i < tokens.size(); i++) {
        bool chiffre {is_floating(tokens[i])}; 
        if (chiffre == true) {
            float flottant {std::stof(tokens[i])};
            stack.push(flottant);
        } 
        else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/') {
                float rightOperand { stack.top() };
                stack.pop();
                float leftOperand { stack.top() };
                stack.pop();
                float result{};
                if (tokens[i][0] == '+') {
                    result = leftOperand + rightOperand;
                }
                if (tokens[i][0] == '-') {
                    result = leftOperand - rightOperand;
                }
                if (tokens[i][0] == '*') {
                    result = leftOperand * rightOperand;
                }
                if (tokens[i][0] == '/') {
                    result = leftOperand / rightOperand;
                }
                stack.push(result);
        } else {
            erreur = true;
            std::cout << "Probleme de caracteres speciaux "<< tokens[i] << ". Votre operation NPI est incorrecte !" << std::endl;
            break;
        }

        }
    
    if (stack.size() > 1) {
        erreur = true;
        std::cout << "Probleme de stack. Votre operation NPI est incorrecte !" << std::endl;
    }
    else if (stack.size() == 1 && erreur == false) {
        float final_result{stack.top()};
        stack.pop();
        std::cout << "Le resultat de votre operation NPI est " << final_result << std::endl;
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

    npi_evaluate(chaine);


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