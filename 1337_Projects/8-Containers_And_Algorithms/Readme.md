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

## begin() and end() methods
`begin()` and `end()` are methods belong to the containers and not the iterator itself.  
+ **`begin()`** returns an iterator that point to the first element of the container;  
+ **`end()`** returns an iterator that point to the end of the container not the last element, if we want to use the last element of the container we use `ve.end() - 1`.  

Here is the list of all the other methods that returns iterator to the containers :  
<p align="center">
	<img src="../../assets/itmeth.png" width=500>
</p>
## Adding/Subtracting integer to iterators

Just on some containers like vectors and deque, we can add and subtract integer to iterator to move it forward and backward.  
```cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5, 6};
	
	std::vector<int>::iterator it = vec.begin();
	std::cout << *it << ' ';
	it += 4;
	std::cout << *it << ' ';
	it--;
	std::cout << *it << std::endl;
}
```
Output is :  `1 5 4`;

# Algorithms
Algorithms are used to solve problems by **sorting**, **searching** and **manipulating** data structures.  
The header `#inlude <algorithm>` is necessary to use them.   
We can divide the algorithms into **four** parts :  
## Searching Algorithms

### Definition 
Searching algorithms are used to **find** a specific element  or information in a data structure like as array, vector or list.  

### Example of algorithms
#### find()
The find function takes three parameters : `start_iterator`, `end_iterator` and `value` to search for, and it returns an iterator to the specific element if found or to `.end()` iterator if not found.   
**syntax :**
`std::find(start_iter, end_iter, value);`
```cpp
#include <algorithm>

std::vector<int> nums = {12, 23, 34, 45};

std::vector<int>::iterator it = find(nums.begin(), nums.end(), 23);
if (it == nums.end())
	std::cout << "Element not found";
else
	std::cout << "Element Found";
```

## Sorting Algorithms
### Definition
To store the elements in a container or array we use sorting algorithms.

### Example of sorting algorithms
#### sort()
sort() function take two parameters, the iterator to start sorting and the iterator to stop, its default sort is ascending order.  
**Syntax :**  
`sort(start_iter, end_iter);`  
```cpp
std::vector<int> nums = {12, -23, 0, 34, 5};

// sorting ascending
sort(nums.begin(), nums.end());

// sorting descending
sort(nums.rbegin(), nums.rend());
```


## Other types of algorithms
And there is other types of algorithms as **Manipulation algorithms** which contain `copy()`, `swap()`, `move()` etc... and the **Counting & Comparing algorithms** which contain `count()`, `equal()`etc ...  

