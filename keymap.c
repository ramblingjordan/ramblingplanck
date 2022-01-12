#include QMK_KEYBOARD_H

#ifndef __INTELLISENSE__
#    include "muse.h"
#endif

enum planck_layers {
    _BASE, _LOWER, _RAISE, _ACCENT, _ADJUST
};

enum planck_keycodes {
    BASE = SAFE_RANGE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ACCENT MO(_ACCENT)
#define LWR_ENT KC_ENT// LT(_LOWER, KC_ENT)
//#define RSE_BSP //KC_BSPC // LT(_RAISE, KC_BSPC)
#define SFT_LFT SFT_T(KC_LEFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    [_BASE] = LAYOUT_planck_grid(
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER, RAISE  , KC_SPC , KC_SPC , SFT_LFT, KC_DOWN, KC_UP  , KC_RGHT
    ),

    [_RAISE] = LAYOUT_planck_grid(
        _______, KC_BSLS, KC_PERC, KC_AT  , KC_ASTR, KC_LBRC, KC_RBRC, KC_PGUP, KC_UP  , KC_PGDN, KC_DEL , _______,
        _______, KC_EXLM, KC_AMPR, KC_MINS, KC_SLSH, KC_LPRN, KC_RPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, KC_PIPE,
        ACCENT , KC_TILD, KC_GRV , KC_EQL , KC_PLUS, KC_DLR , KC_HOME, KC_END , KC_INS , KC_PSCR, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ACCENT] = LAYOUT_planck_grid(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, KC_CIRC, KC_HASH, KC_UNDS, KC_QUES, KC_LCBR, KC_RCBR, _______, _______, _______, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_LOWER] = LAYOUT_planck_grid(
        _______, _______, KC_PERC, _______, KC_ASTR, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , _______, _______,
        _______, _______, _______, _______, _______, _______, KC_SPC , KC_SPC , KC_P0  , KC_PDOT, _______, _______
    ),

    [_ADJUST] = LAYOUT_planck_grid(
        _______, RESET  , DEBUG  , RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

    // clang-format on
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//     switch (keycode) {}
//     return true;
// }
