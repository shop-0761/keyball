// ref: https://docs.qmk.fm/features/tap_dance
#pragma once

enum tap_dances {
    _TD_Q_ESC,
    _TD_A_TAB,
    _TD_Z_CZ,
    _TD_X_CX,
    _TD_C_CC,
    _TD_V_CV,
    _TD_S_S
};

#define TD_Q_ESC TD(_TD_Q_ESC)
#define TD_A_TAB TD(_TD_A_TAB)

#define TD_Z_CZ TD(_TD_Z_CZ)
#define TD_X_CX TD(_TD_X_CX)
#define TD_C_CC TD(_TD_C_CC)
#define TD_V_CV TD(_TD_V_CV)
#define TD_S_CS TD(_TD_S_S)

tap_dance_action_t tap_dance_actions[] = {
    [_TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [_TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
    [_TD_Z_CZ]  = ACTION_TAP_DANCE_DOUBLE(KC_Z, C(KC_Z)),
    [_TD_X_CX]  = ACTION_TAP_DANCE_DOUBLE(KC_X, C(KC_X)),
    [_TD_C_CC]  = ACTION_TAP_DANCE_DOUBLE(KC_C, C(KC_C)),
    [_TD_V_CV]  = ACTION_TAP_DANCE_DOUBLE(KC_V, C(KC_V)),
    [_TD_S_S]   = ACTION_TAP_DANCE_DOUBLE(KC_S, C(KC_S))
};
