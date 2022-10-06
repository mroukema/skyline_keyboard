/*
Copyright 2022 @demibyte

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
 
#define LAYER_ENTRY KC_TRANSPARENT

enum custom_keycodes {
  KC_DTEX,
  KC_CMQM,
  KC_L_PACB,
  KC_R_PACB
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_ARW_UP = 0,
    TD_ARW_LEFT,
    TD_ARW_DOWN,
    TD_ARW_RIGHT,
    RET_RSTHD,
    CAPS_LOCK
};

enum layer_names {
    RSTHD = 0,
    QWERTY,
    SYSTEM,
    SYMBOLS,
    NUMPAD,
    GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [RSTHD] = LAYOUT_split_skyline_3x6_5(
  //,--------------------------------------------------------------------------------------------------------------------.            ,-------------------------------------------------------------------------------------------------------------------.
      KC_TAB,           KC_SLSH,            KC_C,               KC_Y,               KC_F,               KC_K,                          KC_Z,              KC_L,               KC_CMQM,            KC_SCLN,            KC_QUOT,             KC_EQUAL,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_ESC,           MT(MOD_LSFT, KC_R), MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_T), MT(MOD_LGUI, KC_H), KC_D,                          KC_M,              MT(MOD_RGUI, KC_N), MT(MOD_RALT, KC_A), MT(MOD_RCTL, KC_I), MT(MOD_RSFT, KC_O),  KC_MINS,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      TT(SYMBOLS),      KC_J,               KC_V,               KC_G,               KC_P,               KC_B,                          KC_X,              KC_W,               KC_DTEX,            KC_U,               KC_Q,               TT(NUMPAD),
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
                        KC_NO,              KC_NO,              TT(SYSTEM),         KC_E,               KC_BSPC,                       KC_ENT,            KC_SPC,             KC_DEL,             KC_NO,              KC_NO
                     //`-------------------------------------------------------------------------------------------------'            `----------------------------------------------------------------------------------------'

  ),
  [QWERTY] = LAYOUT_split_skyline_3x6_5(
  //,--------------------------------------------------------------------------------------------------------------------.            ,-------------------------------------------------------------------------------------------------------------------.
      KC_TAB,           KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,                          KC_Y,              KC_U,               KC_I,               KC_O,               KC_P,                 KC_MINS,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_ESC,           MT(MOD_LSFT, KC_A), MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G,                          KC_H,              MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), MT(MOD_RCTL, KC_L), MT(MOD_RSFT, KC_SCLN),  KC_QUOT,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      TT(SYMBOLS),      KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,                          KC_N,              KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,             TT(NUMPAD),
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
                        KC_TRANSPARENT,     KC_TRANSPARENT,     TT(SYSTEM),         KC_SPC,             KC_BSPC,                       KC_ENT,            KC_SPC,             KC_DEL,             TD(RET_RSTHD),       LAYER_ENTRY
                     //`-------------------------------------------------------------------------------------------------'            `----------------------------------------------------------------------------------------'
  ),
  [SYSTEM] = LAYOUT_split_skyline_3x6_5(
  //,--------------------------------------------------------------------------------------------------------------------.            ,-------------------------------------------------------------------------------------------------------------------.
      KC_F1,            KC_F2,              KC_F3,              KC_F4,              KC_F5,              KC_F6,                         KC_F7,             KC_F8,               KC_F9,             KC_F10,             KC_F11,              KC_F12,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_ESC,           KC_MS_BTN1,         KC_MS_LEFT,         KC_MS_UP,           KC_MS_RIGHT,        KC_PGUP,                       KC_HOME,           TD(TD_ARW_LEFT),    TD(TD_ARW_UP),      TD(TD_ARW_RIGHT),   KC_TRANSPARENT,      TD(CAPS_LOCK),
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      TT(SYMBOLS),      KC_MS_BTN2,         KC_V,               KC_MS_DOWN,         KC_P,               KC_PGDOWN,                     KC_END,            KC_TRANSPARENT,     TD(TD_ARW_DOWN),    KC_TRANSPARENT,     KC_TRANSPARENT,      TO(GAME),          
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
                        KC_MS_BTN3,         KC_TRANSPARENT,     LAYER_ENTRY,        KC_TRANSPARENT,     KC_BSPC,                       KC_ENT,            KC_SPC,             KC_DEL,             TD(RET_RSTHD),          TO(QWERTY)
                     //`-------------------------------------------------------------------------------------------------'            `----------------------------------------------------------------------------------------'
  ),
  [SYMBOLS] = LAYOUT_split_skyline_3x6_5(
  //,--------------------------------------------------------------------------------------------------------------------.            ,-------------------------------------------------------------------------------------------------------------------.
      KC_TILD,           KC_SLSH,            KC_AMPR,            KC_AT,              KC_HASH,            KC_DLR,                       KC_PERC,           KC_CIRC,            KC_QUES,            KC_COLN,            KC_DQUO,             KC_PLUS,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_ESC,         MT(MOD_LSFT, KC_LABK), KC_LBRACKET,        KC_LPRN,            KC_LCBR,            KC_TILD,                      KC_GRAVE,          KC_RCBR,            KC_RPRN,            KC_RBRACKET,      MT(MOD_RSFT, KC_RABK), KC_UNDS,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      LAYER_ENTRY,      KC_BSLASH,          KC_MINUS,           KC_PLUS,            KC_ASTR,            KC_EQUAL,                      KC_TRANSPARENT,    KC_PIPE,            KC_EXLM,            KC_SCOLON,          KC_TRANSPARENT,      TT(NUMPAD),
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
                        KC_TRANSPARENT,     KC_TRANSPARENT,     TT(SYSTEM),         KC_TRANSPARENT,     KC_BSPC,                        KC_ENT,            KC_SPC,             KC_DEL,             TD(RET_RSTHD),       KC_TRANSPARENT
                     //`-------------------------------------------------------------------------------------------------'            `----------------------------------------------------------------------------------------'
  ),
  [NUMPAD] = LAYOUT_split_skyline_3x6_5(
  //,--------------------------------------------------------------------------------------------------------------------.            ,-------------------------------------------------------------------------------------------------------------------.
      KC_TAB,           KC_KP_COMMA,        KC_KP_7,            KC_KP_8,            KC_KP_9,             KC_KP_DOT,                     KC_TRANSPARENT,    KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_ESC,           KC_KP_ASTERISK,     KC_KP_4,            KC_KP_5,            KC_KP_6,             KC_KP_PLUS,                    KC_TRANSPARENT,    TD(TD_ARW_LEFT),    TD(TD_ARW_UP),    TD(TD_ARW_RIGHT),   MT(MOD_RSFT, KC_O),  KC_TRANSPARENT,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      TT(SYMBOLS),      KC_KP_SLASH,        KC_KP_1,            KC_KP_2,            KC_KP_3,            KC_KP_MINUS,                    KC_TRANSPARENT,    KC_TRANSPARENT,    TD(TD_ARW_DOWN),     KC_TRANSPARENT,      KC_TRANSPARENT,     LAYER_ENTRY,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
                        KC_KP_0,            KC_TRANSPARENT,     KC_LSFT,            KC_KP_ENTER,        KC_BSPC,                       KC_ENT,            KC_SPC,             KC_DEL,              TD(RET_RSTHD),      KC_TRANSPARENT
                     //`-------------------------------------------------------------------------------------------------'            `----------------------------------------------------------------------------------------'
  ),
  [GAME] = LAYOUT_split_skyline_3x6_5(
  //,--------------------------------------------------------------------------------------------------------------------.            ,-------------------------------------------------------------------------------------------------------------------.
      KC_2,              KC_TAB,            KC_Q,               KC_1,               KC_E,               KC_R,                          KC_F5,             KC_5,              KC_6,               KC_7,               KC_8,                KC_F9,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_3,              KC_LSFT,           KC_A,               KC_W,               KC_D,               KC_F,                          KC_G,              KC_LEFT,            KC_UP,              KC_RIGHT,           KC_RSFT,             KC_QUOT,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
      KC_4,              KC_LCTL,           KC_Z,               KC_S,               KC_X,               KC_C,                          KC_V,              KC_B,               KC_DOWN,            KC_DOT,             KC_RCTL,             LAYER_ENTRY,
  //|------------------+------------------+-------------------+-------------------+-------------------+------------------|            |------------------+-------------------+-------------------+-------------------+-------------------+----------------|
                         KC_NO,             KC_NO,              KC_ENT,             KC_SPC,             KC_BSPC,                       KC_ENT,            KC_SPC,             KC_DEL,             TD(RET_RSTHD),       KC_TRANSPARENT
                     //`-------------------------------------------------------------------------------------------------'            `----------------------------------------------------------------------------------------'
  ),
};

void keyboard_post_init_user(void) {
}

void handle_custom_shifted_key(uint16_t base_keycode, uint16_t shifted_code, keyrecord_t *record) {
    if (record->event.pressed){
      if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
        register_code16(shifted_code);
      } else {
        register_code16(base_keycode);
      }
    } else {
      unregister_code16(shifted_code);
      unregister_code16(base_keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CMQM:
      handle_custom_shifted_key(KC_COMMA, KC_QUES, record);
      return false;
    case KC_DTEX:
      handle_custom_shifted_key(KC_DOT,   KC_EXLM, record);
      return false;
    case KC_L_PACB:
      handle_custom_shifted_key(KC_LPRN,  KC_LCBR, record);
      return false;
    case KC_R_PACB:
      handle_custom_shifted_key(KC_RPRN,  KC_RCBR, record);
      return false;
  }
  return true;
}  

/* 
 * TAP DANCE LOGIC 
 **/ 

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[6];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_up(qk_tap_dance_state_t *state, void *user_data);
void dance_up_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_up_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_left(qk_tap_dance_state_t *state, void *user_data);
void dance_left_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_left_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_down(qk_tap_dance_state_t *state, void *user_data);
void dance_down_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_down_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_right(qk_tap_dance_state_t *state, void *user_data);
void dance_right_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_right_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_nothing(qk_tap_dance_state_t *state, void *user_data);

