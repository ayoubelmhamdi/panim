#include "raylib.h"
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
    Color background;
} Plug;

static Plug *p = NULL;

void plug_init(void){
    p = (Plug *)malloc(sizeof(*p));
    assert(p != NULL);
    memset(p, 0, sizeof(*p));
    p->background = RED;
    TraceLog(LOG_INFO, "----------------");
    TraceLog(LOG_INFO, "initialized plug");
    TraceLog(LOG_INFO, "----------------");
}

void *plug_pre_reload(void){
    return p;
}
      
void plug_post_reload(void *state){
    p = state;
}

void plug_update(void*){
    float h = GetScreenHeight();
    // float w = GetScreenWidth();
    // float dt = GetTime();

    float rw = 100;
    float rh = 100;
    float pad = rw*0.1;

    BeginDrawing();
    ClearBackground(GetColor(0x181818FF));
    for(size_t i = 0; i < 3; ++i){
        DrawRectangle(rw*i + i*pad, (h-rh)*0.5, rw, rw, YELLOW);
    }
    EndDrawing();
}

