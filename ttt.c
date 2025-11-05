#include <stdio.h>

int isbrdfull (char brd[3][3]);
int wincheck (char m, char brd[3][3]);

int main (void) 
{
    char brd[3][3] = {{' ', ' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    int x = 0; 
    char move;
    int ox;

    printf(
        "\n\n"
        "________________________________________\n"
        "WELCOME TO THIS SIMPLE TIC-TAC-TOE GAME\n"
        "========================================\n\n"

        "How to play moves?\n"
        " # The moves are all like the indices of\n   a 3x3 matrices\n\n"
        " # the allowed range is 11,12,13,21,...,33\n"
        "________________________________________\n\n"

        "CHOOSE WHO'LL PLAY FIRST? 'X' OR 'O': "
    );


    scanf(" %c", &move);
    if (move == 'X' || move == 'x')
    {
        ox = 0;
    }
    else if (move =='O'|| move == 'o')
    {
        ox = 1;
    }
    else 
    {
        //Sets the X as the default first player
        ox = 0;
    }

    // The game loop begins

    while (1)
    {
        if (ox%2==0) move = 'X';
        else move = 'O';

        if (isbrdfull(brd))
        {
            printf("DRAW!\n");
            break;
        }

        printf("%c: ", move);
        scanf("%d", &x);
        
        int rw = ((x)/10)-1; int cl = ((x)%10)-1;
        if (rw >= 0 && rw <= 2 && cl >= 0 && cl <= 2)
        {
            if (brd[rw][cl]==' ')
            {
                brd[rw][cl] = move;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        printf("[%c]",brd[i][j]);
                    }
                    printf("\n");
                }
                
            }
            else 
            {
                printf("Invalid Move!\n");
                ox--;
            }
        }
        else 
            {
                printf("Invalid Move!\n");
                ox--;
            }
        if (wincheck(move, brd))
        {
            printf("%c wins!\n", move);
            break;
        }
        ox++;
    }
    return 0;
}

//USER-DEFINED FUNCTIONS

int isbrdfull (char brd[3][3])
{
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (brd[i][j] == ' ')
                {
                   return 0;
                }
            }
        }
    return 1;
}

int wincheck(char m, char brd[3][3])
{
    if (
            (brd[0][0] == m && brd[0][1] == m && brd[0][2] == m) ||
            (brd[1][0] == m && brd[1][1] == m && brd[1][2] == m) ||
            (brd[2][0] == m && brd[2][1] == m && brd[2][2] == m) ||
            (brd[0][0] == m && brd[1][1] == m && brd[2][2] == m) ||
            (brd[0][2] == m && brd[1][1] == m && brd[2][0] == m) ||
            (brd[0][0] == m && brd[1][0] == m && brd[2][0] == m) ||
            (brd[0][1] == m && brd[1][1] == m && brd[2][1] == m) ||
            (brd[0][2] == m && brd[1][2] == m && brd[2][2] == m) 
    )
    {
        return 1;
    } else return 0;
}