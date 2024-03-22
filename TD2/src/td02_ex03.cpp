#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

int main() {
    std::vector<int> tableau {1, 9, 5, 12, 9, 3, 4, 6, 8};
    std::sort(tableau.begin(), tableau.end());

    {
    ScopedTimer timer("Chronos");
    std::sort(tableau.begin(), tableau.end());
    }
}