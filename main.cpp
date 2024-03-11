#include <iostream>
#include "bits.h"
using namespace std;
int main()
{
	Bitset bits;
	cout << "Our bitset now: ";
	bits.print_bitset();
	cout << "Trying to set bits: " << endl;
	try
	{
		bits.set_bit(2);
		bits.set_bit(4);
		bits.set_bit(5);
		bits.set_bit(6);
		bits.set_bit(-678);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Bitset after seting bits: ";
	bits.print_bitset();
	try
	{
		bits.reset_bit(5);
		bits.reset_bit(6);
		bits.reset_bit(-89);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Bitset afyer reseting bits: "; bits.print_bitset();
	try
	{
		bits.flip_bit(11);
		bits.flip_bit(12);
		bits.flip_bit(111);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Bitset after fliping bits: "; bits.print_bitset();
	try
	{
		cout << "Index 12: " << bits[12] << endl;
		cout << "Index 11: " << bits[11] << endl;
		cout << bits[77] << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "Check if all elements set(0 - not, 1 - yes): " << bits.all_bits() << endl;
	cout << "Check if any element set(0 - not, 1 - yes): " << bits.any_bit() << endl;
	cout << "Check if none element set(0 - not, 1 - yes): " << bits.none_bit() << endl;
	cout << "Count: " << bits.count() << endl;
	cout << "Testing 1 bit: " << bits.test_bit(1) << endl;
	cout << "Testing 2 bit: " << bits.test_bit(2) << endl;
	cout << "Testing 7 bit: " << bits.test_bit(7) << endl;
	Bitset testing;
	testing.set_bit(31);
	bits |= testing;
	cout << "Using |= : "; bits.print_bitset();
	~bits;
	cout << "Using ~ : "; bits.print_bitset();
	bits &= testing;
	cout << "Using &= : "; bits.print_bitset();
	return 0;
}