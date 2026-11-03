# Straight merge sort (external sorting)

Sorts the integers in `datos.txt` without loading them all into memory, using the **straight merge** method (*mezcla directa*). External sorting like this is used when the data is too large to fit in RAM.

## How it works

Starting with runs of length 1, the program repeats two steps until the file is a single sorted run:

1. **Split:** copy alternating runs of the data file into two auxiliary files, `f1` and `f2`.
2. **Merge:** merge pairs of runs from `f1` and `f2` back into the data file, producing runs of twice the length (1, 2, 4, 8, ...).

## Files

| File | Contents |
|---|---|
| `main.cpp` | Split, merge and display functions |
| `datos.txt` | 20 unsorted integers used as input |

## Run

```bash
make run P=06-straight-merge-sort
```

`make run` works on a copy of `datos.txt` inside `build/`, so the original file stays unsorted. If you compile and run the program by hand, it sorts `datos.txt` in place.

```text
Antes: 8 14 5 9 3 4 10 17 23 2 18 30 35 13 28 20 25 31 16 22
Despues: 2 3 4 5 8 9 10 13 14 16 17 18 20 22 23 25 28 30 31 35
```
