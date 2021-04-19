# Unordered Containers

The order of the elements is not defined and they may change over the time. 

### Unordered Set 

Hash table - array of linked lists. Buckets and entries.  

[] -> Hash function -> Buckets -> Entries  

Lookup and insert take O(1) time if the hash function is fast enough.  

```
	std::unordered_set<std::string> mySet = {"red", "green", "blue"};
	std::unordered_set<std::string>::const_iterator itr = mySet.find("green"); // O(1)
	if(itr != mySet.end()) // Important check
		std::cout << "Elem found: " << *itr << std::endl;

	mySet.insert("yellow"); // O(1)

	std::vector<std::string> vec = {"purple", "pink"};
	mySet.insert(vec.begin(), vec.end());

	// Hash table specific APIs:

	std::cout << "load_factor = " << mySet.load_factor() << std::endl;
	std::string colour = "red";
	std::cout << colour << " is in bucket " << mySet.bucket(colour) << std::endl;
	std::cout << "Total buckets " << mySet.bucket_count() << std::endl;
```

`Load_factor = total_elem_num / total_bucket_num`  

The output is:  

```
Elem found: green
load_factor = 0.545455
red is in bucket 5
Total buckets 11
```

### Other containers

1. Unordered myltiset: unordered set that allows duplicated elements.  
2. Unordered map: unordered set of pairs.  
3. Unordered multimap: unordered map that allows duplicated keys.

### Hash collision

Hash collision leads to a performance degradation. For instance, in the worst case all the elements are inserted into one bucket. The performance of searching degrates to O(n).

### Properties of Unordered Containers

1. Fastest `search/insert` at any place: O(1)  
- Associative containers take O(log(n))  
- vector, deque take O(n)  
- list takes O(1) to `insert`, O(n) to `search`  
2. Unordered set/multiset: element value can not be changed  
- Unordered map/multimap: element key can not be changed. Because it can corrupt the data structure.  

### Associative array - map and unordered map

```
	std::unordered_map<char, std::string> day = {{'S', "Sunday"}, {'M', "Monday"}};
	std::cout << day['S'] << std::endl;    // No range check
	std::cout << day.at('M') << std::endl; // Has range check

	std::vector<int> vec = {1, 2, 3};
	vec[5] = 5; // error

	day['W'] = "Wednesday"; // Inserting {'W', "Wednesday"}
	day.insert(std::make_pair('F', "Friday")); // Inserting {'F', "Friday"}

	std::pair<std::unordered_map<char, std::string>::iterator, bool> ret;
	ret = day.insert(std::make_pair('M', "MONDAY")); // fail to modify
	if(ret.second == false)
	{
		std::cout << "insert failed!\n";
	}

	std::cout << day['M'] << std::endl;
	day['M'] = "MONDAY";
	std::cout << day['M'] << std::endl;
```

The output is:  

```
Sunday
Monday
insert failed!
Monday
MONDAY
```

The subscriiption `operator[]` provides a write access to the container.  

```
void foo(const std::unordered_map<char, std::string>& m)
{
	// m['S'] = "Sunday";
	// std::cout << m['S'] << std::endl;
	auto itr = m.find('S');
	if(itr != m.end())
		std::cout << itr->second << std::endl;
}

// .......

	foo(day);
```

m has a `const` qualifier so it can not use `operator[]`  

### Notes about assosiative array  

1. Search time: unordered_map, O(1); map, O(log(n))  
2. Unordered_map may degrade to O(n)  
3. Can not use multimap and unordered_multimap, they do not have `operator[]`  

### Container Adaptor

- Provide a restricted interface to meet special needs  
- Implemented with fundamental container classes  

1. stack: LIFO, push(), pop(), top()  
2. queue: FIFO, push(), pop(), front(), back()  
3. priority queue: first item always has the greatest priority, push(), pop(), top()  

### Another way of categorizing containers:

1. Array based containers: vector, deque  
2. Node base containers: list + associative containers + unordered containers  

Array based containers invalidate pointers:  
- Native pointers, iterators, references

```
	std::vector<int> vec = {1, 2, 3, 4};
	int* p = &vec[2]; // points to 3
	vec.insert(vec.begin(), 0);
	std::cout << *p << std::endl; // ?
```

The last string leads to undefined behaviour.
