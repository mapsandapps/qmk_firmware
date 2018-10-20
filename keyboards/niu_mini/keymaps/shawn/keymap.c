#include QMK_KEYBOARD_H

#include "../../config.h"

// readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _BACKLIT,
	_LR
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
	LR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Layer 0
	 * ,-----------------------------------------------------------------------------------.
	 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      | Tab  | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |  LR  |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_QWERTY] = LAYOUT_planck_mit(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		_______, KC_TAB, KC_LALT, KC_LGUI, LOWER,     KC_SPC,      RAISE, KC_RGUI, KC_RALT, KC_RCTRL,LR
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
  [_LOWER] = LAYOUT_planck_mit(
  _______, KC_GRV,  KC_AMPR, KC_ASTR, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
  _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_BSLS,
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, KC_EQL ,
  _______, _______, _______, _______, _______,    KC_SPC,        KC_0,    KC_0,    KC_DOT,  KC_PENT, _______
  ),

	/* Raise
	* ,-----------------------------------------------------------------------------------.
	* |      |   ~  |      |      |      |   (  |   )  |   /  |  Up  |   *  |   _  |      |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |r_TOG |r_Mode|r_Hue+|r_Hue-|   {  |   }  | Left | Down |Right |      |   |  |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |BL_TOG|BL_STEP|     |      |   [  |   ]  |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |      |      |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
  [_RAISE] = LAYOUT_planck_mit(
  _______, KC_TILD, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSLS, KC_UP,   KC_PAST, KC_UNDS, KC_BSPC,
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
  _______, BL_TOGG, BL_STEP, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_ENT ,
  _______, _______, _______, _______, _______,    KC_SPC,        _______, _______, _______, _______, _______
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
   * |      |      |      |      |      |AGnorm|AGswap|Qwerty|      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    _______, RESET,   _______, _______, _______, _______, RESET,   _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
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
        set_single_persistent_default_layer(_LR);
      }
      return false;
      break;
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
