#include <stdio.h>

int convert(int);

int
main(void) {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = upper;
  while(fahr >= lower) {
    celsius = convert(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr - step;
  }
}

int convert(int fahr) {
  float celsius;
  celsius = (5.0/9.0) * (fahr-32.0);
  return celsius;
}
