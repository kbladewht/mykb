#include QMK_KEYBOARD_H
#include "hal_pal.h"
#include "actionuart.h"
#include "outputselect.h"
#include "uart.h"
#include "eeconfig.h"
#include "eeprom.h"
// #include "config.h"
#include "analog_qf.h"

bool power_pin_inited = false;
void power_pin_init(void) {
  if (power_pin_inited) return;
  power_pin_inited = true;
  #if defined POWER_PIN
  writeLowPinOutOD(POWER_PIN);
  #endif
}
void rgb_power_enable(bool enable) {
  power_pin_init();
  #if defined POWER_PIN
	if (enable) {
         writeHighPinOut(POWER_PIN);
	} else {
		writeLowPinOutOD(POWER_PIN);
    }

  #endif
}

uint8_t read_handwire_detect(void) {
     uint8_t usb_detect1 = readPin(HAND_WIRE_DETECT);
     return usb_detect1;
}

void setDetectPinOutput(void) {
     setPinInputLow(HAND_WIRE_DETECT);
}

void turnOFF_usb_led(void) {
    #if defined (USB_PIN_LED)
     turn_off_led(USB_PIN_LED);
    #endif
}

void turnoff_power_led(void) {
   #if defined (POWER_LED)
    turn_off_led(POWER_LED);
   #endif
}

void turnon_power_led(void) {
   #if defined (POWER_LED)
    turn_on_led(POWER_LED);
   #endif
}


void turnoff_caps_led(void) {
     #if defined (LED_CAPS_LOCK_PIN)
        turn_off_led(LED_CAPS_LOCK_PIN);
     #endif
}

void setWKPin_high(void) {
      writeHighPinOut(WK_PIN);
}

uint8_t readWKPin(void) {
   return readPin(WK_PIN);
}


void setWKPin_low(void) {
    writePinLow(WK_PIN);
}

void turn_adc_off(void) {
    adc_stop_qf(QF_ADC_PIN);
}


void uartSendByAction(uint8_t actionCode){

    xprintf("action code is %x...."+actionCode);

    uart_write(0xFD);

    uart_write(actionCode); //0x02 is to wakeup

    for(int i=0;i<8;i++){
          uart_write(0x01);
    }

    uart_write(0xFF);
}

void writeHighPinOut(pin_t pin){
    setPinOutput(pin);
    writePinHigh(pin);
}

void switch_cols_gpio_from_3V(pin_t pin){
    writeHighPinOut(pin);
}

void writeLowPinOut(pin_t pin){
    setPinOutput(pin);
    writePinLow(pin);
}

void writeHighPinOutOD(pin_t pin){
    setPinOutputOpenDrain(pin);
    writePinHigh(pin);
}

void writeLowPinOutOD(pin_t pin){
    setPinOutputOpenDrain(pin);
    writePinLow(pin);
}

void pair_blueMode(void){
    xprintf("pair_blueMode  ....");
    uartSendByAction(PAIRCODE);
}

void go_bl_dfu(void){
    xprintf("go_bl_dfu ....");
    uartSendByAction(KB_DFU);
}

void channel_common(uint8_t channel_v){
    xprintf("channel1 ....");
    uartSendByAction(channel_v);
    showPerChannel2();
}

void unpair_current_BLE(void){
    xprintf("unpair_blueMode to do ....");
    uartSendByAction(UNPAIRCODE);
}

void reset_current_BLE(void){
    xprintf("reset_current_BLE to do ....");
    uartSendByAction(RESET_CODE);
}

void show_adc_power(uint8_t f[]){
    xprintf("show_adc_power.");


    uart_write(0xFD);

    uart_write(ADC_DISPALY_CODE); //0x06 is to adc pass in

    for(int i=0;i<8;i++){
          uart_write(0x01);
    }

    uart_write(0xFF);
}

void bluetooth_switch_one(int swc){
    xprintf("bluetooth_switch_one to do %d....",swc);
    if(swc == 0){
        uartSendByAction(0x05);
         xprintf("Channel 1 %d....",swc);
    }
    if(swc == 1){
        uartSendByAction(0x06);
         xprintf("Channel 2 %d....",swc);
    } if(swc == 2){
        uartSendByAction(0x07);
         xprintf("Channel 3 %d....",swc);
    }

}

void turn_on_led(pin_t pin){
    if(LED_ON_HIGH==1){
        writePinHigh(pin);
    }else{
        writePinLow(pin);
    }
}

void turn_on_led_OD(pin_t pin){
    if(LED_ON_HIGH==1){
        writeHighPinOutOD(pin);
    }else{
        writePinLow(pin);
    }
}

void turn_off_led(pin_t pin){
    if(LED_ON_HIGH==1){
        writePinLow(pin);
    }else{
        writePinHigh(pin);
    }
}


uint8_t showled=0;


void showPerChannel2(void) {
     xprintf("where_to_send is ......%d....", where_to_send());
    if (where_to_send() == OUTPUT_USB) {
         #ifdef DISABLE_USB_LED
           turn_off_led(USB_PIN_LED);
         #else
              turn_on_led(USB_PIN_LED);
        #endif
    } else {
           turn_off_led(USB_PIN_LED);
    }

}

void showLEDInit(void) {
     xprintf("where_to_send is ......%d....", auto_detect_output());

    if (where_to_send() == OUTPUT_USB) {
         #ifdef DISABLE_USB_LED
           turn_off_led(USB_PIN_LED);
         #else
              turn_on_led(USB_PIN_LED);
        #endif
    } else {
         #if defined (USB_PIN_LED)
           turn_off_led(USB_PIN_LED);
         #endif
    }

}


void flyInit(void){

    //uint32_t eeprom_default = eeconfig_read_user();
    //set_output_default((uint8_t)eeprom_default);//Remember the default channel , either usb or BLE

    // uint32_t channelEE = eeconfig_read_user();
    // xprintf("eeconfig_init_user111 ,current channel is %d \n",channelEE);

    // set_output_user(channelEE);


    // initialize anything that requires ChibiOS

    #if defined (POWER_LED)
        turn_on_led(POWER_LED);
    #endif

    #if defined (USB_PIN_LED)
        setPinOutput(USB_PIN_LED);
        showLEDInit();
    #endif
    writeHighPinOut(WK_PIN);
    xprintf("This will only init once ....");

}


void process_handle_wk_event(void) {

    const uint32_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
    const uint32_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;


    handle_wk_event(HAND_WIRE_DETECT,
        MATRIX_ROWS,MATRIX_COLS,
        row_pins,col_pins);

}

