# Studio 19
1. The tests we ran for number 2:
We created a abstract file, an image file, specifically. We then used the new read method to change its member variable contents
We then displayed our input, changed the input to something else, and then displayed it again, using the new functionality of the read method we just wrote.
2. We call accept on an abstract file which calls one of the visit methods on the visitor: double dispatch. Because the accept method doesn't need to know the type of visitor being
used and the visitor doesn't need to know the type of file being used, it is double dispatch
3. The visitor class delegates by leaving the display portion of the old read method to concrete objects that inherit the abstract visitor class. This means that if we want to add additional functionality, we only have to make a new object that inherits the visitor, instead of needing to create a new method in each concrete file class.
4. If we have a lot of concrete file types, the visitor class would need to have a lot of methods in order to display each of these individual file types. This is the disadvantage of the visitor pattern. It works well when there are a lot of different visitor classes and not a lot of objects that these classes can be called on, but if there are too many objects that the visitor can be called on, the class becomes cluttered and not as useful.

