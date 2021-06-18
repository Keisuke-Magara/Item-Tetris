// coding: shift-JIS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define FIELD_HEIGHT 23
#define FIELD_WIDTH 12
#define BufferSize (FIELD_HEIGHT-1)*(FIELD_WIDTH-2)
// Block Type
#define I_Block 0
#define O_Block 1
#define T_Block 2
#define J_Block 3
#define L_Block 4
#define S_Block 5
#define Z_Block 6

void init (void);
void display (void);
void blockFall (void);
void blockGenerate (int);
int get_bBuffNo (int, int);

typedef struct
{
    int type; // 0-6
    int x[4], y[4];
    int left, right, up, bottom;
    int angle; // 0 or 90 or 180 or 270
    int active;
} Block;


int field [FIELD_HEIGHT][FIELD_WIDTH] = {
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}
};

Block blockBuffer[BufferSize];
int no = -1; // the ordinal number of current controlled blockBuffer

int main (void)
{
    time_t t;
    init();
    display();
    t = time(NULL);
    while (1){
        if (t != time(NULL)){
            t = time(NULL);
            if (blockBuffer[no].active == 0){
                blockGenerate(1);
                display();
                continue;
            }
            blockFall();
            display();
            //getch();
        }
    }
}

void init (void)
{
    for (int i=0;i<BufferSize;i++){
        blockBuffer[no].active = 0;
    }
    srand(time(NULL));
    for (int i=0;i<FIELD_HEIGHT;i++){
        for (int j=0;j<FIELD_WIDTH;j++){
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    getch();
}

void display (void)
{
    system("cls");
    printf(">>> The TETRIS <<<\n\n");
    printf("Block Type = %d\n", blockBuffer[no].type);
    printf("blockBuffer[no].active = %d\tblockBuffer[no](x,y) = (%2d,%2d)\n\n", blockBuffer[no].active, blockBuffer[no].x[0], blockBuffer[no].y[0]);
    for (int i=0;i<FIELD_HEIGHT;i++){
        for (int j=0;j<FIELD_WIDTH;j++){
            if (field[i][j] != 0){
                printf("■");
            }else{
                printf ("　");
                //printf("0");
            }
        }    
        printf("\n");
    }
    printf("\n");
}

void blockFall (void)
{
    if (blockBuffer[no].active != 0){
        if (field[blockBuffer[no].xbottom + 1
        for (int i=0;i<4;i++){
            blockBuffer[no].y[i]++;
        }
        printf("(y[0], y[1], y[2], y[3]) = (%2d, %2d, %2d, %2d)\n\n", blockBuffer[no].y[0], blockBuffer[no].y[1], blockBuffer[no].y[2], blockBuffer[no].y[3]);
        
    }else{
        blockBuffer[no].active = 0;
    }
}

void blockGenerate (int type)
{
    blockBuffer[no].type = type;
    blockBuffer[no].active = 1;
    int x = 5;
    int y = 1;
    switch (blockBuffer[no].type)
    {
    case I_Block:
        blockBuffer[no].x[0] = x -1;
        blockBuffer[no].y[0] = y;
        blockBuffer[no].x[1] = x;
        blockBuffer[no].y[1] = y;
        blockBuffer[no].x[2] = x + 1;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x + 2;
        blockBuffer[no].y[3] = y;
        break;

    case O_Block:
        blockBuffer[no].x[0] = x;
        blockBuffer[no].y[0] = y - 1;
        blockBuffer[no].x[1] = x + 1;
        blockBuffer[no].y[1] = y - 1;
        blockBuffer[no].x[2] = x;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x + 1;
        blockBuffer[no].y[3] = y;
        break;

    case T_Block:
        blockBuffer[no].x[0] = x;
        blockBuffer[no].y[0] = y - 1;
        blockBuffer[no].x[1] = x - 1;
        blockBuffer[no].y[1] = y;
        blockBuffer[no].x[2] = x;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x + 1;
        blockBuffer[no].y[3] = y;
        break;
    
    case J_Block:
        blockBuffer[no].x[0] = x - 1;
        blockBuffer[no].y[0] = y - 1 ;
        blockBuffer[no].x[1] = x - 1;
        blockBuffer[no].y[1] = y;
        blockBuffer[no].x[2] = x;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x + 1;
        blockBuffer[no].y[3] = y;
        break;

    case L_Block:
        blockBuffer[no].x[0] = x +1;
        blockBuffer[no].y[0] = y - 1;
        blockBuffer[no].x[1] = x;
        blockBuffer[no].y[1] = y;
        blockBuffer[no].x[2] = x + 1;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x + 2;
        blockBuffer[no].y[3] = y;
        break;

    case S_Block:
        blockBuffer[no].x[0] = x;
        blockBuffer[no].y[0] = y - 1;
        blockBuffer[no].x[1] = x + 1;
        blockBuffer[no].y[1] = y - 1;
        blockBuffer[no].x[2] = x -1;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x;
        blockBuffer[no].y[3] = y;
        break;

    case Z_Block:
        blockBuffer[no].x[0] = x -1;
        blockBuffer[no].y[0] = y - 1;
        blockBuffer[no].x[1] = x;
        blockBuffer[no].y[1] = y - 1;
        blockBuffer[no].x[2] = x;
        blockBuffer[no].y[2] = y;
        blockBuffer[no].x[3] = x + 1;
        blockBuffer[no].y[3] = y;
        break;
    }
    blockBuffer[no].left = 999;
    for (int i=0;i<4;i++){
        if (blockBuffer[no].x[i] < blockBuffer[no].left){
            blockBuffer[no].left = blockBuffer[no].x[i];
        }
    }
    blockBuffer[no].right = -999;
    for (int i=0;i<4;i++){
        if (blockBuffer[no].x[i] > blockBuffer[no].right){
            blockBuffer[no].right = blockBuffer[no].x[i];
        }
    }blockBuffer[no].up = -999;
    for (int i=0;i<4;i++){
        if (blockBuffer[no].y[i] > blockBuffer[no].up){
            blockBuffer[no].up = blockBuffer[no].y[i];
        }
    }blockBuffer[no].bottom = 999;
    for (int i=0;i<4;i++){
        if (blockBuffer[no].y[i] < blockBuffer[no].bottom){
            blockBuffer[no].bottom = blockBuffer[no].y[i];
        }
    }
}

int get_bBufNo (int x, int y)
{
    for (int i=0;i<BufferSize;i++){
        for (int j=0;j<4;j++){
            if (blockBuffer[i].y[j] == y){
                for (int k=0;k<4;k++){
                    if (blockBuffer[i].x[k] == x){
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}