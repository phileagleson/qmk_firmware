#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2

#define RAISE TT(_RAISE)
#define LOWER TT(_LOWER)

// Left-hand home row mods mac
#define CTL_A LCTL_T(KC_A)
#define OPT_R LOPT_T(KC_R)
#define CUS_S LGUI_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Right-hand home row mods mac
#define SFT_N RSFT_T(KC_N)
#define CUS_E RGUI_T(KC_E)
#define OPT_I LOPT_T(KC_I)
#define CTL_O RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_5x6(
      KC_GRV,                KC_1,   KC_2,    KC_3,   KC_4,  KC_5,        KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_EQL,
      KC_TAB,                KC_Q,   KC_W,    KC_F,   KC_P,  KC_B,        KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_MINUS,
      MT(MOD_RSFT,KC_ESC),  CTL_A,   OPT_R,  CUS_S,  SHFT_T,  KC_G,        KC_M,   SFT_N,   CUS_E,   OPT_I,   CTL_O,    KC_QUOT,
      _______,               KC_Z,    KC_X,   KC_C,   KC_D,  KC_V,        KC_K  , KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BSLS,
                                   KC_LBRC,   KC_RBRC,                                     KC_LPRN, KC_RPRN,
                                                     LOWER,   KC_SPC,     KC_ENT, RAISE,
                                                     KC_HYPR, KC_BSPC,     KC_DEL,  KC_HYPR,
                                                     _______, _______,    KC_CAPS, _______
    ),

    [_LOWER] = LAYOUT_5x6(
        _______,_______,_______,_______,_______ ,_______,                    _______,_______,KC_KP_SLASH,KC_PAST,KC_KP_MINUS,_______,
        _______,_______,_______,_______,_______,_______,                     KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS,_______,
        _______,_______,_______,_______,_______,_______,                     KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_PENT,_______,
        _______,KC_CUT,KC_COPY,KC_PASTE,_______,_______,                     _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                                _______,_______,                              KC_P0,KC_DOT,
                                                _______,_______,                  _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),

    [_RAISE] = LAYOUT_5x6(
          KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
          _______,_______,_______,KC_UP,_______,_______,                        KC_RBRC,_______,KC_UP,KC_INS ,KC_SCRL,KC_MUTE,
          _______,_______,KC_LEFT,KC_DOWN  ,KC_RIGHT,_______,                   KC_RPRN,KC_LEFT,KC_DOWN,KC_RIGHT,_______,KC_VOLU,
          _______,KC_CUT,KC_COPY,KC_PASTE,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                                  _______,_______,            KC_EQL ,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),
};
