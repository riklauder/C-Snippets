#include <stdio.h>

/* function prototype*/

void tower(int how_many, char start, char finish, char spare);

void main(void) {

  int how_many;
  
  printf("\n\tHow many disks initially on peg1 ? ");


  scanf("%d", &how_many);
    
  tower(how_many, 'A', 'B', 'C');


}

void tower(int n, char start, char finish, char spare)

{
  if (n <= 1) 
    printf("Moving a disk from peg ", start, " to peg, ", finish);
      else
  {
    tower(n - 1, start, spare, finish);

    printf("Moving a disk from peg %c%s%c", start, "to peg ", finish);

    tower(n
      -
      1, spare, finish, start);

  }
}
