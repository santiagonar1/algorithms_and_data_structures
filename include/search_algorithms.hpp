#ifndef SEARCH_ALGORITHMS_HPP
#define SEARCH_ALGORITHMS_HPP
#include <vector>

namespace alg {
    auto nth_element(const std::vector<int> &values, int index) -> int;
    auto find_in_sorted(const std::vector<int> &values, int value) -> int;
}// namespace alg

#endif//SEARCH_ALGORITHMS_HPP
