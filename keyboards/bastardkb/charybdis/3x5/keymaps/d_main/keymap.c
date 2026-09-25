#include QMK_KEYBOARD_H 

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_GAME,
    LAYER_GAME_EXTRA,
    LAYER_DOWN,
    LAYER_DOWN_EXTRA,
    LAYER_MOD,
    LAYER_MOD_EXTRA,
    LAYER_POINTER,
};

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    \
                      KC_NO, MO(3), MO(5), KC_LSFT, KC_SPC

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define LAYOUT_GAME                                                                                      \
       KC_M,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_NO,   KC_NO,      KC_UP,       KC_NO,    KC_NO, \
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_NO,   KC_LEFT,    KC_DOWN,     KC_RGHT,  KC_NO,  \
       MO(5),      KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,   MS_BTN1,    MS_BTN3,     MS_BTN2, DRGSCRL,  \
                      MO(3), MO(2), KC_SPC, DF(0), MO(2)

#define LAYOUT_GAME_EXTRA                                                                           \
       KC_P,      KC_O,    KC_U,    KC_Y,    KC_T,    KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,  \
       KC_LCTL,   KC_L,    KC_J,    KC_H,    KC_G,    KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,   \
       KC_I,      KC_K,    KC_M,    KC_N,    KC_B,    KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,    \
                      KC_NO, KC_TRNS, DF(0), KC_NO, KC_NO

#define LAYOUT_DOWN                                                                                       \
       KC_1,      KC_2,     KC_3,    KC_4,      KC_5,    KC_6,   KC_7,      KC_8,    KC_9,     KC_0,       \
       MO(4),     KC_DOWN,  KC_UP,   KC_BSPC,   KC_DEL,  KC_GRV, KC_MINS,   KC_EQL,  KC_BSLS,  KC_QUOT,     \
       KC_LCTL,   KC_LEFT,  KC_RGHT, SC_SENT, KC_ESC,    UC(0x2014),  KC_LBRC,   KC_NO,   KC_NO,    KC_RBRC, \
                      KC_NO, KC_TRNS, KC_NO, KC_LSFT, KC_CAPS

#define LAYOUT_DOWN_EXTRA                                                                    \
       KC_INS,   KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PAST, \
       KC_TRNS,  KC_PGDN,  KC_PGUP, KC_SPC,   DF(1),    KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PPLS, \
       KC_SLEP,  KC_HOME,  KC_END,  KC_VOLD, KC_VOLU,  KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT,     \
                      MS_BTN3, MS_BTN1, MS_BTN2, KC_NUM, KC_RALT

#define LAYOUT_MOD_                                                                                      \
       KC_F1,     KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_F6,   KC_F7,      KC_F8,    KC_F9,    KC_F10,    \
       MO(6),     KC_LALT,  KC_LCTL, KC_LSFT, KC_TAB, KC_F11,  KC_RSFT,    KC_RCTL,  KC_RALT,  KC_RGUI,    \
       KC_LSFT,   KC_LCTL,  KC_LALT,   KC_APP,   KC_LGUI, KC_F12,  MS_BTN1,    MS_BTN3,  MS_BTN2,  DRGSCRL, \
                      KC_NO, DF(0), KC_TRNS, KC_LSFT, KC_NO


#define LAYOUT_MOD_EXTRA                                                                  \
       KC_NO,  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_CLEAR_EEPROM, QK_BOOT, \
       KC_NO,  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, S_D_MOD, DPI_MOD,              \
       SH_TT,  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, S_D_RMOD, DPI_RMOD,               \
                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define LAYOUT_POINTER                                                                            \
       KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
       KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
       KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN3, MS_BTN2, DRGSCRL,   \
                      SNIPING, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

enum combos {
    DOWN_COMBO_6,    
    DOWN_COMBO_7,     
    DOWN_COMBO_8,  
    DOWN_COMBO_9,    
    DOWN_COMBO_0,    
    MOD_COMBO_F6,
    MOD_COMBO_F7,
    MOD_COMBO_F8,
    MOD_COMBO_F9,
    MOD_COMBO_F10,
    QUICK_TO_MOD_EXTRA,
};

const uint16_t PROGMEM combo_6[]  = {KC_2, KC_4, COMBO_END};
const uint16_t PROGMEM combo_7[]  = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo_8[]  = {KC_3, KC_5, COMBO_END};
const uint16_t PROGMEM combo_9[]  = {KC_2, KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo_0[]  = {KC_2, KC_3, KC_5, COMBO_END};
const uint16_t PROGMEM combo_f6[] = {KC_F2, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_f7[] = {KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_f8[] = {KC_F3, KC_F5, COMBO_END};
const uint16_t PROGMEM combo_f9[] = {KC_F2, KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_F2, KC_F3, KC_F5, COMBO_END};
const uint16_t PROGMEM combo_to_mod_extra[] = {KC_LSFT, KC_SPC, COMBO_END};

combo_t key_combos[] = {
    [DOWN_COMBO_6]  = COMBO(combo_6,  KC_6),
    [DOWN_COMBO_7]  = COMBO(combo_7,  KC_7),
    [DOWN_COMBO_8]  = COMBO(combo_8,  KC_8),
    [DOWN_COMBO_9]  = COMBO(combo_9,  KC_9),
    [DOWN_COMBO_0]  = COMBO(combo_0,  KC_0),
    [MOD_COMBO_F6]  = COMBO(combo_f6, KC_F6),
    [MOD_COMBO_F7]  = COMBO(combo_f7, KC_F7),
    [MOD_COMBO_F8]  = COMBO(combo_f8, KC_F8),
    [MOD_COMBO_F9]  = COMBO(combo_f9, KC_F9),
    [MOD_COMBO_F10] = COMBO(combo_f10, KC_F10),
    [QUICK_TO_MOD_EXTRA] = COMBO(combo_to_mod_extra, MO(6)),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case DOWN_COMBO_6:
        case DOWN_COMBO_7:
        case DOWN_COMBO_8:
        case DOWN_COMBO_9:
        case DOWN_COMBO_0:
            return layer_state_is(3);
            
        case MOD_COMBO_F6:
        case MOD_COMBO_F7:
        case MOD_COMBO_F8:
        case MOD_COMBO_F9:
        case MOD_COMBO_F10:
            return layer_state_is(5);

        case QUICK_TO_MOD_EXTRA:
            return layer_state_is(0);

        default:
            return true;
    }
}

// Automatically enable sniping-mode on the pointer layer.
#ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
#undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_MOD

/*
#ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    bkpd_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#endif
//*/
/*
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD ||
        abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 &&
        TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >=
            CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
    }
}
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
//*/

/*
void keyboard_post_init_user(void) {
    bkpd_set_auto_precision_on_mouse_layer_enabled(true);
    bkpd_set_auto_mouse_layer_enabled(true);
}
*/



const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}},

    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
  [LAYER_GAME] = LAYOUT_wrapper(LAYOUT_GAME),
  [LAYER_GAME_EXTRA] = LAYOUT_wrapper(LAYOUT_GAME_EXTRA),
  [LAYER_DOWN] = LAYOUT_wrapper(LAYOUT_DOWN),
  [LAYER_DOWN_EXTRA] = LAYOUT_wrapper(LAYOUT_DOWN_EXTRA),
  [LAYER_MOD] = LAYOUT_wrapper(LAYOUT_MOD_),
  [LAYER_MOD_EXTRA] = LAYOUT_wrapper(LAYOUT_MOD_EXTRA),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_POINTER),
};