// Copyright 2022 ElsassKabel (@LucasCtrl)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer { BASE, GAME, NAV, MOUSE, MEDIA, NUM, SYM, FN };

// Defines custom keycodes
enum custom_keycodes {
    KC_BASE = SAFE_RANGE,
    KC_GAME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT(
/*
 * ,---------------------------------------.     ,---------------------------------------.
 * |   Q   |   W   |   E   |   R   |   T   |     |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |     |   H   |   J   |   K   |   L   |   '   |
 * |-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |     |   N   |   M   |   ,   |   .   |   /   |
 * `---------------+-------+-------+-------|     |-------+-------+-------+---------------'
 *                 |  Esc  |  Spc  |  Tab  |     | Enter |  Del  | Suppr |
 *                 `-----------------------'     `-----------------------'
 */
    // KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   ,
    // KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
    // KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    //                   KC_ESC,  KC_SPC,  KC_TAB,      KC_ENT,  KC_BSPC, KC_DEL

/*
 * ,---------------------------------------.     ,---------------------------------------.
 * |   Q   |   W   |   E   |   R   |   T   |     |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |     |   H   |   J   |   K   |   L   |   '   |
 * |-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |     |   N   |   M   |   ,   |   .   |   /   |
 * `---------------+-------+-------+-------|     |-------+-------+-------+---------------'
 *                 |  Esc  |  Spc  |  Tab  |     | Enter |  Del  | Suppr |
 *                 `-----------------------'     `-----------------------'
 */
    KC_Q,               KC_W,               KC_F,               KC_P,               KC_B,                       KC_J,               KC_L,               KC_U,               KC_Y,               KC_QUOT,
    GUI_T(KC_A),        ALT_T(KC_R),        CTL_T(KC_S),        SFT_T(KC_T),        KC_G,                       KC_M,               SFT_T(KC_N),        CTL_T(KC_E),        ALT_T(KC_I),        GUI_T(KC_O),
    KC_Z,               KC_X,               KC_C,               KC_D,               KC_V,                       KC_K,               KC_H,               KC_COMM,            KC_DOT,             KC_SLSH,
                                            LT(MEDIA, KC_ESC),  LT(NAV, KC_SPC),    LT(MOUSE, KC_TAB),          LT(SYM, KC_ENT),    LT(NUM, KC_BSPC),   LT(FN, KC_DEL)
),

[GAME] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BASE,
                      KC_LALT, KC_SPC,  KC_G,        KC_NO,   KC_NO,   KC_ESC
),

[NAV] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_GAME,     C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,       KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_NO,   KC_ALGR, KC_NO,   KC_NO,   KC_NO,       KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                      KC_NO,   KC_NO,   KC_NO,       KC_ENT,  KC_BSPC, KC_DEL
),

[MOUSE] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,       KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    KC_NO,   KC_ALGR, KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                      KC_NO,   KC_NO,   KC_NO,       KC_BTN1, KC_BTN3, KC_BTN2
),

[MEDIA] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,       KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_NO,   KC_ALGR, KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_NO,   KC_NO,       KC_MSTP, KC_MPLY, KC_MUTE
),

[NUM] = LAYOUT(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,      KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,     KC_NO,   KC_NO,   KC_NO,   KC_ALGR, KC_NO,
                      KC_DOT,  KC_0,    KC_MINS,     KC_NO,   KC_NO,   KC_NO
),

[SYM] = LAYOUT(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,     KC_NO,   KC_NO,   KC_NO,   KC_ALGR, KC_NO,
                      KC_LPRN, KC_RPRN, KC_UNDS,     KC_NO,   KC_NO,   KC_NO
),

[FN] = LAYOUT(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,     KC_NO,   KC_NO,   KC_NO,   KC_ALGR, KC_NO,
                      KC_APP,  KC_SPC,  KC_TAB,      KC_NO,   KC_NO,   KC_NO
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(BASE);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(GAME);
            }
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE

led_t led_usb_state;

// OLED rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_render_default_layer_state(void) {
    oled_write_P(PSTR("Def. "), false);
    oled_write_P(PSTR("-----"), false);

    switch (get_highest_layer(default_layer_state)) {
        case BASE:
            oled_write_P(PSTR("ColDH"), false);
            break;
        case GAME:
            oled_write_P(PSTR("Game "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base "), false);
            break;
        case NAV:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case MEDIA:
            oled_write_P(PSTR("Media"), false);
            break;
        case NUM:
            oled_write_P(PSTR("Num  "), false);
            break;
        case SYM:
            oled_write_P(PSTR("Sym  "), false);
            break;
        case FN:
            oled_write_P(PSTR("Fn   "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

void oled_render_led_state (void) {
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

void oled_render_wpm (void) {
    oled_write_P(PSTR("WPM  "), false);
    oled_write_P(PSTR("---  "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

static void oled_render_logo(void) {
    // 32x32 logo
    static const char PROGMEM ek_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0x20, 0x60, 0x20, 0x20,
        0x20, 0x20, 0x60, 0x60, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0xf8, 0x0e, 0x03, 0x01, 0x00, 0xf8, 0x0c, 0x06, 0x00, 0x01, 0x01,
        0xcd, 0xf9, 0x00, 0x02, 0x02, 0x0e, 0xf8, 0x01, 0x03, 0x1e, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x1e, 0x13, 0x22, 0x24, 0x44, 0xcc, 0x88, 0x9f, 0x10, 0x30, 0x20, 0x60, 0x60,
        0x7f, 0x61, 0x20, 0x30, 0x10, 0x98, 0x8f, 0xcc, 0x44, 0x24, 0x22, 0x13, 0x1e, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x04,
        0x04, 0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(ek_logo, sizeof(ek_logo));
}

bool oled_task_user(void) {
    led_usb_state = host_keyboard_led_state();

    if(is_keyboard_master()) {
        oled_render_default_layer_state();
        oled_write_ln_P(PSTR(" "), false);
        oled_render_layer_state();
        oled_write_ln_P(PSTR(" "), false);
        oled_write_ln_P(PSTR(" "), false);
        oled_render_led_state();
        oled_write_ln_P(PSTR(" "), false);
        oled_write_ln_P(PSTR(" "), false);
        oled_write_ln_P(PSTR(" "), false);
        oled_render_wpm();
    }
    else {
        oled_render_logo();
    }
    return false;
}

#endif
