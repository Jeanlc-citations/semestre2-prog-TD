#include <iostream> 
#include <string>

size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash1{};
    for (int i{0}; i < s.size(); i++) {
        hash1 += s[i] % max;
    }
    hash1 %= max;
    return hash1;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    size_t hash2{};
    for (int i{0}; i < s.size(); i++) {
        hash2 += s[i] * i % max;
    }
    return hash2;
}


size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash{};
    size_t power {1};
    for (int i{0}; i < s.size(); i++) {
        hash += s[i] * power % m;
        power = (power * p) % m;
    }
    return hash;
}


int main() {
    size_t max {64};
    
    std::string phrase1 {"abc"};
    std::string phrase2 {"cba"};
    
    std::cout << "folding : " << std::endl;
    size_t hash1 {folding_string_hash(phrase1, max)};
    size_t hash2 {folding_string_hash(phrase2, max)};
    std::cout << "Le hash de votre chaine de caracteres est : " << hash1 << std::endl;    
    std::cout << "Le hash de votre chaine de caracteres est : " << hash2 << std::endl; 
    std::cout << std::endl;

    std::cout << "folding par position : " << std::endl;
    size_t hash3 {folding_string_ordered_hash(phrase1, max)};
    size_t hash4 {folding_string_ordered_hash(phrase2, max)};
    std::cout << "Le hash de votre premiere chaine de caracteres est : " << hash3 << std::endl;    
    std::cout << "Le hash de votre seconde chaine de caracteres est : " << hash4 << std::endl; 
    std::cout << std::endl;

    std::cout << "polynomial rolling hash : " << std::endl;
    size_t p{3};
    size_t m{64};
    size_t hash5 {polynomial_rolling_hash(phrase1, p, m)};
    size_t hash6 {polynomial_rolling_hash(phrase2, p, m)};
    std::cout << "Le hash de votre chaine de caracteres est : " << hash5 << std::endl;    
    std::cout << "Le hash de votre chaine de caracteres est : " << hash6 << std::endl; 
    
    return 0;
}