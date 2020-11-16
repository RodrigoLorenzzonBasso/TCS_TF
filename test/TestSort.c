#include "unity.h"
#include "unity_fixture.h"

#include "../sort.h"

TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

TEST(Sort, TestSort1)
{
	int ar1[4] = {3,2,4,2};
	int ar2[4] = {3,2,4,1};
	int ar3[4] = {3,2,4,1};
	int ar4[4] = {3,2,4,1};
	int ar5[4] = {3,2,4,1};
	int ar6[4] = {3,2,4,1};
	int size = 4;
	int i = 0;
	
	selection_sort(ar1,size);
	insertion_sort(ar2,size);
	shell_sort(ar3,size);
	quick_sort(ar4,0,size-1);
	heap_sort(ar5,size);
	merge_sort(ar6,size);
	
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar1[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar2[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar3[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar4[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar5[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar6[i]);
}

TEST(Sort, TestSort2)
{
	int ar[] = {};
	int size = 0;
	
	selection_sort(ar,size);
	insertion_sort(ar,size);
	shell_sort(ar,size);
	quick_sort(ar,0,0);
	//heap_sort(ar,size);  // segmentation fault
	merge_sort(ar,size);
}

TEST(Sort, TestSort3)
{
    int ar1[4] = {4,3,2,1};
	int ar2[4] = {4,3,2,1};
	int ar3[4] = {4,3,2,1};
	int ar4[4] = {4,3,2,1};
	int ar5[4] = {4,3,2,1};
	int ar6[4] = {4,3,2,1};
	int size = 4;
	int i = 0;
	
	selection_sort(ar1,size);
	insertion_sort(ar2,size);
	shell_sort(ar3,size);
	quick_sort(ar4,0,size-1);
	heap_sort(ar5,size);
	merge_sort(ar6,size);
	
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar1[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar2[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar3[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar4[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar5[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar6[i]);
}

TEST(Sort, TestSort4)
{
    int ar1[4] = {1,2,3,4};
	int ar2[4] = {1,2,3,4};
	int ar3[4] = {1,2,3,4};
	int ar4[4] = {1,2,3,4};
	int ar5[4] = {1,2,3,4};
	int ar6[4] = {1,2,3,4};
	int size = 4;
	int i = 0;
	
	selection_sort(ar1,size);
	insertion_sort(ar2,size);
	shell_sort(ar3,size);
	quick_sort(ar4,0,size-1);
	heap_sort(ar5,size);
	merge_sort(ar6,size);
	
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar1[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar2[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar3[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar4[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar5[i]);
	for(i = 0; i < size; i++)
		TEST_ASSERT_EQUAL(i+1,ar6[i]);
}

TEST(Sort, TestSort5)
{
    int ar[1] = {5};
    int size = 1;
    
    selection_sort(ar,size);
	insertion_sort(ar,size);
	shell_sort(ar,size);
	quick_sort(ar,0,size-1);
	heap_sort(ar,size);
	merge_sort(ar,size);
	
	TEST_ASSERT_EQUAL(5,ar[0]);
	TEST_ASSERT_EQUAL(5,ar[0]);
	TEST_ASSERT_EQUAL(5,ar[0]);
	TEST_ASSERT_EQUAL(5,ar[0]);
	TEST_ASSERT_EQUAL(5,ar[0]);
	TEST_ASSERT_EQUAL(5,ar[0]);
}

TEST(Sort, TestSort6)
{
    int ar1[4] = {5,5,5,1};
	int ar2[4] = {5,5,5,1};
	int ar3[4] = {5,5,5,1};
	int ar4[4] = {5,5,5,1};
	int ar5[4] = {5,5,5,1};
	int ar6[4] = {5,5,5,1};
	int size = 4;
	int i = 0;
	
	selection_sort(ar1,size);
	insertion_sort(ar2,size);
	shell_sort(ar3,size);
	quick_sort(ar4,0,size-1);
	heap_sort(ar5,size);
	merge_sort(ar6,size);
	
	for(i = 0; i < size; i++)
	{
		if(i == 0)
			TEST_ASSERT_EQUAL(i+1,ar1[i]);
		else
			TEST_ASSERT_EQUAL(5,ar1[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i == 0)
			TEST_ASSERT_EQUAL(i+1,ar2[i]);
		else
			TEST_ASSERT_EQUAL(5,ar2[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i == 0)
			TEST_ASSERT_EQUAL(i+1,ar3[i]);
		else
			TEST_ASSERT_EQUAL(5,ar3[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i == 0)
			TEST_ASSERT_EQUAL(i+1,ar4[i]);
		else
			TEST_ASSERT_EQUAL(5,ar4[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i == 0)
			TEST_ASSERT_EQUAL(i+1,ar5[i]);
		else
			TEST_ASSERT_EQUAL(5,ar5[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i == 0)
			TEST_ASSERT_EQUAL(i+1,ar6[i]);
		else
			TEST_ASSERT_EQUAL(5,ar6[i]);
	}
}

TEST(Sort, TestSort7)
{
    int ar1[4] = {5,1,1,1};
	int ar2[4] = {5,1,1,1};
	int ar3[4] = {5,1,1,1};
	int ar4[4] = {5,1,1,1};
	int ar5[4] = {5,1,1,1};
	int ar6[4] = {5,1,1,1};
	int size = 4;
	int i = 0;
	
	selection_sort(ar1,size);
	insertion_sort(ar2,size);
	shell_sort(ar3,size);
	quick_sort(ar4,0,size-1);
	heap_sort(ar5,size);
	merge_sort(ar6,size);
	
	for(i = 0; i < size; i++)
	{
		if(i < 3)
			TEST_ASSERT_EQUAL(1,ar1[i]);
		else
			TEST_ASSERT_EQUAL(5,ar1[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i < 3)
			TEST_ASSERT_EQUAL(1,ar2[i]);
		else
			TEST_ASSERT_EQUAL(5,ar2[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i < 3)
			TEST_ASSERT_EQUAL(1,ar3[i]);
		else
			TEST_ASSERT_EQUAL(5,ar3[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i < 3)
			TEST_ASSERT_EQUAL(1,ar4[i]);
		else
			TEST_ASSERT_EQUAL(5,ar4[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i < 3)
			TEST_ASSERT_EQUAL(1,ar5[i]);
		else
			TEST_ASSERT_EQUAL(5,ar5[i]);
	}
		for(i = 0; i < size; i++)
	{
		if(i < 3)
			TEST_ASSERT_EQUAL(1,ar6[i]);
		else
			TEST_ASSERT_EQUAL(5,ar6[i]);
	}
	
}
