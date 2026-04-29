#include <boost/random/taus88.hpp>
#include <boost/random/mersenne_twister.hpp>

#include <cstdint>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <random>
#include <string>

#include "mcml_mcg59.h"
#include "util.hpp"
#include "xoshiro256plus.hpp"
#include "xoshiro256plusplus.hpp"
#include "xoshiro128plus.hpp"

constexpr int seed = 20260416;

int main(int argc, char* argv[]) {
  try {
    if (argc < 2) {
      throw std::logic_error("Error reading standart input");
    }

    util::RngType type = util::parse_input(argv[1]);

    switch(type) {
      case util::RngType::XOSHIRO256P: {
        XoShiRo256Plus xoshiro_plus(seed);
        while (true) {
            std::uint64_t x = xoshiro_plus();
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::MT19937: {
        std::mt19937 mt(seed);
        while (true) {
            std::uint64_t x = mt();
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::XOSHIRO256PP: {
        XoShiRo256PlusPlus xoshiro_pp(seed);
        while (true) {
            std::uint64_t x = xoshiro_pp();
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::MCG59: {
        MCG59 mcg59;
        InitMCG59(&mcg59, seed, 0, 1);
        while (true) {
            std::uint64_t x = NextMCG59(&mcg59);
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::TAUS88: {
        boost::random::taus88 taus88(seed);
        while (true) {
            std::uint64_t x = taus88();
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::MT11213B: {
        boost::random::mt11213b mt11213b(seed);
        while (true) {
            std::uint64_t x = mt11213b();
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::XOSHIRO128P: {
        XoShiRo128Plus xoshiro(seed);
        while (true) {
            std::uint32_t x = xoshiro();
            std::cout.write(reinterpret_cast<char*>(&x), sizeof(x));
        }
      }

      case util::RngType::UNKNOWN: {
        throw std::domain_error("Unknown input"); 
      }
    }
  }
    
  catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
    throw std::runtime_error("Exception caught");
  }
}