# Palindrome check with a queue and a stack

Checks whether a number of up to 10 digits is a palindrome (*capicúa* in Spanish), such as `12321`.

## How it works

Each digit is pushed onto a **stack** and added to a **queue** at the same time. Popping from the stack returns the digits in reverse order, and dequeuing returns them in the original order. If every pair matches, the number is a palindrome.

The queue is a fixed-size **circular array** of 10 slots, implemented as the class template `Cola<T>`.

## Files

| File | Contents |
|---|---|
| `PilaT.h` | Stack template built on a singly linked list |
| `main.cpp` | Circular queue template `Cola<T>` and the palindrome check |

## Run

```bash
make run P=04-palindrome-queue-and-stack
```

```text
12321 es capicúa :)
12345 no es capicúa.
```
