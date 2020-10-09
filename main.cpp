/*
    Morse code translator.

    Copyright 2020 | Catalin Stretcu
*/
#include <iostream>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <windows.h> //Win32 only

using namespace std;


//Global variables used to set the frequency and duration of the beeps
int f = 523;
int T = 100;

//Using'.' and '-' for the two characters used in Morse code.
string convertChar(char& c)
{
    c = char(toupper(c));

    //Allowing the following characters: A-Z, 0-9 and space (ASCII 32)
    //assert((int(c) >= 65 && int(c) <= 90) || (int(c) >= 48 && int(c) <= 57) || int(c) == 32);

    switch(c)
    {
    case ' ':
        return " ";

    case 'A':
        return ".-";
    case 'B':
        return "-...";
    case 'C':
        return "-.-.";
    case 'D':
        return "-..";
    case 'E':
        return ".";
    case 'F':
        return "..-.";
    case 'G':
        return "--.";
    case 'H':
        return "....";
    case 'I':
        return "..";
    case 'J':
        return ".---";
    case 'K':
        return "-.-";
    case 'L':
        return ".-..";
    case 'M':
        return "--";
    case 'N':
        return "-.";
    case 'O':
        return "---";
    case 'P':
        return ".--.";
    case 'Q':
        return "--.-";
    case 'R':
        return ".-.";
    case 'S':
        return "...";
    case 'T':
        return "-";
    case 'U':
        return "..-";
    case 'V':
        return "...-";
    case 'W':
        return ".--";
    case 'X':
        return "-..-";
    case 'Y':
        return "-.--";
    case 'Z':
        return "--..";

    case '0':
        return "-----";
    case '1':
        return ".----";
    case '2':
        return "..---";
    case '3':
        return "...--";
    case '4':
        return "....-";
    case '5':
        return ".....";
    case '6':
        return "-....";
    case '7':
        return "--...";
    case '8':
        return "---..";
    case '9':
        return "----.";

    default:
        cerr << endl <<"Invalid character!" << endl;
        return " ";
    }
}

//A Morse code measure lasts T ms
void printWithSound(string s)
{
    if(s == " ")
    {
        cout << endl;
        Sleep(7*T); //spaces between words last 7 measures
    }
    else
    {
        for(int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            cout << c;

            if(c == '.')
            {
                Beep(f,T);
                Sleep(T); //spaces between characters in the same letter/number last 1 measure
            }
            else
            {
                Beep(f, 3*T);
                Sleep(T);
            }
        }

        cout << " ";
        Sleep(3*T); //spaces between letters last 3 measures
    }
}

void parseInput(string& s)
{
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if(c != '\n')
            printWithSound(convertChar(c));
    }
}

int main()
{
    string inputS;

    cout << "Enter your message here and press RETURN: " << endl;
    getline(cin, inputS);

    parseInput(inputS);
}
