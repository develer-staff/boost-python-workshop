#!/usr/bin/env python3

import my_package

def main() -> None:
    print(">>> a = my_package.my_class()")
    a = my_package.my_class()


    print(">>> a.say_hello_from_python()")
    a.say_hello_from_python()

    print(">>> a.say_hello_from_cpp()")
    a.say_hello_from_cpp()


    print(">>> a.name = \"Monty Python\"")
    a.name = "Monty Python"

    print(">>> print(type(a.name), a.name)")
    print(type(a.name), a.name)

    print(">>> name_ptr = a.name_ptr")
    name_ptr = a.name_ptr

    print(">>> print(type(name_ptr), name_ptr, name_ptr.tobytes())")
    print(type(name_ptr), name_ptr, name_ptr.tobytes())

    print(">>> a.set_name_in_place(\"Mindy\")")
    a.set_name_in_place("Mindy")

    print(">>> print(name_ptr, name_ptr.tobytes())")
    print(name_ptr, name_ptr.tobytes())

    print(">>> a = None")
    a = None


    print("Done.")


if __name__ == "__main__":
    main()
