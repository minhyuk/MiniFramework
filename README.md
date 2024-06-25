MiniFramework
=============

The project was initiated with the motto "flexible and simple framework." MiniFramework is the name of this project. Inspired by the Chain of Responsibility Pattern [1], I have created a safer, more flexible, and usable pattern called the Convey pattern.

Convey Pattern
=============

The Convey pattern is inspired by the conveyor belt system in a factory, where only the conveyor belt (interface) and equipment are involved, allowing for flexible scalability. When using this framework, you can configure your program using well-documented and listed Convey aggregates.

The Convey pattern offers several benefits:
* Simple and structured design
* No need to use pointers: each object is passed as a const reference
* No need to worry about memory management: all objects are local variables, and this variable is the type that is propagated
* Convey assembly is intuitive, making parallelization easy: when a conveyor is configured for parallelization, the programmer can easily parallelize the library
* All assembly procedures are visible in the code: you can see the flow structure of the program at a glance
* Multiple outputs can be generated from multiple inputs: n:m connections are possible
* The Convey pattern faithfully implements the design principles of composition over inheritance: connecting Convey will eventually lead to the completion of Composite
* The single responsibility principle is upheld: Convey is very intuitive in giving only one role, and the interface forces it

Object
=============

Most software starts with a small input and generates a significant output. For example, a compiler takes in a file name and compile options and eventually generates an object file. Similarly, an image processor like Photoshop takes in an original image and passes it through many Convey stages to produce a corrected image. Various software have a similar structure.

The MiniFramework, which is the most basic pattern among GitHub sources, is basically configured (including MiniFramework). We aim to add Convey for various purposes. Some examples of Convey include:
* Convey that converts command-line arguments to an Option List
* Convey that converts a specific file into a property type
* Convey: Map that performs other registered Convey in parallel
* Convey: Reduce, which waits for all other registered Convey to be completed
* Convey that returns a FileSystem object from a specified path/file
* Convey that separates an input string and delimiter into a list
* Convey that outputs objects that satisfy a specific interface to a file
and many more.

The primary goal of this project is to add Convey that seem likely to be useful. If necessary, creating a specific demo program for educational purposes is included in the primary goal.

Comment
=============

Imagine it: a list of Convey overflowing MiniFramework ... and intuitive programs where Convey is freely assembled and produced ...

I need your help.

Minhyuk Kwon
Lead Developer - MiniFramework


Reference
=============

[1] Chain of Responsibility Pattern, OoDesign.com, http://www.oodesign.com/chain-of-responsibility-pattern.html
