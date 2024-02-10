#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Wayne: A01026253
//Clement: A01363591
//Daniel: A01064479

void toLowerCase(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

void removePunctuationsAndSpaces(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int checkAnagram(char str[], char str2[]) {
    int length1 = strlen(str);
    int length2 = strlen(str2);

    if (length1 != length2) {
        return 0;
    }

    toLowerCase(str);
    toLowerCase(str2);

    int counter[256] = {0};

    for (int i = 0; i < length1; i++) {
        counter[(int)str[i]]++;
        counter[(int)str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
      if (counter[i] != 0) {
          return 0;
      }
    }
    return 1;
}

void removeLastCharacter(char *str) {
    if (str == NULL || *str == '\0')
        return;

    int len = strlen(str);
    if (len > 0)
        str[len - 1] = '\0';
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
      fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
      return 1;
  }

  char line1[256];
  char line2[256];

  const char *input_path = argv[1];
  const char *output_path = argv[2];

  FILE *input_file = fopen(input_path, "r");
  FILE *output_file = fopen(output_path, "w");

  if (input_file == NULL || output_file == NULL) {
    fprintf(output_file, "error\n");
    return 1;
  }

  if (fgets(line1, sizeof(line1), input_file) == NULL) {
    fprintf(output_file, "error\n");
    fclose(input_file);
    return 1;
  }

  if (fgets(line2, sizeof(line2), input_file) == NULL) {
    fprintf(output_file, "error\n");
    fclose(input_file);
    return 1;
  }

  removeLastCharacter(line1);
  removePunctuationsAndSpaces(line1);
  removePunctuationsAndSpaces(line2);

  if (checkAnagram(line1, line2) == 1) {
    fprintf(output_file, "1! anagram");
  } else {
    fprintf(output_file, "0! not anagram");
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}