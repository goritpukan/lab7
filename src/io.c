#include <stdio.h>
#include "../include/colors.h"

int userChoice(char *message, int numberOfChoices) {
  int choice;
  do {
    printf("%s", message);
    choice = getchar();
    while (getchar() != '\n');
    if (choice < 48 || choice > numberOfChoices + 48) {
      printf(RED"You must enter a number between 0 and %d!\n"RESET, numberOfChoices);
    }
  }while (choice < 48 || choice > numberOfChoices + 48);
  return choice;
}
double getDoubleFromUser(char *message, const double min, const double max) {
  double number = 0;
  char isValid = 0;
  do {
    printf("%s", message);
    isValid = scanf("%lf", &number);
    while (getchar() != '\n');
    if (number < min || number > max) {
      isValid = 0;
      printf(RED"You must enter a number between %lf and %lf!\n"RESET, min, max);
    }
    if (!isValid) {
      printf(RED"Invalid input, try again.\n"RESET);
    }
  }while (!isValid);
  return number;
}
