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


	char head;
	size_t length;
	size_t x = 0;
	size_t y = 0;
	while ((head = fgetc(raw))!=EOF) // finds the longest line and lineCount (x and y respectively)
	{
		if (head == '\n') 
		{
			y++;
			if (length > x)
			{
				x = length;
			}
			length = 0;
		}
		else
		{
			length++;
		}
	}


	board->x = x;
	board->y = y;

	printf("%lu\n%lu\n", x,y);

	board->boardArr = malloc(x * y * sizeof(char)); 

	fclose(raw);
	raw = fopen(file, "r");

	char * line = NULL;
	length = 0;
	size_t read;



	int counter = 0;


	

	while ((read = getline(&line,&length,raw)!=-1)) // populates table with data from memory
	{
		memcpy(&(board->boardArr[x*counter*sizeof(char)]),line,(size_t)(strchr(line,'\n')-line));
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


