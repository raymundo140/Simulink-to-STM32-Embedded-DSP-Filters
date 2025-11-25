/* lpf_c_caller.c
 * 1st-order IIR Low-Pass Filter
 * fs = 10 kHz, fc ≈ 100 Hz
 */

 #include <stddef.h>
 #include "lpf_c_caller.h"

 /* Coefficients for H(z) = (b0 + b1 z^-1) / (1 + a1 z^-1) */
 static const double b0 = 0.0304590;
 static const double b1 = 0.0304590;
 static const double a1 = -0.9390819;  /* note the sign */

 /* Filter state: x[n-1], y[n-1] */
 static double x1 = 0.0;
 static double y1 = 0.0;

 /* Reset filter state */
 void lpf_reset(void)
 {
     x1 = 0.0;
     y1 = 0.0;
 }

 /* One sample step */
 double lpf_step(double x0)
 {
     /* Difference equation:
        y[n] = b0 * x[n] + b1 * x[n-1] - a1 * y[n-1]
     */
     double y0 = b0 * x0 + b1 * x1 - a1 * y1;

     /* Update states */
     x1 = x0;
     y1 = y0;

     return y0;
 }
