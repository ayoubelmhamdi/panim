#include <stdio.h>

#define NOB_IMPLEMENTATION
#include "nob.h"

void cc(Nob_Cmd *cmd){
    nob_cmd_append(cmd, "cc");
    nob_cmd_append(cmd, "-Wall", "-Wextra", "-ggdb");
    nob_cmd_append(cmd, "-I", "./include");
}


void libs(Nob_Cmd *cmd){
    nob_cmd_append(cmd, "-Wl,-rpath=./lib");
    nob_cmd_append(cmd, "-Wl,-rpath=./");
    nob_cmd_append(cmd, "-L", "./lib");
    nob_cmd_append(cmd, "-l:libraylib.so");
    nob_cmd_append(cmd, "-lm");
}


bool build_plug(Nob_Cmd *cmd){
    cmd->count = 0;
    cc(cmd);
    nob_cmd_append(cmd, "-fPIC", "-shared");
    nob_cmd_append(cmd, "-o", "libplug.so");
    nob_cmd_append(cmd, "plug.c");
    libs(cmd);

    return nob_cmd_run_sync(*cmd);
}

bool build_main(Nob_Cmd *cmd){
    cc(cmd);
    nob_cmd_append(cmd, "-o", "panim");
    nob_cmd_append(cmd, "panim.c");
    libs(cmd);

    return nob_cmd_run_sync(*cmd);
}


int main(int argc, char **argv){
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};

    if (!build_main(&cmd)){
        printf("Failed to build panim\n");
        return 1;
    }

    if (!build_plug(&cmd)){
        printf("Failed to build plug.so\n");
        return 1;
    }
    return 0;
}
