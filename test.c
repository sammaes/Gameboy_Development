#include <stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>

static UINT8 i = 0;
static UINT8 j = 0;
void debugPrintChar(char c)
{
  setchar(c);
  ++i;
  if (i == (GRAPHICS_WIDTH/8))
  {
    ++j;
    i = 0;
    if (j == (GRAPHICS_HEIGHT/8))
    {
      j = 0;
    }
  }
  gotoxy(i, j);
}

void main(void)
{
  UINT8 keys;
  UINT8 prev = 0;

  /* init */
  font_init();
  font_set(font_load(font_ibm)); /* 96 tiles */
  gotoxy(0, 0);
 
  while (1)
  {
    keys = joypad();
    if (keys != prev)
    {
      switch(keys)
      {
        case J_START:  debugPrintChar('S'); prev=keys; break;
        case J_SELECT: debugPrintChar('E'); prev=keys; break;
        case J_B:      debugPrintChar('b'); prev=keys; break;
        case J_A:      debugPrintChar('a'); prev=keys; break;
        case J_DOWN:   debugPrintChar('D'); prev=keys; break;
        case J_UP:     debugPrintChar('U'); prev=keys; break;
        case J_LEFT:   debugPrintChar('L'); prev=keys; break;
        case J_RIGHT:  debugPrintChar('R'); prev=keys; break;
      }
    }
  }
}
    
