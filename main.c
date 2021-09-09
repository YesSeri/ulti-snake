#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define __USE_POSIX199309
#define _POSIX_C_SOURCE 199309L
#define SIZE 15
void update();
void paint();
void sleep_us(unsigned long microseconds);

int main()
{
    // False means no food.
    bool arr[SIZE][SIZE] = { false };

    // for (;;) {
    //     printf("aaa\n");
    //     update();
    //     paint();
    //     sleep_ms(1000);
    // }
    return 0;
}
void update()
{
}
void paint()
{
}
void sleep_ms(unsigned long millis)
{
    unsigned long microseconds = millis * 1000;
    struct timespec ts;
    ts.tv_sec = microseconds / 1000000; // whole seconds
    ts.tv_nsec = (microseconds % 1000000) * 1000; // remainder, in nanoseconds
    nanosleep(&ts, NULL);
}