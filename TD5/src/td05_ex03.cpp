#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    int hash() const;
};


std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

bool operator==(Card const& c1, Card const& c2) {
    return c1.kind ==  c2.kind && c1.value == c2.value;
    
}



namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}


int Card::hash() const {
    /*
    int symbole{};
    if (kind == CardKind::Heart) {
        symbole = 0;
    } 
    else if (kind == CardKind::Diamond){
        symbole = 1;
    }
    else if (kind == CardKind::Club){
        symbole = 2;
    }
    else if (kind == CardKind::Spade){
        symbole = 3;
    }
    */
    int symbole {static_cast<int>(kind)};
    int valeur {static_cast<int>(value)};
    int nombre{valeur * 4 + symbole};

    return nombre;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

/*
std::unordered_map<std::string, int> tri_cartes(std::vector<std::string> & cartes) {
    std::unordered_map<std::string, int> tri_cartes{};
    for (int i{0}; i < cartes.size(); i++) {
        std::string carte {cartes[i]};
        auto it_tableau2 {tri_cartes.find(carte)};

        auto is_name_carte = [carte](const std::string & nom_carte) {
            return nom_carte == carte;
        };

        if (it_tableau2 == tri_cartes.end()) {
            auto carte_suivante {cartes.begin()};
            auto carte_precedente{cartes.begin()};
            int  nombre{0};
            while (carte_suivante != cartes.end()) {
                carte_suivante = std::find_if(carte_precedente, cartes.end(), is_name_carte);
                if (carte_suivante != cartes.end()) {
                    nombre++;
                }
                if (carte_suivante != cartes.end()) {
                    carte_precedente = carte_suivante+1;
                }
                
        
        
            }
            tri_cartes.insert({carte, nombre});
        }
    }
    return tri_cartes;
}
*/


std::unordered_map<std::string, int> tri_cartes(std::vector<std::string> & cartes) {
    std::unordered_map<std::string, int> tri_cartes{};
    // int nombre {1};
    for (int i{0}; i < cartes.size(); i++) {
        std::string carte {cartes[i]};
        auto is_carte {tri_cartes.find(carte)};
        
        if (is_carte == tri_cartes.end()) {
            tri_cartes.insert({carte, 1});
        } else {
            tri_cartes[carte]++;
        }

        
    }
    return tri_cartes;

}



int main() {
    std::vector<Card> liste_cartes {get_cards(100)};
    std::vector<std::string> noms_cartes{};
    for (int i{0}; i < liste_cartes.size(); i++) {
        std::string nom_carte {card_name(liste_cartes[i])};
        noms_cartes.push_back(nom_carte);
        // int num_carte{liste_cartes[i].hash()};
        // std::cout << nom_carte << ", " << num_carte << std::endl;
    }


    
    std::unordered_map<std::string, int> cartes_triees{tri_cartes(noms_cartes)};
    auto it{cartes_triees.begin()};
    for (it; it != cartes_triees.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    

    
    
}
        
     

