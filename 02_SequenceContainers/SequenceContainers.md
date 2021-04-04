# Sequence Containers

## Sequence Containers (Array and Linked List)

 - vector
 - deque
 - list
 - forward list
 - array

## Associative Containers (binary tree)

 - set, multiset
 - map, multimap

## Unordered Containers (hash table)

 - Unordered set / multiset
 - Unordered map / multimap

### STL Headers

```
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
```

## Vector

[][][][][]->

Vector is a dynamicly allocated contiguous array that grows in one direction in memory  

```
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
```

The output is:  

```
0
3
8
8
4 1 8 
4 1 8 
4 1 8 
4 1 6 
```

### Common functions for all the STL containers

```
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
```

The output is:  

```
vector is not empty
size: 3
copy size: 3
size after clear(): 0
after swap:
vec: 4 1 6 
vecCopy: 
```

No penalty of abstraction, very efficient  

Properties of Vector:
1. fast insert/remove at the end O(1)
2. slow insert/remove at the beginning or in the middle: O(n)
3. slow search: O(n)

## Deque

<- [][][][][][] ->  

```
	std::deque<int> deq = {31, 12, 1999};

	for(auto it: deq)
		std::cout << it << " ";
	std::cout << std::endl;

	deq.push_front(1);
	deq.push_back(2);

	for(auto it: deq)
		std::cout << it << " ";
	std::cout << std::endl;
```

The output is:  

```
31 12 1999 
1 31 12 1999 2
12
```

Properties of deque:  

1. fast insert/remove at the beginning and at the end
2. slow insert/remove in the middle: O(n)
3. slow search: O(n)

## List

[]->[]->[]->[]  
[]<-[]<-[]<-[]

```
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
```

The output is:  

```
3 9 1 1 12 
value 9
after insert:
3 8 9 1 1 12 
after erase:
3 8 9 1 12 
```

Properties of list:  

1. fast insert/remove at any place: O(1)
2. slow search: O(n)
3. no random access, no [] operator.

Search is slower than vector because of locality of vector and more cache hits.

Splice is a very useful operation!

```
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
```

The output is:

```
after splice:
myList: 3 
listSplice: 8 9 1 12 
```

## Forward List

[]->[]->[]->[]

Only one link between leafs

## Array

Limitations of Array:  

1. size can not be changed
2. two arrays of integers may be arrays of different type

```
	std::array<int, 3> arr = {3, 4, 5};
	std::array<int, 3>::iterator itr = arr.begin();
	std::cout << "begin: " << *itr << std::endl;

	itr = arr.end();
	itr--;
	std::cout << "end: " << *itr << std::endl;

	std::cout << "size: " << arr.size() << std::endl;
	if(!arr.empty())
		std::cout << "array is not empty!\n";
```

The output:  

```
begin: 3
end: 5
size: 3
array is not empty!
```
