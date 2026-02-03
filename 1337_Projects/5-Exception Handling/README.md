<h1 align="center">Repetition and Exceptions</h1>

## Introduction 

**Handle Exception** is a mechanism used to detect and manage errors that occur during the program execution, so its a **runtime** not compile time error.    

When an error occur, the program terminates its execution. Using the exception handling we bypass the termination of the program by throwing exceptions and catch them for handling, allowing the program to continuing its execution.  

## Example of a program termination

```CPP
#include <iostream>

float divide(float f1, float f2)
{
	if (f2 == 0)
		throw 1337;
	return (f1 / f2);
}

int main()
{
	std::cout << divide(42, 0);
	std::cout << "You'll never see me!\n";
	return (0);
}
```

The output :
<p align=center>
	<img  src="../assets/terminate.png" width=700>
</p>

In C++ when using `throw` and nobody `catch` it, the program calls `std::terminate` which crashes the program.  

## Handling with exception
```CPP
#include <iostream>

float divide(float f1, float f2)
{
	if (f2 == 0)
		throw 1337;
	return (f1 / f2);
}

int main()
{
	try
	{
		std::cout << divide(42, 0);
	}
	catch(int e)
	{
		std::cout << "can't divide by 0\n";
	}
	std::cout << "You got me!\n";
	return (0);
}
```

Output :  
<p align=center>
	<img  src="../assets/catch.png" width=600>
</p>

**Explanation :**     
The `divide(42, 0)` now is executed inside the `try` section, the `divide()` function throws an exception as integer equal `1337`, the `catch` block in main sees the integer coming from `divide()` function, then it execute the code inside the `catch` block and runs it, after that it comes the time for the recovery step where the program continue its execution considering the error is solved.  

## Syntax Explanation

### Try-catch Block

#### Catch one exception
```C++
try
{
	//Part could throw an Exception
}
catch(ExceptionType e)
{
	//handling the caught exception
}
```

Instead of implementing the part of the code that could throw an exception and terminate the program anywhere, we place this part inside the `try` block so we can handle the exception inside the `catch` block and recover the program from terminating to continuing the execution.   

#### Catch multiple exception
```cpp
try
{
	// part might throw an exception
}
catch(type1 e)
{
	// executed when exception of type1
}
catch(type2 e)
{
	// executed when exception of type2
}
catch(...)
{
	// the `catch(...)` syntax executed when no type of the aboves types is caught
}

```

### Throwing Exceptions

There are **three** types of values that could be thrown by exceptions :  
#### Throwing Built-in Types
Those are very simple types like the one we used on the example, it does not provide any useful information, this type is not much different from handling errors using if else statements, 
```cpp
if (f2 == 0)
	throw (1337);
```

#### Throwing Standard Exceptions
Those are set of classes derived from the class `std::exception` declared on the header `<stdexcept>`
<p align=center>
	<img  src="../assets/excephier.webp" width=400>
</p>

`what()` : A method present in every standard exception class to provide information about the exception itself.  

#### Throwing Custom Exceptions
Sometimes the standard exceptions cannot satisfy our requirement, so we need to create a new **class** inherited from  `std::exception` class.  

> **Nested Class :** A class which is declared inside another enclosing class.  

In our project, to define a new exceptions we gonna create a nested class named by the exception type inside the Bureaucrat class.  

```cpp
class Bureaucrat
{
	private:
		// private attributes
	public:
		// public attributes
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade Too High!");
				}
		};
}
```


So from now on we can throw the exception `Bureaucrat::GradeTooHigh()` when needed.  
Why we use exactly that prototype for `what()`  method :  
+ This is an overriding of a virtual method inherited from the standard base class `std::exception`;  
+ We should match the same signature as the base method;  
+ `throw()` : means that this method will not throw any exceptions, for example we throw exception inside the `what()` method the program will terminate immediately calling `std::unexpected`;  

## Stack Unwinding

**Stack Unwinding** is the process of cleaning up the call stack when an exception is thrown. C++ automatically destroys all local objects and exits functions until it finds a matching `catch` block.

### How it works

When you throw an exception:
1. **Destroy** all local objects in the current function (calls their destructors)
2. **Exit** the current function
3. **Repeat** in the calling function
4. **Continue** until a `catch` block is found

### Example

```cpp
#include <iostream>

class Object
{
	private:
		std::string name;
	public:
		Object(std::string n) : name(n)
		{
			std::cout << name << " created\n";
		}
		~Object()
		{
			std::cout << name << " destroyed\n";
		}
};

void functionC()
{
	Object obj3("obj3");
	throw std::runtime_error("Error!");
}

void functionB()
{
	Object obj2("obj2");
	functionC();
}

void functionA()
{
	Object obj1("obj1");
	try
	{
		functionB();
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << "\n";
	}
}

int main()
{
	functionA();
	return (0);
}
```

**Output:**
```
obj1 created
obj2 created
obj3 created
obj3 destroyed    ← Stack unwinding starts
obj2 destroyed    ← Stack unwinding continues
Caught: Error!
obj1 destroyed    ← Normal destruction
```

<p align=center>
	<img  src="../assets/stack_unwinding.png" width=800>
</p>

**Explanation:**  
When the exception is thrown in `functionC`, stack unwinding begins: `obj3` is destroyed, `functionC` exits, then `obj2` is destroyed, `functionB` exits, and finally the exception is caught in `functionA`.

### Why it matters

**The exception object must survive stack unwinding!** That's why C++ copies the thrown exception to special memory:

```cpp
void throwError()
{
	std::runtime_error err("Error");
	throw err; // err is copied
} // Original err destroyed here

try
{
	throwError();
}
catch (const std::runtime_error& e)
{
	// e refers to the copy, not the original
	std::cout << e.what(); // Safe!
}
```

**Important:** Destructors should NEVER throw exceptions during unwinding, or the program will terminate.
