#include <stdbool.h>
#include <stdio.h>

typedef struct {
  int numerator;
  int denominator;
} Rational;

/**
 * Creates a new rational number with the given numerator and denominator.
 * If the denominator is negative, the negative sign is moved to the numerator.
 *
 * @param num Numerator of the rational number.
 * @param denom Denominator of the rational number.
 * @return A new rational number.
 */
Rational create_rational(const int num, const int denom);

/**
 * Creates a deep copy of a given rational number.
 *
 * @param x Pointer to the rational number you want to copy
 * @return A new rational number that is a copy of the input.
 */
Rational copy_rational(const Rational *x);

/**
 * Calculates the greatest common divisor (GCD) of two integers.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return The GCD of the two integers.
 */
int gcd(int a, int b);

/**
 * Simplifies a rational number by dividing the numerator and denominator by
 * their GCD.
 *
 * @param x Pointer to the rational number to be simplified.
 */
void simplify(Rational *x);

/**
 * Adds two rational numbers.
 *
 * @param x Pointer to the first rational number.
 * @param y Pointer to the second rational number.
 * @return The result of the addition.
 */
Rational add(const Rational *x, const Rational *y);

/**
 * Subtracts one rational number from another.
 *
 * @param x Pointer to the rational number that will be subtracted.
 * @param y Pointer to the rational number we will subtract with.
 * @return The result of the subtraction.
 */
Rational subtract(const Rational *x, const Rational *y);

/**
 * Multiplies two rational numbers.
 *
 * @param x Pointer to the first rational number.
 * @param y Pointer to the second rational number.
 * @return The result of the multiplication.
 */
Rational multiply(const Rational *x, const Rational *y);

/**
 * Divides one rational number by another.
 *
 * @param x Pointer to the numerator rational number.
 * @param y Pointer to the denominator rational number.
 * @return The result of the division.
 */
Rational divide(const Rational *x, const Rational *y);

/**
 * Prints a rational number to a file stream.
 *
 * @param f1 File to print the rational number to.
 * @param x Pointer to the rational number you want to print.
 */
void print(FILE *f1, const Rational *x);

/**
 * Checks if two rational numbers are equal.
 *
 * @param x Pointer to the first rational number.
 * @param y Pointer to the second rational number.
 * @return True if the rational numbers are equal, false otherwise.
 */
bool equal(const Rational *x, const Rational *y);

/**
 * Compares two rational numbers.
 *
 * @param x Pointer to the first rational number.
 * @param y Pointer to the second rational number.
 * @return 1 if x > y, -1 if x < y, and 0 if x == y.
 */
int compare(const Rational *x, const Rational *y);
