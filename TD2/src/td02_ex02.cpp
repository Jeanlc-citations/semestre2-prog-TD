#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<float> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);
    size_t const left_size { left_vec.size() };
    size_t const right_size { right_vec.size()};

    
    size_t left_index {0};
    size_t right_index {0};

 

    
    size_t iterrator {left};

    
    while (left_index < left_size && right_index < right_size) {
        if (left_vec[left_index] < right_vec[right_index]) {
            vec[iterrator] = left_vec[left_index];
            left_index++;
        } else {
            vec[iterrator] = right_vec[right_index];
            right_index++;
        }
        iterrator++;
    }

    
    while (left_index < left_size) {
        vec[iterrator] = left_vec[left_index];
        left_index++;
        iterrator++;
    }
    while (right_index < right_size) {
        vec[iterrator] = right_vec[right_index];
        right_index++;
        iterrator++;
    }
}



void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    size_t const middle{(left + right)/2};
    if (right - left >= 1) {
        merge_sort(vec,left, middle);
        merge_sort(vec,middle+1, right);
        merge_sort_merge(vec, left, middle, right);
    } 
}


int main() {
    //std::vector<float> tableau {1, 9, 5, 12, 9, 8, 4, 6, 3};
     std::vector<float> tableau {generate_random_vector(9, 100)};

    merge_sort(tableau, 0, tableau.size()-1);
    for (int i{0}; i<tableau.size(); i++)
    {
        std::cout << tableau[i] << std::endl;
    }
    
    // exercice 3
    {
    ScopedTimer timer("Chronos");
    merge_sort(tableau, 0, tableau.size()-1);
    }

    
}