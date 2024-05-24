#include <stddef.h>

#ifndef PLUG_H
#define PLUG_H

// NOTE:
// void (*foo)(void)= NULL; is variable point to a function.
// void (foo)(void); is a normal variable.

void (*plug_init)(void) = NULL;
void *(*plug_pre_reload)(void) = NULL;
void (*plug_post_reload)(void*) = NULL;
void (*plug_update)(void) = NULL;

#endif // PLUG_H
