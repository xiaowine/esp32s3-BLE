#include "MusicUI.h"

lv_style_t title_style, author_style, lyric_style;
lv_obj_t *title, *author, *lyric;

void create_music_ui(lv_obj_t *parent)
{
  lv_style_init(&title_style);
  lv_style_set_text_font(&title_style, &lv_font_montserrat_40);
  lv_style_set_bg_color(&title_style, lv_color_hex(0x00BFFF));
  lv_style_set_text_align(&title_style, LV_TEXT_ALIGN_CENTER);
  lv_style_set_text_color(&title_style, lv_color_hex(0x00BFFF));
  lv_style_set_bg_opa(&title_style, LV_OPA_COVER);

  title = lv_label_create(parent);
  lv_obj_add_style(title, &title_style, LV_PART_MAIN);
  lv_label_set_long_mode(title, LV_LABEL_LONG_WRAP);
  lv_label_set_text(title, "天111下");
  lv_obj_set_width(title, 150);
  lv_obj_align(title, LV_ALIGN_CENTER, -70, -85);

  lv_style_init(&author_style);
  lv_style_set_text_font(&author_style, &lv_font_montserrat_16);
  lv_style_set_bg_color(&author_style, lv_color_hex(0x00BFFF));
  lv_style_set_text_align(&author_style, LV_TEXT_ALIGN_CENTER);
  lv_style_set_bg_opa(&author_style, LV_OPA_COVER);

  author = lv_label_create(parent);
  lv_obj_add_style(author, &author_style, LV_PART_MAIN);
  lv_label_set_long_mode(author, LV_LABEL_LONG_SCROLL);
  lv_label_set_text(author, "Author");
  lv_obj_set_width(author, 100);
  lv_obj_align(author, LV_ALIGN_CENTER, -70, -55);

  lv_style_init(&lyric_style);
  lv_style_set_text_font(&lyric_style, &lv_font_montserrat_28);
  lv_style_set_bg_color(&lyric_style, lv_color_hex(0x00BFFF));
  lv_style_set_text_align(&lyric_style, LV_TEXT_ALIGN_CENTER);
  lv_style_set_bg_opa(&lyric_style, LV_OPA_COVER);

  lyric = lv_label_create(parent);
  lv_obj_add_style(lyric, &lyric_style, LV_PART_MAIN);
  lv_label_set_long_mode(lyric, LV_LABEL_LONG_WRAP);
  lv_label_set_text(lyric, "Lyric Lyric Lyric Lyric Lyric");
  lv_obj_set_width(lyric, 150);
  lv_obj_align(lyric, LV_ALIGN_CENTER, -70, 10);

  lv_scr_load(parent);
}

void update_title_text(const char *text)
{
  lv_label_set_text(title, text);
}

void update_author_text(const char *text)
{
  lv_label_set_text(author, text);
}

void update_lyric_text(const char *text)
{
  lv_label_set_text(lyric, text);
}