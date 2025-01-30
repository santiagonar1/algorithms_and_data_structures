#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include <functional>
#include <vector>

namespace alg {
    auto insert_sort(const std::vector<int> &values,
                     const std::function<bool(int, int)> &compare = std::less<int>{})
            -> std::vector<int>;
}

#endif//SORTING_ALGORITHMS_HPP
