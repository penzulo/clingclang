#include <stddef.h>
#include <stdint.h>

#define MODE_SET 0
#define MODE_CHECK 1
#define BITS (8 * sizeof(size_t))

void _swap(char *c1, char *c2) {
  char temp = *c1;
  *c1 = *c2;
  *c2 = temp;
}

uint8_t _bitop(size_t *bitmap, unsigned char c, unsigned short mode) {
  size_t index = c / BITS;
  size_t offset = c % BITS;
  size_t mask = (size_t)1 << offset;

  if (mode == MODE_SET) {
    bitmap[index] |= mask;
    return 1;
  }

  /* NOTE: `!!` is supposed to normalize the return
   * value of the bitwise operation between 0 and 1.
   */
  return !!(bitmap[index] & mask);
}

size_t strlength(const char *str) {
  size_t len = 0;
  for (; *str; len++, str++) {}
  return len;
}

size_t strlength_a(const char *str) { return strlength(str) + 1; }

char *strcopy(const char *src, char *dest) {
  char *dptr = dest;
  while ((*dptr++ = *src++) != '\0') {};
  return dest;
}

int8_t strcompare(const char *s1, const char *s2) {
  if (s1 == s2) return 0;
  for (; *s1; s1++, s2++) {
    if (!*s2) return 1;
    if (*s2 > *s1) return -1;
    if (*s1 > *s2) return 1;
  }
  if (!*s2) return 0;
  return -1;
}

char *strconcat(const char *src, char *dest) {
  strcopy(src, dest + strlength(dest));
  return dest;
}

void strreverse(char *str) {
  char *end = str;
  for (; *(end + 1); end++) {}
  for (; str < end; _swap(str, end), str++, end--) {}
}

size_t strspan(const char *accept, const char *space) {
  size_t bitmap[32 / sizeof(size_t)] = {0};
  const char *counter = space;
  for (; *accept && _bitop(bitmap, *accept, MODE_SET); accept++) {};
  for (; *counter && _bitop(bitmap, *counter, MODE_CHECK); counter++) {};
  return counter - space;
}

size_t strcspan(const char *reject, const char *space) {
  size_t bitmap[32 / sizeof(size_t)] = {0};
  const char *counter = space;
  for (; *reject && _bitop(bitmap, *reject, MODE_SET); reject++) {};
  for (; *counter && !_bitop(bitmap, *counter, MODE_CHECK); counter++) {};
  return counter - space;
}

char *strtoken(char *str, const char *delim, char **checkpoint) {
  char *current = str ? str : *checkpoint;
  if (!current) return NULL;
  current += strspan(current, delim);
  if (!*checkpoint) return *checkpoint = NULL;
  *checkpoint = current + strcspan(current, delim);
  if (**checkpoint) {
    **checkpoint = '\0';
    *checkpoint += 1;
  } else {
    *checkpoint = NULL;
  }
  return current;
}
