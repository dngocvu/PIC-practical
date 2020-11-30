#include <baikiemtrapwm.h>

//include "rc_servo_control_v2.h"
unsigned long      n = 0; // Bien dem dung cho ngat timer0
signed long     TURN1,TURN2     ; // goc quay dong co buoc thay doi tu -90 den +90 do
signed long     delay_1,delay_2   ;


#int_timer0
void interupt_timer0 (){
   set_timer0(0);
   n++;
   if(n==390) 
   {  
      delay_1 = 1000;
      delay_2 = 1000;
      n=0;
      output_high(PIN_C0);
      output_high(PIN_C1);
      delay_us(delay_1);
      output_low(PIN_C0);
     // delay_us(delay_2);
      output_low(PIN_C1);
   }
}



void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(T0_INTERNAL|T0_DIV_1);////////
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC);// This device COMP currently not supported by the PICWizard
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
//Setup_Oscillator parameter not selected from Intr Oscillator Config tab

   // TODO: USER CODE!!
   TURN1 = -85; TURN2 = 85;
 //  set_timer0(0);
   set_tris_c(0x00);
   while(true){}
//!   {
//!      while(!input(PIN_B3)) 
//!      {
//!         TURN = 0;         
//!      }
//!      while((!input(PIN_B6)) )
//!      {
//!         delay_ms(500);
//!         TURN++;
//!      }
//!       while((!input(PIN_B7)) )
//!      {
//!         delay_ms(500);
//!         TURN--;
//!      }   
//!     
//!      
//!   }

}
//!#int_RTCC
//!void  RTCC_isr(void) 
//!{
//!set_rtcc(0);
//!   n++;
//!   
//!   if(n==195) 
//!   {  
//!      delay_1 = 1500;
//!      delay_2 = 500;
//!      n=0;
//!      output_high(PIN_C0);
//!      output_high(PIN_C1);
//!      delay_us(delay_1);
//!      output_low(PIN_C0);
//!      delay_us(delay_2);
//!      output_low(PIN_C1);
//!   }

//!}
