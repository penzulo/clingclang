#include <stddef.h>
#include <stdint.h>

// 256 bytes is small enough for the stack, but large enough
// to minimize the number of memcpy calls for medium objects.
#define CHUNK_SIZE 256

void *memcopy(const void *restrict src, void *restrict dest, size_t n) {
  void *dptr = dest;
  const uint8_t *convsrc = (uint8_t *)src;
  uint8_t *convdest = (uint8_t *)dest;

  // Post-increment has higher precedence that dereference,
  // so this moves the pointers forward after assignment.
  // for (; n; *convdest++ = *convsrc++, n--) {}
  // The following has the same logic as the one above but
  // is more readable and the compiler will optimize these
  // instructions into a single instruction anyway.
  while (n) {
    *convdest = *convsrc;
    convdest++;
    convsrc++;
  }

  return dptr;
}

void swap(void *a, void *b, size_t size) {
  uint8_t temp[CHUNK_SIZE];
  uint8_t *conva = a; // Unsigned char converted a
  uint8_t *convb = b; // Unsigned char converted b

  while (size > 0) {
    // size_t copysize = (size % CHUNK_SIZE) ? size : CHUNK_SIZE;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // This is so fucking dumb. I hate myself.

    // Determine the amount to copy: either a full chunk or the
    // remaining tail.
    size_t copysize = (size > CHUNK_SIZE) ? CHUNK_SIZE : size;

    // Perform the standard 3-step swap using the stack buffer
    memcopy(conva, temp, copysize);
    memcopy(convb, conva, copysize);
    memcopy(temp, convb, copysize);

    // Advance pointers and decrese remaining size.
    // conva++;
    // ^^^^^^^^
    // convb++;
    // ^^^^^^^^
    // size--;
    // ^^^^^^^
    // This is so fucking dumb. I hate myself. This just decreases
    // the size by only one which would result in wrong copysize
    // calculations and memcopy function calls. Even the pointers
    // are incremented by one and not by the amount of bytes copied.

    conva += copysize;
    convb += copysize;
    size -= copysize;
  }
}
