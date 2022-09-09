#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;
void clear(char *);
char **conact(char *, int *);
void exece(char **);
void free_grid(char **);
char  *trim(char *);
#endif
