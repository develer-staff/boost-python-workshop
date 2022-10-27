from . import core  # type: ignore


class my_class:
    def __init__(self):
        self._my_class = core.my_class()

    def say_hello(self) -> None:
        self._my_class.say_hello()
