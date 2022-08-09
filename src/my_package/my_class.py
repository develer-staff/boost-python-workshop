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

    @property
    def name_ptr(self) -> memoryview:
        return self._my_class.name_ptr

    def set_name_in_place(self, name:str) -> None:
        self._my_class.set_name_in_place(name)

    def say_hello_from_python(self) -> None:
        print("[Py ] Hello there! I'm a Python function.")

    def say_hello_from_cpp(self) -> None:
        self._my_class.say_hello()
