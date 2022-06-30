#include <gtest/gtest-death-test.h>
#include <gtest/gtest.h>

#include <assumption.hpp>

using namespace ::testing;
TEST(Assumption, AssertSuccess)
{
    ASSERT(true, "");
    ASSERT_EQUAL(3, 3, "");
    ASSERT_NOT_EQUAL(3, 2, "");
    ASSERT_LESS(3, 4, "");
    ASSERT_GREATER(4, 3, "");
    ASSERT_LESS_EQUAL(3, 3, "");
    ASSERT_LESS_EQUAL(3, 4, "");
    ASSERT_GREATER_EQUAL(3, 3, "");
    ASSERT_GREATER_EQUAL(4, 3, "");
}

TEST(Assumption, AssertFailure)
{
#ifdef NDEBUG
    EXPECT_EXIT(ASSERT(false, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(ASSERT_EQUAL(2, 3, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(ASSERT_NOT_EQUAL(2, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(ASSERT_LESS(2, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(ASSERT_GREATER(2, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(ASSERT_LESS_EQUAL(3, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(ASSERT_GREATER_EQUAL(2, 3, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
#else
    ASSERT(false, "");
    ASSERT_EQUAL(2, 3, "");
    ASSERT_NOT_EQUAL(2, 2, "");
    ASSERT_LESS(2, 2, "");
    ASSERT_GREATER(2, 2, "");
    ASSERT_LESS_EQUAL(3, 2, "");
    ASSERT_GREATER_EQUAL(2, 3, "");
#endif
}

TEST(Assumption, CheckSuccess)
{
    CHECK(true, "");
    CHECK_EQUAL(3, 3, "");
    CHECK_NOT_EQUAL(3, 2, "");
    CHECK_LESS(3, 4, "");
    CHECK_GREATER(4, 3, "");
    CHECK_LESS_EQUAL(3, 3, "");
    CHECK_LESS_EQUAL(3, 4, "");
    CHECK_GREATER_EQUAL(3, 3, "");
    CHECK_GREATER_EQUAL(4, 3, "");
}

TEST(Assumption, CheckFailure)
{
    EXPECT_EXIT(CHECK(false, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(CHECK_EQUAL(2, 3, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(CHECK_NOT_EQUAL(2, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(CHECK_LESS(2, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(CHECK_GREATER(2, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(CHECK_LESS_EQUAL(3, 2, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
    EXPECT_EXIT(CHECK_GREATER_EQUAL(2, 3, ""), testing::ExitedWithCode(EXIT_FAILURE), ".*");
}
