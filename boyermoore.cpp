#include <bits/stdc++.h>
using namespace std;

// Boyer–Moore using only the Bad Character rule
vector<int> boyerMoore(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> result;

    if (m == 0 || n < m) return result;

    // Precompute last occurrence of each possible character in the pattern
    const int ALPHABET = 256;
    vector<int> last(ALPHABET, -1);
    for (int i = 0; i < m; ++i)
        last[(unsigned char)pattern[i]] = i;

    int shift = 0; // how much pattern is shifted over the text

    while (shift <= n - m) {
        int j = m - 1;

        // Compare from rightmost character of the pattern
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            // Full match found
            result.push_back(shift);
            // Shift so next character after current match in text aligns
            shift += (shift + m < n) ? m - last[(unsigned char)text[shift + m]] : 1;
        } else {
            // Mismatch -> use bad character rule to decide shift
            int badCharIndex = (unsigned char)text[shift + j];
            int lastOcc = last[badCharIndex];
            int skip = max(1, j - lastOcc);
            shift += skip;
        }
    }

    return result;
}

// Example usage
int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";

    vector<int> positions = boyerMoore(text, pattern);

    if (positions.empty())
        cout << "Pattern not found\n";
    else {
        cout << "Pattern found at positions: ";
        for (int pos : positions)
            cout << pos << " "; // 0-based positions
        cout << "\n";
    }

    return 0;
}
