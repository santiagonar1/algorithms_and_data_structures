#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sorting_algorithms.hpp>

using testing::Eq;
using testing::HasSubstr;
using testing::ThrowsMessage;

TEST(InsertSort, SortsVectorByDefaulFromMinToMax) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::insert_sort(unsorted), Eq(std::vector{1, 2, 3}));
}

TEST(InsertSort, CanReceiveACompareFunction) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::insert_sort(unsorted, std::greater<int>{}), Eq(std::vector{3, 2, 1}));
}

TEST(InsertSort, WorksWithEmptyVector) {
    constexpr auto unsorted = std::vector<int>{};

    EXPECT_THAT(alg::insert_sort(unsorted), Eq(std::vector<int>{}));
}

TEST(MergeSort, SortsVectorByDefaulFromMinToMax) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::merge_sort(unsorted), Eq(std::vector{1, 2, 3}));
}

TEST(MergeSort, CanReceiveACompareFunction) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::merge_sort(unsorted, std::greater<int>{}), Eq(std::vector{3, 2, 1}));
}

TEST(MergeSort, WorksWithEmptyVector) {
    constexpr auto unsorted = std::vector<int>{};

    EXPECT_THAT(alg::merge_sort(unsorted), Eq(std::vector<int>{}));
}

TEST(HeapSort, SortsVector) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::heap_sort(unsorted), Eq(std::vector{1, 2, 3}));
}

TEST(HeapSort, HasInSituVariant) {
    auto to_be_sorted = std::vector{3, 1, 2, 4};

    alg::heap_sort(to_be_sorted);

    EXPECT_THAT(to_be_sorted, Eq(std::vector{4, 3, 2, 1}));
}

TEST(QuickSort, SortsVectorByDefaulFromMinToMax) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::quick_sort(unsorted), Eq(std::vector{1, 2, 3}));
}

TEST(QuickSort, CanReceiveACompareFunction) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::quick_sort(unsorted, std::greater<int>{}), Eq(std::vector{3, 2, 1}));
}

TEST(QuickSort, WorksIfAllElementsAreTheSame) {
    const auto unsorted = std::vector{2, 2, 2};

    EXPECT_THAT(alg::quick_sort(unsorted, std::greater<int>{}), Eq(std::vector{2, 2, 2}));
}

TEST(QuickSort, HasInSituVariant) {
    auto to_be_sorted = std::vector{3, 1, 2, 4};

    alg::quick_sort(to_be_sorted);

    EXPECT_THAT(to_be_sorted, Eq(std::vector{1, 2, 3, 4}));
}

TEST(CountSort, SortsValues) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::count_sort(unsorted), Eq(std::vector{1, 2, 3}));
}

TEST(CountSort, OnlyWorksForNonNegativeValues) {
    const auto unsorted = std::vector{3, 1, 2, -1};

    const auto sort_call = [unsorted] { alg::count_sort(unsorted); };

    EXPECT_THAT(sort_call,
                ThrowsMessage<std::runtime_error>(HasSubstr("Negative values are not allowed")));
}

TEST(RadixSort, SortsValues) {
    const auto unsorted = std::vector{3, 1, 2};

    EXPECT_THAT(alg::radix_sort(unsorted), Eq(std::vector{1, 2, 3}));
}