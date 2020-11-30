#include <control RC Servo vs HCSR04.h>

#DEFINE  BT1     PIN_A4
#define trigger  pin_e2
#define echo     pin_e1

float kcs;
int i;

void tao_xung_trigger()
{
   
   output_high(trigger);
   delay_us(10);
   output_low(trigger);
   set_timer1(0);
   while(!(input(echo)));
   setup_timer_1(t1_internal|t1_div_by_4);
   while(input(echo));
   kcs = get_timer1();
   setup_timer_1(t1_disabled);     
}
void set_up_port_ic_chot()
{
   SET_TRIS_D(0x00);
   SET_TRIS_E(0x02);
   //SET_TRIS_A(0x10);
   set_tris_c(0x00);
   //OUTPUT_D(0xff);
   output_c(0x00);
   output_d(0x00);
}
void Go_Straight()
{
 //set_tris_c(0x00);
 //set_tris_d(0x00);
 //output_c(0x00);
 //output_d(0x00);
    setup_ccp1(ccp_pwm);
    setup_ccp2(ccp_pwm);
    setup_timer_2(t2_div_by_16,255,1);
    set_pwm1_duty(0);
    set_pwm2_duty(0);
    set_pwm1_duty(123);
    set_pwm2_duty(254);
}
void Turn_Left()
{
   setup_ccp1(ccp_pwm);
   setup_ccp2(ccp_pwm);
   setup_timer_2(t2_div_by_16,255,1);
   set_pwm1_duty(0);
   set_pwm2_duty(60);
   delay_ms(1000);
}
void main()
{
   set_up_port_ic_chot();
   setup_timer_1(t1_disabled);
   Go_Straight();
   while(TRUE)
   {  
      tao_xung_trigger();
      kcs=kcs*0.8;
      kcs = (kcs/59);
      if(kcs <= 40)
      {
         Turn_Left();
    
      }
      else 
      {
         Go_Straight();
      }
      //TODO: User Code
   }

}

