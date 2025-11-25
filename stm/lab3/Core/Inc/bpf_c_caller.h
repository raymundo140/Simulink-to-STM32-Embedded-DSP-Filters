/* bpf_c_caller.h
 * 2nd-order IIR Band-Pass Filter
 * fs = 10 kHz, fc ≈ 100 Hz, Q = 5
 */

 #ifndef BPF_C_CALLER_H
 #define BPF_C_CALLER_H

 void   bpf_reset(void);
 double bpf_step(double x0);

 #endif /* BPF_C_CALLER_H */
