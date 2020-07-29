#include "planck.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Alt | GUI  |Lower |    Space    |Raise |  GUI |  Alt | Ctrl |Shift |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT ,
  _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTRL, KC_RSFT
),

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
[_LOWER] = LAYOUT_planck_grid(
  KC_GRV,  _______, KC_AMPR, KC_ASTR, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_BSPC,
  KC_ESC,  _______, KC_DLR,  KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PPLS,  KC_BSLS,
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT,  KC_EQL ,
  BL_STEP, _______, _______, _______, _______, KC_SPC,  KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_PENT,  _______
),

/* Raise/Blue
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |   (  |   )  |   /  |  Up  |   *  |   _  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |   {  |   }  | Left | Down |Right |      |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   [  |   ]  |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      |      |VolDn |VolUp | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_TILD, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSLS, KC_UP,   KC_PAST,     KC_UNDS,   KC_BSPC,
  KC_ESC,  _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT,     _______,   KC_PIPE,
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,     _______,   KC_ENT ,
  RESET,   _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, KC__VOLDOWN, KC__VOLUP, KC__MUTE
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
