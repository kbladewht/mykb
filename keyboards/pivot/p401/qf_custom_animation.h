#include <stdbool.h>
#include <stdint.h>
typedef enum
{
    red_qf_color=0,
    green_qf_color=1,
    blue_qf_color=2
} color_enum;
// fixme should write to register mode
// need refraction


void qf_low_power_animation(void);

// task method
bool qf_custom_animation_task(void);

void clear_old_effect(void);
// test only
void qf_battery_indication(uint8_t percentage);

void custom_animation_task(void);

void blink_animation(uint8_t idx,uint8_t enum_color);
void blink_qf_animation_color_init(uint8_t light_index, color_enum color_index);
void __battery_indication_func(void);
