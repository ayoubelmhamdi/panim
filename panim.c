#include <stdio.h>
#include "raylib.h"
#include "plug.h"
#include <dlfcn.h>

int main(void){
    const char *libplug_path = "libplug.so";
    void *libplug = dlopen(libplug_path, RTLD_NOW);
    if (libplug == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plug_init = dlsym(libplug, "plug_init");
    if (plug_init == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plug_pre_reload = dlsym(libplug, "plug_pre_reload");
    if (plug_pre_reload == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plug_post_reload = dlsym(libplug, "plug_post_reload");
    if (plug_post_reload == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plug_update = dlsym(libplug, "plug_update");
    if (plug_update == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }


    plug_init();

    InitWindow(800, 450, "Panim2");
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(400, 225, 50, RED);
        DrawCircle(400, 325, 50, RED);
        EndDrawing();
    }
    return 0;
}
