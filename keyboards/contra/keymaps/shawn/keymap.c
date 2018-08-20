/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _LR,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  LR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Tab  | Alt  | GUI  |Lower |Space |Space |Raise | GUI  | Alt  | Ctrl |  LR  |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_ESC,  KC_TAB, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTRL,LR
  ),

  /* Colemak
   * ,-----------------------------------------------------------------------------------.
   * | `    |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  | Tab  | Alt  | GUI  |Lower |Space |Space |Raise | Left |Right |  Up  |Down  |
   * `-----------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_ESC,  KC_TAB, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |      |   `  |   &  |   *  |      |      |      |   7  |   8  |   9  |   -  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |   $  |   %  |   ^  |   <  |   >  |   4  |   5  |   6  |   +  |   \  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |   !  |   @  |   #  |      |      |   1  |   2  |   3  |Enter |   =  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |   0  |   0  |   .  |Enter |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_ortho_4x12(
  _______, KC_GRV,  KC_AMPR, KC_ASTR, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
  _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_BSLS,
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, KC_EQL ,
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_PENT, _______
  ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   ~  |      |      |      |   (  |   )  |   /  |  Up  |   *  |   _  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |   {  |   }  | Left | Down |Right |      |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   [  |   ]  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_4x12(
  _______, KC_TILD, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSLS, KC_UP,   KC_PAST, KC_UNDS, KC_BSPC,
  _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_ENT ,
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
  ),

/* LR
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |   P  |   U  |   X  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   G  | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Qwerty|
 * `-----------------------------------------------------------------------------------'
 */
[_LR] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, M(0),    M(1),    KC_UP,   KC_P,    KC_U,    KC_X,
  _______, _______, _______, _______, _______, _______, KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, M(2),    M(3),
  _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, QWERTY
),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      |Reset |      |      |      |      |Reset |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |AGnorm|AGswap|Qwerty|Colemk|      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    _______, RESET,   _______, _______, _______, _______, RESET,   _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
