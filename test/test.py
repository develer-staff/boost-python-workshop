#!/usr/bin/env python3

from my_package import my_class


def main() -> None:
    print("Allocating my_class object...")
    a = my_class()
    print("Done.")


if __name__ == "__main__":
    main()
