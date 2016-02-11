/*
 * Authors (alphabetical order)
 * - Andre Bernet <bernet.andre@gmail.com>
 * - Andreas Weitl
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Gabriel Birkus
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * opentx is based on code named
 * gruvin9x by Bryan J. Rentoul: http://code.google.com/p/gruvin9x/,
 * er9x by Erez Raviv: http://code.google.com/p/er9x/,
 * and the original (and ongoing) project by
 * Thomas Husterer, th9x: http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef timers_h
#define timers_h

#define TMR_OFF      0
#define TMR_RUNNING  1
#define TMR_NEGATIVE 2
#define TMR_STOPPED  3

#define TIMER_MAX     (32767)
#define TIMER_MIN     (-32768)

struct TimerState {
  uint16_t cnt;
  uint16_t sum;
  uint8_t  state;
  int16_t  val;
  uint8_t  val_10ms;
};

extern TimerState timersStates[MAX_TIMERS];

void timerReset(uint8_t idx);

#if defined(CPUARM)
void timerSet(int idx, int16_t val);
#endif // #if defined(CPUARM)

#if defined(CPUARM) || defined(CPUM2560)
  void saveTimers();
  void restoreTimers();
#else
  #define saveTimers()
  #define restoreTimers()
#endif

void evalTimers(int16_t throttle, uint8_t tick10ms);

#endif
