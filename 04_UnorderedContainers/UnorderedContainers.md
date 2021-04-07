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



