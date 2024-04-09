#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <system_error>
#include <charconv>
#include <string>
#include <stack>


bool is_palindrome(std::string & str) {
    std::string::iterator iterateur { str.begin() };
    std::string::reverse_iterator iterateur_inverse { str.rbegin() };
    bool palindrome {std::equal(iterateur, str.end(), iterateur_inverse )};
    return palindrome;

}




int main() {
    
    std::string phrase {};
    std::cout << "Entrez une phrase" << std::endl;
    std::cin >> phrase;
    bool palindrome {is_palindrome(phrase)};
    
    if (palindrome == true ) {
        std::cout << "Votre phrase est un palindrome" << std::endl;
    } else {
        std::cout << "Votre phrase n'est pas un palindrome" << std::endl;
    }
    
   

    return 0;
}