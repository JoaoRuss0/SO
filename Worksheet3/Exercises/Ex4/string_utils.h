#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int is_vowel (char character);
int is_consonant (char character);
int count_vowels (const char *string);
int count_consonants (const char *string);
void string_to_leet (const char *string, char *leet_string);

#endif