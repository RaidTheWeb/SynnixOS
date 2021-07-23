#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#define complex _Complex
#define imaginary _Imaginary

#define _Imaginary_I 1.0di
#define I _Imaginary_I

/** @file
 * @brief Literally just some complex math operations
 * There are no real specific formatting for the libm 
 * 
 */

double creal(double complex);
double cimag(double complex);
double cabs(double complex);

#endif
