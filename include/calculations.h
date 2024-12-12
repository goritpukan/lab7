#ifndef CALCULATIONS_H
#define CALCULATIONS_H

void convertPrecision(int precision, long double *convertedPrecision);

long double methodOfHalving(long double (*functionPointer)(long double), long double a, long double b, long double epsilon);

long double calcEquation1(const long double x);

long double calcEquation2(const long double x);

#endif
