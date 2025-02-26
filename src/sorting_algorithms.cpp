#include "sorting_algorithms.hpp"

#include "binary_heap.hpp"
#include "utils.hpp"

#include <numeric>

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

        auto quick_sort(std::span<int> values, const std::function<bool(int, int)> &compare)
                -> void {
            const auto num_values = static_cast<int>(values.size());

            if (num_values <= 1) { return; }

            const auto random_value = values[::internal::get_random_int(0, num_values - 1)];
            auto num_less_than = 0;
            auto num_equal_than = 0;

            for (int i = 0; i < num_values; ++i) {
                if (compare(values[i], random_value)) {
                    std::swap(values[i], values[num_less_than + num_equal_than]);
                    std::swap(values[num_less_than], values[num_less_than + num_equal_than]);
                    num_less_than++;
                } else if (values[i] == random_value) {
                    std::swap(values[i], values[num_less_than]);
                    num_equal_than++;
                }
            }

            quick_sort(values.subspan(0, num_less_than), compare);
            quick_sort(values.subspan(num_less_than + num_equal_than,
                                      num_values - (num_less_than + num_equal_than)),
                       compare);
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
            ds::sift_up(std::span{values.begin(), values.begin() + i + 1});
        }

        for (int i = static_cast<int>(values.size()) - 1; i > 0; --i) {
            std::swap(values[0], values[i]);
            ds::sift_down(std::span{values.begin(), values.begin() + i});
        }
    }

    auto quick_sort(const std::vector<int> &values, const std::function<bool(int, int)> &compare)
            -> std::vector<int> {
        auto result = values;
        internal::quick_sort(result, compare);
        return result;
    }


    auto quick_sort(std::vector<int> &values, const std::function<bool(int, int)> &compare)
            -> void {
        internal::quick_sort(values, compare);
    }

    auto count_sort(const std::vector<int> &values) -> std::vector<int> {
        const auto max_value = *std::ranges::max_element(values);
        auto counters = std::vector<int>(max_value + 1);

        for (const auto value: values) {
            if (value < 0) { throw std::runtime_error("Negative values are not allowed"); }
            counters[value]++;
        }

        auto values_to_sort = std::vector<int>(values.size());

        int num_values = 0;
        for (int i = 0; i < counters.size(); ++i) {
            for (int j = 0; j < counters[i]; ++j) { values_to_sort[num_values++] = i; }
        }

        return values_to_sort;
    }

    auto radix_sort(const std::vector<int> &values) -> std::vector<int> {
        // this simple implementation works for numbers with two digits
        constexpr auto m = 10;

        auto pairs = std::vector<std::pair<int, int>>{};
        auto counters_units = std::vector<int>(m);
        auto counters_tens = std::vector<int>(m);
        for (const auto value: values) {
            const auto tens = value / m;
            const auto units = value % m;
            pairs.emplace_back(tens, units);
            counters_units[units]++;
            counters_tens[tens]++;
        }

        auto positions = std::vector<int>(m);
        std::exclusive_scan(counters_units.begin(), counters_units.end(), positions.begin(), 0);

        auto pairs_units_sorted = std::vector<std::pair<int, int>>(pairs.size());
        for (const auto &pair: pairs) {
            pairs_units_sorted[positions[pair.second]] = pair;
            positions[pair.second]++;
        }

        auto pairs_tens_sorted = std::vector<std::pair<int, int>>(pairs.size());
        for (const auto &pair: pairs_units_sorted) {
            pairs_tens_sorted[positions[pair.first]] = pair;
            positions[pair.first]++;
        }

        auto values_sorted = std::vector<int>{};
        for (const auto &pair: pairs_tens_sorted) {
            values_sorted.push_back(pair.first * m + pair.second);
        }

        return values_sorted;
    }


}// namespace alg