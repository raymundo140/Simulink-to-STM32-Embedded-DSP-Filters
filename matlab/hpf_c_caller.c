/* hpf_c_caller.c
 * 1st-order IIR High-Pass Filter
 * fs = 10 kHz, fc ≈ 100 Hz
 */

 #include <stddef.h>
 #include "hpf_c_caller.h"
 
 /* Coefficients for H(z) = (b0 + b1 z^-1) / (1 + a1 z^-1) */
 static const double b0 = 0.96954097;
 static const double b1 = -0.96954097;
 static const double a1 = -0.93908194;   /* NOTE: minus sign here */
 
 /* Filter state: x[n-1], y[n-1] */
 static double x1 = 0.0;
 static double y1 = 0.0;
 
 void hpf_reset(void)
 {
     x1 = 0.0;
     y1 = 0.0;
 }
 
 double hpf_step(double x0)
 {
     /* Difference equation:
        y[n] = b0*x[n] + b1*x[n-1] - a1*y[n-1]
        with denominator 1 + a1 z^-1  (a1 = -0.9390...)
     */
     double y0 = b0 * x0 + b1 * x1 - a1 * y1;
 
     x1 = x0;
     y1 = y0;
 
     return y0;
 }
 