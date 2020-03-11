#include QMK_KEYBOARD_H

#define _BASE 0
#define _MOVE 1
#define _MOVE_SHIFT 2
#define _SELECT 3
#define _SELECT_MOVE 4
#define _SELECT_MOVE_SHIFT 5
#define _NUM 6
#define _SYM 7

//#define _FN4 6
enum {
	TD_CPY_PST = 0,
	TD_CMD,
	TD_SLSH,
 	TD_VRDSK
};
enum custom_keycodes {
	MOVE = SAFE_RANGE,
	MOVE_SHIFT,
	SELECT,
	SELECT_MOVE,
	SELECT_MOVE_SHIFT,
	NUM,
	SYM,
	dance_cln_finished,
	KC_GUITAB,
	KC_MOVE,
	KC_MSHIFT,
	KC_SEL_L,
    KC_SEL_R,
    KC_SEL_U,
    KC_SEL_D,
    KC_SEL_L_WRD,
    KC_SEL_R_WRD,
    KC_SEL_PG_UP,
    KC_SEL_PG_D,
    KC_SEL_HOME,
    KC_SEL_END,
    KC_L_WRD,
    KC_R_WRD,
    KC_B_WRD,
    KC_S_COPY,
    KC_S_CUT,
    KC_SEL_A
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define KC_CAPW LGUI(X_LSHIFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(X_LSHIFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(X_LSHIFT(KC_4))       // Capture portion of screen
#define KC_CPYP LGUI(X_LSHIFT(LCTL(KC_4)))  // Copy portion of screen
//#define KC_GUITAB RWIN_T(KC_TAB)

#define KC_SEL_A M(23) // OSL(_SELECT) // turns on the select oneshot, turns off when any key is pressed
#define KC_TABNUM LT(_NUM, KC_TAB)
#define KC_SYM MO(_SYM)
#define KC_CTRLENT MT(MOD_LCTL, KC_ENT)

#define KC_EXLM LSFT(KC_1)
#define KC_AT LSFT(KC_2)
#define KC_HASH LSFT(KC_3)
#define KC_DLR LSFT(KC_4)
#define KC_PERC LSFT(KC_5)
#define KC_CAR LSFT(KC_6)
#define KC_AMPR LSFT(KC_7)
#define KC_ASTR LSFT(KC_8)
#define KC_LPRN LSFT(KC_9)
#define KC_RPRN LSFT(KC_0)

#define OS_CTL LCTL
//#define OS_CTL LCMD

#define KC_ALTAB OS_CTL(KC_TAB)
#define KC_AALTAB OS_CTL(KC_TILDE)

#define KC_NAVTEST OS_CTL(LSFT(KC_T))
#define KC_SAVE OS_CTL(KC_S)
#define KC_COPY OS_CTL(KC_C)
#define KC_CUT OS_CTL(KC_X)
#define KC_PASTE OS_CTL(KC_V)
#define KC_TERMPASTE OS_CTL(LSFT(KC_V))
#define KC_UNDO OS_CTL(KC_Z)
#define KC_ALTENT LCTL(KC_ENT)
#define KC_COMMENT OS_CTL(KC_SLSH)
#define KC_REDO OS_CTL(LSFT(KC_Z))
#define KC_FORMAT LALT(LSFT(KC_L))
#define KC_GOTO OS_CTL(KC_B)
#define KC_DIR LALT(LSFT(KC_D))
#define KC_OPEN LALT(LSFT(KC_O))
#define KC_FINDA LALT(LSFT(KC_F))
#define KC_OOG LALT(LSFT(KC_4)) // Open in oposite group intellij
#define KC_RUN LALT(LCTL(KC_R)) // Run on cursor intellij
#define KC_DEBUG LALT(LCTL(KC_D)) // Debug on cursor intellij
#define KC_SRUN LSFT(LALT(LCTL(KC_R))) // Run on cursor intellij
#define KC_SDEBUG LSFT(LALT(LCTL(KC_D))) // Debug on cursor intellij
#define KC_MVRT LALT(KC_4) // Move window right (do a split) in intellij
#define KC_MVGRP LALT(LSFT(KC_4)) // Alternate the group of the window in intellij
#define KC_CLOSE OS_CTL(KC_W)
#define KC_REP OS_CTL(KC_R)
#define KC_REPA LALT(LSFT(KC_R))
#define KC_OPG LALT(KC_S) // Move to the opposite group intellij
#define KC_FIND OS_CTL(KC_F)
#define KC_P_TAB LCTL(KC_PGUP)
#define KC_N_TAB LCTL(KC_PGDN)
#define KC_PREV LALT(KC_LBRC)
#define KC_NEXT LALT(KC_RBRC)
#define KC_REF LCTL(KC_R)

#define KC_SELALL LCTL(KC_A)

//#define MOVE X_LALT // mac
#define MOVE X_LCTRL // linux/windows


// Fillers to make layering more clear

#define ____ KC_TRNS

bool volatile shift_down=false;
bool volatile space_shift_down=false;
bool volatile gui_down=false;
bool volatile alt_down=false;
bool volatile select_active=false;
bool volatile pressed_something_else=false;
bool volatile pressed_something_else_gui=false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool p = record->event.pressed;
  	switch (keycode) {
      	case KC_SEL_L: // select left
      	    if (p) {
      	      SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_LEFT) SS_UP(X_LSHIFT));
      	    }
      	    else {
      	      SEND_STRING(SS_UP(X_LEFT) SS_UP(X_LSHIFT));
      	    }
  //    	    set_oneshot_layer(_SELECT, ONESHOT_START)
      	    return false;

      	case KC_SEL_R: // select right
      	    if (p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_RIGHT));
      	    }
      	    else {
      	      SEND_STRING(SS_UP(X_RIGHT) SS_UP(X_LSHIFT));
      	    }
  //    	    set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_U: // select up
              if(p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_UP));
              }
              else {
                SEND_STRING(SS_UP(X_UP) SS_UP(X_LSHIFT));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_D: // select down
              if (p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_DOWN));
              }
              else {
                SEND_STRING(SS_UP(X_DOWN) SS_UP(X_LSHIFT));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_L_WRD: // select left word
              if (p) {
                SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_LSHIFT) SS_DOWN(X_LEFT));
              }
              else {
                SEND_STRING(SS_UP(X_LEFT) SS_UP(X_LSHIFT) SS_UP(MOVE));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_R_WRD: // select right word
              if(p) {
                SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_LSHIFT) SS_DOWN(X_RIGHT));
              }
              else {
                SEND_STRING(SS_UP(X_RIGHT) SS_UP(X_LSHIFT) SS_UP(MOVE));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_PG_UP: // select page up
              if (p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_PGUP));
              }
              else {
                SEND_STRING(SS_UP(X_PGUP) SS_UP(X_LSHIFT));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_PG_D: // select page down
              if (p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_PGDOWN));
              }
              else {
                SEND_STRING(SS_UP(X_PGDOWN) SS_UP(X_LSHIFT));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_HOME: // select home
              if(p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_HOME));
              }
              else {
                SEND_STRING(SS_UP(X_HOME) SS_UP(X_LSHIFT));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

          case KC_SEL_END: // select end
              if(p) {
                SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_END));
              }
              else {
                SEND_STRING(SS_UP(X_END) SS_UP(X_LSHIFT));
              }
  //            set_oneshot_layer(_SELECT, ONESHOT_START)
              return false;

      	case KC_L_WRD: // left word
      	    if (p) {
      	      SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_LEFT));
      	    }
      	    else {
        	      SEND_STRING(SS_UP(X_LEFT) SS_UP(MOVE));
      	    }
      		return false;

      	case KC_SEL_A: // Activate select mode
                   if(p) {
                     select_active = !select_active;
                     layer_on(_SELECT_MOVE);
                   }
                   return false;

      	case KC_R_WRD: // right word
      	    if(p) {
                SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_RIGHT));
      	    }
      	    else {
                SEND_STRING(SS_UP(X_RIGHT) SS_UP(MOVE));
      	    }
              return false;

          case KC_B_WRD: // backspace left word
              if (p) {
                SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_BSPACE));
              }
              else {
                SEND_STRING(SS_UP(X_BSPACE) SS_UP(MOVE));
              }
              return false;

          case KC_S_COPY: //scopy
              if (p) {

                SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_C));
              }
              else {
                SEND_STRING(SS_UP(X_C) SS_UP(MOVE) SS_TAP(X_ESCAPE));
                select_active=false;
                layer_off(_SELECT_MOVE);
                layer_on(_MOVE);
              }
              return false;

          case KC_S_CUT: //scut
              if (p) {
                SEND_STRING(SS_DOWN(MOVE) SS_DOWN(X_X));
              }
              else {
                SEND_STRING(SS_UP(X_X) SS_UP(MOVE) SS_TAP(X_ESCAPE));
                select_active=false;
                layer_off(_SELECT_MOVE);
                layer_on(_MOVE);
              }
              return MACRO_NONE;


           case KC_MOVE: // malt
              if(p) {
                alt_down=true;
                if (select_active) {
                  if (shift_down) {
                    SEND_STRING(SS_UP(X_LSHIFT));
                    layer_on(_SELECT_MOVE_SHIFT);
                  }
                  else {
                    layer_on(_SELECT_MOVE);
                  }
                }
                else {
                  if (shift_down) {
                    SEND_STRING(SS_UP(X_LSHIFT));
                    layer_on(_MOVE_SHIFT);
                  }
                  else {
                    layer_on(_MOVE);
                  }
                }
              }
              else {
                alt_down=false;
                select_active = false;
                layer_off(_MOVE);
                layer_off(_MOVE_SHIFT);
                layer_off(_SELECT_MOVE_SHIFT);
                layer_off(_SELECT_MOVE);
              }
              return false;

           case KC_MSHIFT: // mshift
              if(p) {
                shift_down=true;
                if(alt_down) {
                  if(select_active) {
                    layer_on(_SELECT_MOVE_SHIFT);
                  }
                  else {
                    layer_on(_MOVE_SHIFT);
                  }
                }
                else {
                  SEND_STRING(SS_DOWN(X_LSHIFT));
                }
              }
              else {
                shift_down=false;
                layer_off(_SELECT_MOVE_SHIFT);
                layer_off(_MOVE_SHIFT);
                layer_off(_MOVE);
                if (alt_down) {
                  if(select_active) {
                    layer_on(_SELECT_MOVE);
                  }
                  else {
                    layer_on(_MOVE);
                  }
                }
                SEND_STRING(SS_UP(X_LSHIFT));
              }
              return false;

  	}

   return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  CAPS| ALT  |                                                         |   \  |   =  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                             |  TAB |                             | ENT  |
 *                             |   +  |                             |  +   |
 *                             | NUM |                             | CTRL  |
 *                             +------'                             '------u
 *                                    '------+------' '------+------'
 *                                    | MOVE | SHFT | | BSP  |SPACE |
 *                                    '------+------' '------+------'
 *                                    | GUI  | SYM  | |      |      |
 *                                    '------+------' '------+------'
 */
