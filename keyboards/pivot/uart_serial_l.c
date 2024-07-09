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


static uint8_t QMK_LOCK[3];
//uint8_t sss[10] ={0xFE,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#include "qf_custom_animation.h"


void process_caplock_status(uint8_t ledState){

    #if defined(LED_CAPS_LOCK_PIN)
    if (get_mode_before_sleep() != OUTPUT_USB) {
        if(ledState == 0x01){
            turn_on_led(LED_CAPS_LOCK_PIN);
                xprintf("BLE CAPS handled to BLE!!! on \n");
        }else{
                turn_off_led(LED_CAPS_LOCK_PIN);
            xprintf("BLE CAPS handled to BLE!!! off\n");
        }
    }
    xprintf("Set CAP Lock to statue : %d\n",ledState);
    #endif

    #if defined POWER_PIN
        extern void rgb_power_enable(bool enable);
        extern rgb_config_t rgb_matrix_config;

            if(!rgb_matrix_config.enable) {
                if(ledState == 0x01){

                    rgb_power_enable(true);
                    wait_ms(50);
                    xprintf("set_cap_qf_status is SET TO 1.....");
                    blink_animation(CAPS_LED_INDEX,1);
                    //set_cap_qf_status(1);
                    xprintf("light on the caps  ");
                }else{
                   // set_cap_qf_status(0);
                  //  clear_old_effect();
                    xprintf("set_cap_qf_status is SET TO 0.....");
                    xprintf("light off the caps  ");
                }

            }else{
                if(ledState == 0x01){
                    //rgb_matrix_set_color(30, 0, 200, 0);
                        xprintf("1111111111.....");
                  //  set_cap_qf_ble_status(1);
                    xprintf("matrix light on the  ble caps  ");
                }else{
                        xprintf("000000.....");
                    //set_cap_qf_ble_status(0);
                    xprintf("matrix set_cap_qf_ble_status is SET TO 0.....");
                    xprintf("matrix light off the ble caps  ");
                }
            }

    #endif

}

void handle_num_lock(int ledState) {
  xprintf("Set Number Lock to statue : %d\n", ledState);
#if defined(LED_Num_LOCK_PIN)
  if (get_mode_before_sleep() != OUTPUT_USB) {
    if (ledState == 0x01) {
      turn_on_led(LED_Num_LOCK_PIN);
      xprintf("BLE NumLock handled to BLE!!! on \n");
    } else {
      turn_off_led(LED_Num_LOCK_PIN);
      xprintf("BLE NumLock handled to BLE!!! off\n");
    }
  }
  printf("Set LED_Num_LOCK_PIN to statue : %d\n", ledState);
#endif
}

void handle_ble_channel_hint(int ble_channel) {

    xprintf("handle_ble_channel_hint : %d\n", ble_channel);

    if (ble_channel == 0x00) {
        blink_qf_animation_color_init(0,green_qf_color);
    }

    if (ble_channel == 0x01) {
        blink_qf_animation_color_init(1,green_qf_color);
    }

    if (ble_channel == 0x02) {
        blink_qf_animation_color_init(2,green_qf_color);
    }

    if (ble_channel == 0x04) {
        blink_qf_animation_color_init(3,green_qf_color);
    }


}

void process_LED_status(void){

    uint8_t checkByte = uart_read();
//    printf("uart received header : %x\n",checkByte);

    if(checkByte == 0xFD){
        uart_receive(QMK_LOCK,3);
    }

    uint8_t endByte = QMK_LOCK[2]; //
    if(endByte != 0XFF){
         return ;
    }


    uint8_t ledFlag = QMK_LOCK[0]; //LED
    uint8_t ledState = QMK_LOCK[1]; //LED state
    xprintf("uart received ledFlag : %d\n",ledFlag);
    xprintf("uart received ledState : %d\n",ledState);

    switch(ledFlag){

        case 0x01: //caps led
            //set_usb_led_state(ledState);
            process_caplock_status(ledState);
            break;
        case 0x02: //Number Lock led
            //set_usb_led_state(ledState);
            handle_num_lock(ledState);
            break;
        case 0x03: //s
           // uint8_t targetMmode = ledState;
           #if defined(FN_BLE_LED)
            handle_ble_channel_hint(ledState);
            #endif
            xprintf("task test : %d\n",ledState);
            break;
    }

    for(uint8_t i=0;i<3;i++){
        QMK_LOCK[i]=0x00;
    }

    xprintf("Clear this array LED Status...\n");
}

 uint8_t VIA_ARR[40];
 uint8_t VIA_IN[32];
void uart_task(void){

 //raw_hid_receive(buffer, size);
    if(!uart_available()){
        return ;
    }

    process_LED_status();




}

