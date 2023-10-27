#include <iostream>
#include <string>
#include <cmath>

#ifndef OOP_LAB1_BITARRAY_H
#define OOP_LAB1_BITARRAY_H

class BitArray {
public:
    // create constructor
    explicit BitArray(int num_bits, unsigned long value = 0);

    // create copy constructor
    BitArray(const BitArray& mass);

    // create destructor
    ~BitArray();

    // function for print our array
    void PrintBitArray();

    // function for swapping two arrays
    void swap(BitArray& mass);

    // operator =
    BitArray& operator = (const BitArray& mass);

    // Changes the size of the array. In the case of expansion, new elements are initialized with value.
    void resize(int num_bits, bool value = false);

    // Array clear function
    void clear();

    //function to add a new bit to the end of the array
    void push_back(bool bit);

    // operator and
    BitArray& operator &= (const BitArray& mass);

    // operator or
    BitArray& operator |= (const BitArray& mass);

    // operator exclusive or
    BitArray& operator ^= (const BitArray& mass);

    // operator >>
    BitArray& operator >>= (int n);

    // operator <<
    BitArray& operator<<=(int n);

    BitArray operator<<(int n) const;

    BitArray operator>>(int n) const;

    // Inserts the value val at index n
    BitArray& set(int n, bool val = true);

    // Fills the array with true
    BitArray& set();

    // Sets the bit with index n to false
    BitArray& reset(int n);

    // Fills the array with false
    BitArray& reset();

    // true if the array contains a true bit
    bool any() const;

    // true if all bits of the array are false
    bool none() const;

    // bits inversion
    BitArray operator~() const;

    // counter of true bits
    int count() const;

    // outputs the bit at index i
    bool operator[](int i) const;

    // returns the size of the array
    int size() const;

    // returns true if the array is empty
    bool empty() const;

    // Returns a string representation of the array
    std::string to_string() const;

private:
    bool* bits;
    int SizeOfArray;
};

// operator== returns true if arrays are equal
bool operator==(const BitArray & a, const BitArray & b);

// operator!= returns true if arrays are not equal
bool operator!=(const BitArray & a, const BitArray & b);

// operator that does a bitwise AND between two BitArrays
BitArray operator&(const BitArray& b1, const BitArray& b2);

// operator that does a bitwise OR between two BitArrays
BitArray operator|(const BitArray& b1, const BitArray& b2);

// exclusive OR operator
BitArray operator^(const BitArray& b1, const BitArray& b2);


#endif //OOP_LAB1_BITARRAY_H
