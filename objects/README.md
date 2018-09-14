# Objects : Numerical Oriented Programming

An anti-abstract system of objects based on literally defined byte sequences.

## Numerical Oriented Programming

The first rule of programming is "**everything is a file**". And the zeroth rule of programming is "**everything is a number**". By anti-abstracting a programmable system of objects to what it most literally is - a system of byte sequences - we can establish a highly versatile form where functional programming and object oriented programming converge. **Numerical Oriented Programming** is based on a question: what if I could add two objects together like a primitive? What if that feature belonged to all objects regardless of their type? Consider what a system of numerical objects could look like:

> Object oracle = (User alice) + (User bob)

In very literal C code this could take the form of:

> (struct Object oracle) = (struct User alice) + (struct User bob);

In its current form, with no language altering preprocessors implemented, the above code looks like this:

> struct Object oracle = add(struct User* alice, struct User* bob); 
