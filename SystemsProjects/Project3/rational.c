#include "rational.h"
#include <stdbool.h>
#include <stdio.h>

Rational create_rational(const int num, const int denom) {
  Rational new_rational;

  if (denom < 0) {
    // switches negative sign to numerator
    new_rational.numerator = -num;
    new_rational.denominator = denom;
  } else {
    new_rational.numerator = num;
    new_rational.denominator = denom;
  }

  simplify(&new_rational);
  return new_rational;
}
Rational copy_rational(const Rational *x) {
  Rational deep_copy;
  deep_copy.numerator = x->numerator;
  deep_copy.denominator = x->denominator;
  return deep_copy;
}
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
void simplify(Rational *x) {
  int gcf = gcd(x->numerator, x->denominator);
  // finds the greatest common factor then divides the numerator and denominator
  // by that common factor
  x->numerator = x->numerator / gcf;
  x->denominator = x->denominator / gcf;
}
Rational add(const Rational *x, const Rational *y) {
  int newNum;
  int newDenom;
  newNum = ((x->numerator * y->denominator) + (x->denominator * y->numerator));
  newDenom = (x->denominator * y->denominator);
  // I used the method from the youtube video I found located in my references
  Rational new_rational = create_rational(newNum, newDenom);
  simplify(&new_rational);
  return (new_rational);
}
Rational subtract(const Rational *x, const Rational *y) {
  int newNum;
  int newDenom;
  newNum = ((x->numerator * y->denominator) - (x->denominator * y->numerator));
  newDenom = (x->denominator * y->denominator);
  // This is the same method I used in my add function but using subtraction, im
  // gonna be honest I had no clue you could do this before
  Rational new_rational = create_rational(newNum, newDenom);
  simplify(&new_rational);
  return (new_rational);
}
Rational multiply(const Rational *x, const Rational *y) {
  int newNum;
  int newDenom;
  newNum = x->numerator * y->numerator;
  newDenom = x->denominator * y->denominator;
  Rational new_rational = create_rational(newNum, newDenom);
  simplify(&new_rational);

  return new_rational;
}
Rational divide(const Rational *x, const Rational *y) {
  int newNum;
  int newDenom;
  newNum = x->numerator * y->denominator;
  newDenom = x->denominator * y->numerator;
  //Keep the first fraction the same, flip the second and then multiply
  Rational new_rational = create_rational(newNum, newDenom);
  simplify(&new_rational);

  return new_rational;
}
void print(FILE *f1, const Rational *x) {
  // check if denominator is 1
  // I realized after writing my main function that it wouldve been beneficial to use this function 
  if (x->denominator == 1) {
    fprintf(f1, "%d", x->numerator);
  } else {
    fprintf(f1, "%d/%d", x->numerator, x->denominator);
  }
}
bool equal(const Rational *x, const Rational *y) {
  // I casted these to floats to avoid integer division
  float result1 = (float)x->numerator * y->denominator;
  float result2 = (float)y->numerator * x->denominator;

  return result1 == result2;
}
int compare(const Rational *x, const Rational *y) {
  //I was just comparing the results of the fractions themselves but I found that a much easier way is to just use cross multiplication
  float num1 = (x->numerator * y->denominator);
  float num2 = (y->numerator * x->denominator);

  if (num1 > num2) {
    return 1;
  } else if (num1 < num2) {
    return -1;
  } else {
    return 0;
  }
}
