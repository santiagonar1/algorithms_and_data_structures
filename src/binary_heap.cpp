#include "binary_heap.hpp"

#include "sorting_algorithms.hpp"

#include <stdexcept>

namespace ds {

    namespace internal {
        auto has_child(const int i, const int size) -> bool { return 2 * i + 1 < size; }
    }// namespace internal

    auto sift_down(std::vector<int> &values, const int start) -> void {
        int parent_id = start;
        while (internal::has_child(parent_id, static_cast<int>(values.size()))) {
            const int left_child_id = 2 * parent_id + 1;
            const int right_child_id = 2 * parent_id + 2;
            int min_child_id = left_child_id;

            if (right_child_id < values.size() and values[left_child_id] > values[right_child_id]) {
                min_child_id = right_child_id;
            }

            if (values[parent_id] < values[min_child_id]) { break; }

            std::swap(values[parent_id], values[min_child_id]);
            parent_id = min_child_id;
        }
    }

    MinBinaryHeap::MinBinaryHeap(const std::vector<int> &values)
        : _values(alg::merge_sort(values)) {}

    auto MinBinaryHeap::find_min() const -> int {
        if (empty()) { throw std::runtime_error("Heap is empty"); }

        return _values[0];
    }

    auto MinBinaryHeap::extract_min() -> int {
        if (empty()) { throw std::runtime_error("Heap is empty"); }

        const auto min = _values[0];
        _values[0] = _values.back();
        _values.pop_back();

        sift_down(_values, 0);

        return min;
    }

    auto MinBinaryHeap::size() const -> int { return static_cast<int>(_values.size()); }

    auto MinBinaryHeap::empty() const -> bool { return _values.empty(); }

    auto MinBinaryHeap::insert(const int value) -> void {
        _values.push_back(value);

        int node_id = size() - 1;
        int parent_id = (node_id - 1) / 2;
        while (node_id > 0 and _values[parent_id] > _values[node_id]) {
            std::swap(_values[parent_id], _values[node_id]);
            node_id = parent_id;
            parent_id = (node_id - 1) / 2;
        }
    }

}// namespace ds