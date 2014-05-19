#include<iostream>
#include<math.h>

#ifndef _progbar_
#define _progbar_

using namespace std;

template<class start_type, class finish_type, class pos_type, class step_type>
void prog_bar(start_type start, finish_type finish, pos_type position, step_type step){

  static double progress = 0.0;

  // range test step
  step = ((double) step >= 0.99999) ? 1.0 : step;
  step = ((double) step <= 0.01) ? 0.01 : step;

  if(position < start){

    // create header
    printf("0");
    double marker = 0.1;
    progress = 0.0;
    while(progress <= (1.0 - (2.0 * (double) step) + 1.0E-4)){

      progress+=(double) step;
      while(marker < (progress - 1.0E-4)){ marker+=0.1; }

      if(fabs(marker - progress) < 1.0E-4){

	if(fabs(marker - 0.5) < 1.0E-4){

	  std::cout << "|";

	} else {
	  
	  std::cout << ":";

	}

      } else {

	std::cout << "-";

      }
       
    }
    std::cout << "100%%" << endl;
    progress = 0.0;

  } else {

    // update progress bar
    while((progress - 1.0E-4) <= (((double) position - (double) start + 1.0)/((double) finish - (double) start + 1.0))){

      cout << "*" << flush;
      progress+=step;
 
    }

  }

  // move to next line
  if(fabs((double) position - (double) finish) <= 1.0E-4){ cout << endl; }

}

#endif

