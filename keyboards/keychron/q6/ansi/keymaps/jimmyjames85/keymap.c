/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include QMK_KEYBOARD_H

enum custom_keycodes {
    QMKBEST = SAFE_RANGE, // create our custom key code.. start in the safe range
    JMT_BOOT, // boot loader
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 // key counts top row to btm 20, 21, 20, 17, 16, 14


///////////////////////////////// Layer 0 /////////////////////////////////
        [0] = LAYOUT_ansi_108(

 KC_ESC,            KC_F1,       KC_F2,        KC_F3,       KC_F4,                  KC_F5,       KC_F6,       KC_F7,       KC_F8,             KC_F9,       KC_F10,      KC_F11,      KC_F12,           KC_PSCR,     KC_SCRL,     KC_PAUS,           OSL(1),      KC_VOLD,     KC_VOLU,     KC_P0,

 KC_GRV,         KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,       KC_MINS,     KC_EQL,              KC_BSPC,           KC_INS,      KC_HOME,     KC_PGUP,           KC_NUM,      KC_PSLS,     KC_PAST,     KC_PMNS,
 KC_TAB,           KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,          KC_BSLS,           KC_DEL,      KC_END,      KC_PGDN,           KC_P7,       KC_P8,       KC_P9,
 KC_LCTL,            KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,                      KC_ENT,                                                        KC_P4,       KC_P5,       KC_P6,       KC_PPLS,
 KC_LSFT,              KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,                                KC_RSFT,                        KC_UP,                          KC_P1,       KC_P2,       KC_P3,
 KC_LCTL,   KC_LGUI,     KC_LALT,         /****************************/ KC_SPC, /*************************/        KC_RCTL,             KC_RGUI,             KC_APP,               KC_RCTL,           KC_LEFT,     KC_DOWN,     KC_RGHT,           KC_P0,       KC_PDOT,     KC_PENT),

///////////////////////////////// Layer 1 /////////////////////////////////
	[1] = LAYOUT_ansi_108(
 JMT_BOOT,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     RGB_TOG,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_P1,

 TO(0),          TO(1),       TO(2),       TO(3),       KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,            KC_TRNS,           BL_TOGG,     BL_ON,       RGB_RMOD,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,           RGB_M_R,     BL_OFF,      RGB_MOD,           KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                KC_TRNS,                        KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,    KC_TRNS,    KC_TRNS,         /****************************/ KC_TRNS, /*************************/       KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           RGB_M_P,     KC_TRNS,     KC_TRNS),

///////////////////////////////// Layer 2 /////////////////////////////////
	[2] = LAYOUT_ansi_108(
 KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     RGB_TOG,           OSL(1),      KC_TRNS,     KC_TRNS,     KC_P2,

 KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                KC_TRNS,                        KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,    KC_TRNS,    KC_TRNS,         /****************************/ KC_TRNS, /*************************/       KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS),

///////////////////////////////// Layer 3 /////////////////////////////////
	[3] = LAYOUT_ansi_108(
 KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     RGB_TOG,           OSL(1),      KC_TRNS,     KC_TRNS,     KC_P3,

 KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                KC_TRNS,                        KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,
 KC_TRNS,    KC_TRNS,    KC_TRNS,         /****************************/ KC_TRNS, /*************************/       KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS)
};


// keyrecord_t record {
//   keyevent_t event {
//     keypos_t key {
//       uint8_t col
//       uint8_t row
//     }
//     bool     pressed
//     uint16_t time
//   }
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // MACROS here?

    switch (keycode) {
    case JMT_BOOT:
        rgb_matrix_set_color(24, 220, 255, 220);
        rgb_matrix_set_color(25, 220, 255, 220);
        rgb_matrix_set_color(26, 220, 255, 220);
        rgb_matrix_set_color(27, 220, 255, 220);
        SEND_STRING(SS_DELAY(200));
        reset_keyboard();
        return false; // return false to stop qmk from further processing
    // case QMKBEST:
    //     if (record->event.pressed) {
    //         // when keycode QMKBEST is pressed
    //         SEND_STRING("QMK is the best thing ever!");
    //     } else {
    //         // when keycode QMKBEST is released
    //     }
    //     break;
    //
    // case KC_5:
    //     rgb_matrix_set_color(6, 0, 0, 0);
    //     rgb_matrix_set_color(7, 0, 0, 0);
    //     rgb_matrix_set_color(8, 0, 0, 0);
    //     break;
    // case KC_6:
    //     rgb_matrix_set_color(6, 255, 0, 0);
    //     break;
    // case KC_7:
    //     rgb_matrix_set_color(7, 255, 0, 0);
    //     break;
    // case KC_8:
    //     rgb_matrix_set_color(8, 255, 0, 0);
    //     break;
    // case KC_9:
    //     // char abuff[48];
    //     // sprintf(abuff, "\rkc: %04d led: %04d", keycode, RGB_MATRIX_LED_COUNT);
    //     // SEND_STRING(abuff);
    //     //
    //     // if (record->event.pressed) {
    //     //     // when key is pressed
    //     //     // SEND_STRING("hi");
    //     //     // jim RGB_MATRIX_LED_COUNT
    //     // } else {
    //     //     // when key is released
    //     // }
    //     break;
    }
    return true;
};

// Runs constantly in the background, in a loop. Changes on layer change
void matrix_scan_user(void) {

    // TODO: where is layer_state defined?
    uint8_t layer = biton32(layer_state);

    // turn off all leds
    rgb_matrix_set_color(20, 0, 0, 0);
    rgb_matrix_set_color(21, 0, 0, 0);
    rgb_matrix_set_color(22, 0, 0, 0);
    rgb_matrix_set_color(23, 0, 0, 0);


    // turn on led that corresponds to layer
    switch (layer) {
    case 0:
        rgb_matrix_set_color(20, 255, 0, 0);
        break;
    case 1:
        rgb_matrix_set_color(21, 255, 0, 0);
        break;
    case 2:
        rgb_matrix_set_color(22, 255, 0, 0);
        break;
    case 3:
        rgb_matrix_set_color(23, 255, 0, 0);
        break;
    }
};
