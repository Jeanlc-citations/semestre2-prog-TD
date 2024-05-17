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

enum class Operator { ADD, SUB, MUL, DIV, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value) {
     
     return Token {TokenType::OPERAND, value};
}    

Token make_token(Operator op) {
    Token result{TokenType::OPERATOR};
    result.op = op;
    return result;
}


bool is_floating(std::string const& s) {
    bool flottant{};
    for (int i{0}; i < s.size(); i++) {
        if (std::isdigit(s[i]) || s[i] == '.') {
            flottant = true; 
        } else {
            flottant = false;
            break;
        }
    }
    return flottant;
}




std::vector<Token> tokenize(std::vector<std::string> const& s) {
    std::vector<Token> tableau{};
    for (int i{0}; i < s.size(); i++) {
        if (std::isdigit(s[i][0])) {

            bool chiffre {is_floating(s[i])}; 
        if (chiffre == true) {
            float nombre{std::stof(s[i])};
            Token operande {make_token(nombre)};
            tableau.push_back(operande);
        }
        } 
        else if (s[i][0] == '+' || s[i][0] == '-' || s[i][0] == '*' || s[i][0] == '/') {
                if (s[i][0] == '+') {
                    Operator op{Operator::ADD};
                    Token operateur{make_token(op)};
                    tableau.push_back(operateur);
                }
                else if (s[i][0] == '-') {
                    Operator op{Operator::SUB};
                    Token operateur{make_token(op)};
                    tableau.push_back(operateur);
                }
                else if (s[i][0] == '*') {
                    Operator op{Operator::MUL};
                    Token operateur{make_token(op)};
                    tableau.push_back(operateur);
                }
                else if (s[i][0] == '/') {
                    Operator op{Operator::DIV};
                    Token operateur{make_token(op)};
                    tableau.push_back(operateur);
                }
                
        } 
    }
    return tableau;

    
}

void npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> stack{};
    for (int i{0}; i < tokens.size(); i++) { 
        if (tokens[i].type == TokenType::OPERAND) {
            float flottant {tokens[i].value};
            stack.push(flottant);
        } 
        else if (tokens[i].type == TokenType::OPERATOR) {
                float rightOperand { stack.top() };
                stack.pop();
                float leftOperand { stack.top() };
                stack.pop();
                float result{};
                if (tokens[i].op == Operator::ADD) {
                    result = leftOperand + rightOperand;
                }
                if (tokens[i].op == Operator::SUB) {
                    result = leftOperand - rightOperand;
                }
                if (tokens[i].op == Operator::MUL) {
                    result = leftOperand * rightOperand;
                }
                if (tokens[i].op == Operator::DIV) {
                    result = leftOperand / rightOperand;
                }
                stack.push(result);
        } 

        }
    
    if (stack.size() > 1) {
        std::cout << "Probleme de stack. Votre operation NPI est incorrecte !" << std::endl;
    }
    else if (stack.size() == 1) {
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

    std::vector<Token> tokens {tokenize(chaine)};
    npi_evaluate(tokens);


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