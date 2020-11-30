#include <baikiemtrapwm_2.h>


//!//include "rc_servo_control_v2.h"
//unsigned long      n = 0; // Bien dem dung cho ngat timer0
unsigned long      dem = 0,dem1,dem2;
#define trigger  pin_e2
#define echo     pin_e1
float kcs;
//int i;

#int_timer0
void interupt_timer0 (){//ngat nay dung de tang dem va xuat tin hieu chan
   set_timer0(131);
   dem++;
   output_bit(PIN_B0,(dem<=dem1));//dieu kien xuat chan o pin b0 voi bien dem1 dung de cai dat muc cao
   output_bit(PIN_B1,(dem<=dem2));//dieu kien xuat chan o pin b1 voi bien dem2 dung de cai dat muc cao
   if(dem == 400 ) dem = 0;  
}
void Go_Straight()
{
   dem1=39;
   dem2=20;
}
Void Turn_Left()
{
   dem1=39;
   dem2=30;
}
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
void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(T0_INTERNAL|T0_DIV_2);////////
   //setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC);// This device COMP currently not supported by the PICWizard
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);


   set_tris_c(0x00);
   set_tris_e(0x02);
   while(true){
      Go_Straight();
      tao_xung_trigger();
      kcs=kcs*0.8;
      kcs = (kcs/59);
      if(kcs <= 40)
      {
         Turn_Left();
         delay_ms(1000);
       }
     
      
   }
   }

