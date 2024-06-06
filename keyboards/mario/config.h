/*
Copyright 2024 @yuting wang

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

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define TAPPING_TERM 180

/* Select hand configuration */
#define MASTER_LEFT
#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  10
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define SPLIT_POINTING_ENABLE
#ifdef SPLIT_POINTING_ENABLE
#       define POINTING_DEVICE_RIGHT
#       define ANALOG_JOYSTICK_X_AXIS_PIN F4
#       define ANALOG_JOYSTICK_Y_AXIS_PIN F5
#       define ANALOG_JOYSTICK_CLICK_PIN B6
#       define ANALOG_JOYSTICK_SPEED_REGULATOR 6
#       define ANALOG_JOYSTICK_SPEED_MAX 20
#endif


#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define AUTO_MOUSE_TIME 650