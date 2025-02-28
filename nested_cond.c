#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

//#include "__fc_builtin.h"

int main(int argc, char *argv[]) {
  int x;
  scanf("%d", &x);
//  x = Frama_C_interval(200, INT_MAX);
//  x = Frama_C_interval(100, INT_MAX);

  if (x < 100) {
    if (argc != 2)
      return 1;
    assert(strcmp(argv[1], "123") != 0);
  }

  return 0;
}
