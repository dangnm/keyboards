#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif
#ifdef SSD1306OLED
    #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;
extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum crkbd_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum crkbd_keycodes {
    QWERTY = SAFE_RANGE,
    EPRM,
    RGB_RESET,
};

#define KC______     KC_TRNS
#define KC_XXXXX     KC_NO
#define KC_LOWER     MO(_LOWER)
#define KC_RAISE     MO(_RAISE)
#define KC_RESET     RESET
#define KC_EPRM      EPRM
#define KC_RGB_RESET RGB_RESET
#define KC_RGB_TOG   RGB_TOG
#define KC_RGB_HUI   RGB_HUI
#define KC_RGB_HUD   RGB_HUD
#define KC_RGB_SAI   RGB_SAI
#define KC_RGB_SAD   RGB_SAD
#define KC_RGB_VAI   RGB_VAI
#define KC_RGB_VAD   RGB_VAD
#define KC_RGB_MOD   RGB_MOD
#define KC_RGB_RMO   RGB_RMOD
#define KC_AG_NORM   AG_NORM
#define KC_AG_SWAP   AG_SWAP
#define KC_CTL_ESC   CTL_T(KC_ESC)
#define KC_CTL_GRV   CTL_T(KC_GRV)
#define KC_CTL_Z     CTL_T(KC_Z)
#define KC_CTL_SLS   CTL_T(KC_SLSH)
#define KC_GUI_QUO   GUI_T(KC_QUOT)
#define KC_GUI_HOM   GUI_T(KC_HOME)
#define KC_ALT_END   ALT_T(KC_END)
#define KC_GUI_F11   GUI_T(KC_F11)
#define KC_SFT_F12   SFT_T(KC_F12)
#define KC_MOU_SCL   LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define KC_SAV_PIC   LSFT(LGUI(KC_4))        // Shift+Command+4: Save picture of selected area to the clipboard (macOS only)
#define KC_COP_PIC   LCTL(LSFT(LGUI(KC_4)))  // Ctrl+Shift+Command+4: Copy picture of selected area to the clipboard (macOS only)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │                         │   Y    │   U    │   I    │   O    │   P    │BckSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Esc   │   A    │   S    │   D    │   F    │   G    │                         │   H    │   J    │   K    │   L    │   ;    │   '    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │   Z    │   X    │   C    │   V    │   B    │                         │   N    │   M    │   ,    │   .    │   \    │ Shift  │
     * └────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
     *                                     │  Gui   │ LOWER  │  Space │       │ Enter  │  RAISE │  Alt   │
     *                                     └────────┴────────┴────────┘       └────────┴────────┴────────┘
     */
    [_QWERTY] = LAYOUT_kc( \
        TAB,     Q,       W,       E,       R,       T,                                 Y,       U,       I,       O,       P,        BSPC,    \
        CTL_ESC, A,       S,       D,       F,       G,                                 H,       J,       K,       L,       MOU_SCL,  GUI_QUO, \
        LSFT,    CTL_Z,   X,       C,       V,       B,                                 N,       M,       COMM,    DOT,     CTL_SLS,  RSFT,    \
                                            GUI_HOM, LOWER,   SPC,             ENT,     RAISE,   ALT_END                                       \
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                         │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   `    │   F1   │   F2   │   F3   │   F4   │   F5   │                         │   F6   │   F7   │   F8   │   F9   │   F10  │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │                         │        │        │        │        │        │  F12   │
     * └────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
     *                                     │        │        │        │       │        │        │        │
     *                                     └────────┴────────┴────────┘       └────────┴────────┴────────┘
     */
    [_LOWER] = LAYOUT_kc( \
        EQL,     1,       2,       3,       4,       5,                                 6,       7,       8,       9,       0,        MINS,    \
        CTL_GRV, F1,      F2,      F3,      F4,      F5,                                F6,      F7,      F8,      F9,      F10,      GUI_F11, \
        _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                             XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,    SFT_F12, \
                                            _____,   _____,   _____,           _____,   _____,   _____                                         \
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │   !    │   @    │   #    │   $    │   %    │                         │   ^    │   &    │   *    │   (    │   )    │  Del   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │CopyPic │  Left  │ Right  │   Up   │  PgUp  │                         │   -    │   =    │   {    │   }    │   |    │   `    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │SavePic │        │        │  Down  │  PgDn  │                         │   _    │   +    │   [    │   ]    │   \    │   ~    │
     * └────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
     *                                     │        │        │        │       │        │        │        │
     *                                     └────────┴────────┴────────┘       └────────┴────────┴────────┘
     */
    [_RAISE] = LAYOUT_kc( \
        _____,   EXLM,    AT,      HASH,    DLR,     PERC,                              CIRC,    AMPR,    ASTR,    LPRN,    RPRN,     _____, \
        _____,   COP_PIC, LEFT,    RGHT,    UP,      PGUP,                              MINS,    EQL,     LCBR,    RCBR,    PIPE,     GRV,   \
        _____,   SAV_PIC, XXXXX,   XXXXX,   DOWN,    PGDN,                              UNDS,    PLUS,    LBRC,    RBRC,    BSLS,     TILD,  \
                                            _____,   _____,   _____,           _____,   _____,   _____                                       \
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │ RESET  │        │        │        │AG NORM │  HUE-  │                         │  HUE+  │AG SWAP │        │        │        │RGB RST │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │CAPSLOCK│        │        │        │RGB RMOD│  SAT-  │                         │  SAT+  │RGB MOD │        │        │        │RGB TOG │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │  VAL-  │                         │  VAL+  │        │        │        │        │  EPRM  │
     * └────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
     *                                     │        │        │        │       │        │        │        │
     *                                     └────────┴────────┴────────┘       └────────┴────────┴────────┘
     */
    [_ADJUST] = LAYOUT_kc( \
        RESET,   XXXXX,   XXXXX,   XXXXX,   AG_NORM, RGB_HUD,                           RGB_HUI, AG_SWAP, XXXXX,    XXXXX,  XXXXX,   RGB_RESET, \
        CAPS,    XXXXX,   XXXXX,   XXXXX,   RGB_RMO, RGB_SAD,                           RGB_SAI, RGB_MOD, XXXXX,    XXXXX,  XXXXX,   RGB_TOG,   \
        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   RGB_VAD,                           RGB_VAI, XXXXX,   XXXXX,    XXXXX,  XXXXX,   EPRM,      \
                                            _____,   _____,   _____,           _____,   _____,   _____                                          \
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │ MClick │  MS_U  │ RClick │        │                         │        │ RClick │  WH_U  │ MClick │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │ LClick │  MS_L  │  MS_D  │  MS_R  │ LClick │                         │ LClick │  WH_L  │  WH_D  │  WH_R  │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │                         │        │        │        │        │        │        │
     * └────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
     *                                     │        │        │        │       │        │        │        │
     *                                     └────────┴────────┴────────┘       └────────┴────────┴────────┘
     */
    [_MOUSE] = LAYOUT_kc( \
        XXXXX,   XXXXX,   BTN3,    MS_U,    BTN2,    XXXXX,                             XXXXX,   BTN2,    WH_U,    BTN3,    XXXXX,    XXXXX, \
        XXXXX,   BTN1,    MS_L,    MS_D,    MS_R,    BTN1,                              BTN1,    WH_L,    WH_D,    WH_R,    _____,    XXXXX, \
        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                             XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,    XXXXX, \
                                            _____,   _____,   _____,           _____,   _____,   _____                                       \
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                         │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │                         │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │                         │        │        │        │        │        │        │
     * └────────┴────────┴────────┴────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘
     *                                     │        │        │        │       │        │        │        │
     *                                     └────────┴────────┴────────┘       └────────┴────────┴────────┘
     */
};

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// Copy from https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/keymaps/edvorakjp/oled.c
const char *read_layer_state(void) {
    static char layer_state_str[24];
    char layer_name[17];

    switch (biton32(layer_state)) {
    case _QWERTY:
        strcpy(layer_name, "Default");
        break;
    case _LOWER:
        strcpy(layer_name, "Lower");
        break;
    case _RAISE:
        strcpy(layer_name, "Raise");
        break;
    case _ADJUST:
        strcpy(layer_name, "Adjust");
        break;
    case _MOUSE:
        strcpy(layer_name, "Mouse");
        break;
    default:
        snprintf(layer_name, sizeof(layer_name), "Undef-%ld", layer_state);
    }

    strcpy(layer_state_str, "Layer: ");

    strcat(layer_state_str, layer_name);
    strcat(layer_state_str, "\n");
    return layer_state_str;
}

// Copy from https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/keymaps/edvorakjp/oled.c
const char *read_mode_icon(bool windows_mode) {
    static const char logo[][2][3] = {{{0x95, 0x96, 0}, {0xb5, 0xb6, 0}}, {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}}};
    static char mode_icon[10];

    int mode_number = windows_mode ? 1 : 0;
    strcpy(mode_icon, logo[mode_number][0]);

    strcat(mode_icon, "\n");
    strcat(mode_icon, logo[mode_number][1]);

    return mode_icon;
}

// Copy from https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/keymaps/edvorakjp/oled.c
const char *read_host_led_state(void) {
    static char led_str[24];
    // strcpy(led_str, (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NMLK" : "    ");
    // strcat(led_str, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? " CAPS" : "    ");
    // strcat(led_str, (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? " SCLK" : "     ");
    strcpy(led_str, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPSLOCK" : "");
    return led_str;
}

void matrix_init_user(void) {
    iota_gfx_init(!has_usb());   // turns on the display
}

void matrix_scan_user(void) {
    iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
        // If you want to change the display of OLED, you need to change here
        // matrix_write_ln(matrix, read_layer_state());
        // matrix_write_ln(matrix, read_keylog());
        // matrix_write_ln(matrix, read_keylogs());
        // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
        // matrix_write_ln(matrix, read_host_led_state());
        // matrix_write_ln(matrix, read_timelog());
        // OLED Display:
        //   - Mode Icon > Layer
        //   - CAPSLOCK
        matrix_write(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
        matrix_write(matrix, " ");
        matrix_write_ln(matrix, read_layer_state());
        matrix_write(matrix, "   ");
        matrix_write(matrix, read_host_led_state());
    } else {
        matrix_write(matrix, read_logo());
    }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
}
#endif // SSD1306OLED

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (record->event.pressed) {
    //     #ifdef SSD1306OLED
    //         set_keylog(keycode, record);
    //     #endif
    //     // set_timelog();
    // }

    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case RGB_RESET:
        #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
        #endif
        return false;
        break;
    case EPRM:
        if (record->event.pressed) {
            eeconfig_init();
        }
        return false;
        break;
    }
    return true;
}
