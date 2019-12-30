#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Alt | GUI  |Lower |    Space    |Raise |  GUI |VolDn |VolUp | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {_______, KC_LCTL, KC_LALT, KC_LGUI, M(1),    KC_SPC,  KC_SPC,   M(2),   KC_RGUI, KC__VOLDOWN, KC__VOLUP, KC__MUTE}
},

/* Lower/Orange
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |   &  |   *  |      |      |      |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |   $  |   %  |   ^  |   <  |   >  |   4  |   5  |   6  |   +  |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   !  |   @  |   #  |      |      |   1  |   2  |   3  |Enter |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Brite |      |      |      |      |    Space    |   0  |   0  |   .  |Enter |      |
 * `-----------------------------------------------------------------------------------'
 */
[1] = {
  {KC_GRV,  _______, KC_AMPR, KC_ASTR, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_BSPC},
  {KC_ESC,  _______, KC_DLR,  KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_BSLS},
  {_______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, KC_EQL },
  {BL_STEP,   _______, _______, _______, _______, KC_SPC,  KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_PENT, _______}
},

/* Raise/Blue
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |   (  |   )  |   /  |  Up  |   *  |   _  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |   {  |   }  | Left | Down |Right |      |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   [  |   ]  |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = {
  {KC_TILD, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSLS, KC_UP,   KC_PAST, KC_UNDS, KC_BSPC},
  {KC_ESC,  _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE},
  {_______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_ENT },
  {RESET,   _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______}
},


};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};
