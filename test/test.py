#!/usr/bin/env python3

from my_package import my_class


def main() -> None:
    print("Allocating my_class object...")
    a = my_class()

    a.say_hello()

    a.name = "Monty Python"
    print("type(a.name) =", type(a.name))
    print("a.name =", a.name)

    print("Done.")


if __name__ == "__main__":
    main()
