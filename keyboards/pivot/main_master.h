#include <ch.h>
#include <hal.h>
#include <string.h>
#include "report.h"
#include "quantum_keycodes.h"


typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;



enum custom_keycodes {
    KC_BLE_1= QK_KB_0,
    KC_BLE_2,
    KC_BLE_3,
    KC_24_G,
    KC_BLE_DEL,
    KC_BL_DFU,
    KC_LOCK_KB,
    KC_ADC_RGB_SHOW,
};

enum my_keycodes {
  NKRO_GO = SAFE_RANGE,
  SIX_KEY_GO,
  MANU_MODE,
  DFU_QF
};


typedef enum {
  SEND_MODE_USB = 0,
  SEND_MODE_UART = 1
} SEND_MODE;

typedef enum  {
  CONNECTION_TYPE_USB = SEND_MODE_USB,
  CONNECTION_TYPE_UART = SEND_MODE_UART,
} CONNECTION_TYPE;

#define VIAL_RESET     KC_F16  // reset usb

#define BL_SW_1     KC_BLE_1
#define BL_SW_2     KC_BLE_2
#define BL_SW_3     KC_BLE_3  // RADIO
#define RADIO     KC_24_G  // RADIO

#define BLE_DEL     KC_BLE_DEL
#define BL_DFU     KC_BL_DFU  //
#define KB_LOCK     KC_LOCK_KB  // lock keyboard
#define BAU_TOG     KC_F17
#define NKRO_GO     KC_F14  // GO NKRO
#define SIX_KEY_GO     KC_F15  // GO 6KEY
#define ADC_RGB_SHOW     KC_ADC_RGB_SHOW  // GO 6KEY


void send_keyboard_qf(report_keyboard_t *report);
void send_keyboard(report_keyboard_t *report);
void send_extra_qf(report_extra_t *report) ;
void send_extra(report_extra_t *report) ;

void send_consumer_qf(uint16_t report);
void send_consumer(uint16_t report);
void send_system_qf(uint16_t report) ;
void send_system(uint16_t report) ;

void send_battery(u8 report);

enum QF_MACRO{
    QF_MACRO_MODE_ON=SAFE_RANGE,
    QF_MACRO_OFF_AND_WRITE1,//239987=0x5db3
    QF_MACRO_OFF_AND_WRITE2,//239988=0x5db4
    QF_MACRO_SHOW_MEMORY,//239989=0x5db5
    QF_MACRO_SEND_M1,// 239990=0x5db6
    QF_MACRO_SEND_M2,// 239991=0x5db7
};

#define MACAO_MODE_RECORDING  0   //start recording
#define MACAO_MODE_M1  1   //first MACAO mode
#define MACAO_MODE_M2  2   //second MACAO mode
#define MACAO_MODE_M3  3   //third MACAO mode
#define MACAO_MODE_OFF  99  //off
