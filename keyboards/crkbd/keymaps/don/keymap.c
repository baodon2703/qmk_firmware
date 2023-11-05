#include QMK_KEYBOARD_H
#include "features/sentence_case.h"
#include "features/swapper.h"
#include "features/achordion.h"

// Defines the keycodes used by our macros in process_record_user
enum keycodes {
    SW_APP = SAFE_RANGE,  // Switch to next app         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
    SW_WIN,
};

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_R LGUI_T(KC_R)
#define HOME_S LALT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E LALT_T(KC_E)
#define HOME_I RGUI_T(KC_I)
#define HOME_O RSFT_T(KC_O)

#define HOME_SPC LGUI_T(KC_SPC)
#define HOME_WIN_SPC LCTL_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  KC_ESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC, TG(7),
  KC_TAB, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,    KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O, KC_ENT,
  KC_LALT, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
           MO(3), OSL(2), HOME_SPC,         OSM(MOD_LSFT), OSL(4), OSL(5)

  ),

  [1] = LAYOUT_split_3x6_3(
  KC_ESC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC, TG(7),
  KC_TAB, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,    KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O, KC_ENT,
  KC_LALT, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
           MO(3), OSL(2), HOME_WIN_SPC,         OSM(MOD_LSFT), OSL(4), OSL(5)

  ),

  //Navigation
  [2] = LAYOUT_split_3x6_3(
  XXXXXXX,XXXXXXX, XXXXXXX, OSM(MOD_HYPR), OSM(MOD_MEH), XXXXXXX,     KC_HOME, KC_END, LGUI(LSFT(KC_TAB)), LGUI(KC_TAB), KC_BSPC, XXXXXXX,
  XXXXXXX, KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, LGUI(KC_SPC),           KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_ENT, XXXXXXX,
  XXXXXXX, KC_TAB, XXXXXXX, SW_WIN, SW_APP, XXXXXXX,                  KC_PGUP, KC_PGDN, XXXXXXX, SW_LANG, LSFT(KC_ENT), XXXXXXX,
                          _______, _______, _______,   KC_ENT, KC_TAB, LSFT(KC_ENT)
  ),

  //Num
  [3] = LAYOUT_split_3x6_3(
  XXXXXXX, KC_ESC, XXXXXXX, OSM(MOD_HYPR), OSM(MOD_MEH), XXXXXXX,                             KC_DEL,   KC_7,    KC_8,    KC_9,    KC_BSPC, XXXXXXX,
  XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, LGUI(KC_SPC),                                  KC_COLN,  KC_4,    KC_5,    KC_6,    KC_ENT, XXXXXXX,
  XXXXXXX, KC_TAB, XXXXXXX, SW_WIN, SW_APP, XXXXXXX,                                          KC_0,     KC_1,    KC_2,    KC_3,    LSFT(KC_ENT), XXXXXXX,
                          _______, _______, _______,    KC_0, LALT(KC_BSPC), LSFT(KC_ENT)
  ),

  //Symbol
  [4] = LAYOUT_split_3x6_3(
  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_DEL,  KC_BSPC, XXXXXXX,
  XXXXXXX, KC_PLUS, KC_MINS, KC_EQL,  KC_UNDS, KC_QUOT,                      KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, KC_SCLN, XXXXXXX,
  XXXXXXX, KC_TILD, KC_GRV,  KC_BSLS, KC_PIPE, KC_DQUO,                      KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, KC_COLN, XXXXXXX,
                          MO(6),   MO(6), MO(6),        _______, _______, _______
  ),

  //Mouse
  [5] = LAYOUT_split_3x6_3(
  XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                   XXXXXXX, OSM(MOD_MEH), OSM(MOD_HYPR),   KC_DEL,   KC_ESC, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                   LCTL(KC_SPC), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_CAPW, KC_CPYW, KC_CAPP, KC_CPYP,                   XXXXXXX, SW_APP, SW_WIN, XXXXXXX, KC_TAB, XXXXXXX,
                        _______, KC_BTN2, KC_BTN1,      _______, _______, _______
 ),

  //Adj
  [6] = LAYOUT_split_3x6_3(
  QK_BOOT, RGB_HUI, KC_MUTE, KC_MPLY, KC_BRID, KC_BRIU,                               KC_F10,  KC_F7,   KC_F8,   KC_F9,   TG(1), XXXXXXX,
  RGB_TOG, RGB_SAI, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,                               KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX,
  RGB_MOD, RGB_VAI, KC_CAPW, KC_CPYW, KC_CAPP, KC_CPYP,                               KC_F12,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, XXXXXXX,
                        KC_LSFT, KC_LALT, KC_LGUI,    KC_LCTL, _______, _______
 ),

  //QWERTY
  [7] = LAYOUT_split_3x6_3(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, TG(7),
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
  KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LGUI,
           KC_SPC, KC_LSFT, KC_LCTL,        KC_Y, KC_H, KC_N
  ),

};


