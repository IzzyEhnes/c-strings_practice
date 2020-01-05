// Izzy Ehnes
// CS 10B, Section 3031
// a6_1.cpp
// 10/1/18
// 
// This program various tasks with and edits to C-Style strings.

#include <iostream>
#include <cstring> // required for strlen() use in functions reverse() and isPalindrome()

using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);

int main() 
{
	char str1[] = "Scooby doo";
	char str2[] = "Shaggy";
  	char str3[] = "kayak";
	char str4[] = "$up3r c00l $3nt3n(3";
  	char someChar = 'g';

	cout << "-------------------------------------------------------------------------------\n";

	cout << "\n1. Testing of lastIndexOf function (returns '-1' if target char is not found):\n\n";
	cout << "The last index of '" << someChar << "' in '" << str2 << "' is " << lastIndexOf(str2, someChar) << ".";
	cout << "\nThe last index of '" << someChar << "' in '" << str1 << "' is " << lastIndexOf(str1, someChar) << ".";

	cout << "\n\n-------------------------------------------------------------------------------\n";

	cout << "\n2. Testing of reverse function:\n\n'";
	cout << str2 << "' is now '";
  	reverse(str2);
  	cout << str2 << ".'";
	cout << "\n\n...and reversing again: \n\n'";
	cout << str2 << "' is now '";
	reverse(str2);
	cout << str2 << ".'";

	cout << "\n\n-------------------------------------------------------------------------------\n";

  	cout << "\n3. Testing of replace function:\n\n";
  	cout << "Before: " << str1;
  	cout << "\nReplacing 'o' with 'x'";
  	cout << "\nNumber of replacements: " << replace(str1, 'o', 'x');
  	cout << "\nAfter replacements: " << str1;
	replace(str1, 'x', 'o');  // switching back

	cout << "\n\n-------------------------------------------------------------------------------\n";

	cout << "\n4. Testing of isPalindrome function (returns '0' if false and '1' if true):\n\n";
	cout << "\"" << str3 << "\" is a palindrome: ";
	toupper(str3);
	cout << isPalindrome(str3);
	cout << "\n\"" << str2 << "\" is a palindrome: ";
	cout << isPalindrome(str2);

	cout << "\n\n-------------------------------------------------------------------------------\n";

	cout << "\n5. Testing of toupper function:\n\n";
	cout << "Before: " << str2;
	toupper(str2);
	cout << "\nAfter function call: " << str2;

	cout << "\n\n-------------------------------------------------------------------------------\n";

	cout << "\n6. Testing of numLetters function:\n";
	cout << "\nNumber of letters in " << str4 << ": " << numLetters(str4);
	cout << "\nNumber of letters in " << str1 << ": " << numLetters(str1);
	
	cout << "\n\n-------------------------------------------------------------------------------\n";

	return 0;
}






//************************************************************
// The lastIndexOf function finds the last index where the   *
// target char ('char target') can be found in the string    *
// ('const char* inString'), and returns that value. If the  * 
// target char is not found in the string, a -1 is returned. *
// This function is case sensitive.                          *
//************************************************************

int lastIndexOf(const char* inString, char target)
{
	int lastIndex = -1;
	int parser = 0;

	while(inString[parser] != '\0')
	{
		if(inString[parser] == target)
		{
			lastIndex = parser;
		}

		parser++;
	}

	return lastIndex;
}






//************************************************************************
// The reverse function reverses the incoming string ('char* inString'). *
// It does so "in place," without the creation of a second array.        *
//************************************************************************

void reverse(char* inString) 
{
	int length = strlen(inString);
    char swap;

    for (int count = 0; count < (length/2); count++)
    {
        swap = inString[count];
        inString[count] = inString[length-count-1];
        inString[length-count-1] = swap;
    }

}






//************************************************************************
// The replace function finds all instances of the char 'target' in the  *
// string 'inString' and replace them with 'replacementChar'. It returns *
// the number of replacements that it makes. If the target char does not * 
// appear in the string it returns 0.                                    *
//************************************************************************

int replace(char* inString, char target, char replacementChar)
{
	int parser = 0;
	int replacements = 0;

	while(inString[parser] != '\0')
	{
		if(inString[parser] == target)
		{
			inString[parser] = replacementChar;
			
			replacements++;
		}

		parser++;
	}

	return replacements;
}






//********************************************************************************
// The isPalindrome function returns 'true' if the argument string ('inString')  *
// is a palindrome, and 'false' if it is not. It is not case sensitive, and      *
// punctuation is treated the same as alphanumeric characters.                   *
//********************************************************************************

bool isPalindrome(const char* inString)
{
	int length;
	length = strlen(inString);
	bool isPalindrome = true;
	
	for (int index = 0; index < length; index++)
	{
		if (inString[index] != inString[length-index-1])
		{
			isPalindrome = false;
		}
	}
	
	return isPalindrome;
}






//************************************************************************************
// The toupper function converts the c-string parameter 'inString' to all uppercase. *
//************************************************************************************

void toupper(char* inString)
{
	int parser = 0;

	while(inString[parser] != '\0')
	{
		inString[parser] = toupper(inString[parser]);
		parser++;
	}
}






//*************************************************************************
// The numLetters function returns the number of letters in the c-string. *
//*************************************************************************

int numLetters(const char* inString)
{
	int letterCount = 0;
	int parser = 0;

	while(inString[parser] != '\0')
	{
		if(isalpha(inString[parser]))
		{
			letterCount++;
		}

		parser++;
	}

	return letterCount;
}






/* SAMPLE OUTPUT:

-------------------------------------------------------------------------------

1. Testing of lastIndexOf function (returns '-1' if target char is not found):

The last index of 'g' in 'Shaggy' is 4.
The last index of 'g' in 'Scooby doo' is -1.

-------------------------------------------------------------------------------

2. Testing of reverse function:

'Shaggy' is now 'yggahS.'

...and reversing again: 

'yggahS' is now 'Shaggy.'

-------------------------------------------------------------------------------

3. Testing of replace function:

Before: Scooby doo
Replacing 'o' with 'x'
Number of replacements: 4
After replacements: Scxxby dxx

-------------------------------------------------------------------------------

4. Testing of isPalindrome function (returns '0' if false and '1' if true):

"kayak" is a palindrome: 1
"Shaggy" is a palindrome: 0

-------------------------------------------------------------------------------

5. Testing of toupper function:

Before: Shaggy
After function call: SHAGGY

-------------------------------------------------------------------------------

6. Testing of numLetters function:

Number of letters in $up3r c00l $3nt3n(3: 8
Number of letters in Scooby doo: 9

-------------------------------------------------------------------------------

*/
