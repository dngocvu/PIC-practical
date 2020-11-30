#include <dieukhien_bluetooth.h>
#include <string.h>
#use rs232(baud=38400,xmit=pin_c6,rcv=pin_c7)
char cmd[10],kt[10]={"ok"};
char comd='0';
unsigned long      dem = 0,dem1=10,dem2=20;
void Init()
{
   set_tris_a(0x00);
   set_tris_c(0x80);
   output_a(0xff);
}
#int_timer0
void interupt_timer0 (){//ngat nay dung de tang dem va xuat tin hieu chan
   set_timer0(131);
   dem++;
   output_bit(PIN_B0,(dem<=dem1));//dieu kien xuat chan o pin b0 voi bien dem1 dung de cai dat muc cao
  // output_bit(PIN_B1,(dem<=dem2));//dieu kien xuat chan o pin b1 voi bien dem2 dung de cai dat muc cao
   if(dem == 400 ) dem = 0;  
}
//!void Go_Straight()
//!{
//!   dem1=39;
//!   dem2=13;
//!}
//!Void Turn_Left()
//!{
//!   dem1=35;
//!   dem2=30;
//!}
//!Void Stop_Run()
//!{
//!   dem1=0;
//!   dem2=0;
//!}
//!Void Turn_Right()
//!{
//!   dem1=20;
//!   dem2=20;
//!}
//!Void Go_Down()
//!{
//!   dem1=20;
//!   dem2=39;
//!}
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

   Init();
   //Stop_Run();
//!   printf("AT\r\n");
//!   while(kbhit()==0);
//!   output_low(pin_a3);
//!   for (int i = 0;i<10;i++)
//!   {  
//!      cmd[i] = getc();
//!      
//!   }
//!   if(strcmp(cmd,kt)==0)
//!   output_low(pin_a4);
   printf("AT+NAME=cop\r\n");
//!    while(kbhit()==0);
//!   output_low(pin_a4);
   delay_ms(10);
   printf("AT+ROLE=0\r\n");
   delay_ms(10);
   printf("AT+INIT\r\n");
   
   while(TRUE)
   {
      //TODO: User Code
      while(kbhit());
      comd = getch();
     
//!      switch(comd)
//!      {
//!         case 'u':
//!            
//!            Go_Straight();
//!            break;
//!         case 'l':
//!            Turn_Left();
//!            break;
//!         case 'r':
//!            Turn_Right();
//!            break;
//!         case 'd':
//!            Go_Down();
//!            break;
//!         case 'q':
//!            Stop_Run();
//!            break;
          
          
            
      }
     
   }

}
