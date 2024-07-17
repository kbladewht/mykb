
#pragma once
#include QMK_KEYBOARD_H
#include "hal_pal.h"
#include "powermstop.h"
#include "outputselect.h"
#include "uart.h"
#include "pivot.h"

#define SLEEPCODE 0x02
#define PAIRCODE 0x03

#define UNPAIRCODE 0x04
#define RESET_CODE 0x05
#define ADC_DISPALY_CODE 0x06


#define CHANNAL_001 0x07
#define CHANNAL_002 0x08
#define CHANNAL_003 0x09
#define CHANNAL_RADIO 0x0A
#define MUL_MEDIA 0x0B
#define KB_SYSTEM 0x0C

#define KB_BATTERY 0x0D
#define KB_DFU 0x0E


#define SHOWUP_CHANNEL_LED 0x10

void show_adc_power(uint8_t f[]);
void uartSendByAction(uint8_t actionCode);

void go_bl_dfu(void);
void pair_blueMode(void);
void unpair_current_BLE(void);
void reset_current_BLE(void);
void flyInit(void);
void writeHighPinOut(pin_t pin);
void switch_cols_gpio_from_3V(pin_t pin);

void writeLowPinOut(pin_t pin);
void showPerChannel2(void);
void bluetooth_switch_one(int swc);

void channel_common(uint8_t ee);

void turn_on_led(pin_t pin);
void turn_off_led(pin_t pin);
void flyInit(void);

void turn_on_led_OD(pin_t pin);
void writeHighPinOutOD(pin_t pin);

void writeLowPinOutOD(pin_t pin);
void rgb_power_enable(bool enable);
uint8_t read_handwire_detect(void);
void setDetectPinOutput(void);

void setWKPin_high(void);
void setWKPin_low(void);

uint8_t readWKPin(void);
void turnOFF_usb_led(void);
void turnoff_power_led(void);
void turnon_power_led(void);
void turnoff_caps_led(void);
void turn_adc_off(void);
void process_handle_wk_event(void);
void handle_wk_event(pin_t wireDetectStatus,uint8_t rows, uint8_t cols,
                const uint32_t *row_pins,const uint32_t *col_pins);
pin_t get_adc_pin(void);
u16 get_max_adc_val(void);
