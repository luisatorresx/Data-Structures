# Balanced multiway merge sort (external sorting)

Sorts the integers in `datos.txt` with the **balanced multiway merge** method (*mezcla equilibrada múltiple*), an external sorting algorithm that improves on [straight merge](../06-straight-merge-sort).

## How it works

Balanced multiway merge is a stable, divide-and-conquer external sort.

1. **Distribute:** the data file is read once and split into *natural runs*, sequences that are already in ascending order. The runs are spread across 3 input files.
2. **Merge:** one run from each input file is merged at a time, always taking the smallest current value. The merged runs are written alternately to 3 output files.
3. Input and output files swap roles, and the merge repeats until only one run remains.

Using natural runs and 6 files (3 in, 3 out) needs far fewer passes than straight merge, which always starts from runs of length 1.

## Files

| File | Contents |
|---|---|
| `main.cpp` | Distribution, multiway merge and display functions |
| `datos.txt` | 20 unsorted integers used as input |

## Run

```bash
make run P=07-balanced-multiway-merge-sort
```

`make run` works on a copy of `datos.txt` inside `build/`, so the original file stays unsorted. If you compile and run the program by hand, it sorts `datos.txt` in place.

```text
Antes: 17 31 5 59 33 41 43 67 11 23 29 47 3 7 71 2 19 57 37 61
Despues: 2 3 5 7 11 17 19 23 29 31 33 37 41 43 47 57 59 61 67 71
```
