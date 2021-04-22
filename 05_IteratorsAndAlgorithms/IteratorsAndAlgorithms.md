# Iterators and Algorithms

# Random Access Iterator: vector, deque, array

```
	std::vector<int>::iterator itr;
	itr = itr + 5;
	itr = itr - 4;
	std::vector<int>::iterator itr2;
	if(itr2 > itr)
		std::cout << "greater\n";
	++itr; // faster than itr++
	--itr;
```