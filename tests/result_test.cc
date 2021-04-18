#include "include/rusty.h"
#include <gtest/gtest.h>
#include <string>

using rusty::Result;
using rusty::Ok;
using rusty::Err;

TEST(ResultTest, OkInitialization) {
    Result<int, std::string> result{Ok{1}};
    EXPECT_TRUE(result.is_ok());
    EXPECT_FALSE(result.is_err());
    EXPECT_TRUE(result.ok().has_value());
    EXPECT_EQ(result.ok().value(), 1);
}

TEST(ResultTest, ErrInitialization) {
    Result<int, std::string> result{Err{std::string{"error"}}};
    EXPECT_FALSE(result.is_ok());
    EXPECT_TRUE(result.is_err());
    EXPECT_TRUE(result.err().has_value());
    EXPECT_EQ(result.err().value(), "error");
}

TEST(ResultTest, UnwrapOkTest) {
    Result<int, std::string> result{Ok{1}};
    EXPECT_EQ(result.unwrap(), 1);
}

TEST(ResultTest, UnwrapErrTest) {
    Result<int, std::string> result{Err{std::string{"error"}}};
    EXPECT_THROW(result.unwrap(), std::exception);
}
