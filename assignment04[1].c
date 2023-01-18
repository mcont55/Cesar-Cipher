// Maria Contractor
// COP3223H, Fall 2021
// 5150901
#include "assignment04.h"
#include <stdio.h>
#include <ctype.h>

// case01
// Checks if a character is a consonant. If it is, return 1
// if it isn't, return 0
// Uses the tolower() function to check for all letters, no matter the case.
int is_consonant(char ch)
{
	ch = tolower(ch);
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
	|| ispunct(ch) || isspace(ch) || isdigit(ch))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// case02
// Checks if a character is the punctuator: '.', '!', or '?'
// Returns an integer depending on the character.
int is_terminating_punctuator(char ch)
{
	if (ch == '.' || ch == '!' || ch == '?')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// case03
// Function offsets letters based on the offset integer passed.
// The function will wrap around the alphabet if the shifted letter
// reaches the end of the alphabet.
char shift_letter(char ch, int offset)
{
	int MinCap = 'A';
	int MaxCap = 'Z';
	int MinLower = 'a';
	int MaxLower = 'z';
	int shifted_letter = 0;
	if (!isalpha(ch))
	{
		return ch;
	}

	int isCap = 0;
	offset = offset % 26;
	shifted_letter = (ch + offset);

	if ((ch <= MaxCap) && (ch >= MinCap))
	{
		if (shifted_letter > MaxCap)
		{
			shifted_letter = MinCap + shifted_letter - MaxCap - 1;
		}
		else if(shifted_letter < MinCap)
		{
			shifted_letter = MaxCap - (MinCap - shifted_letter) + 1;
		}
	}
	else
	{
		if (shifted_letter > MaxLower)
		{
			shifted_letter = MinLower + shifted_letter - MaxLower - 1;
		}
		else if(shifted_letter < MinLower)
		{
			shifted_letter = MaxLower - (MinLower - shifted_letter) + 1;
		}
	}
	return shifted_letter;
}

// case04
// Function calls the shift_letter() function to read and encrypt a pre-existing file.
// If the file does not exist, print a phrase and return -1.
int cipher(char *filename, int key)
{
	char ch;
	FILE *ifp;
	ifp = fopen(filename, "r");
	if (ifp == NULL)
	{
		printf("Could not open file. Womp womp. :(\n");
		return -1;
	}
	else
	{
		while (fscanf(ifp, "%c", &ch) != EOF)
		{
			ch = shift_letter(ch, key);
			printf("%c", ch);
		}
	}
	fclose(ifp);
}

// case05
// Function opens and looks for the first word that begins with the character ch.
// Function prints the word that begins with the character specified by char ch.
// If file doesn't exist or char ch isn't a letter in the file, return 1.
int print_first_word_beginning_with_character(char *filename, char ch)
{
	char filechar;
	char prevchar = ' ';
	int foundword = 0;
	FILE *ifp;
	ifp = fopen(filename, "r");
	if (ifp == NULL)
	{
		printf("Could not open file. Womp womp. :(\n");
		return -1;
	}
	while (fscanf(ifp, "%c", &filechar) != EOF)
	{
		if (filechar == ch && prevchar == ' ')
		{
			foundword = 1;
		}
		if (foundword == 1)
		{
			if(filechar == ' ')
			{
				printf("\n");
				fclose(ifp);
				return 0;
			}
			printf("%c", filechar);
		}
		prevchar = filechar;
	}
	if (foundword != 1)
	{
		printf("No such word in input file. :(\n");
		fclose(ifp);
		return -1;
	}
	fclose(ifp);
}
// case06
// Returns how difficult I found the assignment
double difficulty_rating(void)
{
	return 3;
}
// case07
// Returns how many hours I spent on the assignment
double hours_invested(void)
{
	return 7;
}
// case08
// Returns how much prior experience I have before the course
double prior_experience(void)
{
	return 2;
}
