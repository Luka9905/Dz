#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define prY(y) ((y) < 0 || (y) > ROW) //Выход за предел по Y
#define prX(x) ((x) < 0 || (x) > COL) //Выход за предел по X
#define pr(x , y) (prX(x) || prY(y)) //Выход за предел по (X,Y)

#define ROW 7 //Число строк
#define COL 7 //Число столбцов
#define InitLife 15

#define L 1 
#define D 0
#define WL 2
#define WD -1

int C[ROW][COL];

int neigh(int x, int y){
    int count=0, dx, dy, n;
    for (dx=(-1);dx<=1;dx++){
        for (dy=(-1);dy<=1;dy++){
            if (dx!=0 || dy!=0){
                if (!pr((x+dx),(y+dy))){
                    n=C[x+dx][y+dy];
                    if (n==L || n==WD){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

void RandLife()
{
 int x , y;
 srand(time(NULL));
 for(int i = 0; i < InitLife; i++)
 {
  x = rand() % ROW;
  y = rand() % COL;
  if(C[x][y] != L)
   C[x][y]=L;
 }
}

int main()
{
    int st,ne,t=1;
    RandLife();
    while(t>0){
        t=0;
        for (int i=0;i<ROW;i++){
            for (int j=0;j<COL;j++){
                if (C[i][j]==L){
                    printf("1");
                    t++;
                }
                else{
                    printf("0");
                }
            }
            printf("\n");
        }
        for (int i=0;i<ROW;i++){
            for (int j=0;j<COL;j++){
                st=C[i][j];
                ne=neigh(i,j);
                if (st==L){
                    if (ne<2 || ne>3)
                        C[i][j]=WD;
                    
                }
                else{
                    if (ne==3)
                        C[i][j]=WL;
                    
                }  
            }
        }
        for (int i=0;i<ROW;i++){
            for (int j=0;j<COL;j++){
                if (C[i][j]==WL)
                    C[i][j]=L;
                
                if (C[i][j]==WD)
                    C[i][j]=D;
                
            }
        }
        printf("|----------------|\n");
    }
    sleep(5);
}        
                    
                