[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
       KC_CAPS, KC_LALT,                                                                    KC_BSLS, KC_EQL,          \
                                  KC_TABNUM,                        KC_CTRLENT,                                       \
                                      KC_MOVE, KC_SYM,   KC_BSPC,  KC_SPACE,                                           \
                                      KC_LSFT, KC_LGUI,    KC_ESC,  ____
),

/* MOVE
 * ,----------------------------------,                             ,----------------------------------,
 * |ALTAB | CLOSE|B_WRD |  REF |      |                             |      | L_WRD|  UP  | R_WRD|      |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |SELALL| SAVE |mshift| FIND |      |                             |   END| LEFT | DOWN | RIGHT|      |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | UNDO | CUT  | COPY |PASTE |      |                             |      |      | P_TAB|N_TAB |      |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |MSHIFT|                                                         | PREV | NEXT |
 *        '------+------'-------------'                             '-------------'------+------'
 *                             |      |                             |      |
 *                             |      |                             |ALTENT|
 *                             |      |                             |      |
 *                             +------'                             '------+
 *                                    '------+------' '------+------'
 *                                    |      |MSHIFT| | RUN  | SEL_A|
 *                                    '------+------' '------+------'
 *                                    |      |      | | DEBUG|      |
 *                                    '------+------' '------+------'
 */

