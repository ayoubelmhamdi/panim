#include <stdio.h>
#include "raylib.h"
#include "plug.h"
#include <dlfcn.h>

void *libplug = NULL;

bool reload_libplug(const char *libplug_path) {
    if (libplug != NULL) {
        dlclose(libplug);
    
    }

    libplug = dlopen(libplug_path, RTLD_NOW);
    if (libplug == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return false; 
    }

    plug_init = dlsym(libplug, "plug_init");
    if (plug_init == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return false; 
    }

    plug_pre_reload = dlsym(libplug, "plug_pre_reload");
    if (plug_pre_reload == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return false; 
    }

    plug_post_reload = dlsym(libplug, "plug_post_reload");
    if (plug_post_reload == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return false; 
    }

    plug_update = dlsym(libplug, "plug_update");
    if (plug_update == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return false; 
    }

    return true;
}


int main(int agrc, char **argv) {
    if (agrc != 2) {
        fprintf(stderr, "Usage: %s <libplug.so>\n", argv[0]);
        return 1;
    }
    // const char *libplug_path = "libplug.so";
    const char *libplug_path = argv[1];
    if (!reload_libplug(libplug_path)){
        fprintf(stderr, "Can not load %s\n", libplug_path);
        return 1;
    }


    plug_init();

    InitWindow(800, 450, "Panim2");
    while (!WindowShouldClose()){
        if (IsKeyPressed(KEY_R)) {
            void *state = plug_pre_reload();
            if(!reload_libplug(libplug_path)){
                fprintf(stderr, "Can not reloaded %s\n", libplug_path);
                return 1;
            }
            plug_post_reload(state);
        
        }
        plug_update();
    }
    return 0;
}
