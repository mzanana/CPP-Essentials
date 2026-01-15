
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


