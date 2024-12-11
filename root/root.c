#include "root.h"

int iteNewton = 0;
int iteBisection = 0;
int iteRegula = 0;

static double derivative(double (*function)(double), double x) {
    double h = sqrt(EPS);
    return (function(x + h) - function(x - h)) / (2 * h);
}

double newton(double (*function)(double), double x_var) {
    double x = x_var, y, dy, next_x;
    int i = 0;
    iteNewton = 0;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        y = function(x);
        dy = derivative(function, x);

        if (fabs(dy) < EPS) {
            return NAN;
        }

        next_x = x - (y / dy);
        iteNewton++;

        if (fabs(next_x - x) < EPS) {
            return next_x;
        }

        x = next_x;
    }

    return NAN;
}

double bisection(double (*function)(double), double a, double b) {
    double mid, Fmid;

    for (iteBisection = 0; iteBisection < MAX_ITERATIONS; iteBisection++) {
        mid = (a + b) / 2.0;
        Fmid = function(mid);

        if (fabs(Fmid) < EPS) {
            return mid;
        }

        /* ist einfach nur eine Vorzeichen ueberpruefung */
        if (function(a) * Fmid < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }

    return NAN;
}

double regulaFalsi(double (*function)(double), double a, double b) {
    double x, fx;

    for (iteRegula = 0; iteRegula < MAX_ITERATIONS; iteRegula++) {
        /* https://de.wikipedia.org/wiki/Regula_falsi
         *
         *        a * f(b) - b * f(a)
         *  x =   -------------------
         *            f(b) - f(a)
         *
         */

        x = (a * function(b) - b * function(a)) / (function(b) - function(a));
        fx = function(x);

        if (fabs(fx) < EPS) {
            return x;
        }

        /* ist einfach nur eine Vorzeichen ueberpruefung */
        if (function(a) * fx < 0) {
            b = x;
        } else {
            a = x;
        }
    }

    return NAN;
}