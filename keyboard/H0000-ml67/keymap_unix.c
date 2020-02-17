#include "keymap_common.h"
#include "keymap_unix_functions.c"
#include "command.h"
#include "bootloader.h"
#include "action_layer.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(   // LAYER 0: Default
      FN13, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSLS, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSPC,      \
      LCTL, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   NO , \
      F4,   FN1,  F13,  LGUI,             SPC,              RALT, FN1,  NO,   LEFT, DOWN, RGHT,\
      FN1,  FN1                                                                                \
    ),
    KEYMAP(   // LAYER 1
      FN15, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  VOLD,VOLU, \
      TRNS, NO,   NO,   END,  NO,   NO,   NO,   PGUP, PSCR, NO,   NO,   NO,   NO,   DEL,       \
      TRNS, HOME, NO,   PGDN, NO,   NO,   LEFT, DOWN, UP,   RGHT, NO,   NO,         NO,        \
      TRNS, NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         TRNS,MSTP,  NO,  \
      TRNS, TRNS, TRNS, TRNS,             F14,              TRNS, TRNS, NO,   MPRV,MPLY,MNXT,  \
      TRNS, TRNS                                                                               \
    )
};

// id for user defined functions
enum function_id {
    ESC,
    PROGRAMMING
};

// Fn action definition
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // FN1 switch to layer 1
    [13] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [15] = ACTION_FUNCTION(PROGRAMMING),      // Program the Teensy.
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
