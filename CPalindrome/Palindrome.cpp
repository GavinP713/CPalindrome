#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  int uppercaseOffset = 32; // the distance between a lowercase and its uppercase form
  int lowercaseThreshold = 97;
  int spaceDec = 32; // the dec ascii value of space

  int maxSize = 10; // size of array (account for extra null character)
  char input[maxSize];
  char reversedInput[maxSize];

  // read into input
  cin.getline(input, maxSize, '\n');
  
  // clean up input
  for (int i = 0; i < strlen(input); i++) {
    int dec = int(input[i]);

    cout << "(i = " << i << ", char = " << input[i] << ", decimal = " << dec << ")" << endl;

    //cout << "Char: " << input[i] << ", Index: " << i << ", Decimal: " << dec << endl;
    
    // REMOVE SPACES:
    // if the current char is a space, remove it by shifting all of the letters in front downwards
    if (dec == spaceDec) {
      int origin = i;
      int originOffset = 0;

      // shift the char down (to replace the space)
      for (int j = origin + 1; j < strlen(input); j++) {
	cout <<" setting "<<"("<<(origin + originOffset)<<", "<<input[origin + originOffset]<<")"<<" To "<<"("<<j<<", "<<input[j]<<")"<<endl; 
	
	input[origin + originOffset] = input[j];
	originOffset++;

	// if the last index has a letter, we need to manually shift it (otherwise its shadow wont be removed)
	if (
      }
    }

    // REMOVE UPPERCASES:
    // if char ascii value is below the lowest lowercase letter
    if (dec < lowercaseThreshold) {
      // offset the char value by 32 to get its uppercase
      //input[i] = char(dec + uppercaseOffset);
    }
  }
  cout << "Input = " << input << endl;

  
  
  // get reverse array
  int j = strlen(input);
  for (int i = 0; i < strlen(reversedInput); i++) {
    j--;
    reversedInput[i] = input[j];
  }
  
  return 0;
}
