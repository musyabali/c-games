#include <stdio.h>

int isbrdfull (char brd[3][3]);
int wincheck (char m, char brd[3][3]);

int main (void) 
{
    char brd[3][3] = {{' ', ' ',' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    int x = 0; int o = 0;
    char move;

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

    the_move: 

    scanf(" %c", &move);
    if (move == 'X' || move == 'x')
    {
        goto x_move;
    }
    else if (move =='O'|| move == 'o')
    {
        goto o_move;
    }

    else {
        printf("Oops! Invalid character! Enter either X or O: ");
        goto the_move;
    }

    // The game loop begins

    while (1)

    {
        if (isbrdfull(brd))
        {
            printf("DRAW!\n");
            break;
        }

        x_move:
        printf("X: "); scanf("%d", &x);
        int Xi = ((x)/10)-1; int Xj = ((x)%10)-1;
        if (Xi >= 0 && Xi <= 2 && Xj >= 0 && Xj <= 2)
        {
            if (brd[Xi][Xj]==' ')
            {
                brd[Xi][Xj] = 'X';
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
                goto x_move;
            }
        }
        else 
            {
                printf("Invalid Move!\n");
                goto x_move;
            }
        if (wincheck('X', brd))
        {
            printf("X wins!\n");
            break;
        }
        
        // O starts here 

        if (isbrdfull(brd))
        {
            printf("DRAW!\n");
            break;
        }

        o_move:
        printf("O: "); scanf("%d", &o);
        int Oi = ((o)/10)-1; int Oj = ((o)%10)-1;
        if (Oi >= 0 && Oi <= 2 && Oj >= 0 && Oj <= 2)
        {
            if (brd[Oi][Oj]==' ')
            {
                brd[Oi][Oj] = 'O';
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
                goto o_move;
            }
        }
        else 
            {
                printf("Invalid Move!\n");
                goto o_move;
            }

        if (wincheck('O', brd))
        {
            printf("O wins!\n");
            break;
        }
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
