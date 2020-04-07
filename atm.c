#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
  unsigned short int remaining_balance = amount;
  unsigned int notes = 0x00000000;
  int denoms[] = DENOMINATIONS;
  int max_amount_limit = 31999;
  if (remaining_balance <= max_amount_limit)
  {
    for (int idx = 0; idx < TOTAL_NOTES; idx++)
    {
      notes <<= 4;
      notes |= remaining_balance / denoms[idx];
      remaining_balance %= denoms[idx];
    }
  }
  return notes;
}

void display_notes(unsigned int notes)
{
  int denoms[] = DENOMINATIONS;
  unsigned int divisor = 0x10000000;
  for (int idx = 0; idx < TOTAL_NOTES; idx++)
  {
    int note_count = notes / divisor;
    if (note_count)
    {
      printf("   %d %s of Rs %d\n", note_count, note_count > 1 ? "notes" : "note", denoms[idx]);
    }
    notes %= divisor;
    divisor >>= 4;
  }
}