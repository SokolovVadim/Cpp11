#include <iostream>
#include <vector>
#include <algorithm>

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
