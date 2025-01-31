#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <binary_heap.hpp>

using testing::Eq;
using namespace ds;

TEST(BinaryHeap, BalancesAfterInsertingElement) {
    const auto values = std::vector{1, 2, 3, 4, 5};
    auto heap = MinBinaryHeap(values);
    heap.insert(-1);

    EXPECT_THAT(heap.extract_min(), Eq(-1));
}

TEST(BinaryHeap, BalancesAfterExtractingElement) {
    const auto values = std::vector{1, 2, 3, 4, 5};
    auto heap = MinBinaryHeap(values);

    EXPECT_THAT(heap.extract_min(), Eq(1));
    EXPECT_THAT(heap.extract_min(), Eq(2));
}