#include "bits.h"
#include <exception>
using namespace std;
void Bitset::set_bit(int index)
{
	if (index >= size || index < 0)
	{
		throw exception("Invalid index");
		return;
	}
	bits |= (1 << index);
}
void Bitset::reset_bit(int index)
{
	if (index >= size||index<0)
	{
		throw exception("Invalid index");
		return;
	}
	bits &= ~(1 << index);
}
void Bitset::flip_bit(int index)
{
	if (index >= size || index < 0)
	{
		throw exception("Invalid index");
		return;
	}
	if (test_bit(index))
	{
		reset_bit(index);
	}
	else
	{
		set_bit(index);
	}
}
bool Bitset::test_bit(int index)const
{
	if (index >= size || index < 0)
	{
		throw exception("Invalid index");
	}
	return (bits & (1 << index)) != 0;
}
size_t Bitset::count()const
{
	int count = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (test_bit(i))
			++count;
	}
	return count;
}
void Bitset::print_bitset()const
{
	for (size_t i = 0; i < size; ++i)
	{
		bool bit = (bits & (1 << i))!=0;
		cout << bit;
	}
	cout << endl;
}
bool Bitset::operator[](int index)const
{
	if (index >= size || index < 0)
	{
		throw exception("Invalid index");
	}
	if (test_bit(index))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Bitset::any_bit()const
{
	bool temp = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (test_bit(i))
		{
			temp = true;
			break;
		}
	}
	return temp;
}
bool Bitset::none_bit()const
{
	bool temp = true;
	for (size_t i = 0; i < size; ++i)
	{
		if (test_bit(i))
		{
			temp = false;
			break;
		}
	}
	return temp;
}
bool Bitset::all_bits()const
{
	bool temp = true;
	for (size_t i = 0; i < size; ++i)
	{
		if (!test_bit(i))
		{
			temp = false;
			break;
		}
	}
	return temp;
}
unsigned int Bitset::operator~()
{
	return bits = ~bits;
}
unsigned int Bitset::operator|=(const Bitset& value)
{
	return bits = bits | value.bits;
}
unsigned int Bitset::operator &= (const Bitset& value)
{
	return bits = bits & value.bits;
}