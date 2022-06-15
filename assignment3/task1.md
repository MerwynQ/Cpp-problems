Task 1 (8 P.):

1. What is the difference between the keywords typedef and using? Also, state one usage example for both. (0.5 P.)
Both generate aliases by creating a synonymous keyword to an already existing type, however typedef is old and using was recently added with C++ 11. Hence,
using has an additional functionality of being able to also generate alias templates, where if the old type was a template type, the new type is not rigid has an option
of modifying the template parameters anytime.

2. What are iterators? Name at least 3 different types of iterators and explain their functionalities. (1 P.)
Iterators are a more complicated defined type in c++, as opposed to pointers which are a basic type of variable that stores an address. Iterators are wrappers around a pointer,
meaning that they contain a pointer to store memory locations but also consist of other members that enable them to do much more. This lets them work with containers and so on, 
instead of just adjacent spaces in memory like pointers. Pointers are declared as being of the type that they point to alongwith the memory address, whereas iterators are of
their own type defined by their class implementation.

Types include input, output and forward iterators. Input iterators are read only, and can only access elements of a container and not modify anything whereas output iterators
cannot read, or check for conditions or do anything with pre existing values and can only be used to do actions like assign values, change or store data. Both are complementary
types and a subset of the third type which is more generic, which is the forward iterator. Hence, as a best of two worlds, it can perform both sets of the aforementioned actions.

3. What is a crucial difference between an input and a forward iterator? (0.5 P.)
An input iterator is a type of forward iterator. A forward iterator already does everything an input iterator does, alongwith the added advantage of also being able to do the
actions typically associated with an output iterator. Hence, the full potential of reading and modifying vs the lack of modification potential in forward and input iterators is
the prime difference.

4. Why are iterators to a std::vector invalided by insert, push_back or erase? (0.5 P.)
Insert and push_back increase the size of containers and basically change the memory and memory location they hold, and this may create an inadvertent result of making the old
pointers or iterators pointing to old spaces in memory invalid due to dereferencing. Erase functions also could invalidate an iterator as they stop once the condition is met 
within a container and erase an element, thus again changing the size of the container which might create the same scenarios as above or result in a shift of elements making the
pointer reference incorrect.

5. Which container would you choose and why if


a) you need to do sorted traversal and no duplicates are allowed (0.5 P.)
Set would be a good option as it is always ordered, unlike vectors, and vastly more compuationally efficient.


b) the order is not important and no duplicates are allowed (0.5 P.)
An unordered set is a good option as it is efficient just like a set, and our goal is a rather trivial traversing action, and unordered sets can store
data which doesn't have to be ordered.

c) you only need to add elements at the end and want fast traversal (0.5 P.)
Queue is a good option as it is very efficient, as we need fast traversal (as opposed to vectors where insert or push_back operations are rather intensive due to memory adjustments)

d) you need to provide a dictionary that can associate multiple values with the same key (0.5 P.)
Multimap containers are ideal in this situation, as they not only store key-value pairs, but also duplicates can have the same key thus resulting in similar access equivalent to a dictionary functionality.

6. How does an STL algorithm usually indicate "not found" or "failure"? (0.5 P.)
Returning an iteraror like end(), that points to the space after the end of the elements in a container is a way that algorithms return not found. For example, with find, we can use string::npos to indicate
the end and to understand if the find function does not find a match of a substring before the end.

7. What does std::sort(b,e) use as its sorting criterion? (0.5 P.)
Since there's no execution policy for the comparison function object to consider, it will just use a default criterion of greater or lesser and since it involves letters in this case, this criterion
will amount to a lexicographical sorting.

8. Why is the STL container set missing a [] (subscript) operator? (0.5 P.)
To improve efficiency is a major reason for set to not provide [], as indexing would be far more compuationally complex, which is linear time.

9. Why does std::map require its key_type to be copy-constructible and its mapped_type to be default constructible? (1 P.)
It is mainly to work with the subscript operator []. When a map object is compared to a key, via [], if the key is not present then that key needs to be added with the same value and hence a copy constructor is needed,
and since that key will have no value, the value needs to be default initialised and hence the mapped type has to be default constructible. Hence, this serves a general purpose with comparisons and subsequent insertion
in case of absence of the key.


10. Why is std::forward_list missing a size member function and why is the empty member-function still implemented if it is typically equal to container.size() == 0? (1 P.)
The std::forward_list acts as linked list, where the ordering of elements is based on association to each element linked to the next one. If size() is added, it occupies extra storage for internal counter and would make the addition and removal of elements inefficient and complicated. The empty function is a lot more efficient in comparison and operates in constant time, because some containers like list operate in linear time.
