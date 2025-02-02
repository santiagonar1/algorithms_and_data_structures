#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP

#include <vector>

namespace ds {

    auto sift_down(std::vector<int> &values, int start) -> void;
    auto sift_up(std::vector<int> &values, int start) -> void;

    class MinBinaryHeap {
    public:
        MinBinaryHeap() = default;
        explicit MinBinaryHeap(const std::vector<int> &values);

        [[nodiscard]] auto find_min() const -> int;
        [[nodiscard]] auto extract_min() -> int;
        [[nodiscard]] auto size() const -> int;
        [[nodiscard]] auto empty() const -> bool;

        auto insert(int value) -> void;


    private:
        std::vector<int> _values;
    };
}// namespace ds


#endif//BINARY_HEAP_HPP
