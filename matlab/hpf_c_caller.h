/* hpf_c_caller.h
 * 1st-order IIR High-Pass Filter
 * fs = 10 kHz, fc ≈ 100 Hz
 */

 #ifndef HPF_C_CALLER_H
 #define HPF_C_CALLER_H
 
 void   hpf_reset(void);
 double hpf_step(double x0);
 
 #endif /* HPF_C_CALLER_H */
 