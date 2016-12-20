MiniFramework
=============

The project was initiated with the motto of "a flexible and simple framework". MiniFramework is the name of this project. The MiniFramework was inspired by the Chain Responsibility Pattern [1]. Based on this, I have created a pattern that is safer, more flexible and usable, named the Convey pattern.

Convey Pattern
=============

The Convey pattern is a pattern similar to the "what" on the Convey belt of a factory, and only the Convey belt (interface) and equipment
Flexible scalability. In addition, when using this framework, you can configure your program using some of the well documented and listed Convey aggregates.

There are many good things about the Convey pattern.
 * Simple and structured.
 * You do not need to use pointers: each object is passed in a const reference pass.
 * You do not have to use memory freed: all objects are local variables, and this variable is the type that is propagated
 * Convey assembly is intuitive, so parallelization is easy: When a conveyor is configured for parallelization, the programmer can easily parallelize the library level.
 * All assembly procedures appear in the code: You can see the flow structure of the program at a glance.
 It is possible to generate multiple outputs from multiple inputs: n: m connections are possible.
 * We can faithfully implement the design principles of compositing rather than inheritance: connecting Convey will eventually lead to the completion of Composite.
 * Can adhere to a single responsibility principle: Convey One is very intuitive to give only one role, and the interface forces it.

Object
=============
Most software starts with a very small hint and creates a huge "good thing".
For example, the compiler starts with "(file name, compile option)" and finally generates "(object file)". Of course,
(In our expression, Convey).
An image processor, such as Photoshop, outputs a "corrected image" from the "original image" and passes through many Convey in the middle.
Similarly, various software have a similar structure.

MiniFramework, which is the most basic pattern among github sources, is basically configured (include / MiniFramework)
We are going to add Convey here for various purposes.
Convey that people can use
 * Convey that changes command line argument to Option List.
 * Convey to convert a specific file into a property type
 * Convey: Map that performs other registered Convey in parallel
 * Convey: Reduce waiting for all other registered Convey to be completed
 * Convey that returns a FileSystem object from the specified path / file
 * Convey that separates input string and delimiter into list
 * Convey that outputs objects that satisfy a specific interface to a file
etc

The primary goal of this project is to add Convey, something that seems likely to be useful and likely to be useful.
If necessary, creating a specific demo program for educational purposes is included in the primary goal.


Comment
=============

Imagine it. List of Convey overflowing MiniFramework ...
And intuitive programs where Convey is freely assembled and produced ...


I need your help.


Minhyuk Kwon
Lead Developer - MiniFramework



Reference
=============

[1] Chain of Responsibility Pattern, OoDesign.com, http://www.oodesign.com/chain-of-responsibility-pattern.html
