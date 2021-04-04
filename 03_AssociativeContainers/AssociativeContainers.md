# Associative Containers

Associative Containers are always sorted with default criteria `<` (less than)  

No `push_back()`, `push_front()`

### Set

No duplicates

```
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T> mySet)
{
	for(auto itr: mySet)
		os << itr << " ";
	os << std::endl;
	return os;
}

void test_set()
{
	std::set<int> mySet;
	mySet.insert(2);
	mySet.insert(1);
	mySet.insert(9);
	mySet.insert(6);

	std::cout << mySet;
}
```

The output is:  

```
1 2 6 9
```

```
	// find
	std::set<int>::iterator itr;
	itr = mySet.find(9); // O(log(n))
	std::cout << "elem found: " << *itr << std::endl;

	// insert
	std::pair<std::set<int>::iterator, bool> ret;
	ret = mySet.insert(4);
	if(ret.second == false)
		itr = ret.first;
	std::cout << "*itr: " << *itr << std::endl;

	ret = mySet.insert(1);
	if(ret.second == false)
		itr = ret.first;
	std::cout << "elem inserted: " << *itr << std::endl;

	mySet.insert(itr, 12); // O(log(n)) -> O(1)
	std::cout << mySet;
```

The output is:  

```
elem found: 9
*itr: 9
elem inserted: 1
1 2 4 6 9 12
```

Insertion always takes `O(log(n))` time  
`find()` takes O(log(n)) time

```
	std::cout << mySet;
	mySet.erase(itr);
	std::cout << mySet;
	mySet.erase(4);
	std::cout << mySet;
```

The output is:  

```
1 2 4 6 9 12 
2 4 6 9 12 
2 6 9 12
```

Erase also benefits from logarithmic time searching of Associative Containers. None of the sequence containers canprovide this kind of erase.

### Multiset

Multiset allows to duplicate items. Insertion in Multiset is always successful.  

```
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::multiset<T> mySet)
{
	for(auto itr: mySet)
		os << itr << " ";
	os << std::endl;
	return os;
}

void test_multiset()
{
	std::multiset<int> mySet;
	mySet.insert(10);
	mySet.insert(1);
	mySet.insert(14);
	mySet.insert(4);
	mySet.insert(1);
	std::cout << mySet;
}
```

The output is:  

```
1 1 4 10 14
```

Value of the elements can not be modified for both `set` and `multiset` because it may corrupt the data structure.  

```
	std::multiset<int>::iterator itr;
	itr = mySet.find(4);
	*itr = 12;
```

The output is:  

```
 error: assignment of read-only location ‘itr.std::_Rb_tree_const_iterator<int>::operator*()’
  *itr = 12;
```

Properties:  

1. Fast search: O(log(n)).  
2. Traversing is slow compared to vector and deque (starvation of locality like list).  
3. No random access, no [] operator.  

### Map

Key-value data structure

```
	std::map<char, int> myMap;
	myMap.insert(std::pair<char, int>('a', 100));
	myMap.insert(std::make_pair('f', 200));

	std::cout << myMap;
```

The output is:

```
{a, 100} {f, 200}
```

`insert` and `find`   

```
	// insert
	std::map<char, int>::iterator it = myMap.begin();
	myMap.insert(it, std::make_pair('b', 300)); // it is a hint
	std::cout << myMap;

	it = myMap.find('f'); // O(log(n))
```

Showing contents:  

```
template<typename T, typename P>
std::ostream& operator<<(std::ostream& os, const std::map<T, P> myMap)
{
	for(auto itr: myMap)
		os << "{" << itr.first << ", " << itr.second << "} ";
	os << std::endl;
	return os;
}
```

### Multimap

Multimap allows duplicated keys

```
	std::multimap<char, int> myMap;
	myMap.insert(std::make_pair('g', 1233));
	myMap.insert(std::make_pair('f', 6537));
	myMap.insert(std::make_pair('a', 6587));
	myMap.insert(std::make_pair('m', 1234));
	myMap.insert(std::make_pair('f', 1234));

	std::cout << myMap;
```

The output is:  

```
{a, 6587} {f, 6537} {f, 1234} {g, 1233} {m, 1234}
```

Keys can not be modified: type of `*it`: `std::pair<const char, int>`

```
	std::multimap<char, int>::iterator it = myMap.find('g');
	std::cout << "elem found: {" << it->first << ", " << it->second << "}" << std::endl;
	it->first = 'd';
```

The output is:  

```
 error: assignment of read-only member ‘std::pair<const char, int>::first’
  it->first = 'd';
```

### Understanding Associative

In `map` the value is associated with key. `set` can be treated as a `map` with the same key as an element's value. 
