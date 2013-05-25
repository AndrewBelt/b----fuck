bfuck
===

`bfuck` is a [brainfuck](http://esolangs.org/wiki/brainfuck) interpreter written in C.

Usage
---

To build, simply `make`.

To run, `./bfuck <filename>`, where filename can be any plaintext source file.

Language
---

The brainfuck memory is analogous to a strip of tape which can be moved, edited, and read.
In the `bfuck` implementation, the pointer is initialized immediately after the last byte in the source code, so one can rewind the tape to modify the source code during runtime.

The brainfuck language uses the following eight operations. All other characters are ignored and can be used as in-source comments.

* `>`  Moves the pointer to the right
* `<`  Moves the pointer to the left
* `+`  Increments the value at the pointer
* `-`  Decrements the value at the pointer
* `.`  Prints the value at the pointer to stdout (as a character)
* `,`  Reads a character from stdin and writes the value
* `[`  Begins a while loop
* `]`  Loops if the value under the pointer is true, i.e. nonzero

