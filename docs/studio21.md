# Studio 21
1. 
2. We declare a virtual constructor in the base class because if one of our concrete commands requires the deletion of more complicated member variables, we are able to override the destructor and do this process ourselves. On the other hand, if one of the concrete classes does not have any member variables that are difficult to destruct, we can simplify our code by inheriting the destructor that has already been implemented.
3. This makes our code flexible because we can use any combination of file system and file factory objects without needing to change the call to the command prompt. In addition, this makes our code extensible, because if we wanted to add a new file system or factory, the command prompt would not need to change.
4. We created a file with the touch command, and after exiting from the command prompt, check to see if that file exists in the file system by attempting to open the file.
