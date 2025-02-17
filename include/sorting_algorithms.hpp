#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include <functional>
#include <span>
#include <vector>

namespace alg {
    auto insert_sort(const std::vector<int> &values,
                     const std::function<bool(int, int)> &compare = std::less<int>{})
            -> std::vector<int>;

    auto merge_sort(const std::vector<int> &values,
                    const std::function<bool(int, int)> &compare = std::less<int>{})
            -> std::vector<int>;

    auto heap_sort(const std::vector<int> &values) -> std::vector<int>;

    auto heap_sort(std::vector<int> &values) -> void;

    auto quick_sort(const std::vector<int> &values,
                    const std::function<bool(int, int)> &compare = std::less<int>{})
            -> std::vector<int>;

    auto quick_sort(std::vector<int> &values,
                    const std::function<bool(int, int)> &compare = std::less<int>{}) -> void;
}// namespace alg

#endif//SORTING_ALGORITHMS_HPP
