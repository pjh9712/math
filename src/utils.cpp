// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "math/utils.hpp"

#include <cmath>

namespace math {
auto IsEqual(double lhs, double rhs) -> bool {
  return (std::abs(lhs - rhs) < std::numeric_limits<double>::epsilon());
}
auto Add(double lhs, double rhs) -> double { return lhs + rhs; }
}  // namespace math
