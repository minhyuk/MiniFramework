MiniFramework
=============

This project, guided by the motto "flexible and simple framework," aims to create a framework that is both adaptable and easy to use. The project's name is MiniFramework.
Inspired by the Chain of Responsibility Pattern[1], I have designed a more secure and flexible pattern, which I have dubbed the Convey Pattern.

Convey Pattern
=============

The Convey pattern is similar to a factory's conveyor belt, where individual components are continuously assembled. By adding a conveyor belt (interface) and facilities (implementation), the pattern can be easily extended. Moreover, when using this framework, you can build a program by selecting and combining documented and listed Convey sets.

The Convey pattern has several advantages:
* It is simple and structured.
* It eliminates the need for pointers: each object is passed by constant reference.
* It does not require memory release: all objects are local variables, and their lifetime is scope-based.
* The assembly of Convey is intuitive, making parallelization easy: once a parallelizable Convey is composed, programmers can easily parallelize it at the library level.
* The entire assembly process is reflected in the code, making it easy to grasp the program's flow structure.
* It allows for multiple inputs to generate multiple outputs: n:m connections are possible.
* It adheres to the composite design principle, rather than inheritance: connecting Conveys ultimately completes a composite.
* It adheres to the single responsibility principle: each Convey has a single, intuitive role, and interfaces enforce this.

Object
=============

Most software starts with a small hint and gradually builds up to something great. For example, a compiler takes "(filename, compile options)" as input and ultimately generates "(object file)". Of course, it goes through various intermediate stages (which we call Convey). Similarly, image processing software like Photoshop starts with a "source image" and outputs a "corrected image", also passing through many Conveys.

Currently, the MiniFramework source code on GitHub is composed of a basic pattern (include/MiniFramework), to which we plan to add various Conveys with different purposes. Some examples of Conveys that people might find useful include:
* A Convey that converts command-line arguments to an option list.
* A Convey that converts a specific file to a property format.
* A Convey that performs registered Conveys in parallel: Map.
* A Convey that waits until all registered Conveys are complete: Reduce.
* A Convey that returns a FileSystem object from a specified path/file.
* A Convey that splits an input string into a list using a delimiter.
* A Convey that outputs an object satisfying a specific interface to a file.

Our first goal is to add Conveys that are likely to be frequently used and prove useful. Additionally, we may create demo programs for educational purposes, depending on needs.

Comment
=============

Imagine it: an overflowing list of Conveys in MiniFramework... and intuitive programs being produced by freely combining Conveys...


We need your help.


Min-Hyuck Kwon
Lead Developer - MiniFramework



Reference
=============

[1] Chain of Responsibility Pattern, OoDesign.com, http://www.oodesign.com/chain-of-responsibility-pattern.html
