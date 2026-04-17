#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

double calculate_entropy(string data) {
    if (data.empty()) return 0.0;
    map<char, int> counts;
    for (char c : data) counts[c]++;
    
    double entropy = 0.0;
    int len = data.length();
    for (auto const& [curr, count] : counts) {
        double p = (double)count / len;
        entropy -= p * log2(p);
    }
    return entropy;
}

double calculate_redundancy(double entropy, int alphabet_size) {
    if (alphabet_size <= 1) return 0.0;
    double max_entropy = log2(alphabet_size);
    return 1.0 - (entropy / max_entropy);
}

int main() {
    string inputs[] = {"aaaa", "abcd", "hello world"};
    for (string s : inputs) {
        double h = calculate_entropy(s);
        // Giả sử bảng chữ cái là các ký tự xuất hiện trong chuỗi
        double r = calculate_redundancy(h, 256); // Thường dùng 256 cho chuẩn ASCII
        cout << "Input: " << s << " | Entropy: " << fixed << setprecision(4) << h << endl;
    }
    return 0;
}