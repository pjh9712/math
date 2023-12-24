// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "math/utils.hpp"

#include <cmath>
#include <limits>
#include <random>

#include "gtest/gtest.h"

namespace math {

const int kNumIterations = 1000;
const double kLowerBound = -1000.0;
const double kUpperBound = 1000.0;

TEST(MathUtils, Add) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(kLowerBound, kUpperBound);

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
  }
}
}  // namespace math
