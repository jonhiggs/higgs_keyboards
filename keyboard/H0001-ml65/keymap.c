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

#include "keymap_common.h"
#include "keymap_unix_functions.c"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(   // LAYER 0: Default
      FN13, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSLS, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSPC,      \
      LCTL, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,        \
      F4,   FN1,  FN1,  LGUI,             SPC,              RALT, FN1,        LEFT, DOWN, RGHT \
    ),
    KEYMAP(   // LAYER 1
      FN15, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  VOLD,VOLU, \
      TRNS, NO,   NO,   END,  NO,   NO,   NO,   PGUP, PSCR, NO,   F13,  F14,  F15,  DEL,       \
      TRNS, HOME, NO,   PGDN, NO,   NO,   LEFT, DOWN, UP,   RGHT, NO,   NO,         NO,        \
      TRNS, NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         TRNS, F16,       \
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS,         F13,F14,F15    \
    )
};

// id for user defined functions
enum function_id {
    ESC,
    PROGRAMMING,
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // Switch to layer 1
    [13] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [15] = ACTION_FUNCTION(PROGRAMMING),      // A Programing button
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    switch (id) {
        case ESC:
            special_esc(event.pressed);
            break;

        case PROGRAMMING:
            clear_keyboard();
            dprint("Jump to bootloader... ");
            _delay_ms(50);
            bootloader_jump(); // not return
            dprint("not supported.\n");
            break;
    }
}
