
<h1 align="center"><b>Understanding <u>C++</u> Concept</b></h1>

# What you'll learn on CPP00

## Namespaces
The problem that namespaces solve if two libraries have a function or variable with the same name its gonna be a conflict.   
```CPP
#include <iostream>

int main()
{
	int x = 0;
	int x = 1;
	
	std::cout << x;
	return (0);
}
```
That why namespaces comes into c++, think of it like the last name, two persons can be named as `mohamed` in same cluster, but the first one is `zanana mohamed` and the other one `bakir mohamed`.  
### Declaration of namespace :
```CPP
namespace Name
{
	/*  variables, functions
		classes, structs
		(namespace can contain almost any kind of declaration)
	*/
}
```

Another example to visualize the namespaces more you can think of it like a folder, same file name can exist in two different folders without any error.  

```CPP
#include <iostream>

namespace first
{
	int x = 1;
}

namespace second
{
	int x = 2;
}

int main()
{
	std::cout << first::x; // this print 1	
	return (0);
}
```

### Using namespace 
In `C++` if we write this line : `using namespace X` it means if any variable is unknown, before displaying an error also check the namespace X,  and the benefit of  this using namespace is we don't need to declare this namespace scope using `X::var` anymore, we call it directly `var`;  
```CPP
#include <iostream>

namespace mzanana
{
	int school = 1337;
}

int main ()
{
	// instead of using this line 
	std::cout << mzanana::school;
	
	// we can declare using namespace and the code gonna be like this
	using namespace mzanana;
	std::cout << school; // the output here is 1337
	
	return (0);
}
```

## OOP
(Object-Orientation Programming)! On C language the program was based on functions and separate data, here on C++ language we organize the program based on **objects** that own their data and provide functions that operate on that data.  

### Object
Its like a package or a collection that contain data (variables) and behavior (functions that use or modify that data);  
To create an object we need first to create a class which act as a `blue-print`

### Classes
Class is a new type created as a **blueprint** that contain variables and methods (function inside the class).  
Think of the class as the **design** of the car, and the object is the actual car built from that design.  
The blueprint of the class :  
```CPP
class Animal
{
	public:
		int         age;
		std::string name;
		
		void speak()
		{
			std::cout << "sdjalf" << sdt::endl;
		}
};
```

To create a class you need to be careful of those things :   
+ `class Animal`: The class name with a capital;  
+ `{}` : Class body;  
+ `;`: required at the end of the class;  
+ `variables` : A scope of the class variables;  
+ `functions`: The actions the object of this class can do;  
+ `private`: The default access specifier, only accessible inside the class;  
+ `public`: Accessible from outside the class;  
+ `protected`: Private, but accessible by the child classes;  

### Constructor
The constructor is a **spacial method** inside the class that :   
+ Has the same name as the class;  
+ Has no return type;  
+ Called automatically when creating an object;  
+ Initializes the object into a valid state, and the state of an object means the value of all its data members at a given moment;  

#### Default Constructor : 
```CPP
animal()
{
	age = 0;
}
```
if you create a constructor, c++ does not auto-create the default one;  

#### Parameterized constructors :  
```CPP
Animal(int a, std::string n)
{
	age  = a;
	name = n;
}
```

Usage :  `Animal dog(3, "Frex");`  

#### Initialization List  
Is a specific syntax used in a constructor's definition to initialize a class's data members before the constructor body begin execution. 
syntax :  
```cpp
Animal (int a) : age(a){}
```

+ The initialization list : `: age(a) ` is for initializing members;  
+ The `{}` body is for the constructor logic;  

**Order of initialization :**  
Members are initialized in the order they are Declared in the Class, not the order in the initialization list.   
```cpp
class Test
{
	int x;
	int y;
	
	public:
		Test() : y(2), x(1) {}
};
```
`x` initialized first by `1`; 
`y` initialized second by `2`;  

Example where the order matters :  
```cpp
class Test
{
	int x;
	int y;
	
	public:
		Test() : y(x), x(10) {}
};
```
Here : 
+ `x` initialized first by garbage value;  
+ `y` initialized using the `x` garbage value;  
+ `x` gets `10`;  
**Correct form :**  
```cpp
class Test
{
	int x;
	int y;
	
	public:
		Test () : x(10), y(x) {}
};
```
