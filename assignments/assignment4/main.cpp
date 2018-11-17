// CPPList.cpp : 定义控制台应用程序的入口点。
//
// 实验内容：
// 1：使用Cpp语言实现一个链表；
// 2：要求能存放整形数据（之后可思考如何改写成适应任意类型的代码，不做要求，不做评分）；
// 3：所写程序需能通过测试程序
// 4: 注意，这里对链表的访问采用STL风格，以begin作为第一个元素，end前一个元素（而不是end）作为最后一个元素
//    即为有效元素区间为 [begin(), end())，“前闭后开”，【不包括】end

// 实验目的：
// 1：熟悉成员变量用法.
// 2：熟悉成员函数、包括构造函数，析构函数的写法
// 3：只提交List.cpp及List.h
// 5：实现时应正确管理内存
// 6：正确使用const

#include <assert.h>

#include <iostream>

#include "List.h"

using std::cout;
using std::endl;

// 一个似乎不起作用的函数，字面的意思是遍历并打印你的链表，但好像没有被调用，
// 不做要求，你可以先看后面。
// 但如果你想挑战，你可以尝试打开这个函数，看看要怎么样增加CPPList的功能，
// 才能在打开这段代码之后，能够编译通过？
// 如果你这样做了，你可以试着思索，为什么有ConstIterator的存在？
#if 1
void dump(const CPPList *list)
{
	// 注意，这里对链表的访问采用STL风格，以begin作为第一个元素，end前一个元素（而不是end）作为最后一个元素
	// 即为区间有效元素区间为 [begin(), end())，“前闭后开”，【不包括】end
	// 这里使用ConstIterator，迭代器本身不是常量，可++，指向内容是常量
	// 参考const int *ptr 与 int *const ptr;  
	for (CPPList::ConstIterator current = list->begin(); current != list->end(); ++current)
	{
		cout << *current << endl; 
	}
}
#endif

int main(int argc, char* argv[])
{
	cout << "70, for your hard work." << endl; 

	CPPList *list = new CPPList; 

	// List的迭代器类型
	CPPList::Iterator current; 
	int idx; 

	//////////////////////////////////////////////////////////////////////////
	int array[] = {1, 1, 2, 2, 3, 4, 4, 5, 6, 7, 8, 8, 8, 8, 9, 10};
	for (idx = 0; idx < sizeof(array) / sizeof(int); ++idx)
	{
		// 尾部依次追加array的每个元素，因此最终数据应与array相同
		list->push_back(array[idx]); 
	}
	assert(list->size() == sizeof(array) / sizeof(int)); 

	cout << "75, for append, size, constructor, etc." << endl;

	//////////////////////////////////////////////////////////////////////////
	// 访问list的有效节点，
	// 这些节点应从begin开始，到end结束，但【不包括】end本身
	for (idx = 0, current = list->begin(); current != list->end(); ++current, ++idx)
	{
		assert(*current == array[idx]); 
	}
	cout << "80, for interator methods, i.e. begin(), next(), and end()" << endl;
	//////////////////////////////////////////////////////////////////////////
	// 嗯，它没有作用，只是看看你的代码会不会出错
	// 想想为什么这里可以输入NULL，而后面需要输入迭代器？
	list->remove(NULL); 

	// 移除所有"1"s, "8"s, and "10"s
	// 并且用"5"替换所有"7"
	// 并且在所有"4"【前方】插入"3"
	// 你会不会疑惑这里为什么是while？别忘了for和while是可以相互替代的
	current = list->begin();
	while (current != list->end())
	{
		int data = *current; 
		if (data == 1 || data == 8 || data == 10)
		{
			// 你应该思考，这里为什么是current++，而不是++current; 
			// 或者，这句话能不能改成：list->remove(current); ++current; 
			list->remove(current++);
			continue;
		}
		else if (data == 7)
		{
			*current = 5;
		}
		else if (data == 4)
		{
			list->insert(current, 3); 
		}
		++current;
	}
	//////////////////////////////////////////////////////////////////////////
	// 执行以上过程后，数据应与以下数据相同
	int array2[] = {2, 2, 3, 3, 4, 3, 4, 5, 6, 5, 9};

	assert(list->size() == sizeof(array2) / sizeof(int));

	for (idx = 0, current = list->begin(); current != list->end(); ++current, ++idx)
	{
		assert(*current == array2[idx]); 
	}

	cout << "85, for method remove and data accessibility" << endl; 

	//////////////////////////////////////////////////////////////////////////
	// 清空list
	list->clear(); 

	//////////////////////////////////////////////////////////////////////////
	int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (idx = 0; idx < sizeof(array3) / sizeof(int); ++idx)
	{
		// 每次插入到begin，也即第一个数据的【前面】，因此，实际上是插入倒序的array3
		list->insert(list->begin(), array3[idx]); 
	}
	assert(list->size() == sizeof(array3) / sizeof(int)); 

	//////////////////////////////////////////////////////////////////////////
	for (idx = sizeof(array3) / sizeof(int) - 1, current = list->begin(); 
		current != list->end(); 
		++current, --idx)
	{
		assert(*current == array3[idx]); 
	}

	cout << "91, cheers, for your insert" << endl; 


	//////////////////////////////////////////////////////////////////////////
	list->clear(); 
	for (idx = 0; idx < sizeof(array3) / sizeof(int); ++idx)
	{
		// end不是最后一个元素，因此每次插入到end前，相当于依次在尾部追加array3的元素，因此与array3相同
		list->insert(list->end(), array3[idx]); 
	}
	assert(list->size() == sizeof(array3) / sizeof(int)); 
	for (idx = 0, current = list->begin(); current != list->end(); ++current, ++idx)
	{
		assert(*current == array3[idx]); 
	}

	cout << "93, for your insert again" << endl; 

	
	// 这里在考察什么？
	CPPList *anotherList = new CPPList(*list); 
	delete list;
	delete anotherList; 
	cout << "100, congratulations!" << endl; 

	// 现在，你可以去思考dump函数的问题了，如果你还有时间:-)
	return 0;
}

