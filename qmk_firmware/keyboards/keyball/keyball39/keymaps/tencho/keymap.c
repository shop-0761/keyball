/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "tapdance.h"
#include "keymacro.h"
#include "combo.h"
#include "cpi.h"

enum custom_keycodes {
    CPI_TOGGLE = KEYBALL_SAFE_RANGE,
};


// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , L2_E     , KC_R     , KC_T      ,                            KC_Y     , KC_U     , KC_I    , KC_O     , KC_P     ,
    SFT_A    , GUI_S    , L1_D     , KC_F     , KC_G      ,                            KC_H     , KC_J     , KC_K    , GUI_L    , SFT_SCLN ,
    CTL_Z    , L4_X     , KC_C     , KC_V     , KC_B      ,                            KC_N     , KC_M     , KC_COMM , KC_DOT   , CTL_SLSH ,
    L5_ESC   , _______  , _______  , _______  , ALT_TAB   , L1_SPC  ,       L2_WIN   , ALT_ENT  , KC_BSPC  , UNDO     , HIST    , LANG
  ),

  [1] = LAYOUT_universal(
    S(KC_1)  , S(KC_2)  , S(KC_3)  , S(KC_4)  , S(KC_5)   ,                            _______  , KC_LBRC  , _______ , KC_RBRC , KC_EQL   ,
    S(KC_6)  , S(KC_7)  , S(KC_8)  , _______  , _______   ,                            _______  , S(KC_9)  , KC_MINS , S(KC_0) , KC_QUOT  ,
    KC_GRV   , KC_TILD  , _______  , _______  , _______   ,                            _______  , S_LBRC   , S_MINS  , S_RBRC  , KC_BSLS  ,
     _______ , _______  , _______  , _______  , _______   , _______  ,      _______  , SS       , KC_DEL   , REDO    , WINTAB  , _______
  ),

  [2] = LAYOUT_universal(
    _______  , _______ , KC_7     , KC_8     , KC_9      ,                            _______  , KC_PMNS  , _______  , KC_PPLS  , _______  ,
    _______  , KC_0    , KC_4     , KC_5     , KC_6      ,                            _______  , KC_PAST  , _______  , KC_PSLS  , _______  ,
    _______  , _______ , KC_1     , KC_2     , KC_3      ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______ , _______  , _______  , _______   , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  ,CPI_TOGGLE, MS_BTN3  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , MO(4)    , MS_BTN1  , MS_BTN2  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , MS_BTN2  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  //スクロールレイヤー
  [4] = LAYOUT_universal(
    _______  , _______  , _______  , MS_BTN3  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , MS_BTN1  , MS_BTN2  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , MS_BTN2  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),
  
  [5] = LAYOUT_universal(
    _______  , _______  , KC_F7    , KC_F8    , KC_F9     ,                            _______  , BACK_ED  , KC_UP    , FOR_ED   , _______  ,
    _______  , _______  , KC_F4    , KC_F5    , KC_F6     ,                            _______  , KC_LEFT  , KC_DOWN  , KC_RIGHT , _______  ,
    _______  , _______  , KC_F1    , KC_F2    , KC_F3     ,                            _______  , VD_LEFT  , WINTAB   , VD_RIGHT , _______  ,
    _______  , _______ , _______  , _______  , _______    , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),
};

// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 4
    keyball_set_scroll_mode(get_highest_layer(state) == 4);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case CPI_TOGGLE:
            precision_toggle(record->event.pressed);
            return false;
    }
    return true;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    // TODO: 標準の表示と切り替えられるようにする
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

void keyboard_post_init_user(void) {
    wait_ms(400);

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);
#endif
}
