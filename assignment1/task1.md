Task 1 (20 P.):

1. List 8 built-in typ es provided by C++. (2 P.)
Integer, Double, Float, Bool, Long Long, Character, Void, Long

2. What is the difference between an expression and a statement? Provide an
example for each. (1 P.)
Expression is a statement that evaluates a line of code and returns a value. Eg a + b - 12; Expressions can therefore often be a part of an if or switch statement, that can go one way or the other depending on value.
Statement on the other hand is an instruction by code that results in some action getting performed. It does not need to return a value. Eg: var = 0;

3. What is type safety and why is it important? (1 P.)
It simplest terms, it means that objects or variables or anything that has a type should only be handled according to it's type limitations and rules. That means only actions and operations that are allowed
to be used on it and that it can take should be used, and these actions should never leave it with a value that it cannot possess. Also variables should be initialised first. It also involves not using unsafe casts.

4. When would a programmer prefer a switch-statement over an if-statement?
(0.5 P.)
A programmer prefers to use switch statement over if statement if the number of cases to be executed is more. As switch cases uses jump table to directly go to a case thus giving all the cases the same access time while in case of if- the compiler goes and checks each and every case. Hence the last if- in the list will be accessed after a long duration, after passing through all previous if expressions, and this can seriously hamper efficiency.

5. What is a common problem with switch statements? Provide an example. (1
P.)
In case of switch statements these are the common problems
(i) Whenever a new type is to be added, a new switch case is inserted causing a modification in the code.
(ii) New requirements increase the number of cases. Hence the methods will increase in size and are  difficult to maintain
(iii) Provides the chances of Redundant Code
(iv) Does not work with some types like float and strings. It can only take int and char.
(v) Lastly, it doesn't work with operators, so complex expressions that if statements can evaluate can't be be evaluated by switch

switch(input)
```
{
	case"1":
		Print("Hello");
        myData+="Hello";
	case"2":
		Print("Hi");
		myData+="Hi";
	case"3":
		Print("Hey");
		myData+="Hey";
	default:
}
```

6. Name one operation available for strings but not for integers and one operation
available for integers but not for strings. (1 P.)
In strings we can change the Case of the string and toggle b/w upper and lower cases using 	ToLower() or ToUpper(). In case of integers we can do arithmetic operations like division, multiplication, subtraction with the integers. 

7. Explain what are references and pointers. Provide examples for each. (2 P.)
A reference is like an alias or another duplicate instance for a already existing variable and copies and stores the value is present at the variable of the referenced object. Eg: int &re = a; (storing the value of a separately and modifying a when re is modified). A pointer holds the memory address of the variable or the object under consideration. The memory location can be accessed using the dereferencing operator * with the object. Eg. int *ptr = &a; (store the address of a). So references cannot be re defined per se, but pointers can be made to point to new memory locations.

8. Explain the relationship between pointers and arrays (and C-strings). Provide
examples. (2 P.)
An array is a block of data of the same data type. If we have to consider the address of an array then the address of the array is equal o the address of the first element of the array. Hence one can say if we are pointing to the first element of the specified array structure, using a pointer, then we are refering to the entire array. 
Eg :
```
#include <stdio.h>
int main()
{
int a[3];   int i;   
for(i = 0; i < 3; i++)
{
	std::cout<< "&x[%d] = %p\n", i, &x[i] <<endl;
}   
std::cout<<"Address of array x: %p", x<<endl;   
return 0;
}

Output: 	
&x[0] = 115876
&x[1] = 115880
&x[2] = 115882
&x[3] = 115884
Address of array x: 115876
```
9. Explain the pass by value and pass by reference concepts. Provide examples.
(1 P.)

Ans 11. Pass by Value : In pass by value, the actual values of the variable are passed from the first variable to the second. Any changes in this value is not reflected in the main variable due to difference in their addresses. In pass by reference, the alias is sort of linked to the original variable meaning that changes to the new alias or duplicate also changes the original value at its location.

Eg:
```
#include <iostream>
#include <string>
void add(int a, int b)
{
	int sum;
	a++;
	sum = a + b;
	std::cout << sum;
}

int main()
{
	int a=5,b=6;
	add (a,b);
	int sum1 = a+b;
	std::cout << sum1;
}
```
output: 1211

