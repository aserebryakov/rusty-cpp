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
}

TEST(ResultTest, ErrInitialization) {
    Result<int, std::string> result{Err{std::string{"error"}}};
    EXPECT_FALSE(result.is_ok());
    EXPECT_TRUE(result.is_err());
}
