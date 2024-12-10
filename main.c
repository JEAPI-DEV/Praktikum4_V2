#include "root/root.h"

#define NUMBEROFFUNCTIONS 3

typedef struct {
    double (*function)(double);
    double a,b;
} functionDef;

double f1(double x) { return sin(x); }
double f2(double x) { return x * x - 3; }
double f3(double x) { return tan(x) - x; }

/* Die functions gelichung fuer jeweils f1, f2, f3 (fuer print ausgabe) */
char* labels[NUMBEROFFUNCTIONS] = {"f1(x) = sin(x)", "f2(x) = x^2 - 3", "f3(x) = tan(x) - x"};

/* function_arr beschreibt die Functionen und die Grenzwerte */
functionDef function_arr[NUMBEROFFUNCTIONS] = {
    {f1, 3.0, 4.0},
    {f2, 1.0, 2.0},
    {f3, 4.4, 4.6}
};

int main() {
    double rootNewton, rootBisection, rootRegula;
    int i;


    for (i = 0; i < NUMBEROFFUNCTIONS; i++) {
        printf("%s\n", labels[i]);
        /* replacing 3 with function_arr[i].b since with that it can find "nullstellen" higher than 3 */
        rootNewton = newton(function_arr[i].function,  function_arr[i].b);
        printf("Newton: %f (Iterations: %d)\n", rootNewton, iteNewton);

        rootBisection = bisection(function_arr[i].function, function_arr[i].a, function_arr[i].b);
        printf("Bisection: %f (Iterations: %d)\n", rootBisection, iteBisection);

        rootRegula = regulaFalsi(function_arr[i].function, function_arr[i].a, function_arr[i].b);
        printf("Regula-Falsi: %f (Iterations: %d)\n", rootRegula, iteRegula);
    }

    return 0;
}