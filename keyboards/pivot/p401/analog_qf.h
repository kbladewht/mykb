/* Copyright 2019 Drew Mills
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

#pragma once

#include <stdint.h>
#include "gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint16_t input;
    uint8_t  adc;
} adc_mux;
#define TO_MUX(i, a) \
    (adc_mux) {      \
        i, a         \
    }

int16_t analogReadPin(pin_t pin);
int16_t analogReadPinAdc(pin_t pin, uint8_t adc);
adc_mux pinToMux(pin_t pin);
typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;
int16_t adc_read(adc_mux mux);
u8   getLightIndexADC(u16 adcx);
u8   getPercent(u16 adcx);
void process_adc_stm(uint8_t force_show);
void process_adc_stm_rgb(void) ;
void adc_stop_qf(pin_t pin);
int16_t read_vbat(void);

#ifdef __cplusplus
}
#endif
