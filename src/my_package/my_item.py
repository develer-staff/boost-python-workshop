from . import core  # type: ignore


class my_item:
    def __init__(self, obj: core.my_item = None):
        if obj is None:
            self._my_item = core.my_item()
        else:
            self._my_item = obj

    def __repr__(self):
        return f"my_item('{self.name}')"

    @property
    def name(self) -> str:
        return self._my_item.name

    @name.setter
    def name(self, value) -> None:
        self._my_item.name = value

    @staticmethod
    def from_str(value: str):
        a = my_item()
        a.name = value
        return a
