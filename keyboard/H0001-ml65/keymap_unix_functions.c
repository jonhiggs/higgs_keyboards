/*
Copyright 2015 Jon Higgs <jhiggs@eml.cc>

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

#include "action_util.h"
#include "debug.h"

 /*
 *   bit 0      ||||+- Left_Control
 *   bit 1      |||+-- Left_Shift
 *   bit 2      ||+--- Left_Alt
 *   bit 3      |+---- Left_Gui
 *   bit 4      ||||+- Right_Control
 *   bit 5      |||+-- Right_Shift
 *   bit 6      ||+--- Right_Alt
 *   bit 7      |+---- Right_Gui
 */

bool controlled() {
    return ((get_mods() & (1 << 0)) != 0) || ((get_mods() & (1 << 4)) != 0);
}

bool shifted() {
    return ((get_mods() & (1 << 1)) != 0) || ((get_mods() & (1 << 5)) != 0);
}

bool alted() {
    return ((get_mods() & (1 << 2)) != 0) || ((get_mods() & (1 << 6)) != 0);
}

bool guied() {
    return ((get_mods() & (1 << 3)) != 0) || ((get_mods() & (1 << 7)) != 0);
}

void special_esc(bool pressed) {
    if (pressed) {
        if (shifted() || guied()) {
            add_key(KC_GRV);
        } else {
            add_key(KC_ESC);
        }
        send_keyboard_report();
    } else {
        clear_keyboard_but_mods();
    }
}
