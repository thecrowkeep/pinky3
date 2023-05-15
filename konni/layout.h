//DHM mod
#define ______________COLEMAK__LEFT_1______________           KC_Q, KC_W, KC_F, KC_P, KC_B
#define ______________COLEMAK__LEFT_2______________           KC_A   , KC_R   , KC_S   , KC_T   , KC_G
#define ______________COLEMAK__LEFT_3______________           KC_Z   , KC_X   , KC_C   , KC_D   , KC_V

#define ______________COLEMAK_RIGHT_1______________           KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN
#define ______________COLEMAK_RIGHT_2______________           KC_M   , KC_N   , KC_E   , KC_I   , KC_O
#define ______________COLEMAK_RIGHT_3______________           KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH


#define ______________FUNC_1______________                    KC_F4  , KC_F5  , KC_F6  , KC_F10 
#define ______________FUNC_2______________                    KC_F1  , KC_F2  , KC_F3  , KC_F12 
#define ______________FUNC_3______________                    KC_F7  , KC_F8  , KC_F9  , KC_F11 


#define _________NUMPAD1_________                                      KC_P4  , KC_P5  , KC_P6  
#define __________________NUMPAD2_________                    KC_P0  , KC_P1  , KC_P2  , KC_P3  
#define _________NUMPAD3_________                                      KC_P7  , KC_P8  , KC_P9  
#define ___________NUMPAD_FULL1___________                    _______, _________NUMPAD1_________
#define ___________NUMPAD_FULL2___________                    __________________NUMPAD2_________
#define ___________NUMPAD_FULL3___________                    _______, _________NUMPAD3_________


#define ______________ARROWS______________                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT

#define __________________________________                    _______, _______, _______, _______


// #define _____________MOD_LEFT_____________                   KC_LALT, LT_NUM , LT(_NUMPAD, KC_DEL) , KC_SPC  
// #define _____________MOD_RIGHT____________                   KC_BSPC, LT(_FUNCTION, KC_PRINT_SCREEN), LT_FNC  , KC_LGUI

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)