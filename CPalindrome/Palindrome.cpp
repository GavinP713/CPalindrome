#include <iostream>
#include <cstring>
#include <list>

using namespace std;

int main()
{
  int uppercaseMin = 65; // decimal value of first uppercase letter
  int uppercaseMax = 90; // decimal value of last uppercase letter
  int lowercaseMin = 97; // decimal value of first lowercase letter
  int lowercaseMax = 122; // decimal value of last lowercase letter

  int uppercaseOffset = 32; // the distance between a lowercase and its uppercase form

  // cstring stuff:
  int maxSize = 10; // size of array
  char input[maxSize];
  char cleanedInput[maxSize];
  char reversedInput[maxSize];
  
  // read into input
  cin.getline(input, maxSize, '\n');
  
  // CLEAN THE INPUT:
  // only increment if current char is a letter
  // used as an index for cleanedInput
  int k = 0;
  // loop through the input, removing symbols and uppercases
  for (int i = 0; i < strlen(input); i++) {
    // integer version of the letter
    int dec = int(input[i]);

    // booleans for (potentially) easier to read code.
    // schecks if the current char value is within
    // the ascii range for letters.
    bool isUppercase = dec >= uppercaseMin && dec <= uppercaseMax;
    bool isLowercase = dec >= lowercaseMin && dec <= lowercaseMax;
    bool isLetter = isUppercase == true || isLowercase == true;
    
    // REMOVE UPPERCASES:
    if (isUppercase == true) {
      // offset the char value by 32 to get its lowercase
      cleanedInput[i] = char(dec + uppercaseOffset);
      
      // make sure this change can be read by rest of loop
      dec = int(cleanedInput[i]);
    }

    // REMOVE SYMBOLS:
    if (isLetter == true) {
      // k will stop incrementing if it reaches a symbol,
      // once i reaches a letter it replaces the symbol at k
      // and k will be incremented until it reaches another symbol
      cleanedInput[k] = char(dec);
      k++;
    }

    // add a null character at the end
    // to prevent weird cstring stuff
    cleanedInput[k] = char(0);
  }
  
  
  // GET REVERSE ARRAY:
  int j = k - 1; // index cleanedInput from back to front
  for (int i = 0; i < k; i++) {
    reversedInput[i] = cleanedInput[j];
    j--;
  }

  // DETERMINE PALINDROME:
  cout << "You inputed: " << input << endl;
  cout << "Removing spaces and symbols: " << cleanedInput << endl;
  cout << "Flipping it: " << reversedInput << endl;
  
  if (strcmp(cleanedInput, reversedInput) == 0) {
    cout << "Its a palindrome!" << endl;
  }
  else {
    cout << "Its not a palindrome :(" << endl;
  }

  // exit code
  return 0;
}
