#include "utils.hpp"

#include <random>

namespace internal {
    auto get_random_int(const int min, const int max) -> int {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
}// namespace internal