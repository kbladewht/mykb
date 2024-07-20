/* Copyright 2021
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "uart.h"
#include "quantum.h"
#include "outputselect.h"
#include "actionuart.h"
#include "qf_custom_animation.h"
static SerialConfig serialConfig = {
    SERIAL_DEFAULT_BITRATE,
    UART_CR1,
    UART_CR2,
    UART_CR3,
};
 static bool is_initialised = false;

 void set_init_raw(void){
    is_initialised = false;
 }
void uart_init(uint32_t baud) {


    if (!is_initialised) {
        is_initialised = true;

        serialConfig.speed = baud;

#if defined(USE_GPIOV1)
        palSetLineMode(SD1_TX_PIN, PAL_MODE_ALTERNATE_OPENDRAIN);
        palSetLineMode(SD1_RX_PIN, PAL_MODE_ALTERNATE_OPENDRAIN);
#else
        palSetLineMode(UART_TX_PIN, PAL_MODE_ALTERNATE(UART_TX_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL);
        palSetLineMode(UART_RX_PIN, PAL_MODE_ALTERNATE(UART_RX_PAL_MODE) | PAL_OUTPUT_TYPE_OPENDRAIN);
#endif
        sdStart(&UART_DRIVER, &serialConfig);
    }
}

void uart_write(uint8_t data) { sdPut(&UART_DRIVER, data); }

uint8_t uart_read(void) {
    msg_t res = sdGet(&UART_DRIVER);

    return (uint8_t)res;
}

void uart_transmit(const uint8_t *data, uint16_t length)
{
     sdWrite(&UART_DRIVER, data, length);
 }

void uart_receive(uint8_t *data, uint16_t length) { sdRead(&UART_DRIVER, data, length); }

bool uart_available(void) { return !sdGetWouldBlock(&UART_DRIVER); }





void uart_task(void){

 //raw_hid_receive(buffer, size);
    if(!uart_available()){
        return ;
    }

    process_LED_status();

}

