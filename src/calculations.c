#include <math.h>
#include "../include/calculations.h"

#include <stdio.h>

void convertPrecision(int precision, long double *convertedPrecision) {
  *convertedPrecision = powl(10.0L, -(long double)precision);
  printf("Precision = %.18Lf\n", *convertedPrecision);
}

long double calcEquation1(const long double x) {
  return cosl(2.0L / x) - 2.0L * sinl(1.0L / x) + 1.0L / x;
}

long double calcEquation2(const long double x) {
  return sinl(logl(x)) - cosl(logl(x)) + 2.0L * logl(x);
}

long double methodOfHalving(long double (*functionPointer)(long double), long double a, long double b, long double epsilon) {
  long double x = 0;
  do {
    x = (a + b) / 2.0L;
    functionPointer(a) * functionPointer(x) > 0.0L ? (a = x) : (b = x);
  } while (fabsl(b - a) > epsilon);
  return x;
}