[_MOVE] = LAYOUT( \
  KC_ALTAB, KC_CLOSE, KC_B_WRD,KC_REP,____,                                     ____, KC_L_WRD, KC_UP, KC_R_WRD, KC_MVRT,         \
  KC_SELALL, KC_SAVE, KC_MSHIFT,KC_FIND,    ____,                                       KC_END, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_OPG,         \
  KC_UNDO, KC_CUT, KC_COPY, KC_PASTE,KC_GOTO,                                       ____,____, KC_P_TAB,KC_N_TAB,  KC_COMMENT,         \
        ____, KC_MSHIFT,                                                                  KC_PREV, KC_NEXT,               \
                                  ____,                        KC_ALTENT,                                                 \
                                      ____,____,     KC_RUN,  KC_SEL_A,                                                   \
                                      KC_MSHIFT, ____,     KC_DEBUG,  ____
),
 /* MOVE_SHIFT
  * ,----------------------------------,                             ,----------------------------------,
  * |AALTAB| CLOSE|B_WRD |REPA | NAVTEST |                             |      | L_WRD| PGUP | OPEN |      |
  * |------+------+------+------+------|                             |-------------+------+------+------|
  * |SELALL| SAVE |  DIR   | FINDA |      |                             |  HOME|      | PGDN | RIGHT|      |
  * |------+------+------+------+------|                             |------|------+------+------+------|
  * | REDO |      |     |      |      |                             |      |      |      |      |      |
  * |------+------+------+-------------,                             ,-------------+------+------+------,
  *        |      |MSHIFT|                                                         |      |      |
  *        '------+------'-------------'                             '-------------'------+------'
  *                             |      |                             |      |
  *                             |      |                             |ALTENT|
  *                             |      |                             |      |
  *                             +------'                             '------+
  *                                    '------+------' '------+------'
  *                                    |      |MSHIFT| | RUN  |DEBUG |
  *                                    '------+------' '------+------'
  *                                    |      |      | |      |      |
  *                                    '------+------' '------+------'
  */
