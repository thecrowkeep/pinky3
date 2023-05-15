/* Copyright 2018 'Masayuki Sunahara'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
// #include "g/engine.h"
// #include "g/keymap_engine.h"

enum layer_names {
    _COLEMAK,
    _ASETNIOP,
    _NUMPAD,
    _ARROWS,
    _NUMBERS,
    _FUNC,
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    NUMPAD,
    ARROWS,
    NUMBERS,
    FUNC,
    ASETNIOP,
};

#define NUMBERS LT(_NUMBERS, KC_BSPC)
#define ASETNIOP TG(_ASETNIOP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x7_4(
        KC_TAB , KC_Q    , KC_W   , KC_F   , KC_P   , KC_B   , KC_LBRC,    KC_RBRC, KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN   , QK_GESC,
        KC_LCTL, KC_A    , KC_R   , KC_S   , KC_T   , KC_G   , KC_BSLS,    KC_QUOT, KC_M   , KC_N   , KC_E   , KC_I   , KC_O      , _______,
        KC_LSFT, KC_Z    , KC_X   , KC_C   , KC_D   , KC_V   , KC_EQL ,    KC_MINS, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH   , KC_GRV ,
                                    KC_LALT, KC_BSPC, NUMPAD , KC_SPC ,    KC_ENT , ARROWS , NUMBERS, KC_RGUI
    ),
    [_ASETNIOP] = LAYOUT_split_3x7_4(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_A   , KC_R   , KC_S   , KC_T   , XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_N   , KC_E   , KC_I   , KC_O   , XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT_split_3x7_4(
        _______, _______, KC_P4  , KC_P5  , KC_P6  , _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , _______, _______,    _______, _______, _______, _______, KC_MINS, KC_EQL , _______,
        _______, _______, KC_P7  , KC_P8  , KC_P9  , _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, KC_DEL , _______
    ),
    [_ARROWS] = LAYOUT_split_3x7_4(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_NUMBERS] = LAYOUT_split_3x7_4(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
    [_FUNC] = LAYOUT_split_3x7_4(
        _______, _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,    _______, _______, _______, _______, _______, _______, ASETNIOP,
        _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_PSCR, _______,
        _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,    _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______,    _______, _______, _______, _______
    ),
};
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return get_highest_layer(layer_state) == _ASETNIOP;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // set_timelog();
    }

    switch (keycode) {
        case NUMPAD:
            if (record->event.pressed) {
                layer_on(_NUMPAD);
                update_tri_layer(_NUMPAD, _ARROWS, _FUNC);
            } else {
                layer_off(_NUMPAD);
                update_tri_layer(_NUMPAD, _ARROWS, _FUNC);
            }
            return false;
            break;
        case ARROWS:
            if (record->event.pressed) {
                layer_on(_ARROWS);
                update_tri_layer(_NUMPAD, _ARROWS, _FUNC);
            } else {
                layer_off(_ARROWS);
                update_tri_layer(_NUMPAD, _ARROWS, _FUNC);
            }
            return false;
            break;
        case FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
            } else {
                layer_off(_FUNC);
            }
            return false;
            break;
    }
    return true;
}
