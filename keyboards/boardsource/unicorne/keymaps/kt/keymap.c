// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _CTRL,
  _SYM,
  _CONFIG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B,                          KC_J, KC_L, KC_U, KC_Y, KC_SCLN, MEH(KC_Q),
    KC_LGUI, LCTL_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), KC_T, KC_G, KC_M, KC_N, RSFT_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), KC_ENT,
    KC_TRNS, KC_Z, KC_X, KC_C, KC_D, KC_V,                         KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS,
             KC_ESC, MO(_CTRL), KC_BSPC,                                 KC_SPC, MO(_SYM), CW_TOGG
  ),

  [_CTRL] = LAYOUT_split_3x6_3(
    KC_BRID,     KC_BRIU, KC_VOLD, KC_MUTE, KC_VOLU, SGUI(KC_S),    KC_DOWN, KC_RGHT, MS_DOWN, MS_RGHT, LGUI(KC_MINS),  LGUI(KC_EQL),
    MO(_CONFIG), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_TRNS,
    KC_TRNS,     MS_BTN2, KC_MRWD, KC_MPLY, KC_MFFD, MS_BTN1,       KC_UP,   KC_LEFT, MS_UP,   MS_LEFT, LGUI(KC_LEFT),  LGUI(KC_RGHT),
                                   KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SYM] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_GRV,  KC_TILD, KC_DQUO, KC_QUOT, KC_PERC,    KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR,  KC_PIPE, KC_TRNS,
    KC_TRNS, KC_MINS, KC_UNDS, KC_PLUS, KC_EXLM, KC_EQL,     KC_COLN, KC_LCBR, KC_RCBR, KC_ASTR, KC_SCLN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BSLS, KC_HASH, KC_QUES, KC_AMPR,    KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS, KC_SLSH, KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_CONFIG] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU,  QK_BOOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RM_PREV, RM_HUED, RM_SATD, RM_VALD, RM_SPDD,  QK_CLEAR_EEPROM,
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case 3:
            rgb_matrix_set_color_all(30, 50, 0);
            break;
        case 2:
            rgb_matrix_set_color_all(60, 20, 20);
            break;
        case 1:
            rgb_matrix_set_color_all(10, 50, 30);
            break;
        default:
            break;
    }
    return false;
}

const uint16_t PROGMEM tn_combo[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM gm_combo[] = {KC_G, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(tn_combo, HYPR(KC_M)),
    COMBO(gm_combo, HYPR(KC_E)), // keycodes with modifiers are possible too!
};
