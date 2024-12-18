#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#define MAX_ITERATIONS 500

void convertPrecision(int precision, long double *convertedPrecision);

long double methodOfHalving(long double (*equationPointer)(long double, long double), long double a, long double b,
                            long double epsilon, long double y);

long double newtonsMethod(long double (*equationPointer)(long double, long double), long double a, long double b,
                          long double epsilon, long double y);

long double cosEquation(const long double x, const long double y);

long double sinEquation(const long double x, const long double y);


#endif
