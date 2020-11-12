#include QMK_KEYBOARD_H

enum custom_keycodes {
    RALT_COM = SAFE_RANGE,
    RALT_DOT,
    RALT_SLSH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[0] = LAYOUT(  /* Base */
			KC_ESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_DEL,
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			KC_CAPS,       KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSPO,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  TT(2),   KC_N,  KC_M,    RALT_COM,  RALT_DOT, KC_SLSH, KC_RSPC, KC_UP, 
		    KC_LCTL,                 KC_LALT,  LGUI_T(KC_SPC),      KC_LGUI,        LT(1, KC_SPC),      KC_RALT,           KC_LEFT, KC_DOWN,   KC_RIGHT),
		
        [1] = LAYOUT( /* FN */
			RESET,         KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  RESET,   _______,
		    KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR,  KC_SLCK, KC_PAUS, RESET,    KC_HOME,
			KC_TRNS,       RGB_SPI,  RGB_SPD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,  KC_TRNS,          EEP_RST,  KC_END,
		    _______,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU,  KC_TRNS, KC_TRNS, KC_TRNS,
		    KC_TRNS,                 KC_TRNS, KC_TRNS,         KC_TRNS,           KC_TRNS,         KC_TRNS,                    KC_TRNS, KC_TRNS,  KC_TRNS),
		
        [2] = LAYOUT(
			_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
		    KC_LSFT,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, _______,
		    _______,               _______,  KC_SPC,           _______,          _______,          _______,                   _______, _______, _______),
		
        [3] = LAYOUT(
			_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			_______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
		    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		    _______,                _______, _______,          _______,          _______,          _______,                   _______, _______, _______),
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
      return false;
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
      return false;
    case RALT_SLSH:
      if (record->event.pressed) {
          uint8_t altgr = get_mods() & (MOD_BIT(KC_RALT));
          if (altgr) {
              tap_code16(KC_NUBS);
          } else {
              tap_code(KC_SLSH);
          }
      }
      return false;
  }
  return true;
}
