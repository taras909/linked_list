
This library is intended to provide possibility to work with linked list.
One linked list could contain data of a different types. (int or char*)
There is some specific to work with that library, to see it more detailed please use Doxygen to generate documentation. 

To build test application and start use linked list library need to do.
1. Open terminal
2. Move to the directory where Makefile located
3. Type in terminal make all

To clean a current progect please reproduce a previus action but instead of make all just type make clean command in terminal.



Graphic example of linked list with 3 items

        |---------------|                                                   |----------------|             
        |      Head     |                                                   |      Tail      |
        |---------------|                                                   |----------------|             
                ^                                                                   ^
                |                                                                   |
                |                                                                   |
                |                                                                   |
  referring to the first node                                          refering to the last node
                |                                                                   |
                | <------------------------        <------------------------        |
                | |                       |        |                       |        |
   |--------------------------|       |--------------------------|     |--------------------------|        
   |  prev  |  data  |  next  |       |  prev  |  data  |  next  |     |  prev  |  data  |  next  |
   |--------------------------|       |--------------------------|     |--------------------------|
                          |                        |        |                        |
                          ------------------------->        ------------------------->
                
                
                
                
                   
