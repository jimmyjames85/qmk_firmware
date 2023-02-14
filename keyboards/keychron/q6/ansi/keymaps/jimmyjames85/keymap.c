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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "ledindex.h"

enum custom_keycodes {
    JT_INFO = SAFE_RANGE, // create our custom key code.. start in the safe range
    JT_BOOT, // bootloader
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};



// position in file is important
//
// https://github.com/qmk/qmk_firmware/blob/master/quantum/process_keycode/process_leader.h
LEADER_EXTERNS();

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

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_F) {
            printf("leader then f\n");
        }
        SEQ_TWO_KEYS(KC_D, KC_D) {
            printf("double Ds oh my !?!\n");
        }
        SEQ_THREE_KEYS(KC_J, KC_I, KC_M) {
            printf("hi jim\n");
        }
    }

    // // TODO: where is layer_state defined?
    // uint8_t layer = biton32(layer_state);
    // // turn on led that corresponds to layer
    // switch (layer) {
    // case 0:
    //     rgb_matrix_set_color(LED_GRV, 255, 0, 0);
    //     rgb_matrix_set_color(LED_P0, 255, 0, 0);
    //     break;
    // case 1:
    //     rgb_matrix_set_color(LED_1, 255, 0, 0);
    //     rgb_matrix_set_color(LED_P1, 255, 0, 0);
    //     break;
    // case 2:
    //     rgb_matrix_set_color(LED_2, 255, 0, 0);
    //     rgb_matrix_set_color(LED_P2, 255, 0, 0);
    //     break;
    // case 3:
    //     rgb_matrix_set_color(LED_P3, 255, 0, 0);
    //     rgb_matrix_set_color(LED_3, 255, 0, 0);
    //     break;
    // }
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // key counts top row to btm 20, 21, 20, 17, 16, 14
    ///////////////////////////////// Layer 0 /////////////////////////////////
    [0] = LAYOUT_ansi_108(
                          TD(TD_ESC_CAPS),            KC_F1,       KC_F2,        KC_F3,       KC_F4,                  KC_F5,       KC_F6,       KC_F7,       KC_F8,             KC_F9,       KC_F10,      KC_F11,      KC_F12,           KC_PSCR,     KC_SCRL,     KC_PAUS,           OSL(1),      KC_VOLD,     KC_VOLU,     QK_LEAD,

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

// all qmk callbacks have a _user() or _kb() suffix
// use _user() for keymaps changes (user files) and _kb()
// for keyboard/revision changes.

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

// gets called after keyboard reboots?
void keyboard_post_init_user(void) {}

// Triggered when you start recording a macro
void dynamic_macro_record_start_user(void){
    printf("macro start\n");
};

// Triggered when you play back a macro.
void dynamic_macro_play_user(int8_t direction) {
    printf("macro play: %d\n", direction);
}

// Triggered on each keypress while recording a macro.
//
// DOES NOT WORK : (
void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
    printf("record_key: %d\n", direction);
    // printf("recording(%d) col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
    //        direction, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
}

// Triggered when the macro recording is stopped.
void dynamic_macro_record_end_user(int8_t direction) {
    printf("macro stop: %d\n", direction);
}



// leader key sequence started
void leader_start(void) {
    rgb_matrix_set_color_all(0, 255, 255);
    printf("leader key: START\n");
}

// leader sequence ended (no success/failure detection)
void leader_end(void) {
    rgb_matrix_set_color_all(0, 0, 0);
    printf("leader key: END\n");
}

#ifdef CONSOLE_ENABLE
#define printf uprintf
#endif

void tap_dance(qk_tap_dance_state_t *state, void *user_data) {
    printf("%d taps\n", state->count);
    switch (state->count) {
    case 0:
        rgb_matrix_set_color(LED_8, 0, 0, 0);
        return;
    case 1:
        // register_code(KC_ESC); // keydown
        // register_code(KC_ESC); // keyup
        tap_code(KC_ESC); // send keydown and keyup
        return;
    case 2:
        rgb_matrix_set_color(LED_8, 255, 0, 0);
        return;
    case 3:
        rgb_matrix_set_color(LED_8, 0, 255, 0);
        return;
    default:
        rgb_matrix_set_color(LED_8, 0, 0, 255);
        return;
    }
}

void printKC(int kc) {


    switch (kc) {
    case KC_A ... KC_Z:
        printf("%-16c: ", ('a'-4+kc));
        return;
    case KC_SPACE:
        printf("%-16s: ", "<KC_SPACE>");
        return;
    }
    printf("%-16s: ", "< ? >");
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // uint16_t macro_kc = (keycode == MO(_DYN) ? DM_RSTP : keycode);
    // if (!process_record_dynamic_macro(macro_kc, record)) {
    // 	return false;
    // }


    printKC(keycode);
    printf("kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
           keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    uint8_t mods;

    switch (keycode) {
    case JT_INFO:
        rgb_matrix_set_color_all(0, 0, 0);

        return false; // return false to stop qmk from further processing
    case JT_BOOT:
        mods = get_mods();
        // ctrl + alt + shift is required
        mods &= get_mods() && ( MOD_BIT(KC_LCTL)
                                | MOD_BIT(KC_RCTL)
                                | MOD_BIT(KC_LALT)
                                | MOD_BIT(KC_RALT)
                                | MOD_BIT(KC_LSFT)
                                | MOD_BIT(KC_RSFT));

        if (mods) {
            printf("entering bootloader mode...\n");
            rgb_matrix_set_color_all(255, 0, 0);
            defer_exec(1500, cb_bootloader, NULL);
        }
        return false;

    case TD(TD_ESC_CAPS):
        printf("%d: %d\n", record->tap.interrupted, record->tap.count);
        return true;
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







// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_FN(tap_dance),
};



// TODO - super alt tab - https://docs.qmk.fm/#/feature_macros?id=super-alt%E2%86%AFtab
// fix alt tab behavior in linux
// alt + tab  - send alt+tab
// holding alt - shift sends alt + shift + tab


// TODO - dynamic macros - https://docs.qmk.fm/#/feature_dynamic_macros?id=dynamic-macros-record-and-replay-macros-in-runtime
