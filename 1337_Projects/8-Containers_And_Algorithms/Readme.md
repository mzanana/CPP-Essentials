<h1 align="center">(STL) Standard Template Library</h1>

# Introduction
## Definition
**STL** is a **collection** of pre-built classes and functions that make it easy to manage data using common data structures. 

## Components of STL
They are the features provided by the **STL** in c++ that are classified into 3 types :  
+ **Containers :** Hold and organize data;  
+ **Iterators :** Helps walking through the data in containers one by one;  
+ **Algorithms :** Perform actions like sorting or searching on the data in containers.  

## Benefits of STL
There are many benefits of the STL in c++, for example :  
+ Save time and effort;  
+ Fast and efficient;  
+ Reusability.  

# Containers
## Definition
Think of a container as a digital box that hold and organize data.  

## Core Characteristics :  
+ It allocates memory to keep the objects safe;  
+ It does not hold just one item, it hold a set or a sequence of object;  
+ It handle the memory cleanup by using a garbage collector.  

## Types of Containers
There are 4 types of containers.
### Sequence Containers
Sequence containers implement **linear** data structures in which the elements can be accessed sequentially.  
There are only **5** standard sequence containers in the modern C++ STL, we have `std::array`, `std::vector`, `std::list`, `std::forward_list` and `std::deque`.
#### std::vector
Vector is a class in C++ provided as a class template within the Standard Template Library, it represents a dynamic sized array that automatically grows or shrinks in size as we add or remove elements on it.  
All the elements of the vector are stored right next to each other in memory just like a raw C-Array. 
**Syntax :**  
```cpp
#include <vector>

std::vector<datatype> name(size, init_with);
```
So for example if we want to create int array of size 10 initialized with value 1337, we just need to the next syntax :  
```cpp
std::vector<int> ve1(10, 1337);
```
Or we can use the second manual way :
```cpp
std::vector<int> ve2 = {1337, 1337, ..., 1337} // `1337` 10 times
```

##### Insert Elements
We have two ways to insert elements into the **vector** :  
+ `push_back(value)` to insert the `value` to the end of the vector, notice that we don't have any `push_front()` or `add_back()` or anything like this, we have only `push_back`;  
+ `insert(position, value)` it's the second way to insert element at any position we want on the vector, it takes `O(n)` as it shifts elements to make space.  

```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = {1, 3};
	vec.push_back(7);
	vec.insert(vec.begin() + 1, 3);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i];
	std::cout << std::endl;
	return (0);
}
```
The output is :  `1337`   
