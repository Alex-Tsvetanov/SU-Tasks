#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    char dict [100][2][101];
    cin.getline(dict [0][0], 101); // reading the new line after the number
    for (int i = 0 ; i < n ; i ++)
    {
        cin.getline(dict [i][0], 101);
        cin.getline(dict [i][1], 101); 
    }
    char str [4097];
    cin.getline(str, 4097);
    int strLen = strlen (str);
    char result [409601] = {0};
    int newTextLength = 0;
    for (int i = 0 ; i < strLen ; i ++) 
    {
        //cout << str [i] << endl;
        bool matched = true; // false if current char is not the beginning of a match of any pattern 
        for (int wordNum = 0; wordNum < n and matched ; wordNum ++)
        {
            matched = false;
            int lenPattern = strlen (dict [wordNum][0]);
            int lenReplaced = strlen (dict [wordNum][1]);
            //cout << "trying: " << dict [wordNum][0] << " -> " << dict [wordNum][1] << endl;
            for (int j = 0 ; j < lenPattern && i + j < strLen ; ++j)
            {
                if (str [i + j] == dict [wordNum][0][j]) // still it is not guaranteed that the pattern is found
                    continue;
                else
                {
                    matched = true; // first difference found so our char is not beginning of a match
                    break;
                }
            }
            //cout << i << " " << wordNum << " " << matched << endl;
            if (!matched)
            {
                for (int j = 0 ; j < lenReplaced ; ++j)
                    result [newTextLength ++] = dict [wordNum][1][j]; // add replaced word in the result
                i += lenPattern - 1; // skip the pattern (-1 cuz of the loop step = ++i)
            }
        }
        if (matched) // not matched with any of the patterns
        {
            result [newTextLength ++] = str [i];
        }
    }
    result [newTextLength] = '\0';
    cout << result << endl;
    return 0;
}
