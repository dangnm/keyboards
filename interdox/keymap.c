#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum redox_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum redox_keycodes {
    EPRM = SAFE_RANGE,
};

// clang-format off
#define LWR_PGU LT(_LOWER, KC_PGUP) // Turn on _LOWER layer when held, PgUp when tapped
#define RSE_END LT(_RAISE, KC_END)  // Turn on _RAISE layer when held, End when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN) // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)      // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)        // Left Control when held, z when tapped
#define CTL_SCL LCTL_T(KC_SCLN)     // Left Control when held, ; when tapped
#define CTL_SLS RCTL_T(KC_SLSH)     // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)     // Right Gui when held, ' when tapped
#define CAG_QUO LCAG_T(KC_QUOT)     // Ctrl+Alt+Gui when held, ' when tapped
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,                           KC_ESC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    LWR_PGU, KC_PGDN,        KC_HOME, RSE_END, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
        KC_GRV,  CAG_QUO, KC_LBRC, KC_RBRC,     KC_LGUI,      KC_SPC,  KC_BSPC,        KC_TAB,  KC_ENT,      KC_RALT,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_LOWER] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        _______, _______, KC_LEFT, KC_RGHT, KC_UP,   _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_DOWN, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        _______, _______, KC_LEFT, KC_RGHT, KC_UP,   _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_DOWN, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______,                                            _______, _______, _______, _______, _______, EPRM,
        AG_NORM, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, AG_SWAP,
        _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______,                                            _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, AG_NORM,                          AG_SWAP, _______, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______,
        _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_F14,                           KC_F15,  KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______,
        EPRM,    _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      KC_VOLU, KC_VOLD, _______, _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     *
     * [_SAMPLE] = LAYOUT(
     *     _______, _______, _______, _______, _______, _______,                                            _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______,     _______,      _______, _______,        _______, _______,     _______,      _______, _______, _______, _______
     * ),
     */
};
// clang-format on

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            set_led_off;
            break;
        case _MOUSE:
            set_led_green;
        default:
            break;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
    }
    return true;
}
