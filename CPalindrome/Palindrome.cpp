#include <iostream>
#include <cstring>
#include <list>

using namespace std;

int main()
{
  int uppercaseOffset = 32; // the distance between a lowercase and its uppercase form
  int lowercaseThreshold = 97;
  int spaceDec = 32; // the dec ascii value of space

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

    // REMOVE UPPERCASES:
    // if char ascii value is below the lowest lowercase letter
    if (dec < lowercaseThreshold && dec != spaceDec) {
      // offset the char value by 32 to get its uppercase
      cleanedInput[i] = char(dec + uppercaseOffset);
      dec = int(cleanedInput[i]);
    }
    
    // REMOVE SPACES:
    // copy none space character into the last space character
    if (dec != spaceDec) {
      cleanedInput[k] = char(dec);
      k++;
    }
  }
  
  
  // GET REVERSE ARRAY:
  int j = k - 1; // index for the reverse array (go from back to start)
  for (int i = 0; i < k; i++) {
    reversedInput[i] = cleanedInput[j];
    j--;
  }

  cout << "Input = " << input << endl;
  cout << "Cleaned Input = " << cleanedInput << endl;
  cout << "Reverse = " << reversedInput << endl;

  cout << "strcmp = " << strcmp(cleanedInput, reversedInput);
  
  return 0;
}
