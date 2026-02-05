<h1 align=center> Casting Operators</h1>

# Type Conversion

## Definition 
**Type Conversion** means converting one data type to another compatible data type, the only rule is it shouldn't lose its meaning. we need it for managing different data types.  

<p align=center>
	<img src="../assets/tycon.webp" width=350>
</p>

## Information Losing
 Data has its own value and format, when converting a data to a new type that can't hold its value or format we talking here about losing its meaning;    

### Truncation 
Losing the precision of number, for example converting a **float** number to **int** we gonna lose its precision, for example `3.145 (float)` gonna converted to `3 (int)` so we lost the `.145` and its gone forever! 
<p align=center>
	<img src="../assets/trun.webp" width=350>
</p>

### Overflow 
This happens when converting a huge number into a small cup, for example converting `long 50000` into `short` variable, we know that the maximum value that a short can handle is `32767`, so converting our value gonna overflow and just gives us `(short ) -15536` ;   
    <p align=center>
	<img src="../assets/overflow.webp" width=350>
</p>

### Sign Mismatch
Happens when mixing negative numbers in types that can only be positive, for example converting `(int) -1` into a `unsigned int` type gonna just gives us the maximum value of the unsigned integer, so the conversion gonna equal around `4 billion` instead of `-1`;  
        <p align=center>
	<img src="../assets/sing.webp" width=350>
</p>

# Types of Type Conversion
There are two types of type conversion :  
## Implicit Type  
The implicit type is when the compiler automatically convert the data types bases on needed cases, for example :  
+ Operations are performed of values with the different data types;  
+ Passing argument type X to a function that expect a data type Y;  
+ Assigning a value of one data type to variable of another type;  
<p align=center>
	<img src="../assets/auto.webp" width=350>
</p>

+ **Widening :** Also known as promotion, converting a value from a smaller or less precise data type to a large or more precise data type.  
+ **Narrowing :** Demotion, the opposite process. It is highly possible  to lead to **meaning lost** that we talk about earlier.   

## Explicit Type
The explicit type conversion also called **type casting** is the conversion of one type of data type to another type **manually** by the programmer.  it can be done by two ways :  
+ **C Style Typecasting :** This method is inherited from C. `(newType) expression;` also known as forceful casting;  
+ **C++ Style Typecasting :** This method is an unary operator which force one data type to be converted into another data type. C++ support four types of typecasting, there is **static, dynamic, const and reinterpret cast** ;  

