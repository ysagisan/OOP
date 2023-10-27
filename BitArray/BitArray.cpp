#include "BitArray.h"
#include <iostream>
#include <string>
#include <cmath>

// create constructor
BitArray::BitArray(int num_bits, unsigned long value){
    int len = 0;
    unsigned long check_len_value = value;

    while(check_len_value) {
        check_len_value >>= 1;
        len++;
    }
    if (num_bits < len) {
        std::cout << "The length of the array is less than the length of the bit representation of the number";
        std::exit(1);
    }

    this->SizeOfArray = num_bits;
    this->bits = new bool[SizeOfArray];

    for (int i = 0; i < num_bits; i++) {
        this->bits[num_bits - i - 1] = (value & (1UL << i)) != 0;
    }
}

// create copy constructor
BitArray::BitArray(const BitArray& mass) {
    this->SizeOfArray = mass.SizeOfArray;
    this->bits = new bool[SizeOfArray];

    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] = mass.bits[i];
    }
}

// create destructor
BitArray::~BitArray() {
    delete[] bits;
}

// function for print our array
void BitArray::PrintBitArray() {
    for (int i = 0; i < SizeOfArray; i++) {
        std::cout << bits[i] << "   ";
    }
}

// function for swapping two arrays
void BitArray::swap(BitArray& mass) {
    std::swap(this->SizeOfArray, mass.SizeOfArray);
    std::swap(this->bits, mass.bits);
}

// operator =
BitArray &BitArray::operator = (const BitArray& mass){
    this->SizeOfArray = mass.SizeOfArray;

    this->bits = new bool[mass.SizeOfArray];

    for (int i = 0; i <= mass.SizeOfArray; i++) {
        this->bits[i] = mass.bits[i];
    }

    return *this;
}

// Changes the size of the array. In the case of expansion, new elements are initialized with value.
void BitArray::resize(int num_bits, bool value) {
    bool* newBits = new bool[this->SizeOfArray + num_bits];

    if (num_bits > this->SizeOfArray) {
        for (int i = 0; i < SizeOfArray; i++) {
            newBits[i] = this->bits[i];
        }

        for (int i = SizeOfArray; i < SizeOfArray + (num_bits - SizeOfArray); i++) {
            newBits[i] = value;
        }

        delete[] this->bits;

        this->bits = newBits;
        this->SizeOfArray += (num_bits - SizeOfArray);
    }
    else {
        for (int i = 0; i < num_bits; i++) {
            newBits[i] = this->bits[i];
        }

        delete[] this->bits;

        this->bits = newBits;
        this->SizeOfArray = num_bits;
    }
}

// Array clear function
void BitArray::clear() {
    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] = false;
    }
}

//function to add a new bit to the end of the array
void BitArray::push_back(bool bit) {
    bool* newBits = new bool[this->SizeOfArray + 1];

    for (int i = 0; i < this->SizeOfArray; i++) {
        newBits[i] = this->bits[i];
    }
    newBits[this->SizeOfArray] = bit;
    delete[] this->bits;
    this->bits = newBits;
    this->SizeOfArray++;
}

// operator and
BitArray& BitArray::operator &= (const BitArray& mass) {
    if (this->SizeOfArray != mass.SizeOfArray) {
        std::cout << "You entered arrays of different lengths" << std::endl;
        return *this;
    }

    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] &= mass.bits[i];
    }
    return *this;
}

// operator or
BitArray& BitArray::operator |= (const BitArray& mass) {
    if (this->SizeOfArray != mass.SizeOfArray) {
        std::cout << "You entered arrays of different lengths" << std::endl;
        return *this;
    }

    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] |= mass.bits[i];
    }
    return *this;
}

// operator exclusive or
BitArray& BitArray::operator ^= (const BitArray& mass) {
    if (this->SizeOfArray != mass.SizeOfArray) {
        std::cout << "You entered arrays of different lengths" << std::endl;
        return *this;
    }

    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] ^= mass.bits[i];
    }
    return *this;
}

// operator >>
BitArray& BitArray::operator >>= (int n) {
    bool* newBits = new bool[SizeOfArray + n];

    if (n <= 0) {
        return *this;
    }

    for (int i = 0; i < n; i++) {
        newBits[i] = false;
    }

    for (int i = 0; i < this->SizeOfArray; i++) {
        newBits[i + n] = this->bits[i];
    }

    delete[] this->bits;
    this->bits = newBits;

    return *this;
}

// operator <<
BitArray& BitArray::operator<<=(int n) {
    bool* newBits = new bool[SizeOfArray - n];

    if (n <= 0) {
        return *this;
    }

    for (int i = 0; i < SizeOfArray; i++) {
        newBits[i] = false;
    }

    for (int i = n; i < SizeOfArray; i++) {
        newBits[i - n] = this->bits[i];
    }
    delete[] this->bits;
    this->bits = newBits;

    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray result(    this->SizeOfArray);

    for (int i = 0; i < this->SizeOfArray; i++) {
        result.bits[i] = this->bits[i + n];
    }

    return result;
}

BitArray BitArray::operator>>(int n) const {
    BitArray result(    this->SizeOfArray);

    for (int i = 0; i < this->SizeOfArray; i++) {
        result.bits[i + n] = this->bits[i];
    }

    return result;
}

