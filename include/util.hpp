#pragma once

#include <string>

namespace util {
  enum class RngType {
      MT19937,
      MT11213B,
      MCG59,
      TAUS88,
      XOSHIRO256P,
      XOSHIRO256PP,
      UNKNOWN
  };

  RngType parse_input(const std::string& name) {
      if (name == "mt19937") return RngType::MT19937;
      if (name == "mt11213b") return RngType::MT11213B;
      if (name == "mcg59") return RngType::MCG59;
      if (name == "taus88") return RngType::TAUS88;
      if (name == "xoshiro256+") return RngType::XOSHIRO256P;
      if (name == "xoshiro256++") return RngType::XOSHIRO256PP;
      return RngType::UNKNOWN;
  }
} // namespace util