#ifndef MYLIB_STRING_H
#define MYLIB_STRING_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Calculate the length of a string.
 *
 * Calculates the length of the string pointed to
 * by `str`, excluding the terminator null byte ('\0')
 *
 * @param[in] str Pointer to the string's first character.
 *
 * @return Length of the string excluding the null terminator.
 */
size_t strlength(const char *str);

/**
 * @brief Calculate the actual length of a string from 1.
 *
 * Calculates the length of the string pointed to
 * by `str`. Includes the null terminating byte ('\0')
 *
 * @param[in] str Pointer to the string's first character.
 *
 * @return Length of the string including the null terminator.
 */
size_t strlength_a(const char *str);

/**
 * @brief Copies a string from src to dst.
 *
 * Takes source and destination as input and copies
 * the string over. The buffer for the destination
 * needs to be accounted for by the programmer.
 *
 * @param[in]      src  The string to be copied.
 * @param[in, out] dest Where the string will be copied.
 *
 * @return Returns a pointer to the destination
 */
char *strcopy(const char *src, char *dest);

/**
 * @brief Compares two strings.
 *
 * Takes two strings as input and checks for difference.
 * Used for equality checks and lexicographical sorting.
 *
 * @param[in] s1  The first string
 * @param[in] s2  The second string
 *
 * @return Returns an integer
 * - 0:  Both strings are equal
 * - 1:  s1 is greater than s2
 * - -1: s2 is greater than s1
 */
int8_t strcompare(const char *s1, const char *s2);

/**
 * @brief Appends src after dst into dst.
 *
 * Concatenates the string pointed to by src after
 * the string pointed to by dst replacing it's
 * null terminator. The buffer for the destination
 * needs to be accounted for by the programmer.
 *
 * @param[in]      src The first string.
 * @param[in, out] dst The second string.
 *
 * @return Returns a pointer to the destination.
 */
char *strconcat(const char *src, char *dest);

/**
 * @brief Reverses a string.
 *
 * Reverses a string using a two pointer swap, excluding
 * the terminating null byte ('\0').
 *
 * @param[in] str The string to be reversed
 */
void strreverse(char *str);

/**
 * @brief Get length of a substring
 *
 * Calculates the length (in bytes) of the initial segment
 * of @p space which consists entirely of bytes in @p accept.
 *
 * @param[in] accept
 *      Acceptable array of characters.
 *
 * @param[in] space
 *      String to perform the function on.
 *
 * @return
 * - Difference in index between the first character not in
 *   @p accept and the start of the substring.
 */
size_t strspan(const char *accept, const char *space);

/**
 * @brief Get length of a substring
 *
 * Calculates the length (in bytes) of the initial segment
 * of @p space which entirely of bytes NOT in @p reject.
 *
 * @param[in] reject
 *      Rejectable array of characters.
 *
 * @param[in] space
 *      String to perform the function on.
 *
 * @return
 * - Difference in index between the first character not in
 *   @p accept and the start of the substring.
 */
size_t strcspan(const char *reject, const char *space);

/**
 * @brief Tokenize a string using a set of delimiters, preserving
 * state between calls.
 *
 * Splits a string into tokens separated by any character in @p delim.
 * It maintains iteration state in @p checkpoint so that successive calls
 * return subsequent tokens.
 *
 * @param[in, out] str        String to tokenize or NULL on subsequent calls.
 * @param[in]      delim      String containing delimiter characters.
 * @param[in, out] checkpoint `char **` holding next token's address or NULL
 *
 * @return A pointer to the next token, or NULL if no more tokens.
 *
 * @note Each thread should use it's own `checkpoint` variable.
 */
char *strtoken(char *str, const char *delim, char **checkpoint);

#endif
