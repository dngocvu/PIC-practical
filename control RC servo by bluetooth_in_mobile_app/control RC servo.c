#include <control RC servo.h>
 
void main(void)
{ 
 
 set_tris_c(0x00);
 set_tris_d(0x00);
 output_c(0x00);
 output_d(0x00);
 setup_ccp1(ccp_pwm);
 setup_ccp2(ccp_pwm);
 setup_timer_2(t2_div_by_16,255,1);
 set_pwm1_duty(0);
 set_pwm2_duty(0);
 set_pwm1_duty(123);
 set_pwm2_duty(255);
 while(1) 
 {
 
 }
}
 

