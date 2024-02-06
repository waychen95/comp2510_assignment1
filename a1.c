#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

char removePunctuation(char c){
  if( c < 'z' || c > 'a'){
    return c;
  }
}

int checkAnagram(char str[], char str2[]) {
    int length1 = strlen(str);
    int length2 = strlen(str);

    printf("%d\n", length1);
    printf("%d\n", length2);

    if (length1 != length2) {
        printf("0! not anagram\n"); // Add newline character in the print statement
        return 0; // Return indicating not an anagram
    }

    toLowerCase(str);
    toLowerCase(str2);

    int counter[256] = {0};

    for (int i = 0; i < length1; i++) {
        counter[(int)str[i]]++;
        counter[(int)str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
      printf("%d", counter[i]);
      if (counter[i] != 0) {
          printf("0! not anagram\n");
          return 0;
      }
    }

    printf("1! anagram\n");
    return 1; // Return indicating an anagram
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
      fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
      return 1;
  }

  char line1[100];
  char line2[100];

  const char *input_path = argv[1];
  const char *output_path = argv[2];

  FILE *input_file = fopen(input_path, "r");
  FILE *output_file = fopen(output_path, "w");

  if (input_file == NULL || output_file == NULL) {
    fprintf(output_file, "Error opening files: input or output file is null\n");
    return 1;
  }

  if (fgets(line1, sizeof(line1), input_file) == NULL) {
    perror("Error reading first line");
    fclose(input_file);
    return 1;
  }

  if (fgets(line2, sizeof(line2), input_file) == NULL) {
    perror("Error reading second line");
    fclose(input_file);
    return 1;
  }

  checkAnagram(line1, line2);

  fclose(input_file);
  fclose(output_file);

  return 0;
}