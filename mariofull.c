/*relauder@lakeheadu.ca

   #  #
  ##  ##
 ###  ###
####  ####

mariofull.c */
 

#include <stdio.h>
//#include <cs50.h>

int main(void)
{
    int j;
    /*do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 0 || height > 23);*/
    int height = 4;
    for (int i = 1; i <= height; i++)
    {
        for (j = height; j > i; j--)
        {
            printf(" ");
        }
        int k = j;
        for (; j > 0; j--)
        {
            printf("#");
        }
        printf("  ");
        for (; k > 0; k--)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
