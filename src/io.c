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
  } while (choice < 48 || choice > numberOfChoices + 48);
  return choice - 48;
}

long double getLongDoubleFromUser(char *message, const long double min, const long double max, const int excludeZero) {
  long double number = 0.0L;
  char isValid = 0;
  do {
    printf("%s", message);
    isValid = scanf("%Lf", &number);
    while (getchar() != '\n');
    if (number < min || number > max) {
      isValid = 0;
      printf(RED"You must enter a number between %Lf and %Lf!\n"RESET, min, max);
    }
    if (excludeZero && number == 0) {
      isValid = 0;
      printf(RED"You cant enter 0!\n"RESET);
    }
    if (!isValid) {
      printf(RED"Invalid input, try again.\n"RESET);
    }
  } while (!isValid);
  return number;
}
