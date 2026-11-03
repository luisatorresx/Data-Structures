# Hash table with separate chaining

**Assignment:** find the longest chain in a chained hash table that stores 1,000 random integers with a load factor of 1.

With a load factor of 1 and 1,000 elements, the table has 1,000 slots.

## How it works

- The hash function is `key mod table size`.
- Each slot holds a linked list (a *chain*) of the keys that hash to it. New keys are added at the front of the chain.
- Duplicate keys are rejected, and a new random number is drawn so exactly 1,000 distinct keys are stored.
- The program prints the load factor and the length of the longest chain.

## Files

| File | Contents |
|---|---|
| `main.cpp` | `Elemento` (chain node), `TablaHash` (insert, search, longest chain, load factor) and a small menu |

## Run

```bash
make run P=05-hash-table-chaining
```

```text
--Factor de carga: 1
--Lista más grande: 5
```
