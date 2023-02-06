/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "led_mapping.h"

char wpm_str[10];

enum layers {
    _DVORAK,
    _NUMBER,
    _SYMBOL,
    _ADJUST,
    _QWERTY,
    _GAMING
};

//custom keycodes:
enum {
    TD_CAPS,
    TD_QWERTY,
    TD_GAME,
    TD_LBRK,
    TD_RBRK,
    TD_LPRB,
    TD_RPRB,
    TD_BSLS,
    TD_SFBT,
    TD_SLEQ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CAPS), KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    TD(TD_QWERTY),   MO(1),  KC_SPC,     KC_ENT,   MO(2), TD(TD_GAME)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       C(KC_X), TD(TD_SFBT), KC_F2, KC_F3,   KC_F4, KC_VOLU,                      KC_KP_9, KC_KP_8, KC_KP_7, KC_PMNS, KC_PSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       C(KC_C),   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLD,                      KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PAST, KC_NUM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       C(KC_V),   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MUTE,                      KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_0, KC_EQL, KC_PDOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,     _______,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_EXLM,  KC_AT, KC_HASH,  TD(TD_BSLS), TD(TD_SLEQ),             XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_DLR, KC_PERC, KC_CIRC, TD(TD_LPRB), TD(TD_RPRB),              XXXXXXX,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_AMPR, KC_ASTR, KC_QUES, TD(TD_LBRK), TD(TD_RBRK),             XXXXXXX,  KC_DEL,  KC_END, KC_PGDN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______,   MO(3),  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       _______,   _______,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 TD(TD_QWERTY),   _______,  _______,     _______,   _______, TD(TD_GAME)
                                      //`--------------------------'  `--------------------------'

    ),

  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_KP_9, KC_KP_8, KC_KP_7, KC_PMNS, KC_PSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_PAST, KC_NUM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL ,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_0, KC_PEQL, KC_PDOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 TD(TD_QWERTY),   _______,  _______,     _______,   _______, TD(TD_GAME)
                                      //`--------------------------'  `--------------------------'

    ),
};

#ifdef TAP_DANCE_ENABLE
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Left Shift, twice for Caps Lock
    [TD_CAPS]   =   ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Tap once for LGui, twice for toggle to Qwerty Layer
    [TD_QWERTY] =   ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, 4),
    // Tap once for Right Alt, twice for toggle to Game Layer
    [TD_GAME]   =   ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RALT, 5),
    // Tap once for curly brackets, twice square brackets
    [TD_LBRK]   =   ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LBRC)),
    [TD_RBRK]   =   ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_RBRC)),
    // Tap once for parentheses, twice for angle bracket
    [TD_LPRB]   =   ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LT),
    [TD_RPRB]   =   ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_GT),
    // Tap once for backslash, twice for pipe.
    [TD_BSLS]   =   ACTION_TAP_DANCE_DOUBLE(KC_BSLS, LSFT(KC_BSLS)),
    // Tap once for F1, twice for boot.
    [TD_SFBT]   =   ACTION_TAP_DANCE_DOUBLE(KC_F1, QK_BOOTLOADER),
    // Tap once for slash, twice for equals
    [TD_SLEQ]   =   ACTION_TAP_DANCE_DOUBLE(KC_PSLS, KC_EQL)
};
#endif // TAP_DANCE_ENABLE

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("LAYER: "), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_ln_P(PSTR("DVORAK"), false);
            break;
        case _NUMBER:
            oled_write_ln_P(PSTR("NUMPAD"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("SYMBOLS"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJUST"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("GAMING"), false);
            break;
    }
}

char code_to_name[60] = {
   ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
   'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
   'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
   '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
   '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

//OLED CAPSLOCK ON/OF
void oled_render_capslock(void) {
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {  // if caps lock is on
        oled_write("CAPS LOCK: ON  " , false);
    } else {                                  // if caps lock is off
        oled_write("CAPS LOCK: OFF", false);
    }
}

char keylog_str[24] = {};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_wpm(void) {
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_set_cursor(4,1);
        oled_render_layer_state();
        oled_set_cursor(4,2);
        oled_render_capslock();
        oled_set_cursor(4,3);
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

#ifdef RGB_MATRIX_ENABLE

extern led_config_t g_led_config;

void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max) {

  HSV hsv = {hue, sat, val};
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t i = 0; i < led_max; i++) {
    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

void rgb_matrix_layer_helper_per_key(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max, uint8_t index ) {

  HSV hsv = {hue, sat, val};
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }

  RGB rgb = hsv_to_rgb(hsv);
  RGB_MATRIX_INDICATOR_SET_COLOR(index, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for (uint8_t i = led_min; i < led_max; i++) {
    switch(get_highest_layer(layer_state)) {
            case _DVORAK:
                rgb_matrix_layer_helper(HSV_RED, led_min, led_max);
                break;
            case _QWERTY:
                rgb_matrix_layer_helper(HSV_BLUE, led_min, led_max);
                break;
            case _GAMING:
                rgb_matrix_layer_helper(HSV_GREEN, led_min, led_max);
                //rgb_matrix_layer_helper_per_key(HSV_GREEN, led_min, led_max, LED_9);
                //rgb_matrix_layer_helper_per_key(HSV_GREEN, led_min, led_max, LED_14);
                //rgb_matrix_layer_helper_per_key(HSV_GREEN, led_min, led_max, LED_15);
                //rgb_matrix_layer_helper_per_key(HSV_GREEN, led_min, led_max, LED_16);
                break;
            default:
                break;
    }
  }
  return false;
}
#endif // RGB_MATRIX_ENABLE