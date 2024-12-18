#include <math.h>
#include <stdio.h>
#include "../include/calculations.h"
#include "../include/colors.h"

void convertPrecision(int precision, long double *convertedPrecision) {
  *convertedPrecision = powl(10.0L, -(long double) precision);
  printf("Precision = %.18Lf\n", *convertedPrecision);
}

long double cosEquation(const long double x, const long double y) {
  return cosl(y / x) - 2.0L * sinl(1.0L / x) + 1.0L / x;
}

long double sinEquation(const long double x, const long double y) {
  return sinl(logl(x)) - cosl(logl(x)) + y * logl(x);
}

long double methodOfHalving(long double (*equationPointer)(long double, long double), long double a, long double b,
                            long double epsilon, long double y) {
  const long double firstA = a;
  const long double firstB = b;
  long double x = 0.0L;
  int iterations = 0;
  do {
    iterations++;
    x = (a + b) / 2.0L;
    equationPointer(a, y) * equationPointer(x, y) > 0.0L ? (a = x) : (b = x);
    if (iterations > MAX_ITERATIONS) {
      printf(RED"Error! There is infinity loop! Please try again!"RESET);
      return NAN;
    }
  } while (fabsl(b - a) > epsilon);
  if (x == firstA || x == firstB) {
    return NAN;
  }
  return x;
}

long double newtonsMethod(long double (*equationPointer)(long double, long double), long double a, long double b,
                          long double epsilon, long double y) {
  long double x = b - equationPointer(b, y);
  long double delta = 0.0L;
  int iterations = 0;
  do {
    iterations++;
    delta = equationPointer(x, y) / ((equationPointer(x + epsilon, y) - equationPointer(x, y)) / epsilon);
    if (fabsl(delta) > epsilon) {
      x = x - delta;
    }
    if (iterations > MAX_ITERATIONS) {
      printf(RED"Error! There is infinity loop! Please try again!\n"RESET);
      return NAN;
    }
  } while (fabsl(delta) > epsilon);
  if (isinf(x) || isnan(x)) {
    return NAN;
  }
  return x;
}
