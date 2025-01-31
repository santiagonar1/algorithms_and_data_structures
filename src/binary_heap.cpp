#include "binary_heap.hpp"

#include "sorting_algorithms.hpp"

#include <stdexcept>

namespace ds {

    namespace internal {
        auto has_child(const int i, const int size) -> bool { return 2 * i + 1 < size; }
    }// namespace internal

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

        int parent_id = 0;
        while (internal::has_child(parent_id, size())) {
            const int left_child_id = 2 * parent_id + 1;
            const int right_child_id = 2 * parent_id + 2;
            int min_child_id = left_child_id;

            if (right_child_id < size() and _values[left_child_id] > _values[right_child_id]) {
                min_child_id = right_child_id;
            }

            if (_values[parent_id] < _values[min_child_id]) { break; }

            std::swap(_values[parent_id], _values[min_child_id]);
            parent_id = min_child_id;
        }


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