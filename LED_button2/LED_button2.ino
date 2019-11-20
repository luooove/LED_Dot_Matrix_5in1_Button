// Program to demonstrate the MD_Parola library
//
// Uses the Arduino Print Class extension with various output types
//
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

const uint16_t WAIT_TIME = 1000;

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 5

#define CLK_PIN   4
#define DATA_PIN  2
#define CS_PIN    3

// Hardware SPI connection
//MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin();
}

int a = 0;
int state = 0;
int flag=0;
void loop(void)
{

  //  if (digitalRead(5) == 0)
  //  {
  //    delay(10);
  //    if (digitalRead(5) == 0)
  //      state++;
  //  }
  //  if (state == 1)
  //  {
  //    a++;
  //    delay(10);
  //    P.print(a);
  //  }
  //  if (state == 2)
  //  {
  //    a = 0;
  //    state = 0;
  //    P.print(a);
  //  }


  if (digitalRead(5) == 0)
  {
    delay(80);
    if (digitalRead(5) == 0)
    {
      state++;
      if (state == 3)
      {
        state = 0;
        a=0;
        flag=0;
      }
        
    }
  }

  if (state == 0)
    P.print(0);
  if (state == 1)
  {
    P.print(a);
    a++;
  }
  if (state == 2)
  {
    if(flag==0)
      P.print(a);
    if(a<=102&&a>=98&&flag==0)
    {
      P.print("Great!");
      flag=1;
    }
      
  }



}
