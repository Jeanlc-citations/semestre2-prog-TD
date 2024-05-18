#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}


/*
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> liste{};
    for (int i{0}; i < robots_fixes.size(); i++) {
        std::string name_robot {robots_fixes[i].first};
        // auto it_tableau1 {std::find_if(robots_fixes.begin(), robots_fixes.end(), name_robot)};
        auto it_tableau2 {liste.find(name_robot)};

        auto is_name_robot = [name_robot](const std::pair<std::string, float>& pair) {
            return pair.first == name_robot;
        };

        if (it_tableau2 == liste.end()) {
            auto robot_suivant {robots_fixes.begin()};
            auto robot_precedent{robots_fixes.begin()};
            std::vector<float>  liste_reparations{};
            while (robot_suivant != robots_fixes.end()) {
                robot_suivant = std::find_if(robot_precedent, robots_fixes.end(), is_name_robot);
                if (robot_suivant != robots_fixes.end()) {
                    liste_reparations.push_back(robot_suivant->second);
                }
                if (robot_suivant != robots_fixes.end()) {
                    robot_precedent = robot_suivant+1;
                }
                
        
        
            }
            liste.insert({name_robot, liste_reparations});
        }
    }
    return liste;
}
*/


std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> liste{};
    for (std::pair<std::string, float> reparations : robots_fixes) {
        std::string name_robot {reparations.first};
        auto is_name_robot {liste.find(name_robot)};

        if (is_name_robot == liste.end()) {
            std::vector<float>  liste_reparations{reparations.second};
            liste.insert({name_robot, liste_reparations});
        } else {
            (*is_name_robot).second.push_back(reparations.second);
        }

        
    }
    return liste;
}

float somme_fixes(std::vector<float> & reparations) {
    float somme{};
    for (int i{0}; i < reparations.size(); i++) {
        somme += reparations[i];
    }
    return somme;
}

std::unordered_map<std::string, float> liste_robots(std::vector<std::pair<std::string, float>> & robots_fixes) {
    std::unordered_map<std::string, float> liste_robots{};
    std::unordered_map<std::string, std::vector<float>> trie_robots {robots_fixes_map(robots_fixes)};
    auto it {trie_robots.begin()};
    for (it; it != trie_robots.end(); ++it) {
        auto fixes{it->second};
        liste_robots.insert({it->first, somme_fixes(fixes)});
    }
    return liste_robots;

}

int main() {
    std::vector<std::pair<std::string, float>> robots_fixes{get_robots_fix(100)};
    std::unordered_map<std::string, float> liste{liste_robots(robots_fixes)};
    auto it{liste.begin()};
    for (it; it != liste.end(); it++) {
        std::cout << "Robot : " << it->first << ", prix des reparations : " << it->second << std::endl;
    }
    
    return 0;
}



