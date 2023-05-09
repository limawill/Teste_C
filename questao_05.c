#include <stdio.h>
#include <stdlib.h>

#define LINES 3
#define COLS 5

/****************
 *  Nesse exercicio algumas alterações que fiz foi utilizar a constantes LINES e COlS para definições do while
 * e modifiquei a função create_slots, sendo sincero faz pelo menos 5 anos que não utilizo no dia a dia 
 * a locação de memoria, então achei mais facil fazer alguns debugs entender o que essa função fazia e modificar ela
 * para utilizar uma matrix, nesse caso pelo acredito que não tenha afetado o desempenho.
 *  
****************/

void create_slot(int slot[][COLS])
{
    int linha, coluna;

    for (linha = 0; linha < LINES; linha++)
    {
        printf("Enter line values (5 values) %d:\n", linha + 1);
        for (coluna = 0; coluna < COLS; coluna++)
        {
            scanf("%d", &slot[linha][coluna]);
        }
    }
}

int main(void)
{
    int premio[LINES][COLS] = {{1, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}};
    int slot[LINES][COLS];
    int lines = 0;
    int cols = 0;
    create_slot(slot);
    int comp = slot[0][0];
    int count_prize = 0;
    while (lines < LINES && count_prize != COLS)
    {
        while (cols < COLS)
        {
            if (comp == slot[lines][cols] && premio[lines][cols])
            {
                count_prize++;
            }
            cols++;
        }
        cols = 0;
        lines++;
        if (lines == LINES && count_prize != COLS)
        {
            lines = 0;
            count_prize = 0;
            create_slot(slot);
            comp = slot[0][0];
        }
    }
    printf("You are the winner!\n");
    return (0);
}