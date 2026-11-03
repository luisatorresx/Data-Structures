# Big-number addition with a circular linked list

Adds two integers of 30 to 50 digits, far beyond what `int` or `long long` can hold, by storing one digit per node in a circular doubly linked list.

## How it works

1. Both numbers are read as text. The shorter one is padded with leading zeros.
2. Each digit is inserted into its own circular doubly linked list.
3. A third list receives the digit-by-digit sums.
4. Carries are propagated from the last (least significant) digit back to the first. If the first digit overflows, a new leading `1` node is inserted.

## Files

| File | Contents |
|---|---|
| `Nodo.h` | Node with `info`, `sig` (next) and `ant` (previous) |
| `ListaCircular.h` | Circular doubly linked list: insert first/last, delete by position, count, print, sum and carry |
| `main.cpp` | Input validation and the addition algorithm |

## Run

```bash
make run P=01-circular-list-big-number-sum
```

Example: `999999999999999999999999999999` + `000000000000000000000000000001` = `1000000000000000000000000000000`
