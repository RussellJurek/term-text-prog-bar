#include<iostream>
#include<progbar.h>

int main(){

  int i,j;
  float step = 0.01;

  printf("Testing prog_bar_int . . . \n");
  prog_bar(0,99,-1,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar(0,99,i,step);

  }

  printf("Testing prog_bar_uint . . . \n");
  prog_bar(1,100,0,step);
  for(i = 1; i <= 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar(1,100,i,step);

  }

  printf("Testing prog_bar_lint . . . \n");
  prog_bar((long int) 0,(long int) 99,(long int) -1,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar((long int) 0,(long int) 99,(long int) i,step);

  }

  printf("Testing prog_bar_ulint . . . \n");
  prog_bar((unsigned long int) 1,(unsigned long int) 100,(unsigned long int) 0,step);
  for(i = 1; i <= 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar((unsigned long int) 1,(unsigned long int) 100,(unsigned long int) i,step);

  }

  printf("Testing prog_bar_flt . . . \n");
  prog_bar(0.0,99.0,-1.0,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar(0.0,99.0,(float) i,step);

  }

  printf("Testing prog_bar_dbl . . . \n");
  prog_bar((double) 0.0,(double) 99.0,(double) -1.0,(double) step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar((double) 0.0,(double) 99.0,(double) i,(double) step);

  }


}

