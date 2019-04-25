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
    KA0, KA1, KA2, KA3, KA4, KA5, KA6, KA7, KA8, KA9, KAA, KAB, KAC, KAD, KAE, \
    KB0,  KB1,  KB2,  KB3,  KB4,  KB5,  KB6,  KB7,  KB8,  KB9,  KBA,  KBB,  KBC,  KBD,     \
    KC0,    KC1,  KC2,  KC3,  KC4,  KC5,  KC6,  KC7,  KC8,  KC9,  KCA,  KCB,  KCC,        \
    KD0,      KD1,  KD2,  KD3,  KD4,  KD5,  KD6,  KD7,  KD8,  KD9,  KDA,  KDB,  KDC,  KDE, \
    KE0,  KE1,  KE2,  KE3,            KE4,           KE5,  KE7,  KE8,  KEB,  KEC,  KED  \
) { \
    { KC_##A0 , KC_##A1 , KC_##A2 , KC_##A3 , KC_##A4 , KC_##A5 , KC_##A6 , KC_##A7 , KC_##A8 , KC_##A9 , KC_##AA , KC_##AB , KC_##AC , KC_##AD , KC_##AE },\
    { KC_##B0 , KC_##B1 , KC_##B2 , KC_##B3 , KC_##B4 , KC_##B5 , KC_##B6 , KC_##B7 , KC_##B8 , KC_##B9 , KC_##BA , KC_##BB , KC_##BC , KC_NC   , KC_##BE },\
    { KC_##C0 , KC_##C1 , KC_##C2 , KC_##C3 , KC_##C4 , KC_##C5 , KC_##C6 , KC_##C7 , KC_##C8 , KC_##C9 , KC_##CA , KC_##CB , KC_NC   , KC_##CD , KC_NC    },\
    { KC_##D0 , KC_##D1 , KC_##D2 , KC_##D3 , KC_##D4 , KC_##D5 , KC_##D6 , KC_##D7 , KC_##D8 , KC_##D9 , KC_##DA , KC_##DB , KC_##DC , KC_NC   , KC_NC    },\
    { KC_##E0 , KC_##E1 , KC_##E2 , KC_##E3 , KC_NC   , KC_##E5 , KC_NC   , KC_##E7 , KC_##E8 , KC_NC   , KC_NC   , KC_##EB , KC_##EC , KC_##ED , KC_NC    },\
}

#endif


#include "command.h"
#include "bootloader.h"
#include "action_layer.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(5, 15)
};

// Fn action definition
const uint16_t PROGMEM fn_actions[] = { };
