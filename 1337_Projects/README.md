
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

####  this->
`this` is a hidden pointer inside every non-static member function. it points to the current object.  
It is not necessary to use it in some cases, but in other cases you should use it :  
+ **Optional to use `this->` :** When there is no name conflict, the compiler already knows the member from the constructor variable;  
+ **Necessary :** There are many advanced cases like fluent interface, templates or dependent names , but at our current learning phase `this->` is necessary when the parameter has the same name as the member.  

#### Parameterized constructors :  
```CPP
Animal(int a, std::string name)
{
	age  = a;
	this->name = name;  //this->name is the attribute name, and the name after equal sign is the constructor parameter
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

### Overloaded Constructors  
They are multiple constructors in the same class with different parameter lists, and that for :  
+ Allowing objects to be created in different ways;  
+ Having the same class name but different parameters;  
+ Flexibility.  

**IMPORTANT !**  
Two constructors must be different in the number or the types of the parameters;  
We cannot have two constructors with exactly the same signature;  

```cpp

class Animal
{
	private:
		int age;
		std::string name;
		
	public:
		Animal() : name("unknown"), age(0) {}
		Animal(const std::string& name) : name(name) {}
		Animal(int age) : age (age) {}
		Animal(const std::string& name, int age) : name(name), age(age)
};

```
So we can create now animal object with only age given, name only, name and age or even nothing;  

### Encapsulation 
Called the heart of the **OOP**, it protect the logic and prevent misuse, the encapsulation principle is to hide the internal data and expose only what is necessary;  
C++ implements encapsulation using access specifiers :  
+ **private :** To hide and being sure we can't modify to the declared members outside the class;  
+ **public :** when providing public getters and setters we are controlling the access which is part of the encapsulation.  

**Why we use them ?**  
Imagine we have a class of BankAccount and the balance attribute is public, inside the main function code everyone could modify the balance to whatever he want, or it can be invalid because of no control.  
```cpp
class BankAccount
{
	public:
		int balance;
};

BankAccount bank1; 
bank1.balance = -9999;
```

So the solution is the next : 
```cpp
class BankAccount
{
	private:
		int balance;
		
	public:
		void deposit(int amount)
		{
			if (amount > 0)
				balance += amount;
		}
		void getBalance() const
		{
			return (balance);
		}
};
```

Here the user cannot change the balance directly, but using the line `account.deposit(500);` he can;  


### getters and setters
They are functions used to make a private attribute readable or writable from outside the class :  
#### Getter
A function that return the value of a private member; 
**Syntax :**  
```cpp
ReturnType getMemberName() const
{
	return (memberVariable);
}
```
+ `ReturnType` : the type of the variable we want to access;  
+ `const`: Used to ensure the getter does not modify the object (optional but recommonded).  

#### Setter
A function that change or updates the value of a private member.  
**Syntax :**  
```cpp
void setAge(int a)
{
	if (a >= 0)
		age = a;
	else
		age = 0;
}
```

# To_do later (easy stuff)
+ Memory basics (dynamically and statically);  
+ References and Pointers;  
+ File streams;  
+ Pointer to member functions;  



# Orthodox Canonical, Operator overloading, fixed and floating points

## Orthodox Canonical Class Form
Its a standard set of rules that ensure the classes behave well and correct while copying its object, assigning it or destroying it.  
The form define **four** members :  
+ Default constructor;  
+ Copy constructor;  
+ Copy assignment operator;  
+ Destructor. 

### Why we need to use it 
If a class manages resources (pointers, file handles, sockets, etc.) the default implementation provided by the compiler make some bad behaviors like :  
+ Do Shallow copying;
+ Leads to double deletes, memory leaks or dangling pointers.  

#### Shallow copying, deep copying and dangling pointers

+ **Shallow copying :** While copying an object without the copy constructor or the assignment operator, all variable values are copied, but dynamically allocated memory addresses are shared between objects, also both objects point to the same heap memory, so changes made through one object affect the other;  
+ **Deep copying :** The new object is created by copying all the variable values and allocating separate memory for dynamically allocated variables, both the original and copied objects store their data in different memory locations,  while changing one it doesn't affect the other one.  
+ **Dangling pointers :** Is a pointer that point to a memory location that has been deallocated or is not longer valid, accessing or dereferencing a dangling pointer results in undefined behavior.  

### Default Constructor
The default constructor is a function that runs when a new object is created and declared without parameters,  the important thing it did is making sure all the members are initialized. Initialization is not the same as assignment :    
+ Initialization happens **before** the constructor body runs;    
+ Assignment happens **inside** the constructor body.    
+ `const` members must be initialized and we can't assign them later;   
+ References also should be initialized and not be null or left it empty;    
+ Members are initialized in the order they are declared in the class.  


### Copy Constructor  
It create a new object as a copy of an existing one without any conflict,  if we didn't implement our copy constructor the compiler gonna call its own one which just copy all the members from the existing object to the new object, for simple variables like integers that works fine, but for pointers that gonna cause the dangling pointers we talk about previously, because the new pointer gonna point to the original object pointer element pointed to.   

syntax :  
`ClassName(const ClassName& other)`  

+ Like all constructors it must match the class name and has no return type;  
+ Reference, help us to avoid an infinite loop, where this infinite loop happens ? let me show you. Lets sat we gonna create a copy of an existing object and the copy constructor argument is passed by value, to create this value the compiler gonna need to make a copy of the passed object, and how the compiler make a copy of an object, it just call the copy constructor, again and again and again until we face a stack overflow;   
+ Const means copying from a const objects is allowed, and also to make sure that we don't modify the original object.    

Example of the copy constructor : 
```cpp

