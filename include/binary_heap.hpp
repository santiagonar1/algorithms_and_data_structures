#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP

#include <vector>

namespace ds {
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
