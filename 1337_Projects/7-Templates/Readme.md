<h1 align="center"> Templates </h1>

# Definition & Problematic 
## Problematic
The best way to understand a new concept is by defining the problem that it solves, lets make an example to visualize the problem template fix!  
Lets implement a function the returns the maximum between two strings :  
```cpp
std::string max(const std::string& first, const std::string& second)
{
	return (first > second ? first : second);
}
```

On the same project we want the maximum between two integers, we gonna need :  
```cpp
int max(const int& first, const int& second)
{
	return (first > second ? first : second);
}
```

And so on... For each time we need a new max comparison between two new variables we gonna need a new function that implement it. **ISN'T THAT REPETITIVE ???**   

## Definition
The **templates** came to solve the problem of the repetitive code, so instead of implementing for each variable a function or a class, we implement a template that works for any data type.  

### Syntax
```cpp
template <typename A, typename B, ...>
//entity_definition
```

Here is a template function that return the maximum between two variables with the same data type :  
```cpp
#include <iostream>

template <typename T>
T ft_max(const T& first, const T& second)
{
	return (first > second ? first : second);
}

int main()
{
	int x = 13;
	int y = 37;

	std::cout << ft_max(x, y) << std::endl;

	std::string first = "mohamed";
	std::string second = "zanana";

	std::cout << ft_max(first, second) << std::endl;
}
```

Output : 
> 37
> zanana

The compiler create a separate version of `ft_max()` for each the `int` and the `std::string` variables based on how it's called.  

# Types of templates
## Function template
This is exactly the example we used before to understand the concept of the templates. Allow us to write **generic** code for functions that can be used with different data types.  

## Class template

Class template are useful when class define something that is independent of the data type, some of the example the class template could helps LinkedList, Stack, Queue, Array, etc.   

**Simple example** 
```cpp
template <typename T>
class test
{
	public:
		test(T val1, T val2) : x(val1), y(val2)
		{}
		T x;
		T y;
		void getValues()
		{
			std::cout << x << " " << y << std::endl;
		}
};

int main()
{
	test first(13, 37);
	test second ("mohamed", "zanana");
	first.getValues();
	second.getValues();
}
```