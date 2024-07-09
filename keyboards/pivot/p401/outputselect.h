/*
Copyright 2017 Priyadi Iman Nurcahyo
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

#include <stdint.h>

enum outputs {
    OUTPUT_AUTO=0,
    OUTPUT_NONE=1,
    OUTPUT_USB=2,
    OUTPUT_BLUETOOTH=3
};
#ifndef OUTPUT_DEFAULT
#    define OUTPUT_DEFAULT OUTPUT_USB
#endif
uint8_t get_mode_before_sleep(void);
void    set_output(uint8_t output);
void    set_output_user(uint8_t output);
void    set_output_default(uint8_t output);
uint8_t auto_detect_output(void);
uint8_t where_to_send(void);
uint8_t get_curr_mode(void);
void set_rgb_matrix_qf_status(uint8_t status);
uint8_t get_rgb_matrix_qf_status(void);

void set_cap_qf_status(uint8_t cap_qf_status) ;
void set_cap_qf_ble_status(uint8_t cap_qf_status) ;

uint8_t get_cap_qf_status(void);
uint8_t get_cap_qf_ble_status(void);

void set_num_qf_status(uint8_t num_qf_status) ;
void set_num_qf_ble_status(uint8_t num_qf_status) ;

uint8_t get_num_qf_status(void);
uint8_t get_num_qf_ble_status(void);

void set_scroll_qf_status(uint8_t scroll_qf_status) ;
void set_scroll_qf_ble_status(uint8_t scroll_qf_status) ;

uint8_t get_scroll_qf_status(void);
uint8_t get_scroll_qf_ble_status(void);

void set_rgb_wire_status(uint32_t rgb_wire_status);

uint32_t get_rgb_wire_status(void);
