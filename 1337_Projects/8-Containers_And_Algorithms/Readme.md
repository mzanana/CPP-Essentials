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

##### Insert, Erase Element and Size of vector
We have two ways to insert elements into the **vector** :  
+ `push_back(value)` to insert the `value` to the end of the vector, notice that we don't have any `push_front()` or `add_back()` or anything like this, we have only `push_back`;  
+ `insert(position, value)` it's the second way to insert element at any position we want on the vector, it takes `O(n)` as it shifts elements to make space.  

To erase elements from the vector we have two cases:  
+ For the element at the end of the vector we use `vec.pop_back()`;
+ For element at index i we use the method `vec.erase()` which takes the iterator of the element we wanna erase.  

Also we can have the size of the vector directly using the method `vec.size()`  
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> vec = {1, 3};
	
	vec.push_back(7);
	vec.insert(vec.begin() + 1, 2);
	vec.pop_back();
	vec.erase(std::find(vec.begin(), vec.end(), 3));
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i];
	
	std::cout << std::endl;
	return (0);
}
```
The output is :  `12`   
And to visualize it, it goes by those steps : `13    137    1237   123    12`

For insert() there is three **overloaded** methods :  
1. `iterator insert(iterator pos, const T& value);` Insert single element at position 

2. `void insert(iterator pos, size_type n, const T& value);` Insert n copies of value at position

3. `template<typename InputIterator> void insert(iterator pos, InputIterator first, InputIterator last);` Insert range [first, last] at position


##### Access Elements
We have two options to access elements of a vector, the first one is direct access `vec[i]`, and the second way is **bounds-checked** access which throw exception if the index is out of range, its syntax is `vec.at(i)`;  
```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = {10, 13, 1337, 37};
	
	std::cout << vec[1] << " ";
	std::cout << vec.at(3) << std::endl;
}
```
Output is : `13 37`  

##### Update Element and Empty Check
Just like C-arrays we use the index of the element we wanna update directly. 
And to check the vector if its empty we simply use `vec.empty()`, it returns true if its empty and false if there is elements at the vector.  
```cpp
int main()
{
	std::vector<int> vec = {1, 3, 4, 7};
	
	vec[2] = 3;
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i];
}
```
Output is `1337`  

### Associative Containers
Associative Containers store data in some sorted order and provides fast search, insert and delete in O(log n), we have four types of Associative Containers and they are :  
+ **Set :** Collection of unique elements stored by their values;  
+ **Multiset :** Collection of elements sorted on the basis of their value but allows multiple copies of values;  
+ **Map :** Collection of key-value pairs stored on the basis of the keys where the keys are primary and unique;  
+ **Multimap :** Collection of key-value where pairs can have same keys.  

### Unordered Associative Containers
UAC implement unsorted hashed data structures that can be quickly searched.  
+ **Unordered Set :** Collection of unique elements hashed by their values;  
+ **Unordered Multiset :** Collection of elements hashed by their values and allows multiple copies of values;  
+ **Unordered Map :** Collection of key-value pairs that are hashed by their keys where no two pairs have same keys;  
+ **Unordered Multimap :** Collection of key-value pairs that are hashed by their keys where multiple pairs can have same keys.  

### Container Adapters
**Stack :** Adapts a container to provide stack (LIFO) data structure;  
**Queue :** Adapt a container to provide queue (FIFO) data structure;  
**Priority Queue :** Adapt a container to provide heap data structure.  

# Iterators
## Definition
Iterator is an object that behave like a pointer to traverse and access elements of a container.  

**Syntax :** 
`container_type::iterator it_name`  
**Example :**  
```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {10, 20, 30, 40};
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << ' ';
}
```

## For Each vs Iterator
The best practice is using iterators when editing on the elements, and for each loop just for printing the elements; 
```cpp
int main()
{
	std::vector<int> ve = {1, 3, 3, 7};
	
	for (std::vector<int>::iterator it = ve.begin(); it != ve.end(); it++)
		*it += 2;
	for (const int &i : ve)
		std::cout << i << " ";
	
}
```
