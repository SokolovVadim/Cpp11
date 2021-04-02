#include <iostream>

// STL headers

#include <vector>
#include <deque>
#include <list>
#include <array>
#include <algorithm>

std::vector<int> test_vector();
void test_containers(std::vector<int>& vec);
void test_deque();
void test_list();
void test_array();

int main()
{
	// std::vector<int> vec = test_vector();
	// test_containers(vec);*/
	// test_deque();
	// test_list();
	test_array();
	return 0;
}

std::vector<int> test_vector()
{
	std::vector<int> vec; // vec.size() == 0
	std::cout << vec.size() << std::endl;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);
	std::cout << vec.size() << std::endl;

	// Vector specific operations

	std::cout << vec[2] << std::endl;    // no range check
	std::cout << vec.at(2) << std::endl; // throws range_error exception of out of range

	// Traversal

	for(int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	// faster and universal way of traversing
	for(std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;

	// cpp11
	for(auto it: vec)
		std::cout << it << " ";
	std::cout << std::endl;

	int* ptr = &vec[0];
	ptr[2] = 6;

	for(auto it: vec)
		std::cout << it << " ";
	std::cout << std::endl;
	return vec;
}

void test_containers(std::vector<int>& vec)
{
	// common member functions of all containers
	if(!vec.empty())
		std::cout << "vector is not empty\n";
	std::cout << "size: " << vec.size() << std::endl;

	// copy constructor
	std::vector<int> vecCopy(vec);
	std::cout << "copy size: " << vecCopy.size() << std::endl;

	// remove all items in vec, size == 0
	vec.clear();
	std::cout << "size after clear(): " << vec.size() << std::endl;
	// vecCopy becomes empty, vec.size() == 3
	vecCopy.swap(vec);

	std::cout << "after swap:\nvec: ";
	for(auto it: vec)
		std::cout << it << " ";

	std::cout << "\nvecCopy: ";
	for(auto it: vecCopy)
		std::cout << it << " ";
	std::cout << std::endl;
}

void test_deque()
{
	std::deque<int> deq = {31, 12, 1999};

	for(auto it: deq)
		std::cout << it << " ";
	std::cout << std::endl;

	deq.push_front(1);
	deq.push_back(2);

	for(auto it: deq)
		std::cout << it << " ";
	std::cout << std::endl;

	std::cout << deq[2] << std::endl;
}

void test_list()
{
	std::list<int> myList = {9, 1, 1};
	myList.push_back(12);
	myList.push_front(3);

	for(auto it: myList)
		std::cout << it << " ";
	std::cout << std::endl;

	std::list<int>::iterator itr = std::find(myList.begin(), myList.end(), 9);
	std::cout << "value " << *itr << std::endl;

	myList.insert(itr, 8);

	std::cout << "after insert:\n";
	for(auto it: myList)
		std::cout << it << " ";
	std::cout << std::endl;

	itr++;
	myList.erase(itr);

	std::cout << "after erase:\n";
	for(auto it: myList)
		std::cout << it << " ";
	std::cout << std::endl;

	itr = myList.begin();
	itr++;

	std::list<int> listSplice;
	listSplice.splice(listSplice.begin(), myList, itr, myList.end());
	std::cout << "after splice:\nmyList: ";
	for(auto it: myList)
		std::cout << it << " ";
	std::cout << "\nlistSplice: ";

	for(auto it: listSplice)
		std::cout << it << " ";
	std::cout << "\n";
}

void test_array()
{
	std::array<int, 3> arr = {3, 4, 5};
	std::array<int, 3>::iterator itr = arr.begin();
	std::cout << "begin: " << *itr << std::endl;

	itr = arr.end();
	itr--;
	std::cout << "end: " << *itr << std::endl;

	std::cout << "size: " << arr.size() << std::endl;
	if(!arr.empty())
		std::cout << "array is not empty!\n";
}
