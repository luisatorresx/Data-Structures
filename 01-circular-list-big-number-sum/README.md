# Big-number addition with a circular linked list

Adds two integers of 30 to 50 digits, far beyond what `int` or `long long` can hold, by storing one digit per node in a circular doubly linked list.

## How it works

1. Both numbers are read as text. The shorter one is padded with leading zeros.
2. Each digit is inserted into its own circular doubly linked list.
3. A third list receives the digit-by-digit sums.
4. The result list is then walked to apply carries: any digit of 10 or more keeps its last digit and passes a 1 to the digit before it.

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

Example: `123456789012345678901234567890` + `987654321098765432109876543210` = `1111111110111111111011111111100`
