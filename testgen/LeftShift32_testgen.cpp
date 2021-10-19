#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

uniform_int_distribution<int> unif(INT_MIN, INT_MAX);
random_device rd;
mt19937 engine(rd());
function<int()> rnd = bind(unif, engine);

const int OP_LIM = 1 << 4;
const int SA_LIM = 1 << 5;

void print(int b, int cin, int sa, int c)
{
    cout << cin << "\t" << b << "\t" << c << "\t" << sa << "\n";
}

void gen_sll(int b, int sa, int cin)
{
    int c = b << sa;
    for (int i = 0; i < sa; i++)
    {
        c |= (cin << i);
    }
    
    print(b, cin, sa, c);
}

int main()
{
    freopen("LeftShift32_testvector.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << "Cin\tB[32]\tC[32]\tSa[5]\n";

    vector<int> spec_nums = { 0, 1, -1, INT_MAX, INT_MIN };

    cout << "#special\n";
    for (int i = 0; i < 32; i++)
    {
        for (int n : spec_nums)
        {
            gen_sll(n, i, 0);
            gen_sll(n, i, 1);
        }
    }

    cout << "#random\n";
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int b = rnd();
            gen_sll(b, i, 0);
            gen_sll(b, i, 1);
        }
    }

    return 0;
}