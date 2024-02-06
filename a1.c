#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char removePunctuation(char c){
  if( c < 'z' || c > 'a'){
    return c;
  }


}

int checkAnagram(char str[], char str2[]) {


  toSmallCase(str);
  toSmallCase(str2);



  int length1 = strlen(str);
  int length2 = strlen(str2);

  // char newStr[length1];
  // for(int i = 0; i < length; i++){
  //   newStr[i] = removePunctuation(str[i])
  // }

  for (int i = 0; i < length1; i++) {
    for (int j = 0; j < length2; j++) {
      if (str[i] == str[j]) {
        
      }
    }
  }
}

void toSmallCase(char *str) {
 int length = strlen(str);

  for (int i = 0; i < length; i++) {
    str[i] = toLower(str[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
      fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
      return 1;
  }

  const char *input_path = argv[1];
  const char *output_path = argv[2];

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