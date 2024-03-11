#include "pch.h"
#include "CppUnitTest.h"
#include <exception>
#include "..\бітові множини\bits.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitTests
{
	TEST_CLASS(BitTests)
	{
	public:

		TEST_METHOD(TestingSetFunktion)
		{
			Bitset bits;
			bits.set_bit(1);
			bits.set_bit(2);
			bits.set_bit(3);
			bits.set_bit(4);
			Assert::IsTrue(bits.test_bit(1));
			Assert::IsTrue(bits.test_bit(2));
			Assert::IsTrue(bits.test_bit(3));
			Assert::IsTrue(bits.test_bit(4));
			Assert::ExpectException<std::exception>([]{Bitset a; a.set_bit(37); });
		}
		TEST_METHOD(TestingFlipFunction)
		{
			Bitset bits;
			bits.flip_bit(5);
			Assert::IsTrue(bits.test_bit(5));
			bits.flip_bit(5);
			Assert::IsFalse(bits[5]);
			Assert::ExpectException<std::exception>([] {Bitset a; a.flip_bit(678); });
		}
		TEST_METHOD(TestingAllFunction)
		{
			Bitset bits;
			for (size_t i = 0; i < 32; ++i)
			{
				bits.set_bit(i);
			}
			Assert::IsTrue(bits.all_bits());
			for (size_t i = 0; i < 32; ++i)
			{
				bits.reset_bit(i);
			}
			Assert::IsFalse(bits.all_bits());
		}
		TEST_METHOD(TestingCountFunction)
		{
			Bitset bits;
			Assert::AreEqual((size_t)0, bits.count());
			bits.set_bit(1);
			bits.set_bit(3);
			bits.set_bit(5);
			bits.set_bit(7);
			Assert::AreEqual((size_t)4, bits.count());
		}
		TEST_METHOD(TestingNoneFunction)
		{
			Bitset bits;
			Assert::IsTrue(bits.none_bit());
		}
		TEST_METHOD(TestingAnyFunction)
		{
			Bitset bits;
			Assert::IsFalse(bits.any_bit());
			bits.set_bit(1);
			Assert::IsTrue(bits.any_bit());
		}
		TEST_METHOD(TestingOperator)
		{
			Bitset bits;
			Assert::IsFalse(bits[2]);
			bits.set_bit(1);
			Assert::IsTrue(bits[1]);
			Assert::ExpectException<std::exception>([] {Bitset a; a.operator[](37); });
		}
		TEST_METHOD(TestingTestFunktion)
		{
			Bitset bits;
			Assert::AreEqual(bits[1], bits.test_bit(1));
			Assert::IsFalse(bits.test_bit(2));
			bits.set_bit(6);
			Assert::IsTrue(bits.test_bit(6));
			Assert::ExpectException<std::exception>([] {Bitset a; a.test_bit(67); });
		}
		TEST_METHOD(TestingResetFunction)
		{
			Bitset bits;
			bits.set_bit(2);
			bits.reset_bit(2);
			Assert::IsFalse(bits.test_bit(2));
			Assert::ExpectException<std::exception>([] {Bitset a; a.reset_bit(37); });
		}
		TEST_METHOD(TestingAnotherOperator)
		{
			Bitset bits;
			~bits;
			Assert::IsTrue(bits.all_bits());
		}
		TEST_METHOD(TedtingAND)
		{
			Bitset Mybits;
			~Mybits;
			Bitset AnotherBitset;
			Mybits &= AnotherBitset;
			Assert::IsTrue(Mybits.none_bit());
		}
		TEST_METHOD(TestingOR)
		{
			Bitset Mybits;
			Bitset AnotherBitset;
			~AnotherBitset;
			Mybits |= AnotherBitset;
			Assert::IsTrue(Mybits.all_bits());
		}
	};
}








