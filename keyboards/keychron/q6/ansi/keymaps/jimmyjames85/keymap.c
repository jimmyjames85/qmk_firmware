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
#include "macro.h"

enum custom_keycodes {
    JT_INFO = SAFE_RANGE, // create our custom key code.. start in the safe range
    JT_BOOT, // bootloader
    JT_BL_O2S, // blender origin to selected  ... be in edit mode, select a face, run this macro
    JT_REC, // rec macro
    JT_PLAY, //  stoprec / play macro

};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};


bool no_screensaver_mode = false;
uint32_t last_activity_time = 0;
uint32_t start_no_screensaver_mode=0;


// KC_CODES are uint16_t

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

    //////////////////////////////////////////////////////////////////////
    // leader send strings
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_THREE_KEYS(KC_Q, KC_M, KC_K) {
            SEND_STRING("https://github.com/qmk/qmk_firmware/blob/master/docs");
        }
        SEQ_TWO_KEYS(KC_K, KC_M) {
            SEND_STRING("emo keyboards/keychron/q6/ansi/keymaps/jimmyjames85/keymap.c");
        }
        SEQ_TWO_KEYS(KC_F, KC_M) {
            SEND_STRING("https://docs.qmk.fm/#/newbs");
        }
        SEQ_THREE_KEYS(KC_M, KC_O, KC_N) {
            no_screensaver_mode = !no_screensaver_mode;
            if (no_screensaver_mode){
                start_no_screensaver_mode = timer_read32();
                printf("no_screen_saver_mode: ON\n");
            } else {
                start_no_screensaver_mode = 0;
                printf("no_screen_saver_mode: OFF\n");
            }
        }
    }


    //////////////////////////////////////////////////////////////////////
    // no_screensaver_mode

    uint32_t elapsed = timer_elapsed32(last_activity_time);
    if(no_screensaver_mode){
        if( timer_elapsed32(start_no_screensaver_mode) > 14400000) { //  14400000 ms = 4 hours
            no_screensaver_mode=false; // only run for 4 hours
            printf("no_screen_saver_mode: OFF\n");
        } else if( elapsed > 120000) { //  120000 ms = 2 mins
            tap_code16(KC_MS_UP);
            tap_code16(KC_MS_DOWN);
            last_activity_time = timer_read32();
            printf("no_screen_saver_mode OFF\n");
            printf("move mouse\n");
        }
        rgb_matrix_set_color(LED_M, RGB_GREEN);
    } else {
        rgb_matrix_set_color(LED_M, RGB_RED);
    }


    //////////////////////////////////////////////////////////////////////
    // RGB Layer colors

    uint16_t leds[10]= { LED_P0, LED_P1, LED_P2,
                         LED_P3, LED_P4, LED_P5,
                         LED_P6, LED_P7, LED_P8,
                         LED_P9
    };
    int size = sizeof(leds)/sizeof(leds[0]) ;


    // handle layer change elsewhere?

    // TODO: where is layer_state defined?
    uint8_t layer = biton32(layer_state);

    // turn on led that corresponds to layer
    switch (layer) {
    case 0:

        for ( int i=0; i<size; i++ ){
            rgb_matrix_set_color(leds[i], RGB_GREEN);
        }
        break;
    case 1:
        for ( int i=0; i<size; i++ ){
            rgb_matrix_set_color(leds[i], RGB_BLUE);
        }
        break;
    case 2:
        for ( int i=0; i<size; i++ ){
            rgb_matrix_set_color(leds[i], RGB_MAGENTA);
        }
        break;
    case 3:
        for ( int i=0; i<size; i++ ){
            rgb_matrix_set_color(leds[i], RGB_CYAN);
        }
        break;
    default:
        break;
    }
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // key counts top row to btm 20, 21, 20, 17, 16, 14

    // select/copy a layer and run this is terminal to verify length of array is equal to 108
    //
    // pbpaste | tr "\n" " " | tr "," "\n"  | wc -l
    // 108


    // Layer 0 - Green
    [0] = LAYOUT_ansi_108(
                          TD(TD_ESC_CAPS),            KC_F1,       KC_F2,        KC_F3,       KC_F4,                KC_F5,    KC_F6,      KC_F7,       KC_F8,             KC_F9,       KC_F10,      KC_F11,   KC_F12,           KC_PSCR,     KC_SCRL,     JT_INFO,           OSL(1),      KC_VOLD,     KC_VOLU,     QK_LEAD,

                          KC_GRV,         KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,       KC_MINS,     KC_EQL,              KC_BSPC,           KC_INS,      KC_HOME,     KC_PGUP,           KC_NUM,      KC_PSLS,     KC_PAST,     KC_PMNS,
                          KC_TAB,           KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,          KC_BSLS,           KC_DEL,      KC_END,      KC_PGDN,           KC_P7,       KC_P8,       KC_P9,
                          KC_LCTL,            KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,                      KC_ENT,                                                        KC_P4,       KC_P5,       KC_P6,       KC_PPLS,
                          KC_LSFT,              KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,                                KC_RSFT,                        KC_UP,                          KC_P1,       KC_P2,       KC_P3,
                          KC_LCTL,   KC_LGUI,     KC_LALT,         /****************************/ KC_SPC, /*************************/        KC_RCTL,             KC_RALT,             KC_APP,               KC_RCTL,           KC_LEFT,     KC_DOWN,     KC_RGHT,           KC_P0,       KC_PDOT,     KC_PENT),

    // Layer 1 - Blue
    [1] = LAYOUT_ansi_108(
                          JT_BOOT,         JT_BL_O2S,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           JT_REC,     JT_PLAY,     KC_TRNS,     TO(0),

                          TO(0),          TO(1),       TO(2),       TO(3),       KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                KC_TRNS,                        KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,         /****************************/ KC_TRNS, /*************************/       KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS),

    // Layer 2
    [2] = LAYOUT_ansi_108(
                          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     TO(0),

                          KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                KC_TRNS,                        KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,         /****************************/ KC_TRNS, /*************************/       KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS),

    // Layer 3
    [3] = LAYOUT_ansi_108(
                          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                 KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     TO(0),

                          KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,          KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,                                                        KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                KC_TRNS,                        KC_TRNS,                        KC_TRNS,     KC_TRNS,     KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,         /****************************/ KC_TRNS, /*************************/       KC_TRNS,             KC_TRNS,            KC_TRNS,               KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS),
};






