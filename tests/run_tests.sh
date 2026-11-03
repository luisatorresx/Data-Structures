#!/usr/bin/env bash
# Runs each program with sample input and checks that the output contains
# the expected result. Run with `make test` (it builds everything first).

set -u
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PASS=0
FAIL=0

# check <description> <program folder> <stdin> <expected text in output>
check() {
  local desc=$1 prog=$2 input=$3 expected=$4
  local workdir output
  workdir="$(mktemp -d)"
  cp "$ROOT/$prog"/*.txt "$workdir"/ 2>/dev/null || true
  output="$(cd "$workdir" && printf '%b' "$input" | "$ROOT/build/$prog" 2>&1)"
  rm -rf "$workdir"
  if grep -qF -- "$expected" <<< "$output"; then
    PASS=$((PASS + 1)); echo "  ok    $prog: $desc"
  else
    FAIL=$((FAIL + 1)); echo "  FAIL  $prog: $desc"
    echo "        expected to find: $expected"
    echo "        got:"; sed 's/^/          /' <<< "$output"
  fi
}

echo "Running tests"

check "adds two 30-digit numbers" 01-circular-list-big-number-sum \
  "123456789012345678901234567890\n987654321098765432109876543210\nn\n" \
  "1111111110111111111011111111100"

check "removes an element from the list" 02-doubly-linked-list \
  "" \
  "20.01-> 42.03-> 31.04->"

check "converts the built-in example" 03-infix-to-postfix-stack \
  "n\n" \
  "abc+def^/-g-*h-"
check "converts (a+b)*c" 03-infix-to-postfix-stack \
  "s\n(a+b)*c\nn\n" \
  "ab+c*"

check "detects a palindrome" 04-palindrome-queue-and-stack \
  "12321\nn\n" \
  "12321 es capicúa"
check "detects a non-palindrome" 04-palindrome-queue-and-stack \
  "12345\nn\n" \
  "12345 no es capicúa"

check "fills the table with load factor 1" 05-hash-table-chaining \
  "1\n2\n" \
  "Factor de carga: 1"

check "sorts datos.txt" 06-straight-merge-sort \
  "" \
  "Despues: 2 3 4 5 8 9 10 13 14 16 17 18 20 22 23 25 28 30 31 35"

check "sorts datos.txt" 07-balanced-multiway-merge-sort \
  "" \
  "Despues: 2 3 5 7 11 17 19 23 29 31 33 37 41 43 47 57 59 61 67 71"

echo
echo "$PASS passed, $FAIL failed"
[ "$FAIL" -eq 0 ]
