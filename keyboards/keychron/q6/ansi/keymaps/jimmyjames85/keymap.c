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
    JT_BOOT, // bootloader
    JT_INFO,
};

const uint8_t LED_ESC = 0;
const uint8_t LED_F1 = 1;
const uint8_t LED_F2 = 2;
const uint8_t LED_F3 = 3;
const uint8_t LED_F4 = 4;
const uint8_t LED_F5 = 5;
const uint8_t LED_F6 = 6;
const uint8_t LED_F7 = 7;
const uint8_t LED_F8 = 8;
const uint8_t LED_F9 = 9;
const uint8_t LED_F10 = 10;
const uint8_t LED_F11 = 11;
const uint8_t LED_F12 = 12;
const uint8_t LED_PSCR = 13;
const uint8_t LED_SCRL = 14;
const uint8_t LED_PAUS = 15;
const uint8_t LED_CIRC = 16;
const uint8_t LED_TRIANGLE = 17;
const uint8_t LED_SQUARE = 18;
const uint8_t LED_XXX = 19;
const uint8_t LED_GRV = 20;
const uint8_t LED_1 = 21;
const uint8_t LED_2 = 22;
const uint8_t LED_3 = 23;
const uint8_t LED_4 = 24;
const uint8_t LED_5 = 25;
const uint8_t LED_6 = 26;
const uint8_t LED_7 = 27;
const uint8_t LED_8 = 28;
const uint8_t LED_9 = 29;
const uint8_t LED_0 = 30;
const uint8_t LED_MINS = 31;
const uint8_t LED_EQL = 32;
const uint8_t LED_BSPC = 33;
const uint8_t LED_INS = 34;
const uint8_t LED_HOME = 35;
const uint8_t LED_PGUP = 36;
const uint8_t LED_NUM = 37;
const uint8_t LED_PSLS = 38;
const uint8_t LED_PAST = 39;
const uint8_t LED_PMNS = 40;
const uint8_t LED_TAB = 41;
const uint8_t LED_Q = 42;
const uint8_t LED_W = 43;
const uint8_t LED_E = 44;
const uint8_t LED_R = 45;
const uint8_t LED_T = 46;
const uint8_t LED_Y = 47;
const uint8_t LED_U = 48;
const uint8_t LED_I = 49;
const uint8_t LED_O = 50;
const uint8_t LED_P = 51;
const uint8_t LED_LBRC = 52;
const uint8_t LED_RBRC = 53;
const uint8_t LED_BSLS = 54;
const uint8_t LED_DEL = 55;
const uint8_t LED_END = 56;
const uint8_t LED_PGDN = 57;
const uint8_t LED_P7 = 58;
const uint8_t LED_P8 = 59;
const uint8_t LED_P9 = 60;
const uint8_t LED_CAPS = 61;
const uint8_t LED_A = 62;
const uint8_t LED_S = 63;
const uint8_t LED_D = 64;
const uint8_t LED_F = 65;
const uint8_t LED_G = 66;
const uint8_t LED_H = 67;
const uint8_t LED_J = 68;
const uint8_t LED_K = 69;
const uint8_t LED_L = 70;
const uint8_t LED_SCLN = 71;
const uint8_t LED_QUOT = 72;
const uint8_t LED_ENT = 73;
const uint8_t LED_P4 = 74;
const uint8_t LED_P5 = 75;
const uint8_t LED_P6 = 76;
const uint8_t LED_PPLS = 77;
const uint8_t LED_LSFT = 78;
const uint8_t LED_Z = 79;
const uint8_t LED_X = 80;
const uint8_t LED_C = 81;
const uint8_t LED_V = 82;
const uint8_t LED_B = 83;
const uint8_t LED_N = 84;
const uint8_t LED_M = 85;
const uint8_t LED_COMM = 86;
const uint8_t LED_DOT = 87;
const uint8_t LED_SLSH = 88;
const uint8_t LED_RSFT = 89;
const uint8_t LED_UP = 90;
const uint8_t LED_P1 = 91;
const uint8_t LED_P2 = 92;
const uint8_t LED_P3 = 93;
const uint8_t LED_LCTL = 94;
const uint8_t LED_LGUI = 95;
const uint8_t LED_LALT = 96;
const uint8_t LED_SPC = 97;
const uint8_t LED_RALT = 98;
const uint8_t LED_RGUI = 99;
const uint8_t LED_APP = 100;
const uint8_t LED_RCTL = 101;
const uint8_t LED_LEFT = 102;
const uint8_t LED_DOWN = 103;
const uint8_t LED_RGHT = 104;
const uint8_t LED_P0 = 105;
const uint8_t LED_PDOT = 106;
const uint8_t LED_PENT = 107;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // key counts top row to btm 20, 21, 20, 17, 16, 14


    ///////////////////////////////// Layer 0 /////////////////////////////////
    [0] = LAYOUT_ansi_108(

                          KC_ESC,            KC_F1,       KC_F2,        KC_F3,       KC_F4,                  KC_F5,       KC_F6,       KC_F7,       KC_F8,             KC_F9,       KC_F10,      KC_F11,      KC_F12,           KC_PSCR,     KC_SCRL,     KC_PAUS,           OSL(1),      KC_VOLD,     KC_VOLU,     KC_P0,

                          KC_GRV,         KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,       KC_MINS,     KC_EQL,              KC_BSPC,           KC_INS,      KC_HOME,     KC_PGUP,           KC_NUM,      KC_PSLS,     KC_PAST,     KC_PMNS,
                          KC_TAB,           KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,          KC_BSLS,           KC_DEL,      KC_END,      KC_PGDN,           KC_P7,       KC_P8,       KC_P9,
                          KC_LCTL,            KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,                      KC_ENT,                                                        KC_P4,       KC_P5,       KC_P6,       KC_PPLS,
                          KC_LSFT,              KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,                                KC_RSFT,                        KC_UP,                          KC_P1,       KC_P2,       KC_P3,
                          KC_LCTL,   KC_LGUI,     KC_LALT,         /****************************/ KC_SPC, /*************************/        KC_RCTL,             KC_RALT,             KC_APP,               KC_RCTL,           KC_LEFT,     KC_DOWN,     KC_RGHT,           KC_P0,       KC_PDOT,     KC_PENT),

    ///////////////////////////////// Layer 1 /////////////////////////////////
    [1] = LAYOUT_ansi_108(
                          JT_BOOT,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     RGB_TOG,           KC_TRNS,     KC_TRNS,     KC_TRNS,     JT_INFO,

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





// All deferred executor callbacks have a common function signature and look like:
uint32_t cb_ledgreen(uint32_t trigger_time, void *cb_arg) {
    rgb_matrix_set_color(LED_8, 0, 255, 0);
    // return 500; // means come back and call me again in 500ms
    return 0; // means we are done
}


uint32_t cb_bootloader(uint32_t trigger_time, void *cb_arg) {
    reset_keyboard();
    return 0;
}




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




// This function gets called at the end of all QMK processing, before starting the next iteration. You
// can safely assume that QMK has dealt with the last matrix scan at the time that these functions are
// invoked – layer states have been updated, USB reports have been sent, LEDs have been updated, and
// displays have been drawn.
//
// . To keep your board responsive, it’s suggested to do as little as possible during these function
// calls, potentially throtting their behaviour if you do indeed require implementing something special.
void housekeeping_task_user(void) {}


// code will run multiple times while keyboard is suspended
void suspend_power_down_user(void) {}

// code will run on keyboard wakeup
void suspend_wakeup_init_user(void) {}

// all callbacks have _user() or _kb() suffix .. use _user() for keymaps changes (user files) and _kb()
// for keyboard/revision changes.

// gets called after keyboard reboots?
void keyboard_post_init_user(void) {}



#ifdef CONSOLE_ENABLE
#define printf uprintf
#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // MACROS here?

    printf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    uint8_t mods;

    switch (keycode) {

    case JT_BOOT:
        rgb_matrix_set_color(24, 220, 255, 220);
        rgb_matrix_set_color(25, 220, 255, 220);
        rgb_matrix_set_color(26, 220, 255, 220);
        rgb_matrix_set_color(27, 220, 255, 220);
        defer_exec(1500, cb_bootloader, NULL);
        return false; // return false to stop qmk from further processing

    case JT_INFO:
        mods = get_mods();

        // ctrl + alt + shift is required
        mods &= get_mods() && ( MOD_BIT(KC_LCTL)
                  | MOD_BIT(KC_RCTL)
                  | MOD_BIT(KC_LALT)
                  | MOD_BIT(KC_RALT)
                  | MOD_BIT(KC_LSFT)
                  | MOD_BIT(KC_RSFT));
        printf("mods: 0x%04x\n", mods);

        if (mods) {
            rgb_matrix_set_color_all(255, 0, 0);
            defer_exec(1500, cb_ledgreen, NULL);
        }
        return false;

    case KC_8:
        rgb_matrix_set_color_all(120, 120, 120);
        rgb_matrix_set_color(LED_8, 0, 0, 0);
        // deferred_token my_token;
        defer_exec(1500, cb_ledgreen, NULL);


        // char abuff[48];
        // sprintf(abuff, "\rkc: %04d led: %04d", keycode, RGB_MATRIX_LED_COUNT);
        // send_string(abuff) // this works
        // SEND_STRING(abuff) // this does not work

        return true; // let qmk process the key
        break;
    }

    return true;
};