void dance_return_to_rsthd_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_return_to_rsthd_reset(qk_tap_dance_state_t *state, void *user_data);
 
void dance_capslock_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_capslock_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ARW_UP] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_up, dance_up_finished, dance_up_reset),
    [TD_ARW_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_left, dance_left_finished, dance_left_reset),
    [TD_ARW_DOWN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_down, dance_down_finished, dance_down_reset),
    [TD_ARW_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_right, dance_right_finished, dance_right_reset),
    [RET_RSTHD] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_nothing, dance_return_to_rsthd_finished, dance_return_to_rsthd_reset),
    [CAPS_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_nothing, dance_capslock_finished, dance_capslock_reset)
};

void on_dance_up(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UP);
        tap_code16(KC_UP);
        tap_code16(KC_UP);
    }
    if(state->count > 3) {
        tap_code16(KC_UP);
    }
}

void dance_up_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[TD_ARW_UP].step = dance_step(state);
    switch (dance_state[TD_ARW_UP].step) {
        case SINGLE_TAP: register_code16(KC_UP); break;
        case SINGLE_HOLD: register_code16(LALT(KC_UP)); break;
        case DOUBLE_TAP: register_code16(KC_UP); register_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UP); register_code16(KC_UP);
    }
}

void dance_up_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_ARW_UP].step) {
        case SINGLE_TAP: unregister_code16(KC_UP); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_UP)); break;
        case DOUBLE_TAP: unregister_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UP); break;
    }
    dance_state[TD_ARW_UP].step = 0;
}

