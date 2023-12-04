#include <fstream>
using namespace std;
int main()
{
    ifstream f("genab.in");
    int n;
    f >> n;
    f.close();
    char s[n], i;
    for (i = 0; i < n; i++) s[i] = 'a';
    ofstream g("genab.out");
    bool gata = 0;
    while (!gata)
    {
        for (i = 0; i < n; i++) g << s[i];
        g << '\n';
        i = n-1;
        bool ok;
        do
        {
            ok = 1;
            while (s[i] == 'b' && i >= 0) i--;
            if ((i > 0 && s[i-1] == 'a')
                || (i == 0 && s[i] == 'a'))
            {
                s[i] = 'b';
                for (i = i+1; i < n; i++) s[i] = 'a';
                ok = 0;
            }
            else i--;
            if (i < 0)
            {
                ok = 0;
                gata = 1;
            }
        } while (ok);
    }
    g.close();
    return 0;
}
