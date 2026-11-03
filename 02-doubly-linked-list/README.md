# Generic doubly linked list

A doubly linked list written as a class template, so it works with any type (`int`, `float`, `string`, ...).

## Operations

| Method | Description |
|---|---|
| `insertar(e)` | Appends an element at the end |
| `quitar(e)` | Unlinks the node holding `e` from the list |
| `mostrar(ASCENDENTE \| DESCENDENTE)` | Prints the list forwards or backwards |
| `primero()`, `ultimo()`, `siguiente()`, `anterior()` | Move the internal cursor |
| `eActual()` | Returns the element under the cursor |

## Files

| File | Contents |
|---|---|
| `NodoDoble.h` | Node template with `siguiente` (next) and `anterior` (previous) pointers |
| `ListaDoble.h` | The list template |
| `main.cpp` | Demo with a list of `float` |

## Run

```bash
make run P=02-doubly-linked-list
```

```text
20.01-> 15.12-> 42.03-> 31.04->
31.04-> 42.03-> 15.12-> 20.01->
Primero: 20.01
Ultimo: 31.04
Se eliminará un elemento
20.01-> 42.03-> 31.04->
31.04-> 42.03-> 20.01->
```