Pass by Reference: In this method, the address of the respective values are passed and any changes occurring in the new variable is also reflected in the main variable.
Eg:
```
#include <iostream>			
#include <string>
void add(int &a, int &b)
{
	int sum;
	a++;
	sum = a + b;
	std::cout << sum;
}

int main()
{
	int a=5,b=6;
	add (a,b);
	int sum1 = a+b;
	std::cout << sum1;
}
```

output: 1212


10. Explain the terms declaration and definition. (1 P.)
Declaration (of a function) is defined as the way to make the compiler understand about the function’s name, return type, arguments etc.
Definition (of the function) on the other hand is the way to actually provide the body of the function. Similarly for variables, declaration is like introducing a variable in the code and to the compiler, by providing a name and return type, whereas definition is assigning a value to it.

11. What is a namespace and what is its typical use? (1 P.)
A namespace is a declarative region that provides a scope to the identifiers  inside it and can be identified, accessed and made distinct from other named scopes by its name. It is used to declare the types, functions and variables in the same named scope, and to keep code like variables and classes and functions separate from similarly named ones in other namespaces.


12. Why should you avoid using directives in a header? (0.5 P.)
Directives should be avoided in the header files and should be included with the main cpp files. The reason being that most of the directives might not actually be required by the source files, hence will unnecessary utilize more space. Unless a particular pre-processor directive (#) is not utilized in all the source files, it must be avoided in the headers. Also, the source files might have code from different header files and this can create
unwanted behaviour due to clashing of entities that have been used differently.

13. List four kinds of errors and provide an example for each. (2 P.)
Four types of errors are:

```
Compile time errors:
Eg: syntax error:
void main()
{
	int x=10; 
	cout << x 
}

As there's no semicolon at the end, the syntax is wrong and the compiler won't do anything.

Link time errors
Eg:
void main()
{
	int n=9;
	int div =n/0;
}

Run time errors
Eg: Out of Range
void main()
{
	vector<string> v = {"string, "string2"}
	cout < v[3];
}
Here the error is because the vector has only 2 positions but we tried to print an element that's out of range.

Logic Errors

int main()
{
vector<int> v;
for(int i=0; i<3,i++);
{   
    cout << v[i];
    i = 0;
}
if we want to print all elements, this won't work because our own code is not designed to iterate but only to output the first element indefinitely.
}

```

14. What is the free store and for what reasons might one use it? (1 P.)
Free store is a huge set of unallocated heap memory given to the program, and is done by keywords new and delete. The use is to dynamically allocate the memory during the execution of the program, for objects without a big scope but still need to be outside a function they're declared in, and that are still intended to be short lived, with the use of delete for instance

15. How do you allocate memory and about what do you need to be careful?
Provide an example. (1 P.)
We can allocate memory to a variable using ‘new’ statement. After using the memory we need to deallocate the memory using delete[] or delete so that new allocations can be done.
Eg:

```
void main()
{
	int *x= new int [x];
	if(x)return;
	delete[]p;
}
```

16. How do you safely allocate/manage memory? (1 P.)
We can statically allocate the memory or use ‘stack’ or ‘heap’ based allocation of memory. The new operator can be used to request memory on the free store and must be initialized properly. Furthermore, pointers need to
be carefully worked with on the heap or used minimally if and when needed to avoid memory errors. Also the delete operator should be used when variables outlive their scope due to being on the free store, so as to avoid leaks.

17. What is RAII? (1 P.)
RAII refers to Resource Acquisition is initialization. It is basically the management of resources which means if the object goes out of scope then it must be destroyed to release memory and actions should therefore be
scope oriented and not their effects should not spill over into other scopes



Task 2 (10 (5+5) P.): 

We provide two code snippets for this task in task2a.cpp and task2b.cpp. First
compile and run the code. Then describe and explain the observed behavior. Finally
fix the code so that it behaves as expected.

A. In the initial program, the auto keyword sets the loop iterators to be unsigned longs, hence there's no output. After changing it to an int, the desired behaviour of obtaining numbers 50 to 1 for positions 50 to 1 in the vector is observed. This is because unsigned variables can only have positive values, and after reaching zero, it won't stop at a negative value being less than zero, at which point it should stop, because what comes after zero is again positive values and therefore it will go on indefinitely, away from zero and never fulfilling that condition.

B. Debugging shows that a segmentation fault occurs at line 15 that results in EOP
upon further examination we can understand it is a memory problem owing to the ampersand operator next to the get_max function return type. So basically as a reference, it dies after the function is called, returning nothing to the callee resulting in undesirable behaviour. Deleting that gives an output of 1000.

