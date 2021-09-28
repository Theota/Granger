#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define STUDENTS_NB 12

/* Theo Tardy */

int used_check(int used[2][STUDENTS_NB]){

   int i=0;
   int used_count=0;

   for (i = 0; i < STUDENTS_NB; i++)
   {
      // printf("%d\n",used[1][i]);
       if (used[1][i]==1)
       {
            used_count++;
       }
   } 
   return used_count; 
}

int main (int argc, char *argv[]) {

    int r1=0;
    int r2=0;
    int all_used=0;
    int sujet=0;

    int used[2][STUDENTS_NB]={
        {0,1,2,3,4,5,6,7,8,9,10,11},
        {0,0,0,0,0,0,0,0,0,0,0,0}
    };

    char *students[]={
        "Rayane",
        "Louis",
        "Julien",
        "Jeremy.M",
        "Jeremy.C",
        "Frederic",
        "Estebane",
        "Enzo",
        "Evan",
        "Theo",
        "Thibault",
        "Pierre"
    };

    srand(time(NULL));
    while (all_used==0)
    {   
        r1= rand () % 12;
        r2= rand () % 12;
        
        //printf("1ere valeur : %d\n",r1);
        //printf("2eme valeur : %d\n",r2);

        if ((r1 != r2)&& (used[1][r1]==0) && (used[1][r2]==0))
        {
            printf("Sujet : %d \tBinome : %s / %s\n",sujet+1,students[r1],students[r2]);
            used[1][r1]=1;
            used[1][r2]=1;
            sujet++;
            if (used_check(used)==12)
            {
                all_used=1;
            }
        } 
    }
}