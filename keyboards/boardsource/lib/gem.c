#include "gem.h"

#define FRAME_DURATION 20

uint32_t timer = 0;
uint8_t current_frame = 0;

static void render_animation(void) {
    if (timer_elapsed(timer) > FRAME_DURATION) {
        timer = timer_read();

        current_frame = (current_frame + 1) % (sizeof(frames) / sizeof(frames[0]));

        oled_write_raw_P(frames[current_frame], frames_sizes[current_frame]);
    }
}

