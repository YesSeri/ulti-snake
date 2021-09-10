#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define __USE_POSIX199309
#define _POSIX_C_SOURCE 199309L
#define SIZE 15

int nanosleep(const struct timespec *req, struct timespec *rem);
void update();
void paint();
void set_food();
void sleep_us(unsigned long microseconds);

int main()
{
    // False means no food.
    bool board[SIZE][SIZE] = { false };
    paint(board);
    set_food(1, 8, board);
    paint(board);

    // for (;;) {
    //     printf("aaa\n");
    //     update();
    //     paint();
    //     sleep_ms(1000);
    // }
    return 0;
}
void set_food(int x, int y, bool board[SIZE][SIZE]){
    board[y][x] = true;
}
void update()
{
}
void paint(bool boardp[SIZE][SIZE])
{
    for(int x = 0; x < SIZE; x++){
        for(int y = 0; y < SIZE; y++){
            printf(boardp[y][x] ? "*" : "-");
        }
        printf("\n");
    }
    printf("\n");
}
void sleep_ms(unsigned long millis)
{
    unsigned long microseconds = millis * 1000;
    struct timespec ts;
    ts.tv_sec = microseconds / 1000000; // whole seconds
    ts.tv_nsec = (microseconds % 1000000) * 1000; // remainder, in nanoseconds
    nanosleep(&ts, NULL);
}
