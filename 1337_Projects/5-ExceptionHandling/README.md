<h1 align="center">Repetition and Exceptions</h1>

### Exception Handling  
It is a mechanism used to detect and manage errors that occur during the program execution, so its a **runtime** not compile time error.    

Normally when an error occur, the program terminate its execution. Using the exception handling we bypass the termination of the program by throwing exceptions and catch them for handling, allowing the program to continuing its execution.  

Example of a runtime error :  
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
	<img  src="./terminate.png" width=700>
</p>
In C++ when using `throw` and nobody `catch` it, the program calls `std::terminate` which crashes the program
