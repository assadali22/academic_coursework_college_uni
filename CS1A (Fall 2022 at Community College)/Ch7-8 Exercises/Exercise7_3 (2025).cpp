/*
Chapter 7 Programming Exercises Problem 3

The Programming Example: Pig Latin Strings converts a string into the pig Latin
form, but it processes only one word. Rewrite the program so that it can be used
to process a text of an unspecified length. If a word ends with a punctuation
mark, in the pig Latin form, put the punctuation at the end of the string. For
example, the pig Latin form of Hello! is ello-Hay! Assume that the text contains
the following punctuation marks: , (comma), . (period), ? (question mark),
; (semicolon), and : (colon). (Your program may store the output in a file.)

Pig Latin rules:
1. If the string begins with a vowel, add the string "-way" at the end
of the string. For example, the pig Latin form of the string "eye" is "eye-way".

2. If the string does not begin with a vowel, first add "-" at the end of the string.
Then rotate the string one character at a time; that is, move the first character
of the string to the end of the string until the first character of the string becomes a vowel.
Then add the string "ay" at the end. For example, the pig Latin form of
the string "There" is "ere-Thay".

3. Strings such as "by" contain no vowels. In cases like this, the letter
y can be considered a vowel. So, for this program, the vowels are
a, e, i, o, u, y, A, E, I, O, U, and Y. Therefore, the pig Latin form of
"by" is "y-bay".

4. Strings such as "1234" contain no vowels. The pig Latin form of
the string "1234" is "1234-way". That is, the pig Latin form of a
string that has no vowels in it is the string followed by the string "-way".

*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

bool isVowel(char ch);
string rotate(string pStr);
void pigLatinString(vector<string> word);

int main()
{
    vector<string> words;
    char str[1000]; //c string in order to use strtok()
    int len = 0;
    cout << "Program assumes text only has punctuation marks ,.?;:" << endl;
    cout << "Enter a string (max 1000 characters): ";
    cin.getline(str, 1000); //get the whole line, whole text
    cout << endl;

    //make an array of strings for the words (it worked thanks to cplusplus.com reference)
    char* tok = strtok(str, " "); //delimiter for only blank spaces, keep punctuation for processing
    while (tok != NULL)
    {
        words.push_back(tok);
        tok = strtok(NULL, " ");
    }

    //debug, make sure original words actually print out
    //for (int j = 0; j < words.size(); j++)
    //{
        //cout << words[j] << endl;
    //}

    cout << "The pig Latin form of the string entered is: " << endl;
    pigLatinString(words);

    return 0;

}


//from textbook
bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
    default:
        return false;
    }
}

//from textbook
string rotate(string pStr)
{
    string::size_type len = pStr.length();
    string rStr;
    rStr = pStr.substr(1, len - 1) + pStr[0];
    return rStr;
}


//from textbook, with the modification of processing multiple words.
//process first word to pig latin, then print, then process 2nd word, etc.
void pigLatinString(vector<string> word)
{
    bool foundVowel;
    string::size_type len;
    string::size_type lenForPunc;
    string::size_type counter;
    char punc;

    //Process every word for pig latin
    for (int i = 0; i < word.size(); i++)
    {
        //Check for a punctuation mark at the end of a word
        //If true, save that punctuation mark so it can be printed out
        lenForPunc = word[i].length();
        if (word[i][lenForPunc - 1] == '?' || word[i][lenForPunc - 1] == '.' || word[i][lenForPunc - 1] == ',' || word[i][lenForPunc - 1] == ';' || word[i][lenForPunc - 1] == ':')
        {
            punc = word[i][lenForPunc - 1];
            word[i] = word[i].substr(0, lenForPunc - 1);
        }
        else punc = ' '; //blank space

        if (isVowel(word[i][0])) //rule 1
        {
            word[i] = word[i] + "-way";
            cout << word[i] << punc << " "; //print word and punctuation mark
        }
        else
        {
            word[i] = word[i] + '-';
            word[i] = rotate(word[i]);
            len = word[i].length();
            foundVowel = false;
            for (counter = 1; counter < len - 1; counter++)
            {
                if (isVowel(word[i][0]))
                {
                    foundVowel = true;
                    break;
                }
                else
                    word[i] = rotate(word[i]);
            }


            if (!foundVowel) //rule 4
            {
                word[i] = word[i].substr(1, len) + "-way";
            }

            else
            {
                word[i] = word[i] + "ay"; //rules 2, 3
            }

            cout << word[i] << punc << " "; //print word and punctuation mark
        }



    } //end for

}


/*
Sample Run 1
Program assumes text only has punctuation marks ,.?;:
Enter a string (max 1000 characters): this is character; there is a word? This is MAXIMUM. The program, stores words for pig latin.

The pig Latin form of the string entered is:
is-thay  is-way  aracter-chay; ere-thay  is-way  a-way  ord-way? is-Thay  is-way  AXIMUM-May. e-Thay  ogram-pray, ores-stay  ords-way  or-fay  ig-pay  atin-lay.


Sample Run 2
Program assumes text only has punctuation marks ,.?;:
Enter a string (max 1000 characters): hello, I have my eye on you; do not cause trouble.

The pig Latin form of the string entered is:
ello-hay, I-way  ave-hay  y-may  eye-way  on-way  you-way; o-day  ot-nay  ause-cay  ouble-tray.


Sample Run 3
Program assumes text only has punctuation marks ,.?;:
Enter a string (max 1000 characters): We will get there, as soon as possible; be strong.

The pig Latin form of the string entered is:
e-Way  ill-way  et-gay  ere-thay, as-way  oon-say  as-way  ossible-pay; e-bay  ong-stray.

*/
