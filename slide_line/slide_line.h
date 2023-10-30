#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

#define LINE_SIZE 32
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int slide_right(int *line, size_t size);
int slide_left(int *line, size_t size);
int reorder(int *line, size_t size, int direction);

#endif
