#pragma once
#include <iostream>
class Bitset
{
private:
	unsigned int bits;
	size_t size;
	size_t calculatesize()const{ return sizeof bits * 8; }
public:
	Bitset() :bits(0) { size = calculatesize(); }
	Bitset(unsigned int value):bits(value){}
	void set_bit(int index);
	void reset_bit(int index);
	void flip_bit(int index);
	void print_bitset()const;
	bool test_bit(int index)const;
	bool operator[](int index)const;
	unsigned int operator~();
	unsigned int operator|=(const Bitset& value);
	unsigned int operator &= (const Bitset & value);
	bool any_bit()const;
	bool none_bit()const;
	bool all_bits()const;
	size_t count()const;
};
