<h1 align="center"> Templates </h1>

# Definition 
The best way to understand a concept is by defining the problem that it solves, lets make an example to visualize the problem template fix!  
For example we want to find the maximum between two strings, we gonna need :  
```cpp
std::string max(const std::string& first, const std::string& second)
{
	return (first > second ? first : second);
}
```

On the same project for we want the maximum between two integers, we need :  
```cpp
int max(const int& first, const int& second)
{
	return (first > second ? first : second);
}
```

And so on ... For each time we need a new max comparison between two variables we gonna need a new function that implement it. **ISN'T THAT REPETITIVE ???**   