void on_dance_left(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[TD_ARW_LEFT].step = dance_step(state);
    switch (dance_state[TD_ARW_LEFT].step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_ARW_LEFT].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state[TD_ARW_LEFT].step = 0;
}

void on_dance_down(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_DOWN);
    }
}

void dance_down_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[TD_ARW_DOWN].step = dance_step(state);
    switch (dance_state[TD_ARW_DOWN].step) {
        case SINGLE_TAP: register_code16(KC_DOWN); break;
        case SINGLE_HOLD: register_code16(LALT(KC_DOWN)); break;
        case DOUBLE_TAP: register_code16(KC_DOWN); register_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOWN); register_code16(KC_DOWN);
    }
}

void dance_down_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_ARW_DOWN].step) {
        case SINGLE_TAP: unregister_code16(KC_DOWN); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_DOWN)); break;
        case DOUBLE_TAP: unregister_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOWN); break;
    }
    dance_state[TD_ARW_DOWN].step = 0;
}

void on_dance_right(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[TD_ARW_RIGHT].step = dance_step(state);
    switch (dance_state[TD_ARW_RIGHT].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_ARW_RIGHT].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state[TD_ARW_RIGHT].step = 0;
}

void on_dance_nothing(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_return_to_rsthd_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[RET_RSTHD].step = dance_step(state);
    switch (dance_state[RET_RSTHD].step) {
        case DOUBLE_HOLD: layer_move(RSTHD); break;
    }
}

void dance_return_to_rsthd_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[RET_RSTHD].step) {
    }
    dance_state[RET_RSTHD].step = 0;
}  

void dance_capslock_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[CAPS_LOCK].step = dance_step(state);
    switch (dance_state[CAPS_LOCK].step) {
        case DOUBLE_HOLD: register_code16(KC_CAPSLOCK); break;
    }
}

void dance_capslock_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[CAPS_LOCK].step) {
        case DOUBLE_HOLD: unregister_code16(KC_CAPSLOCK); break;
    }
    dance_state[CAPS_LOCK].step = 0;
}