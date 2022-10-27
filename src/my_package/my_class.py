from . import core  # type: ignore


class my_class:
    def __init__(self):
        self._my_class = core.my_class()

    def say_hello(self) -> None:
        self._my_class.say_hello()

    @property
    def name(self) -> str:
        return self._my_class.name

    @name.setter
    def name(self, value: str) -> None:
        self._my_class.name = value
