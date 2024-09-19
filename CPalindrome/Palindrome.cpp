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
  
  int maxSize = 10; // size of array (account for extra null character)
  char input[maxSize];
  char cleanedInput[maxSize];
  char reversedInput[maxSize];

  // have range for uppercase and lowercase letters, if a char isnt in the range, it is a symbol so remove it (spaces count as symbol
  
  
  // read into input
  cin.getline(input, maxSize, '\n');
  
  // CLEAN THE INPUT:
  int k = 0; // only increment if current char isnt a space (index for cleanedInput)
  for (int i = 0; i < strlen(input); i++) {
    int dec = int(input[i]); // integer version of the letter

    cout << "(i = " << i << ", char = " << input[i] << ", decimal = " << dec << ")" << endl;

    bool isUppercase = dec >= uppercaseMin && dec <= uppercaseMax;
    bool isLowercase = dec >= lowercaseMin && dec <= lowercaseMax;
    bool isLetter = isUppercase == true || isLowercase == true;
    
    // REMOVE UPPERCASES:
    // if char is an uppercase letter
    if (isUppercase == true) {
      // offset the char value by 32 to get its lowercase
      cleanedInput[i] = char(dec + uppercaseOffset);
      dec = int(cleanedInput[i]);
    }

    // REMOVE SYMBOLS
    if (isLetter == true) {
      cleanedInput[k] = char(dec);
      k++;
    }

    // add a null character at the end
    cleanedInput[k] = char(0);
  }
  
  
  // GET REVERSE ARRAY:
  int j = k - 1; // index for the reverse array (go from back to start)
  for (int i = 0; i < k; i++) {
    reversedInput[i] = cleanedInput[j];
    j--;
  }

  // DETERMINE PALINDROME:
  if (strcmp(cleanedInput, reversedInput) == 0) {
    cout << "Its a palindrome!" << endl;
  }

  cout << "Input = " << input << endl;
  cout << "Cleaned Input = " << cleanedInput << endl;
  cout << "Reverse = " << reversedInput << endl;

  cout << "strcmp = " << strcmp(cleanedInput, reversedInput);
  
  return 0;
}
