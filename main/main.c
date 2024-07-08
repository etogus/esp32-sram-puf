#include <stdint.h>
#include "esp_log.h"

void hex_to_binary(uint32_t hex_value)
{
    char binary_str[33];
    binary_str[32] = '\0'; // Null-terminate the string

    for (int i = 31; i >= 0; i--)
    {
        binary_str[i] = (hex_value & 1) ? '1' : '0';
        hex_value >>= 1;
    }

    ESP_LOGI("AFTER", "Binary: %s", binary_str);
}

void read_sram_after_init(void)
{
    uint32_t *sram_start = (uint32_t *)0x3FC88000;                        // 0x3FC88000; // SRAM start address for ESP32-S3
    uint32_t sram_size = 0x20000;                                         // 128 KB
    uint32_t *sram_end = (uint32_t *)((uint8_t *)sram_start + sram_size); // end address based on size
    uint32_t read_count = 10;                                             // Read only the first 10 addresses

    ESP_EARLY_LOGI("TAG", "Reading first 10 SRAM addresses after initialization:");
    for (uint32_t i = 0; i < read_count; i++)
    {
        uint32_t *addr = sram_start + i;
        ESP_EARLY_LOGI("AFTER", "SRAM[0x%08X] = 0x%08X", (uint32_t)addr, *addr);
        hex_to_binary(*addr);
    }
}

void app_main()
{
    read_sram_after_init();
}