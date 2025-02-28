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

  printf("x = %d\n", x);

  if (x < 100000) {
    //abort();
    assert(x != 12345);
  }

  return 0;
}
