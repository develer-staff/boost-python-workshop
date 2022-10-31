#!/usr/bin/env python3

from my_package import my_class


def main() -> None:
    print("Allocating my_class object...")
    a = my_class()

    a.say_hello()

    a.name = "Monty Python"
    print("type(a.name) =", type(a.name))
    print("a.name =", a.name)

    ptr = a.name_ptr  # Note: ptr is a local variable!
    print("type(ptr) =", type(ptr))
    print("ptr =", ptr)
    print("ptr.tobytes() =", ptr.tobytes())
    a.set_name_in_place("Mindy")
    print("ptr.tobytes() =", ptr.tobytes())

    print("type(a.name_as_bytes) =", type(a.name_as_bytes))
    print("a.name_as_bytes =", a.name_as_bytes)
    a.name_as_bytes = b"John Coltrane"
    print("a.name_as_bytes =", a.name_as_bytes)
    print("a.name =", a.name)

    print("Done.")


if __name__ == "__main__":
    main()
