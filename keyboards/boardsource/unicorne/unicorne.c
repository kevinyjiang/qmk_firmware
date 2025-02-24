// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "wpm.h"
#include "lib/bongo.h"
#include "lib/oled.h"
#include "lib/utils.h"

#ifdef OLED_ENABLE

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {

        switch(get_highest_layer(layer_state)) {
            case 3:
            case 2:
            case 1:
                render_layer_state();
                break;
            default:
                render_anim();
                oled_write(PSTR("WPM "), false);
                oled_write(fmt(get_current_wpm(), '0'), false);
                break;
        }
    }
    return false;
}
#endif
