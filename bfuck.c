
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 65536
#define BRACKET_STACK_SIZE 1024

/*
 *  >  Moves the pointer to the right
 *  <  Moves the pointer to the left
 *  +  Increments the value at the pointer
 *  -  Decrements the value at the pointer
 *  .  Prints the ASCII value at the pointer
 *  ,  Reads from stdin and writes the value
 *  [  Begins a while loop
 *  ]  Loops if the value under the pointer is nonzero
 */


int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		printf("belt's b****fuck interpreter\n");
		printf("usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	
	/* Allocate the memory block */
	
	char *source = (char *) calloc(BUFFER_SIZE, sizeof(char));
	
	/* Read the entire file to memory */
	
	FILE *source_file = fopen(argv[1], "rb");
	
	if (source_file == NULL)
	{
		fputs("error: cannot read file\n", stderr);
		exit(1);
	}
	
	size_t source_size = fread(source, sizeof(char), BUFFER_SIZE, source_file);
	fclose(source_file);

	/* Initialize pointers */
	
	char *op = source;
	char *data = source + source_size;
	char *p = data;
	char **bracket_stack = (char **) calloc(BRACKET_STACK_SIZE, sizeof(char *));
	char **b = bracket_stack;
	
	/* Loop through each operation */
	
	do
	{
		switch (*op)
		{
			case '>': p++;
				break;
			case '<': p--;
				break;
			case '+': (*p)++;
				break;
			case '-': (*p)--;
				break;
			case '.': putchar(*p);
				break;
			case ',': *p = getchar();
				break;
			case ']': if (*p) op = *(b - 1);
				break;
			case '[': *(b++) = op;
				break;
		}
	} while (++op < data);

	free(source);

	return 0;
}

