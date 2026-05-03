#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "hardware/xosc.h"
//#include "hardware/.h"
//#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "pico/multicore.h"
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "hardware/i2c.h"
#include "hardware/clocks.h"
#include "hardware/vreg.h"
#include <malloc.h>
#include <math.h>
#include <time.h>

//#include "pio1.s"
//#include <tinyusb.mk>
//#include "tinyusb/src/tusb.h"
// #include "hardware/pwm.h"


int HSYNC=16,VSYNC=15,RED=17;

void volatile cycle(int16_t k) {
          //       #pragma GCC unroll 0
          //   for (int i = 0; i < 40; i++)
          //   {
          //       __asm volatile ("nop\n");
          // //   __asm volatile ("nop\n");
          // //   __asm volatile ("nop\n");
          //       //__asm volatile ("nop\n");
          //   // __asm volatile ("nop\n");
          //   }
            busy_wait_us(1);
             sio_hw->gpio_set = 1<<HSYNC;
            
        //     #pragma GCC unroll 0
        //     for (int i = 0; i < 128; i++)
        //     {
        //         __asm volatile ("nop\n");
        //  //     __asm volatile ("nop\n");
        //    //     __asm volatile ("nop\n");
        //         //__asm volatile ("nop\n");
        //     // __asm volatile ("nop\n");
        //     }
             busy_wait_us(3);
            
      //    for (int i = 0; i < 10; i++)
       //   {
        //    __asm volatile ("nop\n");
       //   }
          
                       __asm volatile(
          "mov  r0, #10\n"    		// 1 cycle
          "loop1: sub  r0, r0, #1\n"	// 1 cycle
          "nop\n"
          "bne   loop1\n"  
          //  "nop\n"
          //"nop\n"        	// 2 cycles if loop taken, 1 if not
            );
           sio_hw->gpio_clr = 1<<HSYNC;
          //   #pragma GCC unroll 0
          //   for (int i = 0; i < 88; i++)
          //   {
          //       __asm volatile ("nop\n");
          // //    __asm volatile ("nop\n");

          // //     __asm volatile ("nop\n");
          //   //  __asm volatile ("nop\n");
          //   //  __asm volatile ("nop\n");
          //   }
          busy_wait_us(2);
       //   #pragma GCC unroll 0
          // __asm volatile(
          // "mov  r0, #86\n"    		// 1 cycle
          // "loop2: sub  r0, r0, #1\n"	// 1 cycle
          // "nop\n"
          // "nop\n"
          // "bne   loop2\n"  
          //   "nop\n"
          // "nop\n"  
          // "nop\n"
          // "nop\n"        	// 2 cycles if loop taken, 1 if not
          //   );
       //  for (int i = 0; i < 9; i++)
       //  {
       //    __asm volatile ("nop\n");
        //   __asm volatile ("nop\n");
       //  }
          __asm volatile(
          "mov  r0, #10\n"    		// 1 cycle
          "loop2: sub  r0, r0, #1\n"	// 1 cycle
          "nop\n"
          "bne   loop2\n"  
          //  "nop\n"
          //"nop\n"        	// 2 cycles if loop taken, 1 if not
            );
          //sio_hw->gpio_set = 1<<RED;
           
            //sleep_us(20);
        //  for (int i = 0; i < 800; i++)
         // {
             
         //     __asm volatile ("nop\n");
         //      __asm volatile ("nop\n");
         //       __asm volatile ("nop\n");
          //      __asm volatile ("nop\n");
          //      __asm volatile ("nop\n");
          //        __asm volatile ("nop\n");
          //     __asm volatile ("nop\n");
          //             __asm volatile ("nop\n");
            
 
         // }
         //sleep_us(2);
        // sio_hw->gpio_set = 1<<RED;
          //int8_t temp=5;
         __asm volatile(
          //"ldr r3,tmp\n"
          "mov r5,#208\n"
          "lsl r5,r5,#24\n"
          //"add r0,r0,#20\n"
          "mov r6,#1\n"
          "lsl r6,r6,#17\n"
          "mov r0,#25\n"
          "lsl r0,r0,#4\n"
          //"str r6,[r5,#20]\n"  //turn red on

         // "mov r0,#255\n"
          "loop4: sub  r0, r0, #1\n"	// 1 cycle
         // "nop\n"       //1 cycle
          "str r6,[r5,#20]\n"
          "nop\n"       //1 cycle
          "nop\n"       //1 cycle
          "nop\n"       //1 cycle
          //"nop\n"       //1 cycle
          //"nop\n"       //1 cycle
          "str r6,[r5,#24]\n"
          "nop\n"       //1 cycle
          "nop\n"       //1 cycle
          //"nop\n"       //1 cycle
          //"nop\n"       //1 cycle
          //"nop\n"       //1 cycle
          //"nop\n"       //1 cycle
   	      "bne   loop4\n"           //2 if repeats, 1 on exit

         // "mov r0,#56\n"
         // "loop5: sub  r0, r0, #1\n"	// 1 cycle
          //"nop\n"
         // "bne   loop5\n"  

         );
       // int i,j;
       // if(tab[i][j])
       //   sio_hw->gpio_set = 1<<RED;
       // else
       //   sio_hw->gpio_set = 1<<RED;
     //  sio_hw->gpio_clr = 1<<RED;
//         for (int i = 0; i < 10; i++)
//         {
//                                           asm volatile(
// 	"mov  r0, #132\n"    		// 1 cycle
// 	"loop4: sub  r0, r0, #1\n"	// 1 cycle
// 	"bne   loop4\n"  
//  //   "nop\n"
//   //"nop\n"        	// 2 cycles if loop taken, 1 if not
//     );
//         }
        

         // sio_hw->gpio_clr = 1<<RED;
              

        

}

