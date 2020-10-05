#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum redox_layers {
    _LAYOUT0,
    _LAYOUT1,
    _LAYOUT2,
    _LAYOUT3,
};

#define LA1_GRV LT(_LAYOUT1, KC_GRV)     // Turn on _LAYOUT1 layer when held, ` when tapped
#define LA2_SCL LT(_LAYOUT2, KC_SCLN)     // Turn on _LAYOUT2 layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_SCL LCTL_T(KC_SCLN)         // Left Control when held, ; when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, ' when tapped
#define CAG_QUO LCAG_T(KC_QUOT)         // Ctrl+Alt+Gui when held, ' when tapped
#define HYP_LBR ALL_T(KC_LBRC)          // Hyper when held, [ when tapped
#define MEH_RBR MEH_T(KC_RBRC)          // Meh when held, ] when tapped
#define LAYOU1  LT(_LAYOUT1,KC_NO)
#define LAYOU2  LT(_LAYOUT2,KC_NO)
#define MEH_NO  MEH_T(KC_NO)
#define TOGGL0  TO(_LAYOUT0)
#define TOGGL1  TO(_LAYOUT1)
#define TOGGL2  TO(_LAYOUT2)
#define TOGGL3  TO(_LAYOUT3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                                           │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │   =    │                         │  TO(2) │   Y    │   U    │   I    │   O    │   P    │   =    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │Hyper/ [│                         │Meh / ] │   H    │   J    │   K    │   L    │ ; / LA2│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │  LALT  │  Home  │       │  Home  │  Esc   │   N    │   M    │   ,    │   .    │ / / CTL│ Shift  │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │ L1 / ` │  CTL   │  ALT   │  MEH   │    │  GUI   │   │ Space  │ BkSpace│       │  Tab   │  Enter │   │  L1    │    │  GUI   │   [    │   ]    │  GUI   │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_LAYOUT0] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL,                           TOGGL2,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    HYP_LBR,                          MEH_RBR,   KC_H,    KC_J,    KC_K,    KC_L,    LA2_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_HOME,        KC_PGUP, KC_PGDN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
        LA1_GRV, KC_LCTL, KC_LALT, MEH_NO,      KC_LGUI,      KC_SPC,  KC_BSPC,        KC_TAB,  KC_ENT,      LAYOU1,         KC_RGUI, KC_LBRC, KC_RBRC, KC_RGUI
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  F12   │   F1   │   F2   │   F3   │   F4   │   F5   │                                           │   F6   │   F7   │   F8   │   F9   │  F10   │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │   !    │   @    │   {    │   }    │   |    │  Vol+  │                         │  TO(2) │   /    │ WH_Up  │   8    │ WH_Down│   *    │  F12   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │CAPSLOCK│   #    │   $    │   [    │   ]    │   `    │  Vol-  │                         │        │ Left   │  Down  │   Up   │ Right  │   +    │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │   %    │   ^    │   (    │   )    │   ~    │        │        │       │        │        │        │   1    │   2    │   3    │   \    │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │ LClick │        │       │        │ RClick │   │  L1    │    │   0    │        │        │  TO(2) │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_LAYOUT1] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_VOLU,                          TOGGL2,  KC_SLSH, KC_AMPR, KC_8,    KC_LPRN, KC_PAST, KC_F12,
        KC_CAPS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_VOLD,                          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS, KC_MFFD,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_MSTP, _______,        _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_MRWD,
        _______, _______, _______, _______,     _______,      KC_BTN1, _______,        _______, KC_BTN2,    LAYOU1,        KC_0,    KC_DOT,  _______, TOGGL2
    ),


    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │  TO(0) │  TO(1) │  TO(2) │  TO(3) │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │  7     │  8     │   9    │        │        │                         │  TO(2) │        │        │MouseUp │        │WheelUp │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │ Mouse1 │  4     │  5     │   6    │Mouse2  │        │                         │        │        │  M_L   │MDown   │  M_R   │WheelD  │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │  1     │  2     │   3    │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │  0     │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_LAYOUT2] = LAYOUT(
        _______, TOGGL0,  TOGGL1,  TOGGL2,  TOGGL3, _______,                                            _______, _______, _______, _______, _______, _______,
        _______, _______, KC_7,    KC_8,    KC_9,   _______, _______,                          TOGGL2,  _______, _______, KC_MS_U, _______, KC_WH_U, _______,
        _______, KC_BTN1, KC_4,    KC_5,    KC_6,   KC_BTN2, _______,                          _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
        _______, _______, KC_1,    KC_2,    KC_3,   _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_0,    _______,     _______,     KC_BTN1, _______,        _______, KC_BTN2,     _______,      _______, _______, _______, _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                                           │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │  TO(2) │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │                         │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │       │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │    │        │   │        │        │       │        │        │   │        │    │        │        │        │        │
     * └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
     */
    [_LAYOUT3] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                               _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL,                           TOGGL2,  KC_Y,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    HYP_LBR,                          KC_M,    KC_H,    KC_P4,   KC_P5,   KC_P6,   _______, _______,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_HOME,        KC_PGUP, KC_PGDN, KC_N,    KC_P1,   KC_P2,   KC_P3,   _______, _______,
        LA1_GRV, KC_LCTL, KC_LALT, MEH_NO,      KC_LGUI,      KC_SPC,  KC_BSPC,        KC_TAB,  KC_ENT,      _______,      KC_P0,   KC_PDOT, KC_PENT, _______
    ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LAYOUT0:
            set_led_off;
            break;
        case _LAYOUT1:
            set_led_red;
            break;
        case _LAYOUT2:
            set_led_green;
        case _LAYOUT3:
            set_led_green;
        default:
            break;
    }
    return state;
}
