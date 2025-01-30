#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sorting_algorithms.hpp>

using testing::Eq;

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

