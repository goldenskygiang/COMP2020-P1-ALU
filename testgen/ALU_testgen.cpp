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

void print(int a, int b, int op, int sa, int c, int v)
{
    if (sa < 0) sa *= -1;
    if (op < 0) op *= -1;
    cout << op << "\t" << a << "\t" << b << "\t" << sa << "\t" << c << "\t" << v << "\n";
}

void gen_add()
{
    int op = (rnd() & 1) ? 2 : 3;
    int a = rnd(), b = rnd();
    int c = a + b;

    ll c1 = c;
    ll aa = a, bb = b;
    ll c2 = aa + bb;

    int sa = 0;
    int v = (c1 != c2);
    print(a, b, op, sa, c, v);
}

void gen_sub()
{
    int op = (rnd() & 1) ? 6 : 7;
    int a = rnd(), b = rnd();
    int c = a - b;

    ll c1 = c;
    ll aa = a, bb = b;
    ll c2 = aa - bb;

    int sa = 0;
    int v = (c1 != c2);
    print(a, b, op, sa, c, v);
}

void gen_and()
{
    int op = 4;
    int a = rnd(), b = rnd();
    int c = a & b;

    int sa = 0;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_or()
{
    int op = 5;
    int a = rnd(), b = rnd();
    int c = a | b;

    int sa = 0;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_ne()
{
    int op = 8;
    int a = rnd(), b = rnd();
    int c = (a != b);

    int sa = 0;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_eq()
{
    int op = 9;
    int a = rnd(), b = rnd();
    int c = (a == b);

    int sa = 0;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_xor()
{
    int op = 10;
    int a = rnd(), b = rnd();
    int c = a ^ b;

    int sa = 0;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_nor()
{
    int op = 11;
    int a = rnd(), b = rnd();
    int c = ~(a | b);

    int sa = 0;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_sll()
{
    int op = rnd() & 1;
    int a = 0, b = rnd();

    int sa = rnd() % SA_LIM;
    if (sa < 0) sa *= -1;
    int c = b << sa;
    int v = 0;
    print(a, b, op, sa, c, v);
}

int rightLogical(int x, int n) {
	if (n == 0) return x;
	unsigned int a = x;
	return a >> n;
}

void gen_srl()
{
    int op = 12;
    int a = 0, b = rnd();

    int sa = rnd() % SA_LIM;
    if (sa < 0) sa *= -1;

    int c = rightLogical(b, sa);
    
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_sra()
{
    int op = 13;
    int a = 0, b = rnd();

    int sa = rnd() % SA_LIM;
    if (sa < 0) sa *= -1;

    int c = b >> sa;
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_le()
{
    int op = 14;
    int a = rnd(), b = 0;

    int sa = 0;
    int c = (a <= 0);
    int v = 0;
    print(a, b, op, sa, c, v);
}

void gen_gt()
{
    int op = 15;
    int a = rnd(), b = 0;

    int sa = 0;
    int c = (a > 0);
    int v = 0;
    print(a, b, op, sa, c, v);
}

int main()
{
    freopen("ALU_testvector.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << "Op[4]\tA[32]\tB[32]\tSa[5]\tC[32]\tV\n#all random\n";

    cout << "#add\n";
    for (int i = 0; i < 50; i++) gen_add();
    cout << "#sub\n";
    for (int i = 0; i < 50; i++) gen_sub();
    cout << "#and\n";
    for (int i = 0; i < 50; i++) gen_and();
    cout << "#or\n";
    for (int i = 0; i < 50; i++) gen_or();
    cout << "#xor\n";
    for (int i = 0; i < 50; i++) gen_xor();
    cout << "#nor\n";
    for (int i = 0; i < 50; i++) gen_nor();
    cout << "#ne\n";
    for (int i = 0; i < 50; i++) gen_ne();
    cout << "#eq\n";
    for (int i = 0; i < 50; i++) gen_eq();
    cout << "#le\n";
    for (int i = 0; i < 50; i++) gen_le();
    cout << "#gt\n";
    for (int i = 0; i < 50; i++) gen_gt();
    cout << "#sll\n";
    for (int i = 0; i < 50; i++) gen_sll();
    cout << "#sra\n";
    for (int i = 0; i < 50; i++) gen_sra();
    cout << "#srl\n";
    for (int i = 0; i < 50; i++) gen_srl();

    return 0;
}