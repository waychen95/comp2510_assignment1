#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkAnagram(char str[], char str2[]) {



}

void toSmallCase(char *str) {
  int length = strlen(str);

  for (int i = 0; i < length; i++) {
    
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
      fprintf(stderr, "Usage: %s <input_file> <output_file> <shift>\n", argv[0]);
      return 1;
  }

  const char *input_path = argv[1];
  const char *output_path = argv[2];
  int shift = atoi(argv[3]);

  if (shift < 0 || shift >= 26) {
      perror("Shift must be between 0 and 25 (inclusive)\n");
      return 1;
  }

  FILE *input_file = fopen(input_path, "r");
  FILE *output_file = fopen(output_path, "w");

  if (input_file == NULL || output_file == NULL) {
      fprintf(output_file, "Error opening files: input or output file is null\n");
      return 1;
  }

  checkAnagram(input_file, output_file);

  fclose(input_file);
  fclose(output_file);

  return 0;
}