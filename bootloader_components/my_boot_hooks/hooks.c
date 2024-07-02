#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

/* Function used to tell the linker to include this file
 * with all its symbols.
 */

void read_sram_before_init(void);

void bootloader_hooks_include(void)
{
}

void bootloader_before_init(void)
{
    /* Keep in my mind that a lot of functions cannot be called from here
     * as system initialization has not been performed yet, including
     * BSS, SPI flash, or memory protection. */
    ESP_LOGI("HOOK", "This hook is called BEFORE bootloader initialization");
    read_sram_before_init();
}

void bootloader_after_init(void)
{
    ESP_LOGI("HOOK", "This hook is called AFTER bootloader initialization");
}

void read_sram_before_init(void)
{
    uint32_t *sram_start = (uint32_t *)0x3FC88000;                        // 0x3FC88000; // SRAM start address for ESP32-S3
    uint32_t sram_size = 0x20000;                                         // 128 KB
    uint32_t *sram_end = (uint32_t *)((uint8_t *)sram_start + sram_size); // end address based on size
    uint32_t read_count = 10;                                             // Read only the first 10 addresses

    ESP_LOGI("TAG", "Reading first 10 SRAM addresses before initialization:");
    for (uint32_t i = 0; i < read_count; i++)
    {
        uint32_t *addr = sram_start + i;
        ESP_LOGI("TAG", "SRAM[0x%08X] = 0x%08X", (uint32_t)addr, *addr);
    }
}
