#include <bluetooth_driving_exam.h>
#priority rda,timer0
#include <string.h>
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)//38400
//char cmd[10],kt[10]={"ok"};
char comd='0';
unsigned long      dem = 0;
int8 dem1=10,dem2=20;
//int1 lever=1;
void Init()
{
   set_tris_a(0x00);
   set_tris_c(0x80);
   output_a(0xff);
}

#int_timer0
void interupt_timer0 ()
{                                 //ngat nay dung de tang dem va xuat tin hieu chan
   set_timer0(131);
   dem++;
   output_bit(PIN_B0,(dem<=dem1));//dieu kien xuat chan o pin b0 voi bien dem1 dung de cai dat muc cao
   output_bit(PIN_B1,(dem<=dem2));//dieu kien xuat chan o pin b1 voi bien dem2 dung de cai dat muc cao
   if(dem == 400 ) dem = 0;  
}

//!void Down_Lever(){
//!   if(lever!=1) lever--;
//!}
void Go_Straight()
{
   dem1=10;
   dem2=35;
}
Void Turn_Left()
{
   dem1=35;
   dem2=35;
}
Void Stop_Run()
{
   dem1=0;
   dem2=0;
}
Void Turn_Right()
{
   dem1=10;
   dem2=10;
}
Void Go_Down()
{
   dem1=35;
   dem2=10;
}
void R_Right()
{
   dem1=10;
   dem2=28;
}
void L_Left()
{
   dem1=24;
   dem2=33;
}
//!void Change_Lever(){
//!    switch(hieuchinh)
//!      {
//!         case 1:            
//!            Go_Straight();
//!            break;
//!         case 2:
//!            Turn_Left();
//!            break;
//!         case 3:
//!            Turn_Right();
//!            break;
//!         case 4:
//!            Go_Down();
//!            break;
//!      }
//!}
#int_rda
void interupt_rda (){
   comd = getch();     
      switch(comd)
      {
         case 'u':            
            Go_Straight();
            break;
         case 'l':
            Turn_Left();
            break;
         case 'r':
            Turn_Right();
            break;
         case 'd':
            Go_Down();
            break;
         case 't':
            Stop_Run();
            break;
         case 'q':
            L_Left();
            break;        
         case 'b':
            R_Right();
            break;
//!         case 'v':
//!            lever=1;
//!            Change_Lever();
//!            break;
//!         case 'n':
//!            lever=0;
//!            Change_Lever();
//!            break;
      } 
          
            
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
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);

   Init();
   Stop_Run();
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
//!   printf("AT+NAME=cop\r\n");
//!    while(kbhit()==0);
//!   output_low(pin_a4);
//!   delay_ms(10);
//!   printf("AT+ROLE=0\r\n");
//!   delay_ms(10);
//!   printf("AT+INIT\r\n");
   
   while(TRUE)
   {
//!      while(kbhit());
//!      comd = getch();     
//!      switch(comd)
//!      {
//!         case 'u':            
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
//!         case 't':
//!            Stop_Run();
//!            break;
//!         case 'q':
//!            L_Left();
//!            break;        
//!         case 'b':
//!            R_Right();
//!            break;
//!         case 'v':
//!            lever=1;
//!            Change_Lever();
//!            break;
//!         case 'n':
//!            lever=0;
//!            Change_Lever();
//!            break;
      } 
   }



