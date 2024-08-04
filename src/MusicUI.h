#ifndef MUSIC_UI_H
#define MUSIC_UI_H

#include <lvgl.h>

extern lv_style_t title_style, author_style, lyric_style;

void create_music_ui(lv_obj_t *parent);
void update_title_text(const char *text);
void update_author_text(const char *text);
void update_lyric_text(const char *text);

#endif // MUSIC_UI_H