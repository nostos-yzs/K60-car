#include "common.h"
#include "oled.h"

GPIO_InitTypeDef G;
void controller_init(void);

void controller_init(void)
{
  G.GPIO_PTx=PTC;
  G.GPIO_Dir=DIR_INPUT;
  G.GPIO_Output=OUTPUT_L;//0-1
  G.GPIO_PinControl=INPUT_PULL_UP;//make sure the electric level change
  
  //Pin_number refer to the circuit design
  G.GPIO_Pins=GPIO_Pin10;
  LPLD_GPIO_Init(G);
  
  G.GPIO_Pins=GPIO_Pin12;
  LPLD_GPIO_Init(G);
  
  G.GPIO_Pins=GPIO_Pin8;
  LPLD_GPIO_Init(G);
  
  G.GPIO_Pins=GPIO_Pin4;
  LPLD_GPIO_Init(G);
}

void main (void)
{
  controller_init();
  OLED_Init();
  while(1)
  {
    if(!LPLD_GPIO_Input_b(PTC,12))
    {
      oled_display_16x8str(10, 3, "UP");
    }
    if(!LPLD_GPIO_Input_b(PTC,10))
    {
      oled_display_16x8str(10, 3, "LEFT");
    }
    if(!LPLD_GPIO_Input_b(PTC,8))
    {
      oled_display_16x8str(10, 3, "DOWN");
    }
    if(!LPLD_GPIO_Input_b(PTC,4))
    {
      oled_display_16x8str(10, 3, "RIGHT");
    }
  }
}


