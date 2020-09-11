/* Copyright 2018 'mechmerlin'
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

#define _BL 0
#define _MBL 1
#define _FL 2

enum custom_keycodes {
    RALT_COM = SAFE_RANGE,
    RALT_DOT,
    RALT_SLSH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |  Clck |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
  [_BL] = LAYOUT_iso(
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_ESC, \
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_DEL, \
    KC_CLCK, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,  KC_ENT,  KC_PGUP,\
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   RALT_COM, RALT_DOT,  RALT_SLSH, KC_RSFT, KC_UP,            KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(_FL),    TT(_MBL), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Keymap (Mac compatiable Base Layer): Default layer 
    * ,----------------------------------------------------------------.
    * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
    * |----------------------------------------------------------------|
    * |Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
    * |----------------------------------------------------------------|
    * |  Clck |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
    * |----------------------------------------------------------------|
    * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
    * |----------------------------------------------------------------|
    * |Ctrl| Opt | Cmd |      Space       | Fn | Opt |Ctrl|Lef|Dow|Rig |
    * `----------------------------------------------------------------'
    */
  [_MBL] = LAYOUT_iso(
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_ESC, \
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_DEL, \
    KC_CLCK, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,  KC_ENT,  KC_PGUP,\
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   RALT_COM, RALT_DOT,  RALT_SLSH, KC_RSFT, KC_UP,            KC_PGDN, \
    KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                          MO(_FL), KC_RALT, _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Keymap _FL1: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  RESET|PSCR|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   | INS|
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   | PP|PLA| PN|    |   |HOME|
   * |----------------------------------------------------------------|
   * |    |   |   |   |   |   |   |   |   |  V-| MV| V+|     |   | END|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
  [_FL] = LAYOUT_iso(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,   KC_PSCR, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, _______,          KC_INS,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_HOME, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,          KC_END,  \
    _______, _______, _______,                   _______,                            TG(_BL), _______, _______, _______, _______, _______
  ),
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case RALT_COM:
      if (record->event.pressed) {
          uint8_t altgr = get_mods() & (MOD_BIT(KC_RALT));
          if (altgr) {
              uint8_t mods = get_mods();
              clear_mods();
              tap_code16(KC_NUBS);
              set_mods(mods);
          } else {
              tap_code(KC_COMM);
          }
      }
      return false; break;
    case RALT_DOT:
      if (record->event.pressed) {
          uint8_t altgr = get_mods() & (MOD_BIT(KC_RALT));
          if (altgr) {
              uint8_t mods = get_mods();
              clear_mods();
              tap_code16(S(KC_NUBS));
              set_mods(mods);
          } else {
              tap_code(KC_DOT);
          }
      }
      return false; break;
    case RALT_SLSH:
      if (record->event.pressed) {
          uint8_t altgr = get_mods() & (MOD_BIT(KC_RALT));
          if (altgr) {
              tap_code16(KC_NUBS);
          } else {
              tap_code(KC_SLSH);
          }
      }
      return false; break;
  }
  return true;
}