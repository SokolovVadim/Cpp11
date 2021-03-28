# STL Overview

N algorithms + M containers = N * M implementations  

### Iterators

Algorithms -> Iterators -> Containers  

N algorithms + M containers = N + M implementations  
It allows to make a code easily extendable.

##### Vector:

`vec.begin()` points out to the vec[0],   
`vec.end()`   points out to one spot after the last element of the vector. The folowing example will cause undefined behaviour.

```
std::cout << *vec.end() << std::endl;
```

##### Container, Iterator and Algorithm Example

```
int main()
{
	std::vector<int> vec{};

	vec.push_back(10);
	vec.push_back(7);
	vec.push_back(12);

	std::vector<int>::iterator itrBeg = vec.begin(); // half-open: [begin, end)
	std::vector<int>::iterator itrEnd = vec.end();

	for(std::vector<int>::iterator itr = itrBeg; itr != itrEnd; ++itr)
	{
		std::cout << *itr << " ";
	}
	std::sort(itrBeg, itrEnd);
	std::cout << "After sorting\n";

	for(std::vector<int>::iterator itr = itrBeg; itr != itrEnd; ++itr)
	{
		std::cout << *itr << " ";
	}
	return 0;
}
```

### Reasons to Use C++ Standart Library

1. Code reuse, no need to re-invent the wheel.
2. Efficiency (fast and use less resources). Moddern C++ compilers are usually tuned to optimize for C++ standart library code.
3. Accurate, less buggy.
4. Terse, readable code; reduced control flow.
5. Standartization, guaranteed availability.
6. A role model of writing library.
7. Good knowledge of data structures and algorithms
