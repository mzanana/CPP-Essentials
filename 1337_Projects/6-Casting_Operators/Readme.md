<h1 align=center> Casting Operators</h1>

## Type Conversion

### Definition 
**Type Conversion** means converting one data type to another compatible data type, the only rule is it shouldn't lose its meaning. we need it for managing different data types.  

+ **Losing meaning :** Data has its own value and format, when converting a data to a new type that can't hold its value or format we talking here about losing its meaning, for example :  
  + **Truncation :** Losing the precision of number, for example converting a **float** number to **int** we gonna lose its precision, for example `3.145 (float)` gonna converted to `3 (int)` so we lost the `.145` and its gone forever! 
  + **Overflow :** This happens when converting a huge number into a small cup, for example converting `long 50000` into `short` variable, we know that the maximum value that a short can handle is `32767`, so converting our value gonna overflow and just gives us `(short ) -15536` ;  
  + **Sign Mismatch :** Happens when mixing negative numbers in types that can only be positive, for example converting `(int) -1` into a `unsigned int` type gonna just gives us the maximum value of the unsigned integer, so the conversion gonna equal around `4 billion` instead of `-1`;  
