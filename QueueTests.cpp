#include "pch.h"
#include "CppUnitTest.h"
#include "..\черга\queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
	TEST_CLASS(QueueTests)
	{
	public:
		TEST_METHOD(TestingPush)
		{
			Queue MyQueue;
			MyQueue.push(2);
			MyQueue.push(1);
			MyQueue.push(6);
			MyQueue.push(9);
			Assert::AreEqual(2, MyQueue.front());
			Assert::AreEqual(9, MyQueue.back());
		}
		TEST_METHOD(TestingPop)
		{
			Queue MyQueue;
			Assert::ExpectException<std::exception>([] {Queue queue; queue.pop(); });
			MyQueue.push(2);
			MyQueue.push(1);
			MyQueue.push(3);
			MyQueue.pop();
			Assert::AreEqual(1, MyQueue.front());
			MyQueue.pop();
			MyQueue.pop();
			Assert::IsTrue(MyQueue.isEmpty());
		}
		TEST_METHOD(TestingSwap)
		{
			Queue MyQueue;
			MyQueue.push(2);
			MyQueue.push(1);
			MyQueue.push(3);
			Queue OtherQueue;
			OtherQueue.push(7);
			OtherQueue.push(8);
			OtherQueue.push(9);
			MyQueue.swap(OtherQueue);
			Assert::AreEqual(7, MyQueue.front());
			Assert::AreEqual(9, MyQueue.back());
			Assert::AreEqual(2, OtherQueue.front());
			Assert::AreEqual(3, OtherQueue.back());

			PriorityQueue Queue;
			Queue.enqueue(6, 2);
			PriorityQueue Other;
			Other.enqueue(3, 1);
			Queue.swap(Other);
			Assert::AreEqual(3, Queue.front());
			Assert::AreEqual(6, Other.front());
		}
		TEST_METHOD(TestingMakeEmpty)
		{
			Queue MyQueue;
			MyQueue.push(2);
			MyQueue.push(1);
			MyQueue.push(3);
			MyQueue.makeEmpty();
			Assert::IsTrue(MyQueue.isEmpty());
		}
		TEST_METHOD(TestingIsEmpty)
		{
			Queue MyQueue;
			Assert::IsTrue(MyQueue.isEmpty());
			MyQueue.push(2);
			Assert::IsFalse(MyQueue.isEmpty());

			PriorityQueue PQueue;
			Assert::IsTrue(PQueue.isEmpty());
			PQueue.enqueue(56, 1);
			Assert::IsFalse(PQueue.isEmpty());
		}
		TEST_METHOD(TestingFront)
		{
			Queue MyQueue;
			Assert::ExpectException<std::exception>([] {Queue Q; Q.front(); });
			MyQueue.push(29);
			MyQueue.push(14);
			MyQueue.push(32);
			Assert::AreEqual(29, MyQueue.front());

			PriorityQueue PQueue;
			Assert::ExpectException<std::exception>([] {PriorityQueue Q; Q.front(); });
			PQueue.enqueue(71, 3);
			PQueue.enqueue(66, 2);
			PQueue.enqueue(90, 4);
			PQueue.enqueue(23, 1);
			Assert::AreEqual(23, PQueue.front());
		}
		TEST_METHOD(TestingBack)
		{
			Queue MyQueue;
			Assert::ExpectException<std::exception>([] {Queue Q; Q.back(); });
			MyQueue.push(98);
			MyQueue.push(50);
			MyQueue.push(12);
			Assert::AreEqual(12, MyQueue.back());

			PriorityQueue PQueue;
			Assert::ExpectException<std::exception>([] {PriorityQueue Q; Q.Back(); });
			PQueue.enqueue(71, 3);
			PQueue.enqueue(66, 2);
			PQueue.enqueue(90, 4);
			PQueue.enqueue(23, 1);
			Assert::AreEqual(90, PQueue.Back());
		}
		TEST_METHOD(TestingSize)
		{
			Queue MyQueue;
			Assert::AreEqual((size_t)0, MyQueue.size());
			MyQueue.push(14);
			MyQueue.push(67);
			MyQueue.push(88);
			Assert::AreEqual((size_t)3, MyQueue.size());

			PriorityQueue PQueue;
			Assert::AreEqual((size_t)0, PQueue.size());
			PQueue.enqueue(71, 3);
			PQueue.enqueue(66, 2);
			PQueue.enqueue(90, 4);
			PQueue.enqueue(23, 1);
			Assert::AreEqual((size_t)4, PQueue.size());
		}
		TEST_METHOD(TestingOperator)
		{
			Queue MyQueue;
			Queue OtherQueue;
			OtherQueue.push(70);
			OtherQueue.push(80);
			OtherQueue.push(90);
			MyQueue = OtherQueue;
			Assert::AreEqual(70, MyQueue.front());
			Assert::AreEqual(90, MyQueue.back());
			MyQueue.pop();
			Assert::AreEqual(80, MyQueue.front());
		}
		TEST_METHOD(TestingClear)
		{
			PriorityQueue MyQueue;
			MyQueue.enqueue(71, 3);
			MyQueue.enqueue(66, 2);
			MyQueue.enqueue(90, 4);
			MyQueue.enqueue(23, 1);
			MyQueue.clear();
			Assert::IsTrue(MyQueue.isEmpty());
		}
		TEST_METHOD(TestingEnqueue)
		{
			PriorityQueue MyQueue;
			MyQueue.enqueue(71, 3);
			MyQueue.enqueue(66, 2);
			MyQueue.enqueue(90, 4);
			MyQueue.enqueue(23, 1);
			Assert::AreEqual(23, MyQueue.front());
			Assert::AreEqual(90, MyQueue.Back());
		}
		TEST_METHOD(TestingDequeue)
		{
			PriorityQueue MyQueue;
			Assert::ExpectException<std::exception>([] {PriorityQueue Q; Q.dequeue(); });
			MyQueue.enqueue(71, 3);
			MyQueue.enqueue(66, 2);
			MyQueue.enqueue(90, 4);
			MyQueue.enqueue(23, 1);
			MyQueue.dequeue();
			Assert::AreEqual(66, MyQueue.front());
			MyQueue.dequeue();
			Assert::AreEqual(71, MyQueue.front());
			MyQueue.dequeue();
			Assert::AreEqual(90, MyQueue.front());
		}

	};
}