uint32_t cb_bootloader(uint32_t trigger_time, void *cb_arg) {
    reset_keyboard();
    return 0; // means we are done
    // I think return 33; means call me again in 33ms

    // All deferred executor callbacks have a common function signature and look like:
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

void init_state(void) {
    printf("init\n");
    rgb_matrix_set_color_all(0, 0, 0);
    //    these should be in rules.mk
    // RGBLIGHT_ENABLE = no
    // RGB_MATRIX_ENABLE = yes
    // TODO verify these settings?
}

// code will run on keyboard wakeup
void suspend_wakeup_init_user(void) {
    printf("suspend_wakeup_init_user\n");
    init_state();
}

// gets called after keyboard reboots?
void keyboard_post_init_user(void) {
    printf("keyboard_post_init_user\n");
    init_state();
}

// leader key sequence started
void leader_start(void) {
    // TODO detect leader key key code?
    rgb_matrix_set_color_all(0, 255, 0);
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
        rgb_matrix_set_color(LED_ESC, 0, 0, 0);
        return;
    case 1:
        tap_code(KC_ESC); // send keydown and keyup
        return;
    case 2:
        printf("mode: %d\n", rgb_matrix_get_mode());
        rgb_matrix_set_color(LED_ESC, 255, 0, 0);
        return;
    case 3:
        rgb_matrix_set_color(LED_ESC, 0, 255, 0);
        return;
    default:
        rgb_matrix_set_color(LED_ESC, 0, 0, 255);
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

void jtbl_originToSelected(void) {
    // Cursor to Selected
    // Shift+S, U
    register_code(KC_LSFT);
    tap_code(KC_S);
    unregister_code(KC_LSFT);
    tap_code(KC_U);

    // Exit edit mode
    // Tab
    tap_code(KC_TAB);

    // "Set Origin" Menu
    // Ctrl+Alt+Shift+C
    register_code(KC_LCTL);
    register_code(KC_LALT);
    register_code(KC_LSFT);
    tap_code(KC_C);
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
    unregister_code(KC_LSFT);

    // Set Origin to 3D Cursor
    // T
    tap_code(KC_T);
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

int initialized;

static macro_t m1;
void my_init(void) {
    if (initialized == 3) {
        return; // TODO
    }

    m1.state = MS_STOPPED;
    m1.p = m1.records;

    initialized=3;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    my_init();

    printKC(keycode);
    printf("kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
           keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

    // no_screensaver_mode
    if (no_screensaver_mode) {
        last_activity_time = timer_read32(); // reset timer if key is pressed
    }

    uint8_t mods;


    uint16_t ignore[] = {OSL(1)};
    int ignoreCount=1;


    if (keycode == JT_REC){
        if (!record->event.pressed) {
            handle_macro(&m1, keycode, record, 'R', ignore, ignoreCount);
        }
        return false;
    }
    if (keycode == JT_PLAY){
        if (!record->event.pressed) {
            handle_macro(&m1, keycode, record, 'P', ignore, ignoreCount);
        }
        printf("jt_play SHOULD END\n");
        return false;
    }

    handle_macro(&m1, keycode, record, '_', ignore, ignoreCount);

    switch (keycode) {
    case JT_INFO:
        printf("JT_INFO\n");
        if (no_screensaver_mode) {
            printf("\tno screen saver mode ON\n");
        }
        uint32_t time = timer_read32(); // read timer
        printf("\ttimer: %lu\n", time);
        return false; // return false to stop qmk from further processing
    case JT_BL_O2S:
        if(record->event.pressed) { // only once on key down
            jtbl_originToSelected();
        }
        return false;
    case JT_BOOT:
        // TODO verify layer?
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
        // char abuff[48];
        // sprintf(abuff, "\rkc: %04d led: %04d", keycode, RGB_MATRIX_LED_COUNT);
        // send_string(abuff) // this works
        // SEND_STRING(abuff) // this does not work
        return true; // let qmk process the key
    default:
        return true;
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
// this ^^^ switches layers ugh...
// TODO implement dyn macros yourself
