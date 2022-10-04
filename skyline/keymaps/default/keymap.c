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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_skyline_3x6_5(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, KC_SLSH,  KC_C,    KC_Y,    KC_F,    KC_K,                           KC_Z,    KC_L,    KC_COMM, KC_SCLN,KC_QUOT,KC_EQUAL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,    KC_R,    KC_S,    KC_T,    KC_H,    KC_D,                         KC_M,    KC_N,   KC_A,    KC_I,   KC_O,   KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_3,    KC_J,    KC_V,    KC_G,    KC_P,    KC_B,                          KC_X,    KC_W,   KC_DOT,  KC_U,    KC_Q,    KC_5,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            KC_5, KC_6,  KC_7,   KC_BSPC,  KC_DEL,     KC_SPC,   KC_ENT, KC_2, KC_3, KC_4
                                      //`--------------------------'  `--------------------------'

  )
};