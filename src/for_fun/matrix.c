#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

void clear_screen(void) { printf("\033[H\033[J"); }

void print_green_character(void) {
  char characters[] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$\\|^&*"
      "()_+\";:?*~";

  int index = rand() % (sizeof(characters) - 1);
  printf("\033[38;5;82m%c\033[0m", characters[index]);
}

void matrix_effect(void) {
  while (1) {
    for (int y = 0; y < MAX_HEIGHT; y++) {
      for (int x = 0; x < MAX_WIDTH; x++) {
        print_green_character();
        printf("\t");
      }
      printf("\n");
    }

    usleep(100000);
  }
}

int main(void) {
  srand(time(0));

  matrix_effect();

  return 0;
}
