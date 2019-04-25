/*
    ===========================================================================
    Random number generating functions for BigInt
    ===========================================================================
*/

#ifndef BIG_INT_RANDOM_FUNCTIONS_HPP
#define BIG_INT_RANDOM_FUNCTIONS_HPP

#include <random>
#include <climits>

#include "BigInt.hpp"

// when the number of digits are not specified, a random value is used for it
// which is kept below the following:
const size_t MAX_RANDOM_LENGTH = 1000;


/*
    big_random (num_digits)
    -----------------------
    Returns a random BigInt with a specific number of digits.
*/

BigInt big_random(size_t num_digits = 0) {
    std::random_device rand_generator;      // true random number generator

    if (num_digits == 0)    // the number of digits were not specified
        // use a random number for it:
        num_digits = 1 + rand_generator() % MAX_RANDOM_LENGTH;

    BigInt big_rand;
    big_rand.value = "";    // clear value to append digits
    while (big_rand.value.size() < num_digits)
        big_rand.value += std::to_string(rand_generator());
    if (big_rand.value.size() != num_digits)
        big_rand.value.erase(num_digits);   // erase extra digits

    return big_rand;
}

friend BigInt big_random(const T& low, const T& high) {
    std::random_device rand_generator; // creating a random number generator
    
    BigInt big_rand;
    big_rand.value = "";

    // update the value while it's low <= BigInt <= high
    while ((big_rand.value >= low && big_rand.value =< high) {
    big_rand.value += std::to_string(rand_generator());
    }

    return big_rand;
}

	

#endif  // BIG_INT_RANDOM_FUNCTIONS_HPP
