#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int* start = new int [n];
    int* end = new int [n];
    int* lectures = new int [n]; // [i] - i-тата по край лекция
    int* checkpoints = new int [n]; // [i] - колко най-много лекции мога да посетя до end[i]
    
    for (unsigned i = 0; i < n; ++i) 
    {
        lectures [i] = i;
        cin >> start [i] >> end [i];
    }

    sort (lectures, lectures + n, [&](int a, int b) -> bool {
        if (end [a] == end [b])
            return start [a] < start [b];
        else
            return end [a] < end [b];
    });
    
    int answer = 0;

    for (unsigned i = 0; i < n; ++i) // до end [lectures [i]]
    {
        checkpoints [i] = 1; // поне лекция lectures [i] може да бъде посетена
        for(unsigned j = 0; j < i; ++j) // нека опитаме да посетим лекция lectures[j] и след нея веднага лекция lectures[i]
        {
            if (start [lectures [i]] > end [lectures [j]]) // ако можем физически да ги посетим една след друга
            {
                checkpoints [i] = ((checkpoints [i] < (checkpoints [j] + 1)) ? (checkpoints [j] + 1) : checkpoints [i]); // взимаме по-оптималното решение
            }
        }
        
        answer = ((answer < checkpoints [i]) ? checkpoints [i] : answer);
    }
    
    cout << answer << endl;
    return 0;
}