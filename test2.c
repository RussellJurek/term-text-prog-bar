#include<stdlib.h>
#include<stdio.h>
#include<cprogbar.h>

int main(){

  int i,j;
  float step = 0.01;

  printf("Testing prog_bar_int . . . \n");
  prog_bar_int(0,99,-1,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_int(0,99,i,step);

  }

  printf("Testing prog_bar_uint . . . \n");
  prog_bar_uint(1,100,0,step);
  for(i = 1; i <= 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_uint(1,100,i,step);

  }

  printf("Testing prog_bar_lint . . . \n");
  prog_bar_lint((long int) 0,(long int) 99,(long int) -1,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_lint((long int) 0,(long int) 99,(long int) i,step);

  }

  printf("Testing prog_bar_ulint . . . \n");
  prog_bar_ulint((unsigned long int) 1,(unsigned long int) 100,(unsigned long int) 0,step);
  for(i = 1; i <= 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_ulint((unsigned long int) 1,(unsigned long int) 100,(unsigned long int) i,step);

  }

  printf("Testing prog_bar_flt . . . \n");
  prog_bar_flt(0.0,99.0,-1.0,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_flt(0.0,99.0,(float) i,step);

  }

  printf("Testing prog_bar_dbl . . . \n");
  prog_bar_dbl((double) 0.0,(double) 99.0,(double) -1.0,(double) step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_dbl((double) 0.0,(double) 99.0,(double) i,(double) step);

  }


}

