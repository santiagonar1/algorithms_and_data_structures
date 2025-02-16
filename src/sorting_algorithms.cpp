#include "sorting_algorithms.hpp"

#include "binary_heap.hpp"

namespace alg {

    namespace internal {
        auto merge(const std::vector<int> &v1, const std::vector<int> &v2,
                   const std::function<bool(int, int)> &compare) -> std::vector<int> {
            auto i_v1 = 0;
            auto i_v2 = 0;

            const auto n = v1.size() + v2.size();
            auto result = std::vector<int>(n);


            for (int i = 0; i < n; ++i) {
                if (i_v2 == v2.size() or (i_v1 < v1.size() and compare(v1[i_v1], v2[i_v2]))) {
                    result[i] = v1[i_v1];
                    ++i_v1;
                } else {
                    result[i] = v2[i_v2];
                    ++i_v2;
                }
            }

            return result;
        }
    }// namespace internal

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

    auto merge_sort(const std::vector<int> &values, const std::function<bool(int, int)> &compare)
            -> std::vector<int> {
        auto values_to_sort = values;
        if (values_to_sort.size() <= 1) { return values_to_sort; }
        const auto left_sorted = merge_sort(
                {values_to_sort.begin(), values_to_sort.begin() + values_to_sort.size() / 2},
                compare);
        const auto right_sorted = merge_sort(
                {values_to_sort.begin() + values_to_sort.size() / 2, values_to_sort.end()},
                compare);
        return internal::merge(left_sorted, right_sorted, compare);
    }

    auto heap_sort(const std::vector<int> &values) -> std::vector<int> {
        auto result = std::vector<int>{};
        auto heap = ds::MinBinaryHeap(values);
        while (!heap.empty()) { result.push_back(heap.extract_min()); }
        return result;
    }

    auto heap_sort(std::vector<int> &values) -> void {
        for (int i = 0; i < values.size(); ++i) {
            ds::sift_up(values, i);
        }

        for (int i = values.size() - 1; i > 0; --i) {
            std::swap(values[0], values[i]);
            ds::sift_down(std::span{values.begin(), values.begin() + i});
        }
    }

}// namespace alg