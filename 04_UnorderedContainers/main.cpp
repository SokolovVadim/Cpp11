#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

void test_undordered_set();
void test_undordered_map();
void foo(const std::unordered_map<char, std::string>& m);
void test_array_based_containers();

int main()
{
	// test_undordered_set();
	// test_undordered_map();
	test_array_based_containers();
	return 0;
}


void test_undordered_set()
{
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
}

void test_undordered_map()
{
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
	foo(day);
}

void foo(const std::unordered_map<char, std::string>& m)
{
	// m['S'] = "Sunday";
	// std::cout << m['S'] << std::endl;
	auto itr = m.find('S');
	if(itr != m.end())
		std::cout << itr->second << std::endl;
}

void test_array_based_containers()
{
	std::vector<int> vec = {1, 2, 3, 4};
	int* p = &vec[2]; // points to 3
	vec.insert(vec.begin(), 0);
	std::cout << *p << std::endl; // ?
}
