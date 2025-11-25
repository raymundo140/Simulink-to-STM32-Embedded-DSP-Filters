/* bsf_c_caller.h
 * 2nd-order IIR Band-Stop (Notch) Filter
 * fs = 10 kHz, fc ≈ 100 Hz, Q = 5
 */

 #ifndef BSF_C_CALLER_H
 #define BSF_C_CALLER_H
 
 void   bsf_reset(void);
 double bsf_step(double x0);
 
 #endif /* BSF_C_CALLER_H */
 