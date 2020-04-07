#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned short int remaining_balance = amount;
  unsigned int result = 0x00000000;
  int notes[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  int total_notes = 8;
  int max_amount_limit = 31999;
  if (remaining_balance <= max_amount_limit)
  {
    for (int idx = 0; idx < total_notes; idx++)
    {
      result <<= 4;
      result |= remaining_balance / notes[idx];
      remaining_balance %= notes[idx];
    }
  }
  return result;
}