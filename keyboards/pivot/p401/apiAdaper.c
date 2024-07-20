#include QMK_KEYBOARD_H
#include "hal_pal.h"
#include "actionuart.h"
#include "uart.h"
#include "eeconfig.h"
#include "eeprom.h"
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

pin_t get_adc_pin(void){
    return QF_ADC_PIN;
}

u16 get_max_adc_val(void){
    return MAX_ADC_QF;
}

void process_handle_wk_event(void) {

    const uint32_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
    const uint32_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;


    handle_wk_event(HAND_WIRE_DETECT,
        MATRIX_ROWS,MATRIX_COLS,
        row_pins,col_pins);

}

extern void matrix_scan_user_qf(void);
void matrix_scan_user(void) {
    matrix_scan_user_qf();
}
extern void post_process_record_user_qf(uint16_t keycode, keyrecord_t *record);
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
   post_process_record_user_qf(keycode, record);
}
extern bool process_record_user_qf(uint16_t keycode, keyrecord_t *record);
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    return process_record_user_qf(keycode, record);
}
extern void board_init_qf(void);
void board_init(void) {
    board_init_qf();
}


// 全局变量定义
rgb_led_t custom_led[RGBLED_NUM];
int led_count_qf = RGBLED_NUM;

pin_t WK_PIN_API = WK_PIN;
int RGBLED_NUM_API = RGBLED_NUM;

#if defined (POWER_LED)
    pin_t POWER_LED_API = POWER_LED;
#endif


u16 MAX_ADC_QF_API = MAX_ADC_QF;
pin_t QF_ADC_PIN_API = QF_ADC_PIN;
pin_t HAND_WIRE_DETECT_API = HAND_WIRE_DETECT;
pin_t LED_CAPS_LOCK_PIN_API = LED_CAPS_LOCK_PIN;
pin_t USB_PIN_LED_API = USB_PIN_LED;


pin_t POWER_PIN_API = POWER_PIN;

int CAPS_LED_INDEX_API = CAPS_LED_INDEX;
