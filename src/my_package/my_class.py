class my_class:
    def __init__(self):
        from . import core
        self._my_class = core.my_class()

    def __del__(self):
        self._my_class = None

    def say_hello_from_python(self) -> None:
        print("[Py ] Hello there! I'm a Python function.")

    def say_hello_from_cpp(self) -> None:
        self._my_class.say_hello()
