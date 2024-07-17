
#include QMK_KEYBOARD_H
#include "qf_custom_animation.h"

// #include "progmem.h"
#include <stdint.h>
#include "ws2812.h"
#include "progmem.h"

const uint8_t custom_rgblight_effect_breathe_table[] PROGMEM = {
    0x22,
    0x33,
    0x44,
    0x55,
    0x66,
    0x77,
    0x88,
    0x99,
    0xaa,
    0xbb,
    0xcc,
    0xdd,
    0xee,
    0xff,
    0xff,
    0xff,
    0xff,
    0xee,
    0xdd,
    0xcc,
    0xbb,
    0xaa,
    0x99,
    0x88,
    0x77,
    0x66,
    0x55,
    0x44,
    0x33,
    0x22,
};


typedef struct
{
    bool playing;
    uint8_t light_index;
    color_enum color_index;
    uint8_t ticks_per_round;    //
    uint16_t all_ticks;          // % round count
    uint16_t tick_idx;
    uint16_t tick_wait;
    bool reset_when_done;
} ks_anmation_config;

ks_anmation_config custom_config;
// #define RGBLED_NUM 64// undershoots 3 leds, bad timings probably
rgb_led_t custom_led[RGBLED_NUM];

void clear_old_effect()
{
  for (uint8_t i = 0; i < RGBLED_NUM; i++) {
    custom_led[i].r = 0;
    custom_led[i].g = 0;
    custom_led[i].b = 0;
  }

  #ifdef RGB_MATRIX_ENABLE
  ws2812_setleds(custom_led, RGBLED_NUM);
  #endif
}

void rgb_power_enable(bool enable);

void blink_qf_animation_color_init(uint8_t light_index, color_enum color_index)
{
  clear_old_effect();
  rgb_power_enable(true);
  // rgblight_timer_disable();
  custom_config.playing = true;
  custom_config.ticks_per_round    = sizeof(custom_rgblight_effect_breathe_table);
  custom_config.all_ticks         = custom_config.ticks_per_round * 3;
  custom_config.tick_idx          = 0;
  custom_config.light_index              = light_index;
  custom_config.color_index       = color_index;
  custom_config.reset_when_done = false;
  custom_config.tick_wait = 16;
}


void qf_low_power_animation(){
  rgb_power_enable(true);
  // rgblight_timer_disable();
  custom_config.playing = true;
  custom_config.ticks_per_round    = sizeof(custom_rgblight_effect_breathe_table);
  custom_config.all_ticks         = custom_config.ticks_per_round * 10;
  custom_config.tick_idx          = 0;
  custom_config.light_index              = 0;
  custom_config.reset_when_done = false;
}


void __single_blink_animation_func(uint8_t idx);
void __whole_board_breath_func(void);
void __battery_indication_func(void);

// extern rgblight_config_t rgblight_config;
uint32_t cacount=0;
void custom_animation_task(void){

  if (!custom_config.playing) {
     return ;
  }

    cacount++;
    if(cacount > 100000){
        cacount=0;
    }
    // xprintf("custom_config.tick_idx  is %d!!\n",custom_config.tick_idx);
    //  xprintf("custom_config.all_ticks  is %d!!\n",custom_config.all_ticks);
    //  xprintf("custom_config.color_index  is %d!!\n",custom_config.color_index);
  if (custom_config.tick_idx >= custom_config.all_ticks){
    if (custom_config.reset_when_done) {
      return ;
    }

    cacount=0;
       clear_old_effect();
        rgb_power_enable(false);
      custom_config.playing = false;
      custom_config.tick_idx = 0;
      // uint8_t new_mode = rgblight_get_mode();
      // rgblight_mode_noeeprom(new_mode);
      return ;
  }
   // __single_blink_animation_func(custom_config.type);
    blink_animation(custom_config.light_index,custom_config.color_index);
     if(cacount % custom_config.tick_wait ==0){
        custom_config.tick_idx++;
    }


}


void blink_animation(uint8_t idx,color_enum enum_color){

    if(enum_color == red_qf_color){
        custom_led[idx].r = custom_rgblight_effect_breathe_table[custom_config.tick_idx % custom_config.ticks_per_round];
    }
    if(enum_color == green_qf_color){
        custom_led[idx].g = custom_rgblight_effect_breathe_table[custom_config.tick_idx % custom_config.ticks_per_round];
    }
    if(enum_color == blue_qf_color){
        custom_led[idx].b = custom_rgblight_effect_breathe_table[custom_config.tick_idx % custom_config.ticks_per_round];
    }
    #ifdef RGB_MATRIX_ENABLE
    ws2812_setleds(custom_led, RGBLED_NUM);
    #endif
}

void __whole_board_breath_func(void)
{
    for (uint8_t i = 0; i < RGBLED_NUM; i++) {
      custom_led[i].r = custom_rgblight_effect_breathe_table[custom_config.tick_idx % custom_config.ticks_per_round];
      custom_led[i].g = 0;
      custom_led[i].b = 0;
    }
    ws2812_setleds(custom_led, RGBLED_NUM);
}

void __battery_indication_func(void){

    // if(custom_config.playing == true){
    //     return;
    // }

     // clear_old_effect();
  rgb_power_enable(true);
  // rgblight_timer_disable();
  custom_config.playing = true;
  custom_config.ticks_per_round   = 1;
  custom_config.all_ticks         = custom_config.ticks_per_round * 3;
  custom_config.tick_idx          = 0;
  custom_config.light_index       = 0;
  custom_config.color_index       = red_qf_color;
  custom_config.reset_when_done = false;
  custom_config.tick_wait = 3000;
}



#include "ch.h"
#include "hal.h"

#include "chprintf.h"

extern void chThdExit(msg_t msg);
#define LED_PIN PAL_LINE(GPIOB, 8)
#define BLINK_INTERVAL_MS 40

#include "actionuart.h"
static THD_WORKING_AREA(blink_led_thread_wa, 128);
static THD_FUNCTION(blink_led_thread, arg) {
    (void)arg;
    // uint8_t ledS = 0;
    while (!chThdShouldTerminateX()) { // 检查线程是否应该终止
         palToggleLine(LED_PIN); // 切换 LED 状态
        chThdSleepMilliseconds(BLINK_INTERVAL_MS); // 等待指定的时间间隔
    }

    if(where_to_send() == OUTPUT_USB){
         writePinHigh(USB_PIN_LED);
    }

    chThdExit(0); // 退出线程
}

static thread_t *blink_led_thread_ptr = NULL;


void qf_blink_led_start(void) {

    if (blink_led_thread_ptr == NULL) {
             xprintf(" 222222 on \n");
        blink_led_thread_ptr = chThdCreateStatic(blink_led_thread_wa, sizeof(blink_led_thread_wa), HIGHPRIO, blink_led_thread, NULL); // 创建 blink 线程
    }
}

// #define CH_CFG_USE_WAITEXIT
void qf_blink_led_stop(void) {
    if (blink_led_thread_ptr != NULL) {
        chThdTerminate(blink_led_thread_ptr); // 终止 blink 线程
       // chThdWait(blink_led_thread_ptr); // 等待线程退出
       xprintf(" quit on \n");
        blink_led_thread_ptr = NULL;
    }
}