#include <iostream>

class ClassName
{
	private:
		int x;
	public:
		int getX() const
		{
			return (this->x);
		}
		ClassName(int nbr):x(nbr){}
		ClassName (const ClassName& other)
		{
			this->x = other.getX();
		}
};

int main()
{
	ClassName A(17);
	ClassName B(A);
	std::cout << B.getX();
}
```


And now lets make an complex example of a pointer that exist inside the class  
```cpp
	#include <iostream>
	#include <cstring>
	
	class Student
	{
		private:
			char *name;
		public:
			Student() : name(NULL){}
			Student(const Student& other)
			{
				if (other.name)
				{
					int len = std::strlen(other.name);
					this->name = new char[len + 1];
					std::strcpy(this->name, other.name);
				}
				else
					this->name = NULL;
			}
			~Student()
			{
				delete[] name;
			}
	};
```

### Assignment Operator
The difference between the copy constructor and the assignment operator is that the copy constructor build the object from scratch, create it and initialize it, while the assignment operator happen between two existing object, we just want to assign one object values to other one, and of course the syntax is different from the copy constructor.  

**Syntax :**  
```Cpp
ClassName& operator=(const ClassName& right)
```
+ We return `ClassName&` so it return a reference of the current object `(*this)`;  
+ `operator=` This is a special c++ keyword that tells the compiler that we gonna redefine the `=` operator;  
+ `const ClassName& right` we call const so we can accept also the const objects, and the reference because we gonna take a long time and it gonna be inefficient, lets say you want to make `a = b`, if the assignment didn't have a reference then it gonna make a copy which gonna create a new copy `b => right` and also we are copying for the second time from `right => a`;   That's why reference is important, so to pass directly the right object; 

Example :
```cpp
#include <iostream> 

class SmartD
{
	private:
		int id;
		bool ison;
		
	public:
		SmartD();
		SmartD(int id) : id(id){}
		SmartD(const SmartD& other)
		{
			//copy constructor
		}
		SmartD& operator=(const SmartD& right)
		{
			if (this != right)
			{
				this->id = right.id;
				this->ison = right.ison;
			}
			return (*this);
		}
}
```