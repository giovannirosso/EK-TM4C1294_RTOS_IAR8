#include <stdio.h>

extern int func_asm(int, int);

void main(void){
  while(1){
    int c;
    for(int b = 0; b < 10; b++)
      for(int a = 0; a < 10; a++){
        c = func_asm(a, b);
        printf("func_asm(%d, %d) = %d\n", a, b, c);
      } // for
  } // while
} // main
