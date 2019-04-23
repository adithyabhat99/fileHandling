#include <iostream>
#include "file.hpp"
#include "image.hpp"
#include "audio.hpp"
#include "csv.hpp"
#include "default.hpp"
using namespace std;
int main()
{
    int ch;
    do
    {
        cout << "Enter 1 to continue,0 Exit\n";
        cin >> ch;
        if (ch == 0)
            continue;
        cout << "Enter the file\n";
        string filename;
        cin >> filename;
        filename="files/"+filename;
        File f(filename);
        string type = f.findType();
        if (!f.existOrnot())
        {
            cout << "File does not exist\n";
        }
        else
        {
            int n = type.size() - 1;
            if ((type.compare(0, n, "jpg") == 0) || (type.compare(0, n, "jpeg") == 0) || (type.compare(0, n, "png") == 0))
            {
                Image I(filename);
            }
            else if (type.compare(0, n, "mp4") == 0)
            {
                //mp4 M(filename);
            }
            else if ((type.compare(0, n, "wav") == 0) || (type.compare(0, n, "ogg") == 0) || (type.compare(0, n, "flac") == 0))
            {
                Music Mu(filename);
            }
            else if (type.compare(0,n,"csv") == 0)
            {
                CSV C(filename);
            }
            else
            {
                Default D(filename);
            }
        }

    } while (ch);

    cout << "Thank you!\n";
    return 0;
}