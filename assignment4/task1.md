Task 1 (10 P.):

1. Why is it dangerous to return a reference when you must return an object?
(1 P.)
References have a short life corresponding to the caller method or function, and therefore they get deleted upon completion of the call. Hence, the returned object type will be non existent
and due to no access it might cause undefined behaviour.


2. What is an implicit interface in the context of compile-time polymorphism?
(1 P.)
An implicit interface is the body of a template class or function, where the type of the parameters is unknown and hence the logic is checked only at compile time, as opposed to explicit interfaces where
the parameter is checked against the function signatures.


3. Why should you prefer range memb er functions to their single-element coun-
terparts? (1 P.)
It is more simpler and computationally efficient when dealing with containers, as it will go over every element from container.begin() to container.end(), while not having to evaluate arithmetic comparisons at every step.


4. Why should you avoid in-place modification of keys in a set? (1 P.)
Sets have unique elements that cannot be directly modified but only deleted and new elements can be inserted. Hence doing the latter approach is too expensive as sets are also ordered, and the elements would have to be
arranged again by the set. Furthermore, options like using extract could be more precise if done correctly, but at the same time they are more complicated to execute. 


5. Why should predicate functions be pure? (1 P.)
Since predicate functions can only return boolean values or similar types, we need a consistent duality in every call, and to ensure that these predicate functions only return 2 values, it is important
to have them be pure. This ensures reproducibility.


6. Why should you avoid the default capture modes of lamdbas? (1 P.)
Since depending on the function, every value to be captured could be used differently, and some require a reference capture and some require a value capture. When the default capture mode is active,
using the wrong capture for the wrong variable could result in unwanted behaviour like dangling pointers in the case of capturing something by reference that should have rather been taken by value.
There are many disavantages, but to generalise, it can be said that default capture modes would act similar to having a program only use pass by value or pass by reference concepts, as opposed to specifically
adapting the strategy for specific types.


7. What do std::move and std::forward do? (2 P.)
move allows users to cast any value to an rvalue whereas forward casts lvalues to lvalues and rvalues to rvalues, depending on the value of the type inside the angle brackets part of the forward call.
So in essence, move works better with temporary types and forward works better with templated types. 


8. How are the strings of a std::set<std::string*> sorted? How you would
make them sorted lexicographically? Provide the necessary code. (2 P.)
Since the string has an asterisk, it is a set of pointers and the pointers and consequently the strings they are pointing to will be sorted according the names of their memory locations, which will happen to 
correspond to their original user provided order, as memory addresses are assigned serially and named lexicographically.

```
std::set<string> ss;
string s;
For(size_t i = 0; i < set.size(); i++)
{
    s = **set.begin();
    set.erase(set.begin());
    ss.insert(s);
}
```
