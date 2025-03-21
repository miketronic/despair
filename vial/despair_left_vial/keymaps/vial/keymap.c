// Copyright 2024
// miketronic@github m1ketronic@discord -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _NUM,
  _BTB,
  _FN
};

// Layer macros
#define ZFN     LT(_FN, KC_Z)           // Tap for "Z", hold for FN layer
#define TNUM    LT(_NUM, KC_T)          // Tap for "T", hold for Numbers layer
#define BTB     LT(_BTB, KC_B)          // Tap for "B", hold for Trackball layer
#define SFTSPC  SFT_T(KC_SPC)           // Tap for "Space", hold for Shift
#define SFTENT  SFT_T(KC_ENT)           // Tap for "Enter", hold for Shift


// MISC
#define CALTDEL LCTL(LALT(KC_DEL))	    // Ctrl Alt Del
#define TSKMGR  LCTL(LSFT(KC_ESC))	    // Task Manager
#define CLIP    LCTL(LALT(KC_Q))	    	// Clipboard (Ditto)
#define SS      LCTL(LALT(KC_G))		    // Greenshot region
#define DELWORD LCTL(KC_BSPC)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define ____    KC_TRNS
#define XXXX    KC_NO
#define XXXXXXX KC_NO



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA] = LAYOUT (
   KC_Q,  KC_W,  KC_E,  KC_R,  TNUM,  KC_Y,  KC_U,  KC_I,  KC_O,   KC_P,
   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,   KC_SCLN,
   ZFN,   KC_X,  KC_C,  KC_V,  BTB,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,
   SFTSPC, SFTSPC,  KC_BTN1,  KC_BTN3,  KC_BTN3, KC_BTN1, SFTENT,  SFTENT
  ),

  [_NUM] = LAYOUT (
   KC_TAB,   XXXX,  XXXX,  KC_LSFT, XXXX,    KC_7,   KC_8,  KC_9,  KC_0,   KC_BSPC,
   KC_LSFT,  XXXX,  XXXX,  XXXX,    XXXX,    KC_4,   KC_5,  KC_6,  XXXX,   KC_DEL,
   QK_BOOT,  XXXX,  XXXX,  XXXX,    XXXX,    KC_1,   KC_2, KC_3,   XXXX,   XXXX,
   SFTSPC, SFTSPC,  KC_BTN1,  KC_BTN3,  KC_BTN3, KC_BTN1, SFTENT,  SFTENT
  ),

  [_BTB] = LAYOUT (
   XXXX, XXXX,  KC_BTN3,  KC_BTN2,  KC_BTN1,      KC_RSFT,  KC_WH_U,  KC_WH_D,  XXXX,  XXXX,
   XXXX, XXXX,  KC_LSFT,  KC_WH_U,  KC_WH_D,      XXXX,     XXXX,     XXXX,  XXXX,   XXXX,
   XXXX, XXXX,  XXXX,        XXXX,     XXXX,      XXXX,     XXXX,     XXXX,  XXXX,   XXXX,
   SFTSPC, SFTSPC,  KC_BTN1,  KC_BTN3,  KC_BTN3, KC_BTN1, SFTENT,  SFTENT
  ),

  [_FN] = LAYOUT (
   XXXX, KC_TAB, XXXX,      CLIP,    SS,        KC_F2,    KC_UP,   KC_DEL,  KC_BSPC,   XXXX,
   XXXX, XXXX,   KC_TAB,    XXXX,    XXXX,    KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,    XXXX,
   XXXX, XXXX,   XXXX,    DELWORD,   XXXX,    XXXX,     XXXX,   XXXX,      XXXX,      XXXX,
   SFTSPC,  SFTSPC, XXXX,   TSKMGR,  TSKMGR,  XXXX,   SFTENT,  SFTENT
  )

};

void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 10); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 1800); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}
