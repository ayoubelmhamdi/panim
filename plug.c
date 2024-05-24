#include "raylib.h"
#include <stdlib.h>
#include <assert.h>

typedef struct {
    Color background;
} Plug;

static Plug *p = NULL;

void plug_init(void){
    p = (Plug *)malloc(sizeof(*p));
    assert(p != NULL);
}

void *plug_pre_reload(void){
    return p;
}
      
void plug_post_reload(void *state){
    p = state;
}

void plug_update(void*){
    BeginDrawing();
    ClearBackground(p->background);
    EndDrawing();
}

