#include <stdlib.h>
#include <stdio.h>

#define MEM_SIZE 65536
#define STACK_SIZE 1024

/*

## B****fuck language reference

>  Moves the pointer to the right
<  Moves the pointer to the left
+  Increments the value at the pointer
-  Decrements the value at the pointer
.  Prints the ASCII value at the pointer
,  Reads from stdin and writes the value
[  Begins a while loop
]  Loops if the value under the pointer is nonzero

*/


int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		fprintf(stderr, "belt's b****fuck interpreter\n");
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	
	/* Read the entire file to memory */
	FILE *source_file = fopen(argv[1], "r");
	
	if (source_file == NULL)
	{
		fprintf(stderr, "error: could not open file\n");
		exit(1);
	}
	
	/* Set up memory */
	char *mem = calloc(MEM_SIZE, 1);
	int *op_stack = calloc(STACK_SIZE, sizeof(int *));
	
	int p = 0;
	int op = 0;
	int op_stack_pos = 0;
	
	/* Read the file into the beginning of the memory */
	size_t source_size = fread(mem, 1, MEM_SIZE, source_file);
	
	if (source_size <= 0)
	{
		fprintf(stderr, "error: could not read file\n");
		exit(1);
	}
	
	fclose(source_file);
	p = source_size;
	
	/* Loop through each operation */
	do
	{
		switch (mem[op])
		{
			case '>': p++;
				break;
			case '<': p--;
				break;
			case '+': mem[p]++;
				break;
			case '-': mem[p]--;
				break;
			case '.': putchar(mem[p]);
				break;
			case ',': mem[p] = getchar();
				break;
			case ']':
				op_stack_pos--;
				if (op_stack_pos < 0)
				{
					fprintf(stderr, "Reached mismatched ']'\n");
					exit(1);
				}
				if (mem[p])
					op = op_stack[op_stack_pos] - 1;
				break;
			case '[': op_stack[op_stack_pos++] = op;
				break;
			default:
				/* Ignore non-op characters */
				break;
		}
	} while (++op < source_size);
	
	free(mem);
	free(op_stack);
	
	return 0;
}
