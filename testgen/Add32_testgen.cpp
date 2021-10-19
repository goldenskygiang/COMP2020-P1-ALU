#include <bits/stdc++.h>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

uniform_int_distribution<int> unif(INT_MIN, INT_MAX);
random_device rd;
mt19937 engine(rd());
function<int()> rnd = bind(unif, engine);

void print(int a, int b, int cin, int c, int v)
{
    cout << cin << "\t" << a << "\t" << b << "\t" << c << "\t" << v << "\n";
}

void gen_add(int a, int b)
{
    int c = a + b;

    ll c1 = c;
    ll aa = a, bb = b;
    ll c2 = aa + bb;

    int cin = 0;
    int v = (c1 != c2);
    print(a, b, cin, c, v);
}

void gen_sub(int a, int b)
{
    int c = a - b;

    ll c1 = c;
    ll aa = a, bb = b;
    ll c2 = aa - bb;

    int cin = 1;
    int v = (c1 != c2);
    print(a, b, cin, c, v);
}

int main()
{
    freopen("Add32_testvector.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << "Cin\tA[32]\tB[32]\tC[32]\tV\n";

    vector<int> spec_nums = { 0, 1, -1, INT_MIN, INT_MAX };

    cout << "#edge cases\n";
    for (int i = 0; i < (1 << 5); i++)
    {
        int cnt = __builtin_popcount(i);

        if (cnt > 2) continue;
        int terms[2];

        for (int j = 0, id = 0; j < 5; j++)
        {
            if ((i >> j) & 1)
            {
                terms[id] = spec_nums[j];
                id++;
                if (cnt == 1) terms[id] = spec_nums[j];
            }
        }

        gen_add(terms[0], terms[1]);
        gen_sub(terms[0], terms[1]);
    }

    cout << "#random\n";
    for (int i = 0; i < 50; i++) gen_add(rnd(), rnd());
    for (int i = 0; i < 50; i++) gen_sub(rnd(), rnd());

    return 0;
}