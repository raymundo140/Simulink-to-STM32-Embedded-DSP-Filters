/* apf_c_caller.h
 * 1st-order IIR All-Pass Filter
 * fs = 10 kHz, fc ≈ 100 Hz
 */

 #ifndef APF_C_CALLER_H
 #define APF_C_CALLER_H

 void   apf_reset(void);
 double apf_step(double x0);

 #endif /* APF_C_CALLER_H */
