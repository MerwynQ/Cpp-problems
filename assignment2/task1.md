Task 1 (8 P.):
1. What is the difference between a struct and a class? (0.5 P.)
Both are user defined types, however the members of a struct are public by default and thus accessible by every other entity and are always that way, and the members of a class are private by default and accessible only
by its derived objects. However, with a class, members can be made private.

2. Why should the public interface to a class be as small as possible? (1 P.)
For starters, it eases debugging as only a few functions can access the data, thus narrowing down which ones are causing bugs. Furthermore, it helps in having invariants separate and dealing with them by keeping
their access private. Also lastly it helps in segregation of important and basic members from messy and complex ones thus making the tasks easier.

3. What is the difference between const and static? (0.5 P.)
A const object or variable stays constant throughout and trying to assign it different values will result in an error.

4. Why should you distinguish between functions that modify objects and those that do not? (1 P.)
It is important because const member functions will not change the derived objects in anyway irrespective of whether the objects themselves are constant or not but other functions will. This maintains
a separation in uses of a function, and when we want to avoid changing variables as much as possible with the use of only the said function, then the objects can be declared as const so that only the const function
can be accessed in that case. Hence we need to distinguish to make our code more robust and specific for specific uses of a class.

5. What is the concept and effect of inline functions? When would you prefer inline functions over function calls? (0.5 P.)
Inline functions are class members that are defined inside the class body and the most significant effect of inline functions is reduced run time. Basic class components like getter and setter functions to work with
access specifiers would be a good idea to have as inline functions as they don't change often.

6. What is a destructor and when is it called? What is the typical consequence of its usage? (1 P.)
A destructor releases memory of the variables that the constructor initialised in an object of a class when it goes out of scope.

7. In which context are virtual functions used? (1 P.)
Virtual functions are used in the context of derived classes where the original methods need to be overriden to serve a different purpose.

8. What is the semantic result of combining the keywords friend and virtual for a class function? Explain and state reasons for your observations. (1 P.)
Both cannot exist at the same time and hence a compiler error may get thrown up. Friend functions are usually independent of the class whereas virtual functions are class members, hence these two functionalities cannot
be combined, however a virtual function can be a friend of another class.

9. When would you make a virtual member function pure? (0.5 P.)
When in a base class, we have a vague idea of what derived class functions can be like, but not a general idea that would apply to all possible derived functions, we define an abstract idea and to
do this we would make a virtual member function pure.

10. What are pitfalls of multiple inheritance? (0.5 P.)
The diamond problem is a main pitfall of multiple inheritance. When there are branches in the division of derived classes and they finally converge down the line to one last derived class,
there could be ambiguities between members that may or may not have been overriden and that can cause problems in the code.

11. What is the difference between a concrete class and an interface? (0.5 P.)
Classes have concrete methods that are implemented beforehand and hence the resulting objects are properly instantiated. However, interfaces are rather blank and lend flexibility to users down the line
to be be implemented as needed with the help of derived classes. Hence they cannot be used to make objects themselves, and this is done by only having pure virtual functions in them.

