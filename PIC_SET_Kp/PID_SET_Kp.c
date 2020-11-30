#include <PID_SET_Kp.h>

int WF_Left=0;
int WF_Front=0;
float WF_Error = 0;
float WF_Kp = 0.8;
float WF_LastError = 0;

void WF_SR04_Left.Distance(void)
{


}
void WF_CONTINUE_WALL (void)
{
    WF_Left = WF_SR04_Left.Distance();
    WF_Error = WF_Left - WF_DISTANCE;
    WF_Correction = WF_Kp * WF_Error 
    WF_LastError = WF_Error;
}

void WF_Front ()
{
   
}

void WF_LEFT ()
{

}

void main()
{

   while(TRUE)
   {


      //TODO: User Code
   }

}
