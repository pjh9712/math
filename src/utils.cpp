// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors: Jeonghoon Park

#include "math/utils.hpp"

#include <cmath>
#include <stdexcept>

namespace math {
auto IsEqual(double lhs, double rhs) -> bool {
  return (std::abs(lhs - rhs) < std::numeric_limits<double>::epsilon());
}

auto Add(double lhs, double rhs) -> double {
  if (std::isnan(lhs) || std::isnan(rhs) || std::isinf(lhs) ||
      std::isinf(rhs)) {
    throw std::invalid_argument("Invalid input: NaN or Infinity");
  }

  if ((lhs > 0 && rhs > std::numeric_limits<double>::max() - lhs) ||
      (lhs < 0 && rhs < std::numeric_limits<double>::lowest() - lhs)) {
    throw std::overflow_error("Overflow");
  }

  return lhs + rhs;
}

auto Subtract(double lhs, double rhs) -> double {
  if (std::isnan(lhs) || std::isnan(rhs) || std::isinf(lhs) ||
      std::isinf(rhs)) {
    throw std::invalid_argument("Invalid input: NaN or Infinity");
  }

  if ((lhs < 0 && rhs > std::numeric_limits<double>::max() + lhs) ||
      (lhs > 0 && rhs < std::numeric_limits<double>::lowest() + lhs)) {
    throw std::overflow_error("Overflow");
  }

  return lhs - rhs;
}

auto Multiply(double lhs, double rhs) -> double {
  if (std::isnan(lhs) || std::isnan(rhs) || std::isinf(lhs) ||
      std::isinf(rhs)) {
    throw std::invalid_argument("Invalid input: NaN or Infinity");
  }

  return lhs * rhs;
}
}  // namespace math
