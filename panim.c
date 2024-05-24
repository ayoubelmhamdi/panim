#include <stdio.h>
#include "raylib.h"
#include "plug.h"
#include <dlfcn.h>

int main(int agrc, char **argv) {
    if (agrc != 2) {
        fprintf(stderr, "Usage: %s <libplug.so>\n", argv[0]);
        return 1;
    }
    // const char *libplug_path = "libplug.so";
    const char *libplug_path = argv[1];
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
        plug_update();
    }
    return 0;
}
