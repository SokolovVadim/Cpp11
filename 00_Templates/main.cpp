#include <iostream>

/*int square(int x)
{
	return x * x;
}

double square(double x)
{
	return x * x;
}*/

template<typename T>
T square(T x)
{
	return x * x;
}

template<typename T>
class Vector
{
	T arr[100];
	int size;
public:
	Vector(): size(0) {};
	void push(T x)
	{
		arr[size] = x;
		size++;
	}
	void print() const
	{
		for(int i = 0; i < size; ++i)
		{
			std::cout << arr[i] << std::endl;
		}
	}
	T get(int idx) const
	{
		return arr[idx];
	}
	T getSize() const
	{
		return size;
	}
};

template<typename T>
Vector<T> operator*(const Vector<T>& rhs1, const Vector<T>& rhs2)
{
	Vector<T> ret{};
	for(int i = 0; i < rhs1.getSize(); ++i)
	{
		ret.push(rhs1.get(i) * rhs2.get(i));
	}
	return ret;
}


int main()
{
	std::cout << square(5)   << std::endl;
	std::cout << square(5.5) << std::endl;
	std::cout << square<float>(4.1f) << std::endl;

	Vector<int> v{};
	v.push(10);
	v.push(12);
	v.push(20);
	v.print();

	std::cout << "Multiply vector\n";
	v = square(v);
	v.print();
	return 0;
}