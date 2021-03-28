# Templates

### The same function with multiple parameter types

```
int square(int x)
{
	return x * x;
}

double square(double x)
{
	return x * x;
}

int main()
{
	
	std::cout << square(5)   << std::endl;
	std::cout << square(5.5) << std::endl;
	return 0;
}
```

### Function Templates

Function temlates can infer the data type from the parameter.  
So it can be used both with specified parameter and without one.

```
template<typename T>
T square(T x)
{
	return x * x;
}

int main()
{
	std::cout << square(5)   << std::endl;
	std::cout << square(5.5) << std::endl;
	std::cout << square<float>(4.1f) << std::endl;
	return 0;
}
```

### Code bloat

Template functions are different and occupy their own space in a program image.  
Therefore the code size bloats

### Template class

Temlate class can not infer data type. Data type is to be specified via parameter of template.

```
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
};

int main()
{
	Vector<int> v{};
	v.push(31);
	v.push(12);
	v.push(99);
	v.print();
	return 0;
}
```

### Template class with template function

```
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
```
