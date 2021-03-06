#include QMK_KEYBOARD_H

#include "../../config.h"

// underglow timeout (from https://gist.github.com/algernon/9182469e21894192017f2bb5d478c7df)
#define UNDERGLOW_TIMEOUT 10 // minutes
static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;

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

	/* Qwerty
	 * ,-----------------------------------------------------------------------------------.
	 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |  LR  |
	 * `-----------------------------------------------------------------------------------'
	 */
	[_QWERTY] = LAYOUT_planck_mit(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		_______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,     KC_SPC,      RAISE, KC_RGUI, KC_RALT, KC_RCTRL,LR
  ),

  /* Lower
  * ,-----------------------------------------------------------------------------------.
  * |      |   `  |   &  |   *  |      |      |      |   7  |   8  |   9  |   -  |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |   $  |   %  |   ^  |   <  |   >  |   4  |   5  |   6  |   +  |   \  |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |   !  |   @  |   #  |      |      |   1  |   2  |   3  |Enter |   =  |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |    Space    |   0  |   0  |   .  |Enter |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT_planck_mit(
  _______, KC_GRV,  KC_AMPR, KC_ASTR, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
  _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_LT,   KC_GT,   KC_4,    KC_5,    KC_6,    KC_PPLS, KC_BSLS,
  _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______, KC_1,    KC_2,    KC_3,    KC_PENT, KC_EQL ,
  _______, _______, _______, _______, _______,      KC_SPC,      KC_0,    KC_0,    KC_DOT,  KC_PENT, _______
  ),

	/* Raise
	* ,-----------------------------------------------------------------------------------.
	* |      |   ~  |      |      |      |   (  |   )  |   /  |  Up  |   *  |   _  |      |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |r_TOG |r_Mode|r_Hue+|r_Hue-|   {  |   }  | Left | Down |Right |      |   |  |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |BL_TOG|BL_STEP|     |      |   [  |   ]  |      |      |      |      |      |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |    Space    |      |      |      |      |      |
	* `-----------------------------------------------------------------------------------'
	*/
  [_RAISE] = LAYOUT_planck_mit(
  _______, KC_TILD, _______, _______, _______, KC_LPRN, KC_RPRN, KC_PSLS, KC_UP,   KC_PAST, KC_UNDS, KC_BSPC,
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PIPE,
  _______, BL_TOGG, BL_STEP, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_ENT ,
  _______, _______, _______, _______, _______,      KC_SPC,      _______, _______, _______, _______, _______
  ),

	/* LR
	* ,-----------------------------------------------------------------------------------.
	* |      |      |      |      |      |      |      |      |  Up  |   P  |   U  |   X  |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* |      |      |      |      |      |      |   G  | Left | Down |Right |      |      |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* |      |      |      |      |      |      |   0  |   1  |   2  |   3  |   4  |   5  |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |      |      |      |      |      |    Space    |      |      |      |      |Qwerty|
	* `-----------------------------------------------------------------------------------'
	*/
	[_LR] = LAYOUT_planck_mit(
		_______, _______, _______, _______, _______, _______, M(0),    M(1),    KC_UP,   KC_P,    KC_U,    KC_X,
		_______, _______, _______, _______, _______, _______, KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, M(2),    M(3),
		_______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
		_______, _______, _______, _______, _______,       KC_SPC,     _______, _______, _______, _______, QWERTY
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
  [_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   _______, _______, _______, _______, RESET,   _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
  )
};


void matrix_init_user(void) {
	rgblight_mode(2);
	rgblight_sethsv(22, 255, 255);
}

void matrix_scan_user(void) {
  // underglow timeout
  if (idle_timer == 0) idle_timer = timer_read();

  if (timer_elapsed(idle_timer) > 30000) {
    // after each half-minute the LED has been on, increment the counter
    halfmin_counter++;
    idle_timer = timer_read();
  }

  if (halfmin_counter >= UNDERGLOW_TIMEOUT * 2) {
    print("turn underglow off\n");
    rgblight_disable();
    halfmin_counter = 0;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // underglow timeout
  idle_timer = timer_read();
  halfmin_counter = 0;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
				rgblight_mode(1);
				rgblight_sethsv(22, 255, 255);
				// rgblight_sethsv_at(0, 0, 255, 0);
				// rgblight_sethsv_at(0, 0, 255, 1);
				// rgblight_sethsv_at(0, 0, 255, 2);
				// rgblight_sethsv_at(22, 255, 255, 3);
				// rgblight_sethsv_at(22, 255, 255, 4);
				// rgblight_sethsv_at(22, 255, 255, 5);
				// rgblight_sethsv_at(22, 255, 255, 6);
				// rgblight_sethsv_at(247, 0, 0, 7);
				// rgblight_sethsv_at(247, 0, 0, 8);
				// rgblight_sethsv_at(247, 0, 0, 9);
				// rgblight_sethsv_at(22, 255, 255, 10);
				// rgblight_sethsv_at(22, 255, 255, 11);
				// rgblight_sethsv_at(22, 255, 255, 12);
				// rgblight_sethsv_at(22, 255, 255, 13);
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
				rgblight_mode(2);
				rgblight_sethsv(206, 60, 220);
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
