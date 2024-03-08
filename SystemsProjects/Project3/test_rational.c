#include "rational.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_rational(FILE *, int *, int *, int *, int *, char[]);

int main(int argc, char *argv[]) {
  //check if the user input enough arguments into the command line
  if (argc < 3) {
    puts("Not enough arguments!\n");
    return 1;
  }
  //open the last file inputed to write the ouput of the math equations
  FILE *f2 = fopen(argv[argc - 1], "w");
  if (f2 == NULL) {
    puts("Error opening file\n");
    return 1;
  }

  for (int i = 1; i < argc - 1; i++) {
    // open every file except the last (output file)
    FILE *f1 = fopen(argv[i], "r");
    // open the files to read and check if they open
    if (f1 == NULL) {
      puts("Error opening input file.\n");
      fclose(f2);
      return 1;
    }
    //initialize variables  
    int num = 0;
    int denom = 0;
    int num2 = 0;
    int denom2 = 0;
    char operator[10];
    // Professor mortensen told me to use a char*, but I was having issues being
    // able to pass that to the read_rational function, just using a character
    // array I thought maybe I would run out of space to fit operators but since
    // im constantly passing just the address of the array, only the first few
    // values oever get edited

    while (read_rational(f1, &num, &denom, &num2, &denom2, operator) > 0) {
      Rational A = create_rational(num, denom);
      Rational B = create_rational(num2, denom2);
      Rational result;

      // Print rational in a simplified form if denominator is 1
      if (A.denominator == 1) {
        fprintf(f2, "%d %s ", A.numerator, operator);
      } else {
        fprintf(f2, "%d/%d %s ", A.numerator, A.denominator, operator);
      }
      // check the same for the other rational
      if (B.denominator == 1) {
        fprintf(f2, "%d\t: ", B.numerator);
      } else {
        fprintf(f2, "%d/%d\t: ", B.numerator, B.denominator);
      }
      if (strcmp(operator, "+") == 0) {
        result = add(&A, &B);
      } else if (strcmp(operator, "-") == 0) {
        result = subtract(&A, &B);
      } else if (strcmp(operator, "*") == 0) {
        result = multiply(&A, &B);
      } else if (strcmp(operator, "/") == 0) {
        result = divide(&A, &B);
      } else if (strcmp(operator, "==") == 0) {
        if (equal(&A, &B)) {
          fprintf(f2, "true\n");
        } else {
          fprintf(f2, "false\n");
        }
        continue; // I decided to use continue statements here and beyond
                  // because since the comparison operators share similar
                  // properties, it is safer to just go to the next iteration of
                  // the loop after finiding one that is correct rather than
                  // checking ever ofther if and if else statements. I also
                  // noticed when I was debugging that I would often get the
                  // correct answer and the rest of the if and if else
                  // statements would mess up what I wanted to print
      } else if (strcmp(operator, "!=") == 0) {
        // if its not equal print true
        if (!equal(&A, &B)) {
          fprintf(f2, "true\n");
        } else {
          fprintf(f2, "false\n");
        }
        continue;
      } else if (strcmp(operator, "<=") == 0) {
        if (compare(&A, &B) <= 0) {
          fprintf(f2, "true\n");
        } else {
          fprintf(f2, "false\n");
        }
        continue;
      } else if (strcmp(operator, ">=") == 0) {
        if (compare(&A, &B) >= 0) {
          fprintf(f2, "true\n");
        } else {
          fprintf(f2, "false\n");
        }
        continue;
      } else if (strcmp(operator, "<") == 0) {
        if (compare(&A, &B) < 0) {
          fprintf(f2, "true\n");
        } else {
          fprintf(f2, "false\n");
        }
        continue;
      } else if (strcmp(operator, ">") == 0) {
        if (compare(&A, &B) > 0) {
          fprintf(f2, "true\n");
        } else {
          fprintf(f2, "false\n");
        }
        continue;
      }

      // Print the result of arithmetic operations and check if the denominator
      // is 1
      if (result.denominator == 1) {
        fprintf(f2, "%d\n", result.numerator);
      } else {
        fprintf(f2, "%d/%d\n", result.numerator, result.denominator);
      }
    }

    fclose(f1); // Close the input file
  }
  fclose(f2); // Close output file
  return 0;
}

int read_rational(FILE *f1, int *n1, int *d1, int *n2, int *d2, char op[]) {
  char line[100];
  char *s = fgets(line, 99, f1);
  if (s == NULL) {
    return 0;
  } else {
    // 1. rational1 op rational2
    if (sscanf(line, "%d/%d %s %d/%d", n1, d1, op, n2, d2) == 5) {
      return 5;
    }
    // 2. num1 op rational2
    else if (sscanf(line, "%d %s %d/%d", n1, op, n2, d2) == 4) {
      *d1 = 1;
      return 4;
    }
    // 3. rational1 op num2
    else if (sscanf(line, "%d/%d %s %d", n1, d1, op, n2) == 4) {
      *d2 = 1;
      return 4;
    }
    // 4. num1 op num2
    else if (sscanf(line, "%d %s %d", n1, op, n2) == 3) {
      *d1 = 1;
      *d2 = 1;
      return 3;
    }
    // 5. Error!
    else {
      return -1;
    }
  }
}