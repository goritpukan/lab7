#include <stdio.h>

#include "include/io.h"
#include "include/calculations.h"

int main(void) {
  do {
    int precision = 0;
    long double epsilon = 0, intervalA = 0, intervalB = 0;
    int equationChoice = userChoice(
      "Choose an equation: \n 0 -> cos(y/x) - 2sin(1/x) + 1/x = 0\n 1 -> sin(ln(x) - cos(ln(x) + y * ln(x) = 0\n x ∈ [a,b]\n Enter your choice: ",
      1);
    int methodChoice = userChoice(
      "Choose method of calculation \n 0 -> By the method of halving\n 1 -> Newton\n Enter your choice: ", 1);

    precision = (int)getDoubleFromUser("Enter precision value [3 - 30]: ", 3, 30);
    convertPrecision(precision, &epsilon);

    intervalA = getDoubleFromUser("Enter interval A [-100, 99]: ", -100, 99);
    intervalB =  getDoubleFromUser("Enter interval B [A, 100]: ", intervalA, 100);

    long double roots[5] = {};
    long double root = 0;
    long double prevRoot = 0;
    int i = 0;
    do {
      root = methodOfHalving(calcEquation1, intervalA, intervalB, epsilon);
      printf("\nRoot = %Lf\n", root);
      roots[i] = root;
      intervalA = root;
      if (i != 0) {
        prevRoot = root;
      }
      i++;
    }while (root != prevRoot);
    printf("Type \'r\' for restart: ");
  }while (getchar() == 'r');
}
