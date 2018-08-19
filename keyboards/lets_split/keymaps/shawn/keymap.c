#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _LR 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  LR,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl |  Alt |  GUI |Lower |Space |Space |Raise |  GUI |  Alt |Adjust|  LR  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTRL,KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, ADJUST,  LR       \
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
[_LOWER] = KEYMAP( \
  _______, KC_GRV,  KC_AMPR, KC_ASTR, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______, \
  _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_BSLS, \
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, KC_EQL , \
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_PENT, _______  \
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
[_RAISE] = KEYMAP( \
  _______, KC_TILD, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSLS, KC_UP,   KC_PAST, KC_UNDS, KC_BSPC, \
  _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE, \
  _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_ENT , \
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______  \
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
[_LR] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, M(0),    M(1),    KC_UP,   KC_P,    KC_U,    KC_X,    \
  _______, _______, _______, _______, _______, _______, KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, M(2),    M(3),    \
  _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    \
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, QWERTY   \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |      |      |      |      |Reset |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch(id) {
      case 0:
        return MACRO( D(LGUI), T(Z), U(LGUI), END );
      case 1:
        return MACRO( D(LGUI), D(LSFT), T(Z), U(LSFT), U(LGUI), END );
      case 2:
        return MACRO( D(LGUI), T(A), U(LGUI), END );
      case 3:
        return MACRO( D(LGUI), T(D), U(LGUI), END );
    }
  }
  return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
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
    case LR:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_LR);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
