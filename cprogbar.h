#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#ifndef _cProgBar_
#define _cProgBar_

void prog_bar_int(int start, int finish, int position, float step);

void prog_bar_uint(unsigned int start, unsigned int finish, unsigned int position, float step);

void prog_bar_lint(long int start, long int finish, long int position, float step);

void prog_bar_ulint(unsigned long int start, unsigned long int finish, unsigned long int position, float step);

void prog_bar_flt(float start, float finish, float position, float step);

void prog_bar_dbl(double start, double finish, double position, double step);

#endif
