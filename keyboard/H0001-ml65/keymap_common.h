/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];

#define KEYMAP( \
    KA0, KA1, KA2, KA3, KA4, KA5, KA6, KA7, KA8, KA9, KAA, KAB, KAC, KAD, KAE,              \
    KB0,  KB1,  KB2,  KB3,  KB4,  KB5,  KB6,  KB7,  KB8,  KB9,  KBA,  KBB,  KBC,  KBE,      \
    KC0,    KC1,  KC2,  KC3,  KC4,  KC5,  KC6,  KC7,  KC8,  KC9,  KCA,  KCB,  KCD,          \
    KD0,      KD1,  KD2,  KD3,  KD4,  KD5,  KD6,  KD7,  KD8,  KD9,  KDA,  KDB,  KDC,        \
    KE0,  KE1,  KE2,  KE3,            KE5,           KE7,  KE8,        KEB,  KEC,  KED,     \
    KF0                                                                                     \
) { \
    { KC_##KA0 , KC_##KA1 , KC_##KA2 , KC_##KA3 , KC_##KA4 , KC_##KA5 , KC_##KA6 , KC_##KA7 , KC_##KA8 , KC_##KA9 , KC_##KAA , KC_##KAB , KC_##KAC , KC_##KAD , KC_##KAE , KC_NO     },\
    { KC_##KB0 , KC_##KB1 , KC_##KB2 , KC_##KB3 , KC_##KB4 , KC_##KB5 , KC_##KB6 , KC_##KB7 , KC_##KB8 , KC_##KB9 , KC_##KBA , KC_##KBB , KC_##KBC , KC_NO    , KC_##KBE , KC_NO     },\
    { KC_##KC0 , KC_##KC1 , KC_##KC2 , KC_##KC3 , KC_##KC4 , KC_##KC5 , KC_##KC6 , KC_##KC7 , KC_##KC8 , KC_##KC9 , KC_##KCA , KC_##KCB , KC_NO    , KC_##KCD , KC_NO    , KC_NO     },\
    { KC_##KD0 , KC_##KD1 , KC_##KD2 , KC_##KD3 , KC_##KD4 , KC_##KD5 , KC_##KD6 , KC_##KD7 , KC_##KD8 , KC_##KD9 , KC_##KDA , KC_##KDB , KC_##KDC , KC_NO    , KC_NO    , KC_NO     },\
    { KC_##KE0 , KC_##KE1 , KC_##KE2 , KC_##KE3 , KC_NO    , KC_##KE5 , KC_NO    , KC_##KE7 , KC_##KE8 , KC_NO    , KC_NO    , KC_##KEB , KC_##KEC , KC_##KED , KC_NO    , KC_NO     },\
    { KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_##KF0 }, \
}

#endif

