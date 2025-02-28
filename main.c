#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "__fc_builtin.h"

// Init array
void gen_arr(int arr[], unsigned size) {
  for (unsigned i = 0; i < size; ++i)
    arr[i] = i;
}

void func(unsigned x, unsigned size, int arr[]) {
  unsigned index = 0;

  for (unsigned i = 0; i < x; i++) {
    // Random branch on each iteration
    if (rand() % 2 == 0) {
      index += 1;
    } else {
      index += 2;
    }
    // index++;
  }

  // Crash depending on index after the loop
  // assert(index < size);
  // Access index
  arr[index] = 37;
}

int main() {
  unsigned x = Frama_C_interval(1, 99);

  unsigned size = 200;
  int arr[size];
  gen_arr(arr, size);

  func(x, size, arr);

  return 0;
}

/*  requires x > 0 && x < size;
    requires size > 0;
    requires \valid(arr+(0..size-1));
*/
