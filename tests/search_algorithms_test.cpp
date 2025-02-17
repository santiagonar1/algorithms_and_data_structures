#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <search_algorithms.hpp>

using testing::Eq;

TEST(NthElement, FindsNthElementAsIfTheVectorWereSorted) {
    const auto values = std::vector{2, 1, 3, 4, 5, 0};

    EXPECT_THAT(alg::nth_element(values, 2), Eq(2));
}