#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <search_algorithms.hpp>

using testing::Eq;

TEST(NthElement, FindsNthElementAsIfTheVectorWereSorted) {
    const auto values = std::vector{2, 1, 3, 4, 5, 0};

    EXPECT_THAT(alg::nth_element(values, 2), Eq(2));
}

TEST(FindInSorted, ReturnsTheIndexOfTheElement) {
    const auto values = std::vector{0, 1, 2, 3};

    EXPECT_THAT(alg::find_in_sorted(values, 2), Eq(2));
}

TEST(FindInSorted, ReturnsTheIndexOfFirstInstance) {
    const auto values = std::vector{0, 1, 2, 2, 2, 2, 2, 3};

    EXPECT_THAT(alg::find_in_sorted(values, 2), Eq(2));
}

TEST(FindInSorted, ReturnsMinusOneIfElementNotFound) {
    const auto values = std::vector{0, 1, 2, 2, 2, 2, 2, 3};

    EXPECT_THAT(alg::find_in_sorted(values, 5), Eq(-1));
    EXPECT_THAT(alg::find_in_sorted(values, -1), Eq(-1));
}