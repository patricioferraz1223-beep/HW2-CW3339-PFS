#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

void print_bits(float f) 
{
    unsigned int bits;
    memcpy(&bits, &f, sizeof(float));
    bitset<32> b(bits);

    // Sign bit
    cout << b[31] << " ";

    // Exponent bits (30-23)
    for (int i = 30; i >= 23; --i) cout << b[i];
    cout << " ";

    // Fraction bits (22-0)
    for (int i = 22; i >= 0; --i) cout << b[i];
    cout << endl;
}

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        cout << "usage:" << endl;
        cout << "      ./fp_overflow_checker loop_bound loop_counter" << endl;
        cout << endl;
        cout << "      loop_bound is a positive floating-point value" << endl;
        cout << "      loop_counter is a positive floating-point value" << endl;
        return 0;
    }

    float bound = stof(argv[1]);
    float counter = stof(argv[2]);

    cout << "Loop bound:   ";
    print_bits(bound);
    cout << "Loop counter: ";
    print_bits(counter);
    cout << endl;

    //Logic
    float threshold = counter * pow(2.0f, 24.0f);

    //Overflow I/O
    if (bound >= threshold) 
    {
        cout << "Warning: Possible overflow!" << endl;
        cout << "Overflow threshold:" << endl;
        cout << "      " << scientific << setprecision(5) << threshold << endl;
        cout << "      ";
        print_bits(threshold);
    } 
    else 
    {
        cout << "There is no overflow!" << endl;
    }

    return 0;
}