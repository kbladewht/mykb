#include QMK_KEYBOARD_H
#include "hal_pal.h"
#include "actionuart.h"
#include "uart.h"
#include "eeconfig.h"
#include "eeprom.h"
#include "analog_qf.h"
#define GPIO_PIN_INVALID -1 // 自定义无效引脚常量

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


void turnon_caps_led(void){
    #if defined(LED_CAPS_LOCK_PIN)
        turn_on_led(LED_CAPS_LOCK_PIN);
    #endif
}


void turnoff_caps_led(void){
    #if defined(LED_CAPS_LOCK_PIN)
        turn_off_led(LED_CAPS_LOCK_PIN);
    #endif
}

bool power_pin_enable(void){
    #if defined(POWER_PIN)
        return true;
    #else
        return false;
    #endif
}
bool caps_pin_enable(void){
    #if defined(LED_CAPS_LOCK_PIN)
        return true;
    #else
        return false;
    #endif
}
bool BLINK_BLE_LED_enable(void){
    #if defined(BLINK_BLE_LED)
        return true;
    #else
        return false;
    #endif
}

bool FN_BLE__RGB_LED_enable(void){
    #if defined(FN_BLE__RGB_LED)
        return true;
    #else
        return false;
    #endif
}

void setWKPin_high(void) {
      writeHighPinOut(WK_PIN);
}

uint8_t readWKPin(void) {
   return readPin(WK_PIN);
}

uint8_t useVBat(void) {

    #if defined (USE_VBAT)
        return 1;
     #else
        return 0;
     #endif

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

pin_t get_CHANNEL0_LED_PIN_pin(void){
    #ifdef CHANNEL0_LED_PIN
        return CHANNEL0_LED_PIN;
    #else
        return GPIO_PIN_INVALID;
    #endif
}

pin_t get_CHANNEL1_LED_PIN_pin(void){
    #ifdef CHANNEL1_LED_PIN
        return CHANNEL1_LED_PIN;
    #else
        return GPIO_PIN_INVALID;
    #endif
}

pin_t get_CHANNEL2_LED_PIN_pin(void){
    #ifdef CHANNEL2_LED_PIN
        return CHANNEL2_LED_PIN;
    #else
        return GPIO_PIN_INVALID;
    #endif
}

pin_t get_CHANNEL4_LED_PIN_pin(void){
    #ifdef CHANNEL4_LED_PIN
        return CHANNEL4_LED_PIN;
    #else
        return GPIO_PIN_INVALID;
    #endif
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

#if defined (POWER_LED)
    pin_t POWER_LED_API = POWER_LED;
#endif


u16 MAX_ADC_QF_API = MAX_ADC_QF;
pin_t QF_ADC_PIN_API = QF_ADC_PIN;
pin_t HAND_WIRE_DETECT_API = HAND_WIRE_DETECT;
pin_t USB_PIN_LED_API = USB_PIN_LED;
u16 MATRIX_ROWS_API = MATRIX_ROWS;
u16 MATRIX_COLS_API = MATRIX_COLS;
u16 RADIO_LED_INDEX_API = RADIO_LED_INDEX;
u16 RGBLED_NUM_API = RGBLED_NUM;
// pin_t LED_PIN_API = LED_PIN;

// pin_t POWER_PIN_API = POWER_PIN;

int CAPS_LED_INDEX_API = CAPS_LED_INDEX;
