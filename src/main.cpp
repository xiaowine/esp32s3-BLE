#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "MusicUI.h"

#define DRAW_BUF_SIZE (TFT_WIDTH * TFT_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
#define MAIN_COLOR 0x00BFFF // 示例颜色值
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

lv_obj_t *init_page_scr;

void setup()
{
  Serial.begin(115200);
  lv_init();
  LV_FONT_DECLARE(lv_font_montserrat_40);

  lv_display_t *display = lv_tft_espi_create(TFT_HEIGHT, TFT_WIDTH, draw_buf, sizeof(draw_buf));
  lv_theme_t *th = lv_theme_default_init(display, lv_color_hex(0x00BFFF), lv_color_hex(0x87CEEB), false, &lv_font_montserrat_40);
  lv_disp_set_theme(display, th);

  init_page_scr = lv_obj_create(NULL);

  create_music_ui(init_page_scr);

  lv_scr_load(init_page_scr);
}

void loop()
{
  lv_task_handler(); // Ensure this is called
  delay(5);
  lv_tick_inc(5);
}