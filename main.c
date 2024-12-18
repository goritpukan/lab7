#include <math.h>
#include <stdio.h>

#include "include/io.h"
#include "include/calculations.h"
#include "include/colors.h"

int main(void) {
  char restart = 0;
  do {
    int precision = 0;
    long double epsilon = 0.0L, intervalA = 0.0L, intervalB = 0.0L, y = 0.0L, result = 0.0L;
    long double (*equationPointer)(long double, long double);
    char *methodString, *equationString;
    int equationChoice = userChoice(
      "Choose an equation: \n 0 -> cos(y/x) - 2sin(1/x) + 1/x = 0\n 1 -> sin(ln(x) - cos(ln(x) + y * ln(x) = 0\n x ∈ [a,b]\n Enter your choice: ",
      1);
    int methodChoice = userChoice(
      "Choose method of calculation \n 0 -> By the method of halving\n 1 -> Newton\n Enter your choice: ", 1);

    precision = (int) getLongDoubleFromUser("Enter precision value [3 - 15]: ", 3, 15, 0);
    convertPrecision(precision, &epsilon);

    intervalA = getLongDoubleFromUser("Enter interval A (-10, 9) / {0}: ", -10, 9, 1);
    intervalB = getLongDoubleFromUser("Enter interval B [A, 10) / {0}: ", intervalA, 10, 1);
    y = getLongDoubleFromUser("Enter y [-5, 5]: ", -5, 5, 0);
    switch (equationChoice) {
      case 0:
        equationPointer = cosEquation;
        equationString = "cos(y/x) - 2sin(1/x) + 1/x = 0";
        break;
      case 1:
        equationPointer = sinEquation;
        equationString = "sin(ln(x) - cos(ln(x) + y * ln(x) = 0";
        break;
      default:
        printf("Invalid Equation Choice\n");
        return 0;
    }

    switch (methodChoice) {
      case 0:
        result = methodOfHalving(equationPointer, intervalA, intervalB, epsilon, y);
        methodString = "Method of halving";
        break;
      case 1:
        result = newtonsMethod(equationPointer, intervalA, intervalB, epsilon, y);
        methodString = "Newton's method";
        break;
      default:
        printf("Invalid Method Choice\n");
        return 0;
    }
    if (isnan(result)) {
      printf(RED"There is no roots, or this method cant find them\n"RESET);
      continue;
    }
    printf("x of equation (%s) on interval [%Lf, %Lf] using %s = %.*Lf\n", equationString, intervalA, intervalB,
           methodString, precision, result);
    printf("Type \'r\' for restart: ");
    scanf("%c", &restart);
    while (getchar() != '\n');
  } while (restart == 'r');

  return 0;
}
