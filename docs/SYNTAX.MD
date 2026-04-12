# Basics

IIL is made to be as simple and intuitive as possible. This is a simple guide on IIL so you can start writing. 



# Contents

[Print](#print)    
[Operators](#operators)    
[Comments](#comments)    
[Precedence Rules](#precedence-rules)     
[Statement Endings](#statement-endings)     
[Variables](#variables)    
[Variable Naming Rules](#variable-naming-rules)  
[Keywords](#keywords)  
[If-Statements](#if-statements)    
[Loops](#loops)    
[Try](#try)    
[Functions](#Functions)    
[Data Types](#data-types)   
# Print

A print statetement can print any variable of any datatype. If you would like to print a string, character, or integer. It can be done: 
``` 
iprint("Hello World!"); ### printing a string
iprint(85239) ### printing a integer 
iprint('A') ### printing a character 
```
When printing integers (as shown above) the integers are converted to strings and then printed.      
**Note:** You cannot print an integer and a character in the same statement. You must place them in a string. 

In IIL, most keywords begin with an 'i' which stands for "interesting" 
For example "iprint" means ***interesting print.***    


# Operators 

### Arithmetic Operators 


### Arithmetic Operators

- ```+```  
  The **Addition** operator

- ```-```  
  The **Subtraction** operator

- ```*```  
  The **Multiplication** operator

- ```/```  
  The **Division** operator 

- ```%```  
  The **Modulo** operator 

- ```**```  
  The **exponentiation** operator 


### Comparison Operators

- ```==```  
  The **Equal** operator 

- ```!=```  
  The **Not Equal** operator 

- ```<```  
  The **Less Then** operator 

- ```>```  
  The **Greater Then** operator 

- ```<=```  
  The **less then or equal to** operator 

- ```>=```  
  The **Greater then or equal to** operator 


### Logical Operators 

- ```&&```  
  The **And** operator 

- ```||```  
  The **Or** operator 

- ```!```  
  The **Not** operator 


### Assignment Operators

- ```=```  
  The **assignment** operator 

- ```+=```  
  The **Compound Assignment Addition** Operator 

- ```-=```  
  The **Compound Assignment Subtraction** Operator 

- ```*=```  
  The **Compound Assignment Multiplication** Operator

- ```/=```  
  The **Compound Assignment Division** Operator 

- ```%=```  
  The **Compound Assignment Modulo** Operator 
### Grouping Operators 

- ``` () ```     
**Parentheses.** Used to group expression and control evaluation order

# Comments 

## Single line comments
Single line comments are begun with ```##```   

```## This is a single line comment ```     

## Multiple line comments 

Multiple line comments are begun   with ``` ### ```  and ended with ```###```

``` 
### 
This
is 
a 
multi-line 
comment 
###
```

# Precedence Rules 

In IIL Precedence rules follow BODMAS/PEMDAS. The precedence of arithmetic operators from highest to lowest is as follows: 
1. Parenthesis ```()```
2. Orders ```**``` 
3. Multiplication, division, and modulus ```*``` ```/``` ```%``` 
4. Addition and subtraction ```+``` ```-```
 

# Statement Endings 

In IIL a statement is ended with a new line

```
iprint("no")
iprint("yes")
```

# Variables

## Variable declaration 
Local variables can be declared with ```ivar``` which stands for ***interesting variable***. IIL is a dynamically typed language so you don't need to define the datatype. This also means that reassigning values is possible. 

### Lexical scope 
- Variables defined within an expression are only accessible within that expression.
- Inner functions have access to variables in their parent functions. 
- Variables defined inside a function or block, are accessible only within that function or block. 
- Variables defined outside any function or block, are scoped to the file where the variable was declared in, but it is not visible to the other files, even if they import or depend on this file. They have a module scope. 


Defining a local variable: 

```
ivar x = 1

x = "hello"; ### reassigning the value of x
``` 

Uninitialized variables are declared as follows: 
```  
ivar x
```
The variable can be initialized later: 

```
x = 10
```

When referencing the value of ```x```, if the value is undefined, this will result in a compile-time error. 

To make a variable global, you can use ```global ivar``` meaning interesting variable. A global variable can be accessed all throughout the file. And if the file is included (added as a dependency) in a different file. A global variable is accessible throughout that file as well. 

For example: 
``` 
global ivar x = 1; 
```

**Note:** 
``` 
x = 5
``` 
will result in a compile-time error. This is not the correct way to define a global variable. 

To declare a variable with the value NULL this can be done as follows: 
```
 x = NULL 
``` 

In IIL **Nil** is not used. 
## Variable Naming Rules

1. A variable name must begin with a letter or an underscore ``` _```.
2. Variable names can only contain alpha-numeric characters and underscores. ```a-z```, ``` A-Z```, ``` 0-9 ```.
3. Variable names are case sensitive. 
4. A variable name can not contain spaces. 
5. There is no limit on the length of a variable name. 
6. The variable name cannot be any IIL keywords. 

# Keywords 

## If-Statements
For simplicity, if statements are not written with an extra i, as in ```iif``` (or interesting if). Because I think that would cause some confusion.  
In IIL an **if-statement** is written as follows: 
```
if (x == y) do: 
    iprint("x is equal to y")
```
### Else-statements 
Else-statements are optional and are used like this:

``` 
if (x == y) do: 
    iprint("x is equal to y")
else do: 
    iprint("x is not equal to y")
```

### Else-If:

An else if statement is written like this: 

```
if (x == y) do: 
    iprint("x is equal to y")

eif (x == z) do: 
    iprint("x is equal to z")

else do: 
    iprint("x is not equal to y")
```

## Loops 

in IIL there are 2 kinds of loops.     
1. While loop
2. For loop

### While Loop

A while loop is declared with ```iwhile``` and ended with ```iend```. 
```
iwhile (true) do: 
    iprint("hello")
iend
```
At this point I don't think I need to explain what the "i" means.

A while loop can be exited using ```exit```. 

### For Loop

A for loop is declared with ```ifor```. 

``` 
ifor (var x = 0; x < 10; x++) do: 

    iprint(x)
```

If you would like to end a for loop early, you can use ``` ibreak ```.
## Try
In ILL a try statement allows you to run a block of code and use except to handle any errors encountered. You can add a finally block to the end. That will execute no matter if the try block catches an error or not.     
``` 
itry do:
    iprint(x / 0)
iexcept DivideByZeroError do:  
    iprint("You can't divide by zero")
ifinally do: 
    iprint("try statement completed")
``` 


# Functions
The basic function syntax is as follows: 

``` 
ifunc <name>(<parameters>):
    <statements>
    return <expression>

```

### Local and Global Functions: 
By default, functions in IIL are local. A global function can be specifically declared by adding i to the beginning of the declaration. Meaning to define a local function you write: ```ifunc basicFunction()``` and to define a global function you type ``` global ifunc basicFunction() ```. 

### Function Name Rules: 

1. A function name must begin with a letter or an underscore ```_```.
2. Function names are case sensitive. (eg. goo ≠ Goo)
3. Function names can not contain spaces. 
4. There is no limit on the length of a variable name. 
5. The function name can not be any IIL keywords.

### Parameters

Parameters are written inside the parentheses and are separated by commas. IIL optionally allows a trailing comma at the end of the parameters. Parameters are local variables and they are not accessible outside the function. Parameters are assigned from arguments at function call time.

### Function body 

A function body contains the instructions that define what the function does. The function body is executed when the function is called. It can include variable declarations, expressions, and control flow. Expressions are constructs that evaluate to a value. They can be used in assignments, function arguments, and other expressions. 

### Return 

In IIL returning a value from a function is done with a ```return``` statement. The value of the returned expression is returned back to the function caller. If no return statement is present, the function will return the value of the last expression in the function. 

### Function Calls 

Calling a function is done like this: 

```
<name>(<arguments>)
```

### Arity rules 
1. If too few arguments are passed as parameters, the missing arguments will be defined as **null**. In IIL arguments must be expressions. 
2. Too many arguments will result in an run-time error. Using an uninitialized variable as an argument will result in a compile-time error. 

### Scope Rules

1. Parameters and variables inside functions are local to that function
2. Variables outside the function are not accessible unless explicitly allowed.
3. Functions use [lexical scope](#lexical-scope).


### Hoisting behavior 
- All function declarations are registered before execution.
- Functions can be called before their definition appears. 
- Functions nested inside functions are hoisted inside that function. 

### Nesting rules 
1. Functions may be defined inside other functions. But these functions are scoped to the parent function and can not be accessed elsewhere. They are defined with ```ifunc```. Using  ```global ifunc``` will result in a run-time error. 

### Recursion
- Functions can call themselves. 

### Example Function 

```
ifunc addX(x): 
    ivar y = 1 + x
    return y

ivar z = addX(x)
iprint(z)
```

# Data Types

- **Integer**  
  Represents whole numbers without decimal points (e.g., 42, -7).

- **Float (Floating Point)**  
  Represents numbers with decimal points (e.g., 3.14, -0.5).

- **Character**  
  Represents a single letter, digit, symbol, or space (e.g., 'A', '7', '?').

- **Boolean**  
  Represents a logical value: either `true` or `false`.

- **String**  
  Represents a sequence of characters treated as text (e.g., "Hello World").

- **Null**  
  Represents the absence of a value (nothing).

- **Array**  
  Represents an ordered collection of elements, usually of the same type.

- **Dictionary**  
  Represents a collection of key-value pairs for fast lookup by key.



