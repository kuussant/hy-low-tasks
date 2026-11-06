#include "tasks.h"

// Counts the number of one bits in x
// Example: bit_count(123) -> 6
//    123 = 1111011
int bit_count(unsigned int x) {
    unsigned int num = x;
    int bits = 0;

    while (num) {
        if (num & 1) bits++;

        num >>= 1;
    }

    return bits;
}

// Returns the parity of x
//   - If x has an even number of one bits, return 0
//   - If x has an odd number of one bits, return 1
// Example: parity(123) -> 0
//    123 = 1111011
int parity(unsigned int x) {
    if (bit_count(x) % 2) return 1;
    return 0;
}

// Returns the bit at position pos
//   - Bit at position 0 is the least significant bit
// Example: get_bit(123, 0) -> 1
// Example: get_bit(123, 2) -> 0
//   123 = 1111011
//             ^ ^
int get_bit(unsigned int x, int pos) {
    return 1 & x >> pos;
}

// Sets the bit at position pos to 1
// Example: set_bit(123, 2) -> 127
//   123 = 1111011
//   127 = 1111111
unsigned int set_bit(unsigned int x, int pos) {
    return 1 << pos | x;
}

// Sets the bit at position pos to 0
// Example: clear_bit(123, 0) -> 122
//   123 = 1111011
//   122 = 1111010
unsigned int clear_bit(unsigned int x, int pos) {
    return ~(1 << pos) & x;
}

// Flips the bit at position pos
// Example: flip_bit(123, 0) -> 122
// Example: flip_bit(123, 2) -> 127
//   123 = 1111011
//   122 = 1111010
//   127 = 1111111
unsigned int flip_bit(unsigned int x, int pos) {
    return 1 << pos ^ x;
}

// Returns the position of the highest one bit
//   - You can assume that x != 0
// Example: highest_bit_pos(42) -> 5
//   42 = 101010
//        ^
int highest_bit_pos(unsigned int x) {
    unsigned int n = x;
    int pos = -1;
    
    while (n) {
        n /= 2;
        pos++;
    }

    return pos;
}

// Returns the position of the lowest one bit
//   - You can assume that x != 0
// Example: lowest_bit_pos(42) -> 1
//   42 = 101010
//            ^
int lowest_bit_pos(unsigned int x) {
    unsigned int n = x;
    int pos = 0;

    while (!(1 & n)) {
        n >>= 1;
        pos++;
    }

    return pos;
}

// Sets the lowest one bit to zero
// Example: clear_lowest_bit(42) -> 40
//   42 = 101010
//   40 = 101000
unsigned int clear_lowest_bit(unsigned int x) {
    return clear_bit(x, lowest_bit_pos(x));
}

// Returns 1 if x is a power of two, otherwise returns 0
// Example: is_power_of_two(16) -> 1
// Example: is_power_of_two(17) -> 0
int is_power_of_two(unsigned int x) {
    return 1 << highest_bit_pos(x) == x;
}

// Counts the number of bit positions where a and b have the same bit
// Example: common_bit_count(42, 1337) -> 27
//     42 = 00000000000000000000000000101010
//   1337 = 00000000000000000000010100111001
//          ^^^^^^^^^^^^^^^^^^^^^ ^ ^^^ ^^
int common_bit_count(unsigned int a, unsigned int b) {
    return bit_count(~(a ^ b));
}

// Rotates all 32 bits of x one position to the left
//   - The highest bit wraps around to the lowest bit
// Example: rotate_left(3333333333) -> 2371699371
//   3333333333 = 11000110101011101010000101010101
//   2371699371 = 10001101010111010100001010101011
unsigned int rotate_left(unsigned int x) {
    return (x << 1) | (x >> 31);
}

// Rotates all 32 bits of x one position to the right
//   - The lowest bit wraps around to the highest bit
// Example: rotate_right(3333333333) -> 3814150314
//   3333333333 = 11000110101011101010000101010101
//   3814150314 = 11100011010101110101000010101010
unsigned int rotate_right(unsigned int x) {
    return (x >> 1) | (x << 31);
}

// Flips all 32 bits of x
// Example: flip_all_bits(1337) -> 4294965958
//         1337 = 00000000000000000000010100111001
//   4294965958 = 11111111111111111111101011000110
unsigned int flip_all_bits(unsigned int x) {
    return x ^ ~0;
}

// Swaps every pair of adjacent bits
// Example: swap_adjacent_bits(1337) -> 2614
//   1337 = 010100111001
//   2614 = 101000110110
unsigned int swap_adjacent_bits(unsigned int x) {
    return ((0xAAAAAAAA & x) >> 1) | ((0x55555555 & x) << 1);
}

// Reverses the order of all bits of x
// Example: reverse_bits(1337) -> 2627731456
//         1337 = 00000000000000000000010100111001
//   2627731456 = 10011100101000000000000000000000
unsigned int reverse_bits(unsigned int x) {
    int highest_bit = highest_bit_pos(x);
    unsigned int n = 0;

    for (int i = 0; i <= highest_bit; i++) {
        n |= ((x & (1 << i)) > 0) << (31 - i);
    }

    unsigned int swapped = swap_adjacent_bits(x);
    return n;
}

// Returns 1 ^ 2 ^ 3 ^ ... ^ n.
// Example: xor_sum(5) -> 1
long xor_sum(int n) {
    long out = 0;
    
    for (int i = 1; i <= n; i++) {
        out ^= i;
    }

    return out;
}
