#include <stdio.h>

int isboardfull (int size, char board[size][size]);
int wincheck (char m, int size, char board[size][size]);

int main (void)
{
	int size, playernum, move; //size defines the 2D dimension of the tic-tac-toe game board 
	int count = 0;
	char c; // to handle input 
	
	printf("Size of the BOARD? : "); // print board range 3 to 9
	while (scanf("%d", &size)!=1 || size < 3 || size > 9)
	{
		printf("Invalid Input. Try Again.\n");
		printf("Size of the BOARD? : ");
		while ((c = getchar()) != '\n') {}
	} 	while ((c = getchar()) != '\n') {}
	
	printf("# of players?: ");
	while (scanf("%d", &playernum)!=1 || playernum<2)
	{
		printf("Invalid Input\n");
		if (playernum<2) printf("Minimum Number of Players are 2\n");
		printf("# of players?: ");
		while ((c = getchar()) != '\n') {}
	}	while ((c = getchar()) != '\n') {}

	char board[size][size]; 
	char player[playernum]; // Now, playernum and size have been initialized.

	for (int i = 0; i < playernum; i++) // Asks players to choose their characters (A, B, C, ..., a, b, etc.)
	{
		printf("Player %d: ", i+1);
		while (scanf(" %c", &player[i])!=1)
		{
			printf("Invalid Input. Just Type One Character.\n"
			"# of players?: ");
			while ((c = getchar()) != '\n') {}
		}	while ((c = getchar()) != '\n') {}
	}

	for	(int i=0; i < size; i++) //initializes the values of board and set all to blankspace
	{
	for (int j = 0; j < size; j++)
	board[i][j] = ' ';
	}

	

	while (1)
	{
        char current_player = player[count];

        if (isboardfull(size, board)) //if no cell have blankspace character, the game draws
        {
            printf("DRAW!\n");
            break;
        }

        printf(" %c: ", current_player);

	  while (scanf("%d", &move)!=1)
	  {
		printf("Invalid Move!\n");
		printf(" %c: ", current_player);
		while ((c = getchar()) != '\n') {}
	  }	while ((c = getchar()) != '\n') {}
        
        int row_index = ((move)/10)-1; int column_index = ((move)%10)-1; // change moves (23) to rows_index(2) and column_index(3) of the cell of the board
        if (row_index >= 0 && row_index <= size && column_index >= 0 && column_index <= size)
        {
            if (board[row_index][column_index]==' ')
            {
                board[row_index][column_index] = current_player;
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        printf("[%c]", board[i][j]);
                    }
                    printf("\n");
                }
                
            }
            else 
            {
                printf("Invalid Move!\n");
                count--;
            }
        }
        else 
            {
                printf("Invalid Move!\n");
                count--;
            }
        if (wincheck(current_player, size, board))
        {
            printf("%c WINS!\n", current_player);
            break;
        }
        count++;

	  if (count == playernum)
	  {
		count = 0;
        }
	  
    }
    getchar();
    return 0;
}

//user-defined functions

int isboardfull (int size, char board[size][size])
{
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
            	if (board[i][j] == ' ')
            	return 0;
            }
        }
    return 1;
}

int wincheck(char m, int size, char board[size][size])
{
    int diagonalrule = 0;
    int diagonalrule2 = 0;
        for (int i = 0; i < size; i++)
        {
            int rowrule = 0;
            int columnrule = 0;
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == m) {rowrule++;}
                if (rowrule == size) {
                return 1;
                }
            }
            
            for (int k = 0; k < size; k++)
            {
                if (board[k][i] == m)
                {columnrule++;}
                if (columnrule == size) {
                return 1;
                }
            }

            if (board[i][i] == m)
            {diagonalrule++;}
            if (diagonalrule == size) {
            return 1;
            }

            if (board[i][size-(i+1)] == m)
            {diagonalrule2++;}
            if (diagonalrule2 == size) {
            return 1;
            }
        }
    return 0;
}