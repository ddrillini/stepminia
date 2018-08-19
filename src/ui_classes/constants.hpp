#pragma once

#define ARROW_SIZE 64
#define LEFT 0
#define DOWN 1
#define UP 2
#define RIGHT 3

#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640

// need to be wrapped in parens in case of order of operation issues
#define WINDOW_Y_CENTER (WINDOW_HEIGHT / 2)
#define WINDOW_X_CENTER (WINDOW_WIDTH / 2)

#define LEFT_ARROW_OFFSET (WINDOW_X_CENTER - 96)
#define DOWN_ARROW_OFFSET (WINDOW_X_CENTER - 32)
#define UP_ARROW_OFFSET   (WINDOW_X_CENTER + 32)
#define RIGHT_ARROW_OFFSET (WINDOW_X_CENTER + 96)

#define OFFSET_FROM_TOP_OF_SCREEN 32

#define SPEEDMOD 100

