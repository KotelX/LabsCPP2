#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //Задание 1
    string path = "text.txt";

    double sum = 0;
    ifstream in(path); 
    if (in.is_open())
    {
        for (int n; in >> n; )
        {
            sum += n;
        }
    }
    in.close();     

    ofstream out;			
    out.open(path, ios::app);
    if (out.is_open())
    {
        out << sum << endl;
    }
    cout << endl << sum << endl;
    out.close();

    //Задание 2
    string path2 = "text2.txt";
    int n = 4;

    ofstream out2;
    out2.open(path2);
    if (out2.is_open())
    {
        for (int i = 1; i <= n; i++)
        {
            out2 << i * 2 << endl;
        }

    }
    cout << endl << n << endl;
    out2.close();


    return 0;
}