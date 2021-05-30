#include <basic.h>
#include <math.h>

double fabs(double v) {
    if (v < 0) {
        return -v;
    }
    return v;
}

double sqrt(double v) {
    asm volatile(
        "sqrtsd %0, %1"
        : "=x"(v)
        : "0"(v)
    );
    return v;
}

double hypot(double a, double b) {
    return sqrt(a * a + b * b);
}


double acos(double x) { return 0; }
double asin(double x) { return 0; }
double atan2(double y, double x) { return 0; }
double ceil(double x) { return 0; }
double cos(double x) { return 0; }
double cosh(double x) { return 0; }
double exp(double x) { return 0; }
double floor(double x) { return 0; }
double log(double x) { return 0; }
double log10(double x) { return 0; }
double log2(double x) { return 0; }
double pow(double x, double y) { return 0; }
double sin(double x) { return 0; }
double sinh(double x) { return 0; }
int ifloor(double x) { return 0; }
int iceil(double x) { return 0; }
double fmod(double x, double y) { return 0; }
double frexp(double x, int *exp) { return 0; }
double tan(double x) { return 0; }
double tanh(double x) { return 0; }