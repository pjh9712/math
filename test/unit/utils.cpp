// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "math/utils.hpp"

#include <cmath>
#include <limits>
#include <random>

#include "gtest/gtest.h"

namespace math {

const int kNumIterations = 10;
const double kLowerBound = -1000.0;
const double kUpperBound = 1000.0;

const double kDoubleMaxValue = std::numeric_limits<double>::max();
const double kDoubleMinValue = std::numeric_limits<double>::min();
const double kDoubleLowestValue = std::numeric_limits<double>::lowest();
const double kEpsilon = std::numeric_limits<double>::epsilon();

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> dis(kLowerBound, kUpperBound);

TEST(MathUtils, Add) {
  for (int i = 0; i < kNumIterations; ++i) {
    double lhs = dis(gen);
    double rhs = dis(gen);

    double result = Add(lhs, rhs);

    EXPECT_EQ(result, lhs + rhs);

    EXPECT_THROW(Add(std::numeric_limits<double>::quiet_NaN(), rhs),
                 std::invalid_argument);
    EXPECT_THROW(Add(lhs, std::numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
    EXPECT_THROW(Add(std::numeric_limits<double>::quiet_NaN(),
                     std::numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);

    EXPECT_THROW(Add(std::numeric_limits<double>::infinity(), rhs),
                 std::invalid_argument);
    EXPECT_THROW(Add(lhs, std::numeric_limits<double>::infinity()),
                 std::invalid_argument);
    EXPECT_THROW(Add(std::numeric_limits<double>::infinity(),
                     std::numeric_limits<double>::infinity()),
                 std::invalid_argument);

    EXPECT_THROW(Add(kDoubleLowestValue, kDoubleLowestValue),
                 std::overflow_error);
    EXPECT_THROW(Add(kDoubleMaxValue, kDoubleMaxValue), std::overflow_error);
  }
}
TEST(MathUtils, Subtract) {
  for (int i = 0; i < kNumIterations; ++i) {
    double lhs = dis(gen);
    double rhs = dis(gen);

    double result = Subtract(lhs, rhs);

    EXPECT_EQ(result, lhs - rhs);

    EXPECT_THROW(Subtract(std::numeric_limits<double>::quiet_NaN(), rhs),
                 std::invalid_argument);
    EXPECT_THROW(Subtract(lhs, std::numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
    EXPECT_THROW(Subtract(std::numeric_limits<double>::quiet_NaN(),
                          std::numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);

    EXPECT_THROW(Subtract(std::numeric_limits<double>::infinity(), rhs),
                 std::invalid_argument);
    EXPECT_THROW(Subtract(lhs, std::numeric_limits<double>::infinity()),
                 std::invalid_argument);
    EXPECT_THROW(Subtract(std::numeric_limits<double>::infinity(),
                          std::numeric_limits<double>::infinity()),
                 std::invalid_argument);

    EXPECT_THROW(Subtract(kDoubleLowestValue, kDoubleMaxValue), std::overflow_error);
    EXPECT_THROW(Subtract(kDoubleMaxValue, kDoubleLowestValue), std::overflow_error);
  }
}

TEST(MathUtils, Multiply) {
  for (int i = 0; i < kNumIterations; ++i) {
    double lhs = dis(gen);
    double rhs = dis(gen);

    double result = Multiply(lhs, rhs);

    EXPECT_EQ(result, lhs * rhs);

    EXPECT_THROW(Multiply(std::numeric_limits<double>::quiet_NaN(), rhs),
                 std::invalid_argument);
    EXPECT_THROW(Multiply(lhs, std::numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
    EXPECT_THROW(Multiply(std::numeric_limits<double>::quiet_NaN(),
                          std::numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);

    EXPECT_THROW(Multiply(std::numeric_limits<double>::infinity(), rhs),
                 std::invalid_argument);
    EXPECT_THROW(Multiply(lhs, std::numeric_limits<double>::infinity()),
                 std::invalid_argument);
    EXPECT_THROW(Multiply(std::numeric_limits<double>::infinity(),
                          std::numeric_limits<double>::infinity()),
                 std::invalid_argument);
  }
}
}  // namespace math
