#include "search_algorithms.hpp"

#include <span>

#include "utils.hpp"

namespace alg {

    namespace internal {
        auto nth_element(std::span<int> values, int index) -> int {
            const auto num_values = static_cast<int>(values.size());

            if (num_values == 1) { return values[0]; }

            // We choose two to decrease the likelihood of selecting the minimum value, which
            // breaks the algorithm.
            const auto random_value =
                    std::max(values[::internal::get_random_int(0, num_values - 1)],
                             values[::internal::get_random_int(0, num_values - 1)]);
            auto num_less_than = 0;

            for (int i = 0; i < num_values; ++i) {
                if (values[i] < random_value) {
                    std::swap(values[i], values[num_less_than]);
                    num_less_than++;
                } else {
                }
            }

            if (index < num_less_than) {
                return nth_element(values.subspan(0, num_less_than), index);
            }

            return nth_element(values.subspan(num_less_than, num_values - num_less_than),
                               index - num_less_than);

            return 0;
        }
    }// namespace internal

    auto nth_element(const std::vector<int> &values, int index) -> int {
        auto search_values = values;
        return internal::nth_element(search_values, index);
    }
}// namespace alg