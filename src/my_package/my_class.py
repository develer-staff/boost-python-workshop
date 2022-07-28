class my_class:
    def __init__(self):
        from . import core
        self._my_class = core.my_class()

    def __del__(self):
        self._my_class = None

    @property
    def name(self) -> str:
        return self._my_class.name

    @name.setter
    def name(self, value) -> None:
        self._my_class.name = value

    def say_hello_from_python(self) -> None:
        print("[Py ] Hello there! I'm a Python function.")

    def say_hello_from_cpp(self) -> None:
        self._my_class.say_hello()
