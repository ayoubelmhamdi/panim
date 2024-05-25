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
    // Get screen dimensions
    const float h = GetScreenHeight();
    const float w = GetScreenWidth();


    // Calculate padding and box dimensions
    const float pv = h * 0.01f;
    const float ph = w * 0.01f;
    const float bw = (w - 3*ph) * 0.5f;
    const float bh = h - 2 * pv;

    // Calculate box positions
    const Rectangle r1 = { ph, pv, bw, bh };
    const Rectangle r2 = { 2*ph + bw, pv, bw, bh };

    // Begin drawing
    BeginDrawing();
    ClearBackground(GetColor(0x181818FF));

    // Draw boxes
    DrawRectangleRec(r2, BLUE);
    DrawRectangleRec(r1, RED);

    // Draw ultra shot (if applicable)
    if (IsKeyPressed(KEY_SPACE)) {
        const Vector2 u1 = {r1.x + r1.width, r1.y + r1.height * 0.5f};
        const Vector2 u2 = {r2.x, r2.y + r2.height * 0.5f};
        DrawLineEx(u1, u2, 5.0f, YELLOW);
    }

    EndDrawing();
}
