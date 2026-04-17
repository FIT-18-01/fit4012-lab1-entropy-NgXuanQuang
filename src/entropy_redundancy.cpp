#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Tính entropy
double calculate_entropy(const string &text) {
    if (text.empty()) {
        return 0.0;
    }

    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    double entropy = 0.0;
    for (const auto &pair : freq) {
        double p = static_cast<double>(pair.second) / text.size();
        entropy -= p * log2(p);
    }
    return entropy;
}

// Tính redundancy
double calculate_redundancy(const string &text) {
    if (text.empty()) {
        return 0.0;
    }

    // Đếm số ký tự khác nhau
    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    int m = freq.size();          // số ký tự khác nhau
    double H = calculate_entropy(text);
    double Hmax = log2(m);        // entropy tối đa

    return Hmax - H;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    getline(cin, input);

    double entropy = calculate_entropy(input);
    double redundancy = calculate_redundancy(input);

    cout << "Entropy: " << entropy << endl;
    cout << "Redundancy: " << redundancy << endl;

    return 0;
}