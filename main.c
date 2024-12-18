#include "root/root.h"

#define NUMBEROFFUNCTIONS 6

typedef struct {
    double (*function)(double);

    double a, b;
    char *label;
} functionDef;

double f1(double x) { return sin(x); }
double f2(double x) { return x * x - 3; }
double f3(double x) { return tan(x) - x; }
double f4(double x) { return pow(sin(x), 2); }
double f5(double x) { return x*x-x-1; }
double f6(double x) { return pow(2, x)-32; }



functionDef function_arr[NUMBEROFFUNCTIONS] = {
    {f1, 3.0, 4.0, "f1(x) = sin(x)"},
    {f2, 1.0, 2.0, "f2(x) = x^2 - 3"},
    {f3, 4.4, 4.6, "f3(x) = tan(x) - x"},
    {f4, 3.0, 4.0, "f4(x) = sin(x)^2"},
    {f5, 1.0, 2.0, "f5(x) = x^2-x-1"},
    {f6, 4.5, 5.5, "f5(x) = 2^x - 32"}
};

int main() {
    double rootNewton, rootBisection, rootRegula;
    int i;

    for (i = 0; i < NUMBEROFFUNCTIONS; i++) {
        printf("%s\n", function_arr[i].label);
        rootNewton = newton(function_arr[i].function, function_arr[i].b);
        printf("Newton: %f (Iterations: %d)\n", rootNewton, iteNewton);

        rootBisection = bisection(function_arr[i].function, function_arr[i].a, function_arr[i].b);
        printf("Bisection: %f (Iterations: %d)\n", rootBisection, iteBisection);

        rootRegula = regulaFalsi(function_arr[i].function, function_arr[i].a, function_arr[i].b);
        printf("Regula-Falsi: %f (Iterations: %d)\n", rootRegula, iteRegula);
        printf("\n");
    }
    return 0;
}
