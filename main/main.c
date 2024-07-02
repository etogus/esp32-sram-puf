#include <string.h>
#include <stdint.h>
#include "sdkconfig.h"
#include "esp_attr.h"
#include "esp_log.h"
// #include "bootloader_init.h"
#include "bootloader_flash_priv.h"
#include "bootloader_flash_config.h"
#include "bootloader_random.h"
#include "bootloader_clock.h"
#include "bootloader_common.h"
#include "esp_flash_encrypt.h"
#include "esp_cpu.h"
#include "soc/rtc.h"
#include "hal/wdt_hal.h"
#include "hal/efuse_hal.h"
#include "esp_bootloader_desc.h"

static const char *TAG = "boot";
esp_image_header_t WORD_ALIGNED_ATTR bootloader_image_hdr;

// This attribute tells the compiler to place the read_sram_before_init function in a specific section of the compiled binary, named .init.
// void read_sram_before_init(void) __attribute__((section(".init")));

void read_sram_before_init(void)
{
    uint32_t *sram_start = (uint32_t *)0x3FC88000;                        // 0x3FC88000; // SRAM start address for ESP32-S3
    uint32_t sram_size = 0x20000;                                         // 128 KB
    uint32_t *sram_end = (uint32_t *)((uint8_t *)sram_start + sram_size); // end address based on size
    uint32_t read_count = 50;                                             // Read only the first 10 addresses

    ESP_EARLY_LOGI(TAG, "Reading first 10 SRAM addresses before initialization:");
    for (uint32_t i = 0; i < read_count; i++)
    {
        uint32_t *addr = sram_start + i;
        ESP_EARLY_LOGI(TAG, "SRAM[0x%08X] = 0x%08X", (uint32_t)addr, *addr);
    }

    // ESP_EARLY_LOGI(TAG, "Reading SRAM content before initialization:");
    // for (uint32_t *addr = sram_start; addr < sram_end; addr++)
    // {
    //     ESP_EARLY_LOGI(TAG, "SRAM[0x%08X] = 0x%08X", (uint32_t)addr, *addr);
    // }
}

void read_sram_after_init(void)
{
    uint32_t *sram_start = (uint32_t *)0x3FC88000;                        // 0x3FC88000; // SRAM start address for ESP32-S3
    uint32_t sram_size = 0x20000;                                         // 128 KB
    uint32_t *sram_end = (uint32_t *)((uint8_t *)sram_start + sram_size); // end address based on size
    uint32_t read_count = 10;                                             // Read only the first 10 addresses

    ESP_EARLY_LOGI(TAG, "Reading first 10 SRAM addresses after initialization:");
    for (uint32_t i = 0; i < read_count; i++)
    {
        uint32_t *addr = sram_start + i;
        ESP_EARLY_LOGI(TAG, "SRAM[0x%08X] = 0x%08X", (uint32_t)addr, *addr);
    }

    // ESP_EARLY_LOGI(TAG, "Reading SRAM content after initialization:");
    // for (uint32_t *addr = sram_start; addr < sram_end; addr++)
    // {
    //     ESP_EARLY_LOGI(TAG, "SRAM[0x%08X] = 0x%08X", (uint32_t)addr, *addr);
    // }
}

// void bootloader_clear_bss_section(void)
// {
//     memset(&_bss_start, 0, (&_bss_end - &_bss_start) * sizeof(_bss_start));
// }

// esp_err_t bootloader_read_bootloader_header(void)
// {
//     if (bootloader_flash_read(ESP_BOOTLOADER_OFFSET, &bootloader_image_hdr, sizeof(esp_image_header_t), true) != ESP_OK)
//     {
//         ESP_EARLY_LOGE(TAG, "failed to load bootloader image header!");
//         return ESP_FAIL;
//     }
//     return ESP_OK;
// }

void app_main()
{
    // read_sram_before_init();

    read_sram_after_init();
}