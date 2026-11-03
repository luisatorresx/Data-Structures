# Infix to postfix conversion with a stack

Converts arithmetic expressions from infix notation (`a+b`) to postfix notation (`ab+`) using a generic stack, `PilaT<T>`, built on a singly linked list.

## How it works

The expression is read left to right:

- **Operands** (letters and digits) go straight to the output.
- **`(`** is pushed onto the stack.
- **`)`** pops operators to the output until the matching `(`.
- **Operators** pop every operator of greater or equal precedence, then are pushed.
- At the end, the remaining operators are popped to the output.

| Operator | Meaning | Precedence |
|---|---|---|
| `^` | Power | 3 |
| `*` `/` | Multiply, divide | 2 |
| `+` `-` | Add, subtract | 1 |

Invalid characters and expressions ending in an operator are reported to the user.

## Files

| File | Contents |
|---|---|
| `PilaT.h` | Stack template: push (`insertar`), pop (`quitar`), peek (`cimaPila`), `pilaVacia`, `limpiarPila` |
| `main.cpp` | Precedence table and the conversion algorithm |

## Run

```bash
make run P=03-infix-to-postfix-stack
```

| Infix | Postfix |
|---|---|
| `a*(b+c-(d/e^f)-g)-h` | `abc+def^/-g-*h-` |
| `(a+b)*c` | `ab+c*` |
