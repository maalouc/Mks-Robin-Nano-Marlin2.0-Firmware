/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * @file tft_lvgl_configuration.h
 * @date    2020-02-21
 * */

//#ifdef __cplusplus
//extern "C" {
//#endif

#include <lvgl.h>

#define LV_USE_ROTATION_180     0
#define USE_WIFI_FUNCTION		1

void tft_lvgl_init();
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
bool my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data);
bool my_mousewheel_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

void LCD_Clear(uint16_t Color);
void tft_set_point(uint16_t x, uint16_t y, uint16_t point);
void ili9320_SetWindows(uint16_t StartX, uint16_t StartY, uint16_t width, uint16_t heigh);
void LCD_WriteRAM_Prepare(void);
void lv_encoder_pin_init();
void lv_update_encoder();

lv_fs_res_t spi_flash_open_cb (lv_fs_drv_t * drv, void * file_p, const char * path, lv_fs_mode_t mode);
lv_fs_res_t spi_flash_close_cb (lv_fs_drv_t * drv, void * file_p);
lv_fs_res_t spi_flash_read_cb (lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br);
lv_fs_res_t spi_flash_seek_cb(lv_fs_drv_t * drv, void * file_p, uint32_t pos);
lv_fs_res_t spi_flash_tell_cb(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p);

lv_fs_res_t sd_open_cb (lv_fs_drv_t * drv, void * file_p, const char * path, lv_fs_mode_t mode);
lv_fs_res_t sd_close_cb (lv_fs_drv_t * drv, void * file_p);
lv_fs_res_t sd_read_cb (lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br);
lv_fs_res_t sd_seek_cb(lv_fs_drv_t * drv, void * file_p, uint32_t pos);
lv_fs_res_t sd_tell_cb(lv_fs_drv_t * drv, void * file_p, uint32_t * pos_p);

//#ifdef __cplusplus
//} /* extern "C" */
//#endif
