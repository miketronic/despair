// Copyright 2024 
// miketronic@github m1ketronic@discord -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

enum layers {
  _ALPHA,
  _NUM,
  _BTB,
  _FN,
  _SYMB
};

// Layer macros
#define GSYM    LT(_SYMB, KC_G)         // Tap for "G", hold for Symbols layer
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


// Tap Dance
enum tapdance_id{
  T_WESC = 0,
  T_20,
  T_OCOM,
  T_YDOT,
  T_BRACES,
  T_PAREN,
  T_ANGLE
};

#define TD_WESC  TD(T_WESC)
#define TD_20    TD(T_20)
#define TD_OCOM  TD(T_OCOM)
#define TD_YDOT  TD(T_YDOT)
#define TD_BRACES TD(T_BRACES)
#define TD_PAREN TD(T_PAREN)
#define TD_ANGLE TD(T_ANGLE)

tap_dance_action_t tap_dance_actions[] = {
  [T_WESC] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_ESC),                     // "w", Escape
  [T_20] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0),                         // "2", "0"
  [T_OCOM] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_COMMA),	                // "O", ","
  [T_YDOT] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_DOT),                     // "Y", "."
  [T_BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),                // "[", "]"
  [T_PAREN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),                // "(", ")"
  [T_ANGLE] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),                    // "<", ">"
};

enum custom_keycodes{
  MAKE = QK_USER,
  ANGLE,
  PAREN,
  BRACES,
  CCCV,
  ENDHOME,
  UNDOER,
  SYM1,
  SYM2,
  SYM3,
  SYM4,
  SYM5,
  SYM6,
  SYM7,
  SYM8
};






const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA] = LAYOUT (
   KC_Q,  KC_W,  KC_E,  KC_R,  TNUM,  KC_Y,  KC_U,  KC_I,  KC_O,   KC_P,  
   KC_A,  KC_S,  KC_D,  KC_F,  GSYM,  KC_H,  KC_J,  KC_K,  KC_L,   KC_SCLN,    
   ZFN,   KC_X,  KC_C,  KC_V,  BTB,   KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,
   SFTSPC, SFTSPC,  KC_BTN1,  KC_BTN3,  KC_BTN3, KC_BTN1, SFTENT,  SFTENT
  ),

  [_NUM] = LAYOUT (
   KC_TAB,   XXXX,  XXXX,  KC_LSFT, XXXX,    KC_7,   KC_8,  KC_9,  KC_0,   KC_BSPC,   
   KC_LSFT,  CCCV,  XXXX,  XXXX,    XXXX,    KC_4,   KC_5,  KC_6,  XXXX,   KC_DEL,   
   QK_BOOT,  XXXX,  XXXX,  XXXX,    XXXX,    KC_1,   TD_20, KC_3,  XXXX,   XXXX,   
   SFTSPC, SFTSPC,  KC_BTN1,  KC_BTN3,  KC_BTN3, KC_BTN1, SFTENT,  SFTENT
  ),

  [_BTB] = LAYOUT (
   XXXX, XXXX,  KC_BTN3,  KC_BTN2,  KC_BTN1,      KC_RSFT,  KC_WH_U,  KC_WH_D,  XXXX,   RGB_TOG, 
   XXXX, XXXX,  KC_LSFT,  KC_WH_U,  KC_WH_D,      CCCV,     RGB_HUI,  RGB_SAI,  XXXX,   XXXX, 
   XXXX, XXXX,  XXXX,        XXXX,     XXXX,      RGB_TOG,  RGB_MOD,  RGB_VAI,  XXXX,   XXXX, 
   SFTSPC, SFTSPC,  KC_BTN1,  KC_BTN3,  KC_BTN3, KC_BTN1, SFTENT,  SFTENT
  ),

  [_FN] = LAYOUT (
   XXXX, KC_TAB, CCCV,    CLIP,    SS,        KC_F2,    KC_UP,   KC_DEL,  KC_BSPC,   XXXX, 
   XXXX, XXXX,   KC_TAB,    XXXX,    XXXX,    KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,    XXXX, 
   XXXX, XXXX,   XXXX,    DELWORD,   XXXX,    UNDOER,   XXXX,    ENDHOME, XXXX,      XXXX, 
   SFTSPC,  SFTSPC, CCCV,   TSKMGR,  TSKMGR,  CCCV,   SFTENT,  SFTENT
  ),

  [_SYMB] = LAYOUT (
   XXXX, XXXX,   XXXX,    SYM1,   XXXX,        TD_PAREN,   TD_BRACES,   TD_ANGLE, XXXX,   XXXX, 
   XXXX, XXXX,   XXXX,    SYM2,   XXXX,        SYM3,    SYM4,    SYM5,  XXXX,   XXXX, 
   XXXX, XXXX,   XXXX,    XXXX,   XXXX,        SYM6,    SYM7,    SYM8,  XXXX,   XXXX, 
   SFTSPC,  SFTSPC, CCCV,   TSKMGR,  TSKMGR,  CCCV,   SFTENT,  SFTENT
  ),

};


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ZFN:
            return false;
        case BTB:
            return false;
        case GSYM:
            return false;
        case TNUM:
            return false;           
        case SFTSPC:
            return false;
        case SFTENT:
            return false;
        case TD_WESC:
            return false;
        case TD_OCOM:
            return false;
        case TD_YDOT:
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
switch (keycode) {
	  case CCCV:
				return 80;
			default:
				return TAPPING_TERM;
		}
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case CCCV: // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) { // Hold, copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap, paste
                    tap_code16(LCTL(KC_V));
                }
            }
            return false;
            break;
            
        case ENDHOME:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_HOME);
                } else {
                    tap_code16(KC_END);
                }
            }
            return false;
            break;

        case UNDOER:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    SEND_STRING(SS_LCTL("y"));
                } else {
                    SEND_STRING(SS_LCTL("z"));
                }
            }
            return false;
            break;

        case SYM1:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_CIRC);
                } else {
                    tap_code16(KC_ASTR);
                }
            }
            return false;
            break;

        case SYM2:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_PLUS);
                } else {
                    tap_code16(KC_EQL);
                }
            }
            return false;
            break;

        case SYM3:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_SCLN);
                } else {
                    tap_code16(KC_COLN);
                }
            }
            return false;
            break;

        case SYM4:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_BSLS);
                } else {
                    tap_code16(KC_SLSH);
                }
            }
            return false;
            break;

        case SYM5:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_AMPR);
                } else {
                    tap_code16(KC_PIPE);
                }
            }
            return false;
            break;

        case SYM6:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_DQUO);
                } else {
                    tap_code16(KC_QUOT);
                }
            }
            return false;
            break;

        case SYM7:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_HASH);
                } else {
                    tap_code16(KC_AT);
                }
            }
            return false;
            break;

        case SYM8:
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    tap_code16(KC_DLR);
                } else {
                    tap_code16(KC_PERC);
                }
            }
            return false;
            break;

        case ANGLE:
            if (record->event.pressed) {
                SEND_STRING("<>");
                tap_code(KC_LEFT);
            }
            return false;
            break;

        case BRACES:
            if (record->event.pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
            }
            return false;
            break;

        case PAREN:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            return false;
            break;

    }
    return true;
}


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