#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM hexagram_logo[] = {
	0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x18, 0x06,
    0x06, 0x18, 0x70, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x07, 0x1f, 0x32, 0x66, 0xc4, 0x6c, 0x38, 0x1e, 0x37, 0x61, 0xc0, 0x80, 0x80,
    0x80, 0x80, 0xc0, 0x61, 0x37, 0x1e, 0x38, 0x6c, 0xc4, 0x66, 0x32, 0x1f, 0x07, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xe0, 0xf8, 0x4c, 0x66, 0x23, 0x36, 0x1c, 0x78, 0xec, 0x86, 0x03, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x86, 0xec, 0x78, 0x1c, 0x36, 0x23, 0x66, 0x4c, 0xf8, 0xe0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0e, 0x18, 0x60,
    0x60, 0x18, 0x0e, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00
};
    oled_write_raw_P(hexagram_logo, sizeof(hexagram_logo));
}



static void print_logo_narrow(void) {
    render_logo();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    /* switch (get_highest_layer(state)) { */
    /* case 0: */
    /*     rgb_matrix_reload_from_eeprom(); */
    /*     break; */
    /* case 1: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_TEAL); */
    /*     break; */
    /* case 2: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_PURPLE); */
    /*     break; */
    /* case 3: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_GOLD); */
    /*     break; */
    /* case 4: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_GREEN); */
    /*     break; */
    /* case 5: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_RED); */
    /*     break; */
    /* case 6: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_BLUE); */
    /*     break; */
    /* case 7: */
    /*     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS); */
    /*     rgb_matrix_sethsv_noeeprom(HSV_GREEN); */
    /*     break; */
    /* } */
  return state;
}

static void print_status_narrow(void) {


    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write("Base ", false);
            break;
        case 1:
            oled_write("Win  ", false);
            break;
        case 2:
            oled_write("Nav  ", false);
            break;
        case 3:
            oled_write("Num  ", false);
            break;
        case 4:
            oled_write("Sym  ", false);
            break;
        case 5:
            oled_write("Mouse", false);
            break;
        case 6:
            oled_write("Adj  ", false);
            break;
        case 7:
            oled_write("Game ", false);
            break;
        default:
            oled_write("Undef", false);
    }

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  switch (tap_hold_keycode) {
    case HOME_SPC:
      return true;
      break;
    case HOME_WIN_SPC:
      return true;
      break;
  }

  switch (other_keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      other_keycode &= 0xff;  // Get base keycode.
  }
  // Allow same-hand holds with non-alpha keys.
  if (other_keycode > KC_Z) { return true; }
  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool sw_win_active = false;
bool sw_lang_active = false;
bool sw_app_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_sentence_case(keycode, record)) { return false; }

  update_swapper(
      &sw_app_active, KC_LGUI, KC_TAB, SW_APP,
      keycode, record
  );
  update_swapper(
      &sw_lang_active, KC_LCTL, KC_GRV, SW_LANG,
      keycode, record
  );

  update_swapper(
      &sw_win_active, KC_LGUI, KC_GRV, SW_WIN,
      keycode, record
  );
  return true;
}
