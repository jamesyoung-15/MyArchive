#ifndef UTILITY_H
#define UTILITY_H

// Our own simple implementation of a pseudo-random number generator, 
// for debugging and automated grading consistency.
static unsigned long rng_lab6 = 0;

static void _srand(unsigned seed) {
  rng_lab6 = seed;
}

static int _rand() {
  rng_lab6 = (1103515245 * rng_lab6 + 12345) % (1 << 31);
  return rng_lab6 & 0x7FFFFFFF;
}

#endif
