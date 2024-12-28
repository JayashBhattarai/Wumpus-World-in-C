#include <stdio.h>

int map[10][10];
void create_map();
void mini_map();
void breeze();
void stench();
void player();
void wumpus();

int main()
{
    create_map();
}

void create_map()
{
    int i, j;
    //int map[i][j];
    for (i=0 ; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("+ ");
        }
        printf("\n");
    }
}