[_MOVE_SHIFT] = LAYOUT( \
  KC_AALTAB, KC_CLOSE, KC_B_WRD,KC_REPA,    KC_NAVTEST,                              ____, KC_L_WRD, KC_PGUP, KC_OPEN, KC_MVGRP,         \
  KC_SELALL, KC_SAVE, KC_DIR, KC_FINDA,    ____,                           KC_HOME, ____,    KC_PGDN, KC_RIGHT, ____,         \
  KC_REDO, ____,____ ,    KC_TERMPASTE,    ____,                                       ____, ____,    ____, ____, ____,         \
        ____, ____,                                                                        ____, ____,               \
                                  ____,                        KC_ALTENT,                                                 \
                                      ____, ____,     KC_SRUN,  KC_SDEBUG,                                                   \
                                      KC_MSHIFT, ____,     ____,  ____
),

   /* SELECT
    * ,----------------------------------,                             ,----------------------------------,
    * |      |      |      |      |      |                             |      |      |      |      |      |
    * |------+------+------+------+------|                             |-------------+------+------+------|
    * |      |      |      |      |      |                             |      |      |      |      |      |
    * |------+------+------+------+------|                             |------|------+------+------+------|
    * |      |      |      |      |      |                             |      |      |      |      |      |
    * |------+------+------+-------------,                             ,-------------+------+------+------,
    *        |      |MSHIFT|                                                         |      |      |
    *        '------+------'-------------'                             '-------------'------+------'
    *                             |      |                             |      |
    *                             |      |                             |      |
    *                             |      |                             |      |
    *                             +------'                             '------+
    *                                    '------+------' '------+------'
    *                                    |  MOVE|MSHIFT| |      |     |
    *                                    '------+------' '------+------'
    *                                    |      |      | |      |      |
    *                                    '------+------' '------+------'
    */
[_SELECT] = LAYOUT( \
  ____, ____, ____,    ____,    ____,                                       KC_A, ____,    ____, ____, ____,         \
  ____, ____, ____,    ____,    ____,                                       ____, ____,    ____, ____, ____,         \
  ____, ____, ____,    ____,    ____,                                       ____, ____,    ____, ____, ____,         \
        ____, KC_MSHIFT,                                                                        ____, ____,               \
                                  ____,                        ____,                                                 \
                                      KC_MOVE, ____,     ____,  ____,                                                   \
                                      KC_MSHIFT, ____,     ____,  ____
),

   /* SELECT_MOVE
    * ,----------------------------------,                             ,----------------------------------,
    * |      |      |      |      |      |                             |      |SEL_L_WRD| SEL_U|SEL_R_WRD|      |
    * |------+------+------+------+------|                             |-------------+------+------+------|
    * |      |      |      |      |      |                             |SEL_END|SEL_L|SEL_D | SEL_R|      |
    * |------+------+------+------+------|                             |------|------+------+------+------|
    * |  UNDO| S_CUT|S_COPY| PASTE|      |                             |      |      |      |      |      |
    * |------+------+------+-------------,                             ,-------------+------+------+------,
    *        |      |MSHIFT|                                                         |      |      |
    *        '------+------'-------------'                             '-------------'------+------'
    *                             |      |                             |      |
    *                             |      |                             |      |
    *                             |      |                             |      |
    *                             +------'                             '------+
    *                                    '------+------' '------+------'
    *                                    |  MOVE|MSHIFT| |      |     |
    *                                    '------+------' '------+------'
    *                                    |      |      | |      |      |
    *                                    '------+------' '------+------'
    */
