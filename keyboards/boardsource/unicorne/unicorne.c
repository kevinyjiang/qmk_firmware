// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "lib/oled.h"
#include "wpm.h"
#include "ocean_dream.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    /*if (!is_keyboard_master()) {*/
    /*    return OLED_ROTATION_180;*/
    /*}*/
    return OLED_ROTATION_270;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_stars();
    }
    return false;
}
#endif
