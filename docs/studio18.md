# Studio 18
1. Our group has come to the conclusion that the createFile method is a factory method because the specific type
of Abstract File that is created is done based on the whichever file the client wants to create: it is done so
polymorphically. 
To create a new file system implementation, we would have to change the createFile method to support new file types.
The difficult part here would be defining our AbstractFileSystem interface in the new file type.
With new file systems, creat file would act as a factory method and choose the correct file system to use based on the 
Abstract Files used.
2. 
You would only want to create a new concrete file factory class if you have a new file 
system that takes file types that aren't supported by other file systems, so you have to
make sure that these other file types are put into a system that can accomodate them. 
Besdies this, one instance of a class is sufficient, because the method can keep calling
create to get new files without any problems. To accomodate different file types, we will 
add more if statements to the create file method in the file factory class. The same 
factory can be used for two file systems that implement the same file types differently 
because it is only concerned with the creation of the files, but the file system code 
must be different because it is concered with the management of the files, which is 
different for the two file systems.
3. To check this studio works, we creates an abstract file system and an abstract file factory. We then used the abstract file system method addFile to 
create a new file using the file factory we made and then add the file to the file system. We then take the file we created, opened it, and wrote to it, read to it
and then closed it.
 
