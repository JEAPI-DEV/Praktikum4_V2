#ifndef NEWTON_H
#define NEWTON_H

#include <math.h>
#include <stdio.h>

#define MAX_ITERATIONS 128
#define EPS 1.E-12

extern int iteNewton;
extern int iteRegula;
extern int iteBisection;

double newton(double (*function)(double), double x_var);
double bisection(double (*function)(double), double a, double b);
double regulaFalsi(double (*function)(double), double a, double b);

#endif
