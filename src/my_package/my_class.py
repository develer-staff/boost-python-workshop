from . import core  # type: ignore
from . import my_item


class my_class:
    def __init__(self):
        self._my_class = core.my_class()

    def say_hello(self) -> None:
        self._my_class.say_hello()

    def sabotage(self) -> None:
        self._my_class.sabotage()

    @property
    def name(self) -> str:
        return self._my_class.name

    @name.setter
    def name(self, value: str) -> None:
        self._my_class.name = value

    @property
    def name_ptr(self) -> memoryview:
        return self._my_class.name_ptr

    def set_name_in_place(self, name: str) -> None:
        self._my_class.set_name_in_place(name)

    @property
    def name_as_bytes(self) -> bytes:
        return self._my_class.name_as_bytes

    @name_as_bytes.setter
    def name_as_bytes(self, value) -> None:
        self._my_class.name_as_bytes = value

    @property
    def str_list(self) -> list[str]:
        return self._my_class.str_list

    @str_list.setter
    def str_list(self, value: list[str]) -> None:
        self._my_class.str_list = value

    @property
    def item_list(self) -> list[my_item]:
        return [my_item(x) for x in self._my_class.item_list]

    @item_list.setter
    def item_list(self, value: list[my_item]) -> None:
        self._my_class.item_list = [x._my_item for x in value]
