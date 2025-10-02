#include <iostream>
#include <string>
#include <algorithm>
#include<random>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;
string randomBigInt(int digits) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 9);
    string num;
    num.reserve(digits); //it preallocates some memory
    uniform_int_distribution<int> firstDist(1, 9);
    num += to_string(firstDist(gen));
    for (int i = 1; i < digits; i++) {
        num += to_string(dist(gen));
    }
    return num;
}
// Multiply two large numbers represented as strings
string bruteforce(const string &a, const string &b) {
    int n = a.size();
    int m = b.size();
    string result(n + m, '0');  // maximum digits
    // multiply each digit
    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--) {
            int tmp = (result[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
            result[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        result[i] += carry;
    }
    // remove leading zeros
    int pos = result.find_first_not_of('0'); //finds the character with not zero
    if (pos != string::npos) // if all are zero then it returns npos not found
        return result.substr(pos); //from that position returns substring
    return "0";
}
string addStrings(const string &a, const string &b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string subtractStrings(const string &a, const string &b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0) {
        int diff = (a[i] - '0') - (j >= 0 ? b[j] - '0' : 0) - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else carry = 0;
        res.push_back(diff + '0');
        i--; j--;
    }
    // remove leading zeros
    while (res.size() > 1 && res.back() == '0') 
         res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
string karatsuba(const string &x, const string &y) {
    int n = max(x.size(), y.size());
    if (n <= 10) {
        // small numbers: convert to int and multiply
        long long a = stoll(x);
        long long b = stoll(y);
        return to_string(a * b);
    }
    int m = n / 2;
    string x_high = x.substr(0, x.size() - m);
    string x_low  = x.substr(x.size() - m);
    string y_high = y.substr(0, y.size() - m);
    string y_low  = y.substr(y.size() - m);
    string z0 = karatsuba(x_low, y_low);
    string z2 = karatsuba(x_high, y_high);
    string z1 = karatsuba(addStrings(x_low, x_high), addStrings(y_low, y_high));
    z1 = subtractStrings(subtractStrings(z1, z2), z0);
    // multiply by powers of 10
    z2.append(2 * m, '0');
    z1.append(m, '0');
    return addStrings(addStrings(z2, z1), z0);
}
int main(){
    ofstream fout("Multiplication_2.dat");
    string a,b;
    fout<<"no.of digits"<<" "<<"karatsuba"<<"bruteforce"<<"\n";
    for(int i=450;i<=500;i++){
         a=randomBigInt(i);
         b=randomBigInt(i);
        auto t1=high_resolution_clock::now();
        karatsuba(a,b);
        auto t2=high_resolution_clock::now();
        auto tk=duration_cast<microseconds>(t2-t1).count();
        t1=high_resolution_clock::now();
        bruteforce(a,b);
        t2=high_resolution_clock::now();
        auto tb=duration_cast<microseconds>(t2-t1).count();
        fout<<i<<" "<<tk<<" "<<tb<<"\n";
    }
    fout.close();
    return 0;
}