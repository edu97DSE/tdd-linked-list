/*!
 * @file
 * @brief Tests for Linked List module.
 */

extern "C"
{
#include "LinkedList.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "uassert_test.h"

TEST_GROUP(LinkedList)
{
   LinkedList_t instance;

   void setup()
   {

   }

   void teardown()
   {
   }
};

// TEST(LinkedList, MyFirstTest)
// {
//    FAIL("My first test is running!");
// }


TEST(LinkedList, EmptyAfterInit)
{
   LinkedList_Init(&instance);

   CHECK(0 == LinkedList_Count(&instance));
}

TEST(LinkedList, CountIncreasesAfterPushFront)
{
   LinkedListNode_t node;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);

   CHECK(1 == LinkedList_Count(&instance));
}

TEST(LinkedList, CountIncreasesAfterPushBack)
{
   LinkedListNode_t node;

   LinkedList_Init(&instance);
   LinkedList_PushBack(&instance, &node);

   CHECK(1 == LinkedList_Count(&instance));
}

TEST(LinkedList, PopBackRemovesAndReturnsTheLastElementInTheList)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   
   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushFront(&instance, &node2);
   CHECK(3 == LinkedList_Count(&instance));
   CHECK(&node == LinkedList_PopBackRemoves(&instance));
   CHECK(2 == LinkedList_Count(&instance));
}

TEST(LinkedList, PopFrontRemovesAndReturnsTheFirstElementInTheList)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   
   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushFront(&instance, &node2);
   CHECK(&node2 == LinkedList_PopFrontRemoves(&instance));
}

TEST(LinkedList, CountDecreasesWhenAnElementIsPoppedFromTheFrontOfAList)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   
   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushFront(&instance, &node2);
   CHECK(3 == LinkedList_Count(&instance));
   CHECK(&node2 == LinkedList_PopFrontRemoves(&instance));
   CHECK(2 == LinkedList_Count(&instance));
}

TEST(LinkedList, CountDecreasesWhenAnElementIsPoppedFromTheBackOfAList)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   
   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushBack(&instance, &node2);
   CHECK(3 == LinkedList_Count(&instance));
   CHECK(&node2 == LinkedList_PopBackRemoves(&instance));
   CHECK(2 == LinkedList_Count(&instance));
}

TEST(LinkedList, CountDecreasesWhenANodeIsRemoved)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   LinkedListNode_t node3;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushFront(&instance, &node2);
   LinkedList_PushFront(&instance, &node3);
   CHECK(4 == LinkedList_Count(&instance));
   LinkedList_RemoveNodeIfIsInList(&instance, &node2);
   CHECK(3 == LinkedList_Count(&instance));
}

TEST(LinkedList, CanRemoveNodeThatIsntInList)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   LinkedListNode_t node3;
   LinkedListNode_t node4;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushFront(&instance, &node2);
   LinkedList_PushFront(&instance, &node3);
   CHECK(4 == LinkedList_Count(&instance));
   LinkedList_RemoveNodeIfIsInList(&instance, &node4);
   CHECK(4 == LinkedList_Count(&instance));
}

TEST(LinkedList, CannotAddNodeThatIsAlreadyInTheList)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushBack(&instance, &node1);
   CHECK_ASSERTION_FAILED(LinkedList_PushFront(&instance, &node));
   CHECK_ASSERTION_FAILED(LinkedList_PushBack(&instance, &node1));
}

TEST(LinkedList, CountIsUpdatedCorrectlyAfterAddingMultipleNodes)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   LinkedListNode_t node3;
   LinkedListNode_t node4;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushBack(&instance, &node2);
   LinkedList_PushFront(&instance, &node3);
   LinkedList_PushBack(&instance, &node4);
   CHECK(5 == LinkedList_Count(&instance));
}

TEST(LinkedList, CanGetTheNodeAtAnIndex)
{
   LinkedListNode_t node;
   LinkedListNode_t node1;
   LinkedListNode_t node2;
   LinkedListNode_t node3;
   LinkedListNode_t node4;
   uint16_t index = 3;

   LinkedList_Init(&instance);
   LinkedList_PushFront(&instance, &node);
   LinkedList_PushFront(&instance, &node1);
   LinkedList_PushFront(&instance, &node2);
   LinkedList_PushFront(&instance, &node3);
   LinkedList_PushFront(&instance, &node4);
   CHECK(&node1 == LinkedList_GetTheNodeAtAnIndex(&instance, index)); 
}

