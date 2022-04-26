#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    
    string input;
    cin >> input;
    string vowels = "aeiouyAEIOUY";

    auto predicate = [&vowels](char c) { return vowels.find(c) != string::npos; };
    auto iterator = remove_if(input.begin(), input.end(), predicate);
    input.erase(iterator, input.end());

    cout << endl << input << endl;


    string path = "text3.txt";

    string sum[3];
    int i = 0;
    ifstream in(path);
    if (in.is_open())
    {
        for (char n; in >> n; )
        {
            sum[i] += n;
            if (n == '.')
            {
                i++;
            }
            
        }
    }
    in.close();

    ofstream out;
    out.open(path, ios::app);
    if (out.is_open())
    {
        for (int i = 2; i >= 0; i--)
        {
            out << sum[i];
        }
    }
    cout << endl << sum << endl;
    out.close();
}