from typing import Generic, TypeVar

INITIAL_CAPACITY = 10


T = TypeVar("T")


class CircularArrayQueue(Generic[T]):
    """
    size: current amount of elems
    capacity: current capacity of the queue

    head pointer

    push can be move head pointer to the left and set it
    pop

    """

    def __init__(self) -> None:
        self.capacity = INITIAL_CAPACITY
        self.size = 0
        self._head = 0
        self._tail = -1
        self._backing_array: list[T | None] = [None] * self.capacity

    def push(self, x: T) -> None:
        if self.size == self.capacity:
            self.resize()

        self._tail = (self._tail + 1) % len(self._backing_array)
        self._backing_array[self._tail] = x
        self.size += 1

    def pop(self) -> T:
        assert not self.empty(), "Tried to pop an empty queue"

        val = self._backing_array[self._head]
        self._backing_array[self._head] = None
        self._head = (self._head + 1) % len(self._backing_array)
        self.size -= 1

        assert val is not None, "Head should not point to None"

        return val

    def peek(self) -> T:
        assert not self.empty(), "Tried to pop an empty queue"
        val = self._backing_array[self._head]
        assert val is not None, "Head should not point to None"

        return val

    def empty(self) -> bool:
        return self.size == 0

    def resize(self) -> None:
        self.capacity *= 2
        new_backing_array: list[T | None] = [None] * self.capacity

        idx = self._head
        for i in range(self.size):
            new_backing_array[i] = self._backing_array[idx]
            idx = (idx + 1) % len(self._backing_array)

        self._tail = self.size - 1
        self._head = 0

    def shrink(self):
        raise NotImplementedError("Shrink when size is less than 1/4 capacity")


queue = CircularArrayQueue()

queue.push(1)
print(queue._backing_array)
queue.push(2)
print(queue._backing_array)
