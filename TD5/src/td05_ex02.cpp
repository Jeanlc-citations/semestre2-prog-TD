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
            auto robot_suivant {std::find_if(robots_fixes.begin(), robots_fixes.end(), is_name_robot)};
            auto robot_precedent{robots_fixes.begin()};
            std::vector<float>  liste_reparations{};
            while (robot_suivant != robots_fixes.end()) {
                robot_suivant = std::find_if(robot_precedent, robots_fixes.end(), is_name_robot);
                if (robot_suivant != robots_fixes.end()) {
                    liste_reparations.push_back(robot_suivant->second);
                }
                robot_precedent = robot_suivant+1;
        
        
            }
            liste.insert({name_robot, liste_reparations});
        }
    }
    return liste;
}


int main() {
    std::vector<std::pair<std::string, float>> robots_fixes{get_robots_fix(10)};
    std::unordered_map<std::string, std::vector<float>> liste{robots_fixes_map(robots_fixes)};
    for (int i{}; i < liste.size(); i++) {
        std::cout << liste[i] << std::endl;
    }
    return 0;
}