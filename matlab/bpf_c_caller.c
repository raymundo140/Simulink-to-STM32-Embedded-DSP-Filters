/* bpf_c_caller.c
 * 2nd-order IIR Band-Pass Filter
 * fs = 10 kHz, fc ≈ 100 Hz, Q = 5
 */

 #include <stddef.h>
 #include "bpf_c_caller.h"
 
 /* Coefficients for
  * H(z) = (b0 + b1 z^-1 + b2 z^-2) / (1 + a1 z^-1 + a2 z^-2)
  */
 static const double b0 =  0.00623784;
 static const double b1 =  0.0;
 static const double b2 = -0.00623784;
 
 static const double a1 = -1.98360498;
 static const double a2 =  0.98752433;
 
 /* Filter state: x[n-1], x[n-2], y[n-1], y[n-2] */
 static double x1 = 0.0, x2 = 0.0;
 static double y1 = 0.0, y2 = 0.0;
 
 void bpf_reset(void)
 {
     x1 = x2 = 0.0;
     y1 = y2 = 0.0;
 }
 
 double bpf_step(double x0)
 {
     /* Difference equation:
        y[n] = b0*x[n] + b1*x[n-1] + b2*x[n-2]
               - a1*y[n-1] - a2*y[n-2];
     */
     double y0 = b0 * x0 + b1 * x1 + b2 * x2
                 - a1 * y1 - a2 * y2;
 
     /* Update states */
     x2 = x1;
     x1 = x0;
     y2 = y1;
     y1 = y0;
 
     return y0;
 }
 