// TODO this is preformance sensitive area.
//
// This function gets called at every matrix scan, which is basically as often as the MCU can handle. Be
// careful what you put here, as it will get run a lot.
//
// You should use this function if you need custom matrix scanning code. It can also be used for custom
// status output (such as LEDs or a display) or other functionality that you want to trigger regularly
// even when the user isn’t typing.
//
//
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    // TODO: where is layer_state defined?
    uint8_t layer = biton32(layer_state);


    // turn off all leds
    // rgb_matrix_set_color(20, 0, 0, 0);
    // rgb_matrix_set_color(21, 0, 0, 0);
    // rgb_matrix_set_color(22, 0, 0, 0);
    // rgb_matrix_set_color(23, 0, 0, 0);

    rgb_matrix_set_color(LED_GRV, 0, 0, 0);
    rgb_matrix_set_color(LED_P0, 0, 0, 0);
    rgb_matrix_set_color(LED_1, 0, 0, 0);
    rgb_matrix_set_color(LED_P1, 0, 0, 0);
    rgb_matrix_set_color(LED_2, 0, 0, 0);
    rgb_matrix_set_color(LED_P2, 0, 0, 0);
    rgb_matrix_set_color(LED_3, 0, 0, 0);
    rgb_matrix_set_color(LED_P3, 0, 0, 0);


    // turn on led that corresponds to layer
    switch (layer) {
    case 0:
        rgb_matrix_set_color(LED_GRV, 255, 0, 0);
        rgb_matrix_set_color(LED_P0, 255, 0, 0);
        break;
    case 1:
        rgb_matrix_set_color(LED_1, 255, 0, 0);
        rgb_matrix_set_color(LED_P1, 255, 0, 0);
        break;
    case 2:
        rgb_matrix_set_color(LED_2, 255, 0, 0);
        rgb_matrix_set_color(LED_P2, 255, 0, 0);
        break;
    case 3:
        rgb_matrix_set_color(LED_P3, 255, 0, 0);
        rgb_matrix_set_color(LED_3, 255, 0, 0);
        break;
    }
};




//////////////////////////////////////////////////////////////////////
// defered func
