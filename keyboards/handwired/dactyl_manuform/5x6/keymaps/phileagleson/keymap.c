#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _WINDOWS 1
#define _LOWER 2
#define _RAISE 3

#define RAISE TT(_RAISE)
#define LOWER TT(_LOWER)
#define WINDOWS TT(_WINDOWS)

// Left-hand home row mods mac
#define CTL_A LCTL_T(KC_A)
#define OPT_O LOPT_T(KC_O)
#define CUS_E LGUI_T(KC_E)
#define SFT_U LSFT_T(KC_U)

// Right-hand home row mods mac
#define SFT_H RSFT_T(KC_H)
#define CUS_T RGUI_T(KC_T)
#define OPT_N LOPT_T(KC_N)
#define CTL_S RCTL_T(KC_S)
// Left-hand home row mods windows
#define HOME_A LGUI_T(KC_A)
#define HOME_O LALT_T(KC_O)
#define HOME_E LCTL_T(KC_E)
#define HOME_U LSFT_T(KC_U)

// Right-hand home row mods windows
#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

enum {
  TD_ESC_CAPS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_5x6(
      KC_LBRC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,                      KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_SLASH, 
      TD(TD_ESC_CAPS),  CTL_A,   OPT_O,   CUS_E,   SFT_U, KC_I,                      KC_D,   SFT_H,   CUS_T,   OPT_N,   CTL_S,   KC_MINUS,
      KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                    KC_B  , KC_M,    KC_W,    KC_V,    KC_Z,    KC_BSLASH,
                        KC_LBRC,   KC_RBRC,                                                  KC_LPRN, KC_RPRN,
                                         LOWER, KC_SPC,                         KC_ENT, RAISE, 
                                             KC_HYPR, KC_BSPC,             KC_DEL,  KC_HYPR,
                                             KC_TAB, KC_GRV,             WINDOWS,   KC_EQL
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
          _______,_______,_______,KC_UP,_______,_______,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
          _______,_______,KC_LEFT,KC_DOWN  ,KC_RIGHT,_______,                   KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
          _______,KC_CUT,KC_COPY,KC_PASTE,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                                  _______,_______,            KC_EQL ,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),
    [_WINDOWS] = LAYOUT_5x6(
      KC_LBRC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,                      KC_F,   KC_G,    KC_C,    KC_R,    KC_L,  KC_SLASH, 
      TD(TD_ESC_CAPS),  HOME_A,   HOME_O,   HOME_E,   HOME_U, KC_I,                      KC_D,   HOME_H, HOME_T, HOME_N, HOME_S, KC_MINUS,
      KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                    KC_B  , KC_M,    KC_W,    KC_V,    KC_Z,  KC_BSLASH,
                        KC_LBRC,   KC_RBRC,                                                  KC_LPRN, KC_RPRN,
                                         LOWER, KC_SPC,                         KC_ENT, RAISE, 
                                             KC_HYPR, KC_BSPC,             KC_HYPR,  KC_DEL,
                                             KC_TAB, KC_GRV,               _______,  KC_EQL
    ),
};
