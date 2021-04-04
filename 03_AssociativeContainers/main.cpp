#include <iostream>
#include <set>
#include <utility>
#include <map>

void test_set();
void test_multiset();
void test_map();
void test_multimap();

int main()
{
	// test_set();
	// test_multiset();
	// test_map();
	test_multimap();
	return 0;
}

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
	mySet.insert(1);
	mySet.insert(9);
	mySet.insert(6);

	std::cout << mySet;

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
	mySet.erase(itr);
	std::cout << mySet;
	mySet.erase(4);
	std::cout << mySet;
}

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

	std::multiset<int>::iterator itr;
	itr = mySet.find(4);
	// *itr = 12;
}

template<typename T, typename P>
std::ostream& operator<<(std::ostream& os, const std::map<T, P> myMap)
{
	for(auto itr: myMap)
		os << "{" << itr.first << ", " << itr.second << "} ";
	os << std::endl;
	return os;
}

void test_map()
{
	std::map<char, int> myMap;
	myMap.insert(std::pair<char, int>('a', 100));
	myMap.insert(std::make_pair('f', 200));
	std::cout << myMap;

	// insert
	std::map<char, int>::iterator it = myMap.begin();
	myMap.insert(it, std::make_pair('b', 300)); // it is a hint
	std::cout << myMap;

	it = myMap.find('f'); // O(log(n))
}

template<typename T, typename P>
std::ostream& operator<<(std::ostream& os, const std::multimap<T, P> myMap)
{
	for(auto itr: myMap)
		os << "{" << itr.first << ", " << itr.second << "} ";
	os << std::endl;
	return os;
}

void test_multimap()
{
	std::multimap<char, int> myMap;
	myMap.insert(std::make_pair('g', 1233));
	myMap.insert(std::make_pair('f', 6537));
	myMap.insert(std::make_pair('a', 6587));
	myMap.insert(std::make_pair('m', 1234));
	myMap.insert(std::make_pair('f', 1234));

	std::cout << myMap;

	std::multimap<char, int>::iterator it = myMap.find('g');
	std::cout << "elem found: {" << it->first << ", " << it->second << "}" << std::endl;
	// it->first = 'd';
}
