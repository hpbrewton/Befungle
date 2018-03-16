#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
struct board{
	char * boardArr;
	int x;
	int y; 
} typedef board;


int readFile(char * file, board * board)
{

	FILE * raw = fopen(file, "r");
	assert(raw != NULL);


	char * line = NULL;
	size_t length;
	size_t read;


	size_t x = 0;
	size_t y = 0;
	while ((read = getline(&line,&length,raw)!=-1)) // finds the longest line and lineCount (x and y respectively)
	{
		y++;
		if (length > x)
		{
			x = length;
		}
	}


	board->x = x;
	board->y = y;

	board->boardArr = malloc(x * y * sizeof(char)); 

	fclose(raw);
	fopen(raw, "r");
	int counter = 0;
	while ((read = getline(&line,&length,raw)!=-1)) // populates table with data from memory
	{
		memcpy(line,&(board->boardArr[x*counter*sizeof(char)]),read);
		counter++;
	}

return 0;
}

void printBoard(board * b)
{
write(1,b->boardArr,b->x * b->y * sizeof(char));
}


int main(int argc, char * argv[])
{
board b;
readFile(argv[1],&b);
printBoard(&b);
return 0;
}


