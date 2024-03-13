#include <iostream>
#include <vector>

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size { middle - left + 1 };
    size_t const right_size { right - middle + 1};
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index {0};
    size_t right_index {0};

    size_t index {left};

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size || right_index < right_size) {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] < right_vec[right_index]) {
            vec.push_back(left_vec[left_index]);
            left_index++;
        } else {
            vec.push_back(right_vec[right_index]);
            right_index++;
        }
        /* TODO */
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size) {
        vec.push_back(left_vec[left_index]);
        left_index++;
    }
    while (right_index < right_size) {
        vec.push_back(right_vec[right_index]);
        right_index++;
    }
}

void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }
    // 1. Choix de l'index au milieu de la partition
    // 2. Appels récursifs sur les deux sous-parties
    // 3. Fusion des deux sous-parties
}


int main() {
    std::vector<int> tableau {1, 9, 5, 12, 9, 3, 4, 6, 8};

    
}