[_SELECT_MOVE] = LAYOUT( \
  ____, ____, ____,    ____,    ____,                                       ____, KC_SEL_L_WRD,KC_SEL_U, KC_SEL_R_WRD, ____,         \
  ____, ____, ____,    ____,    ____,                                       KC_SEL_END,KC_SEL_L,KC_SEL_D, KC_SEL_R, ____,         \
  KC_UNDO, KC_S_CUT, KC_S_COPY, KC_PASTE,    ____,                                       ____, ____,    ____, ____, ____,         \
        ____, KC_MSHIFT,                                                                        ____, ____,               \
                                  ____,                        ____,                                                 \
                                      KC_MOVE, ____,     ____,  ____,                                                   \
                                      KC_MSHIFT, ____,     ____,  ____
),
   /* SELECT_MOVE_SHIFT
    * ,----------------------------------,                             ,----------------------------------,
    * |      |      |      |      |      |                             |      |      |SEL_PG_UP|      |      |
    * |------+------+------+------+------|                             |-------------+------+------+------|
    * |      |      |      |      |      |                             |SEL_HOME|    |SEL_PG_D|      |      |
    * |------+------+------+------+------|                             |------|------+------+------+------|
    * |      |      |      |      |      |                             |      |      |      |      |      |
    * |------+------+------+-------------,                             ,-------------+------+------+------,
    *        |      |MSHIFT|                                                         |      |      |
    *        '------+------'-------------'                             '-------------'------+------'
    *                             |      |                             |      |
    *                             |      |                             |      |
    *                             |      |                             |      |
    *                             +------'                             '------+
    *                                    '------+------' '------+------'
    *                                    |  MOVE|MSHIFT| |      |     |
    *                                    '------+------' '------+------'
    *                                    |      |      | |      |      |
    *                                    '------+------' '------+------'
    */
[_SELECT_MOVE_SHIFT] = LAYOUT( \
  ____, ____, ____,    ____,    ____,                                       ____, ____,    KC_SEL_PG_UP, ____, ____,         \
  ____, ____, ____,    ____,    ____,                                       KC_SEL_HOME, ____,    KC_SEL_PG_D, ____, ____,         \
  ____, ____, ____,    ____,    ____,                                       ____, ____,    ____, ____, ____,         \
        ____, KC_MSHIFT,                                                                        ____, ____,               \
                                  ____,                        ____,                                                 \
                                      KC_MOVE, ____,     ____,  ____,                                                   \
                                      KC_MSHIFT, ____,     ____,  ____
),

/* NUM
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |      |  1   |  2   |  3   |     |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |                             |      |  4   |  5   |  6   |      |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  F11 |  F12 |      |      |      |                             |      |  7   |  8   |  9   |  ENT |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | REST |      |                                                         |  0   |  +   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */


[_NUM] = LAYOUT( \
  KC_F1, KC_F2, KC_F3,    KC_F4,    KC_F5,                                       ____, KC_1,KC_2, KC_3, ____,         \
  KC_F6, KC_F7, KC_F8,    KC_F9,    KC_F10,                                       ____, KC_4,KC_5, KC_6, ____,         \
  KC_F11, KC_F12, ____,    ____,    ____,                                       ____, KC_7, KC_8, KC_9, KC_ENT,         \
        RESET, ____,                                                                      KC_0, KC_PLUS,             \
                                  ____,                        KC_PLUS,                                                 \
                                      ____, ____,     KC_DOT,  KC_0,                                                   \
                                      ____, ____,     ____,  ____
),

/* SYM
 * ,----------------------------------,                             ,----------------------------------,
 * | !    | @    |  #   |  $   |  %   |                             |  ^   |  &   |   *  |  +   |   =  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  ~   |   `  |  {   |  }   |  [   |                             |   ]  |  (   |   )  |  '   |  "   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |  [   |  ]   |  _   |                             |   -  |  _   |      |      |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_SYM] = LAYOUT( \
  KC_EXLM,KC_AT, KC_HASH, KC_DLR,KC_PERC,                                       KC_CAR, KC_AMPR,KC_ASTR,KC_PLUS,KC_EQL,         \
  LSFT(KC_GRAVE), KC_GRAVE, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_LBRC,             KC_RBRC, KC_LPRN,KC_RPRN, KC_QUOT, LSFT(KC_QUOT),         \
  ____,           ____,       KC_LBRC, KC_RBRC, LSFT(KC_MINUS),                KC_MINUS, LSFT(KC_MINUS), ____, ____, LSFT(KC_BSLS),         \
        ____, ____,                                                              KC_MINUS, KC_EQL,               \
                                  ____,                        ____,                                                 \
                                      ____, ____,     LSFT(KC_MINUS),  KC_MINUS,                                                   \
                                      ____, ____,     ____,  ____
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
