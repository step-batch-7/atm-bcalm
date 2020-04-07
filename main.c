#include <stdio.h>
#include "atm.h"

int main(void)
{
  unsigned short int amounts[] = {1, 10, 11, 12, 32000, 39, 589, 2590, 31999};
  for (int i = 0; i < 9; i++)
  {
    unsigned int notes = get_money(amounts[i]);
    printf("%5u %08x\n", amounts[i], notes);
  }

  return 0;
}
