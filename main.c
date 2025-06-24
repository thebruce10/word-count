#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_WORD_LENGTH 20

void pause();



int main(int)
{

    int state, character, currentLength, wordCount, lineCount, characterCount;
    int words[MAX_WORD_LENGTH + 1];

    for (int i = 0; i < (MAX_WORD_LENGTH + 1); ++i) //sets all the array to 0
    {
        words[i] = 0;
    }

    state = OUT;
    currentLength = wordCount = lineCount = characterCount = 0;

    while ((character = getchar()) != EOF)
    {
        ++characterCount;
        if (character == '\n') //if there is a newline increment the lineCount
        {
            ++lineCount;
        }


        if (character == ' ' || character == '\n' || character == '\t')
        {
            if (currentLength <= MAX_WORD_LENGTH && currentLength > 0)
            {
                ++words[currentLength - 1]; //the -1 is needed as the indexes of the array start at 0 but the word lengths start at 1
            } else if (currentLength > MAX_WORD_LENGTH)
            {
                ++words[MAX_WORD_LENGTH]; // adds it to the extra long words section
            }

            state = OUT;
        } else if (state == OUT) { //if there is not a break in the text and the previous character was not in a word set the state to inside a word and increment the wordCount
            state = IN;
            ++wordCount;
        }

        if (state == IN)
        {
            ++currentLength;
        } else if (state == OUT){ //if the character is not in a word it resets the length
            currentLength = 0;
        }
    }

    putchar('\n');

    //prints stats
    printf("\tSTATS\n");
    printf("words\t\t= %d\n", wordCount);
    printf("lines\t\t= %d\n", lineCount);
    printf("characters\t= %d\n", characterCount);

    putchar('\n');

    //prints histogram
    printf("\tFREQUENCY of EACH WORD LENGTH\n");
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) //cycle through the word lengths
    {
        printf("%d\t%d\t", i + 1, words[i]); //print the length of the word

        for (int j = 0; j < words[i]; ++j) //print the bars of the histogram
        {
            printf("=");
        }
        printf("\n");
    }
    printf("+\t%d\t", words[MAX_WORD_LENGTH]); //print number of extra long words
    for (int i = 0; i < words[MAX_WORD_LENGTH]; ++i) //print the bar
    {
        printf("=");
    }
    printf("\n\n");


    pause();

    return 0;
}



void pause() //pause until the user enters a newline
{
    printf("Press enter to continue. . .");
    getchar();
}