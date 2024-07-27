#include "mk45.h"
#include "bootmagic.h"


void bootmagic_scan(void) {
    // We need multiple scans because debouncing can't be turned off.
    // matrix_scan();
    // wait_ms(BOOTMAGIC_DEBOUNCE);
    // matrix_scan();

    // if (bootmagic_should_reset()) {
    //     bootmagic_reset_eeprom();

    //     // Jump to bootloader.
    //     bootloader_jump();
    // }
}
