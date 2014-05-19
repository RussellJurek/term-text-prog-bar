#include<cprogbar.h>

void prog_bar_int(int start, int finish, int position, float step){ prog_bar_flt((float) start, (float) finish, (float) position, step); }

void prog_bar_uint(unsigned int start, unsigned int finish, unsigned int position, float step){ prog_bar_flt((float) start, (float) finish, (float) position, step); }

void prog_bar_lint(long int start, long int finish, long int position, float step){ prog_bar_dbl((double) start, (double) finish, (double) position, (double) step); }

void prog_bar_ulint(unsigned long int start, unsigned long int finish, unsigned long int position, float step){ prog_bar_dbl((double) start, (double) finish, (double) position, (double) step); }

void prog_bar_flt(float start, float finish, float position, float step){

  static float progress = 0.0;

  // range test step
  step = (step >= 0.99999) ? 1.0 : step;
  step = (step <= 0.01) ? 0.01 : step;

  if(position < start){

    // create header
    printf("0");
    float marker = 0.1;
    progress = 0.0;
    while(progress <= (1.0 - (2.0 * step) + 1.0E-4)){

      progress+=step;
      while(marker < (progress - 1.0E-4)){ marker+=0.1; }

      if(fabsf(marker - progress) < 1.0E-4){

	if(fabsf(marker - 0.5) < 1.0E-4){

	  printf("|");

	} else {
	  
	  printf(":");

	}

      } else {

	printf("-");

      }
       
    }
    printf("100%%\n");
    progress = 0.0;

  } else {

    // update progress bar
    while((progress - 1.0E-4) <= ((position - start + 1.0)/(finish - start + 1.0))){

      printf("*");
      fflush(stdout);
      progress+=step;
 
    }

  }

  // move to next line
  if(fabsf(position - finish) <= 1.0E-4){ printf("\n"); }

}

void prog_bar_dbl(double start, double finish, double position, double step){

  static double progress = 0.0;

  // range test step
  step = (step >= 0.99999) ? 1.0 : step;
  step = (step <= 0.01) ? 0.01 : step;

  if(position < start){

    // create header
    printf("0");
    double marker = 0.1;
    progress = 0.0;
    while(progress <= (1.0 - (2.0 * step) + 1.0E-4)){

      progress+=step;
      while(marker < (progress - 1.0E-4)){ marker+=0.1; }

      if(fabs(marker - progress) < 1.0E-4){

	if(fabs(marker - 0.5) < 1.0E-4){

	  printf("|");

	} else {
	  
	  printf(":");

	}

      } else {

	printf("-");

      }
       
    }
    printf("100%%\n");
    fflush(stdout);
    progress = 0.0;

  } else {

    // update progress bar
    while((progress - 1.0E-4) <= ((position - start + 1.0)/(finish - start + 1.0))){

      printf("*");
      fflush(stdout);
      progress+=step;
 
    }

  }

  // move to next line
  if(fabs(position - finish) <= 1.0E-4){ printf("\n"); }

}