int main()
{

    stdio_init_all();
    vreg_set_voltage(VREG_VOLTAGE_1_10);
    set_sys_clock_khz(200000, true);
    gpio_init(HSYNC);
    gpio_init(VSYNC);
    gpio_init(RED);
    gpio_init(25);

    gpio_set_dir(HSYNC,true);
    gpio_set_dir(VSYNC,true);
    gpio_set_dir(RED,true);
    gpio_set_dir(25,true);

    //pio_program_t

    sio_hw->gpio_clr = 1<<25;
    sleep_ms(1000);
     sio_hw->gpio_set = 1<<25;
     sleep_ms(1000);
  // sio_hw->gpio_clr= 1<<25;
 //   sleep_ms(1000);
    // sio_hw->gpio_set = 1<<25;
  for (int i = 0; i < 1; i++)
  {
    __asm volatile(
      "mov r0,#208\n"
      "lsl r0,r0,#24\n"
      //"add r0,r0,#20\n"
      "mov r1,#1\n"
      "lsl r1,r1,#25\n"
      "str r1,[r0,#20]\n"
      //"push {r1}\n"
      //"bx r0\n"
     );
     sleep_ms(500);
    sio_hw->gpio_clr= 1<<25;
     sleep_ms(500);

  }
  
  
 

    gpio_put(HSYNC,false);
    gpio_put(VSYNC,false);
    gpio_put(RED,false);

    
    while(true){
     
      for (int i = 0; i < 1; i++)
      {
        cycle(0);
      }
     // busy_wait_us(1);

        //gpio_put(VSYNC, true);
          sio_hw->gpio_set = 1<<VSYNC;

      for (int i = 0; i < 4; i++)
      {
        cycle(0);
      }
   //   busy_wait_us(1);
       sio_hw->gpio_clr = 1<<VSYNC;
    
    //    gpio_put(VSYNC,false);
        
       for (int i = 0; i < 23; i++)
       {
          cycle(0);
        
       }
       // #pragma GCC unroll 0
        for (int k= 0; k < 300; k++)
        {
        
          cycle(k);
          cycle(k);
        }
        
    }

}