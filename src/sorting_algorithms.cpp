#include "sorting_algorithms.hpp"

namespace alg {
    auto insert_sort(const std::vector<int> &values, const std::function<bool(int, int)> &compare)
            -> std::vector<int> {
        auto values_to_sort = values;

        for (int i = 1; i < values_to_sort.size(); ++i) {
            auto sort_at = i;
            while (sort_at > 0 && compare(values_to_sort[sort_at], values_to_sort[sort_at - 1])) {
                std::swap(values_to_sort[sort_at], values_to_sort[sort_at - 1]);
                --sort_at;
            }
        }

        return values_to_sort;
    }
}// namespace alg