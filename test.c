#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void prog_bar_int(int start, int finish, int position, float step);

void prog_bar_flt(float start, float finish, float position, float step);

int main(){

  int i,j;
  float step = 0.01;

  prog_bar_int(0,99,-1,step);
  for(i = 0; i < 100; i++){

    for(j = 0; j < 10000000; j++){ ; }
    prog_bar_int(0,99,i,step);

  }


}

void prog_bar_int(int start, int finish, int position, float step){ prog_bar_flt((float) start, (float) finish, (float) position, step); }

void prog_bar_flt(float start, float finish, float position, float step){

  static float progress = 0.0;

  // range test step
  step = (step >= 0.99999) ? 1.0 : step;
  step = (step <= 0.01) ? 0.01 : step;

  if(position < start){

    // create header
    //printf("Creating header \n");

    printf("0");
    float marker = 0.1;
    progress = 0.0;
    while(progress <= (1.0 - (2.0 * step) + 1.0E-4)){

      progress+=step;
      while(marker < (progress - 1.0E-4)){ marker+=0.1; }

      //printf("%f %f %f: \n",progress,step,marker);
      if(fabs(marker - progress) < 1.0E-4){

	if(fabs(marker - 0.5) < 1.0E-4){

	  printf("|");

	} else {
	  
	  printf(":");

	}

      } else {

	printf("-");

      }
       
      //printf("updated to %f %f \n",progress,marker);

    }
    printf("100%%\n");
    fflush(stdout);
    progress = 0.0;

  } else {

    // update progress bar
    while(progress <= ((position - start + 1.0)/(finish - start + 1.0))){

      printf("*");
      fflush(stdout);
      progress+=step;
 
    }

  }

  // move to next line
  if(fabs(position - finish) <= 1.0E-4){ printf("\n"); }

}