// Inserts the value val at index n
BitArray& BitArray::set(int n, bool val) {
    this->bits[n] = val;

    return *this;
}

// Fills the array with true
BitArray& BitArray::set() {
    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] = true;
    }

    return *this;
}

// Sets the bit with index n to false
BitArray& BitArray::reset(int n) {
    this->bits[n] = false;

    return *this;
}

// Fills the array with false
BitArray& BitArray::reset() {
    for (int i = 0; i < SizeOfArray; i++) {
        this->bits[i] = false;
    }

    return *this;
}

// true if the array contains a true bit
bool BitArray::any() const {
    for (int i = 0; i < this->SizeOfArray; i++) {
        if (this->bits[i]) {
            return true;
        }
    }
    return false;
}

// true if all bits of the array are false
bool BitArray::none() const {
    for (int i = 0; i < this->SizeOfArray; i++) {
        if (this->bits[i]) {
            return false;
        }
    }
    return true;
}

// bits inversion
BitArray BitArray::operator~() const  {
    for (int i = 0; i < this->SizeOfArray; i++) {
        if (this->bits[i]) {
            this->bits[i] = false;
        }
        else {
            this->bits[i] = true;
        }
    }
    return *this;
}

// counter of true bits
int BitArray::count() const {
    int cnt = 0;

    for (int i = 0; i < this->SizeOfArray; i++) {
        if (this->bits[i]) {
            cnt++;
        }
    }
    return cnt;
}

// outputs the bit at index i
bool BitArray::operator[](int i) const {
    return this->bits[i];
}

// returns the size of the array
int BitArray::size() const {
    return this->SizeOfArray;
}

// returns true if the array is empty
bool BitArray::empty() const {
    for (int i = 0; i < this->SizeOfArray; i++) {
        if (this->bits[i]) {
            return false;
        }
    }
    return true;
}

// Returns a string representation of the array
std::string BitArray::to_string() const {
    std::string result;

    for (int i = 0; i < this->SizeOfArray; i++) {
        if (this->bits[i]) {
            result += '1';
        }
        else {
            result += '0';
        }
    }
    return result;
}

// operator== returns true if arrays are equal
bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// operator!= returns true if arrays are not equal
bool operator!=(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return true;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return true;
        }
    }
    return false;
}

// operator that does a bitwise AND between two BitArrays
BitArray operator&(const BitArray& b1, const BitArray& b2) {
    int size = std::max(b1.size(), b2.size());
    int min_size = std::min(b1.size(), b2.size());

    unsigned long newValue = 0;
    bool* mass = new bool[size];

    for (int i = 0; i < min_size; i++) {
        if (b1.size() == b2.size()) {
            mass[i] = b1[i];
        }
        else if (b1.size() < b2.size()) {
            mass[i + (size - min_size)] = b1[i];
        }
        else {
            mass[i + (size - min_size)] = b2[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (b1.size() == b2.size()) {
            mass[i] &= b2[i];
        }
        else if (b1.size() < b2.size()) {
            mass[i] &= b2[i];
        }
        else {
            mass[i] &= b1[i];
        }
    }

    for (int i = 0; i < size; i++) {
        newValue += mass[i] * pow(2, size - i - 1);
    }

    BitArray NewArr(size, newValue);

    return NewArr;
}

// operator that does a bitwise OR between two BitArrays
BitArray operator|(const BitArray& b1, const BitArray& b2) {
    int size = std::max(b1.size(), b2.size());
    int min_size = std::min(b1.size(), b2.size());

    unsigned long newValue = 0;
    bool* mass = new bool[size];

    for (int i = 0; i < min_size; i++) {
        if (b1.size() == b2.size()) {
            mass[i] = b1[i];
        }
        else if (b1.size() < b2.size()) {
            mass[i + (size - min_size)] = b1[i];
        }
        else {
            mass[i + (size - min_size)] = b2[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (b1.size() == b2.size()) {
            mass[i] |= b2[i];
        }
        else if (b1.size() < b2.size()) {
            mass[i] |= b2[i];
        }
        else {
            mass[i] |= b1[i];
        }
    }

    for (int i = 0; i < size; i++) {
        newValue += mass[i] * pow(2, size - i - 1);
    }

    BitArray NewArr(size, newValue);

    return NewArr;
}

// exclusive OR operator
BitArray operator^(const BitArray& b1, const BitArray& b2) {
    int size = std::max(b1.size(), b2.size());
    int min_size = std::min(b1.size(), b2.size());

    unsigned long newValue = 0;
    bool* mass = new bool[size];

    for (int i = 0; i < min_size; i++) {
        if (b1.size() == b2.size()) {
            mass[i] = b1[i];
        }
        else if (b1.size() < b2.size()) {
            mass[i + (size - min_size)] = b1[i];
        }
        else {
            mass[i + (size - min_size)] = b2[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (b1.size() == b2.size()) {
            mass[i] ^= b2[i];
        }
        else if (b1.size() < b2.size()) {
            mass[i] ^= b2[i];
        }
        else {
            mass[i] ^= b1[i];
        }
    }

    for (int i = 0; i < size; i++) {
        newValue += mass[i] * pow(2, size - i - 1);
    }

    BitArray NewArr(size, newValue);

    return NewArr;
}

