#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    string mirrorHalf(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            s[n - 1 - i] = s[i];
        }
        return s;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        if (len == 1) {
            return to_string(stoi(n) - 1); // Single digit case
        }

        // Base palindrome by mirroring the first half
        string firstHalf = n.substr(0, (len + 1) / 2);
        string pal1 = mirrorHalf(n);

        // Generate smaller and larger palindromes by modifying the first half
        long long smallerHalf = stoll(firstHalf) - 1;
        long long largerHalf = stoll(firstHalf) + 1;

        string pal2 = mirrorHalf(to_string(smallerHalf) + n.substr((len + 1) / 2));
        string pal3 = mirrorHalf(to_string(largerHalf) + n.substr((len + 1) / 2));

        // Handle special edge cases like "1000" -> "999" or "10" -> "9"
        string edgeCase1 = to_string(pow(10, len - 1) - 1); // "1000" -> "999"
        string edgeCase2 = to_string(pow(10, len) + 1);     // "999" -> "1001"

        // Convert palindromes to long long for comparison
        long long originalNum = stoll(n);
        long long num1 = stoll(pal1);
        long long num2 = stoll(pal2);
        long long num3 = stoll(pal3);
        long long edge1 = stoll(edgeCase1);
        long long edge2 = stoll(edgeCase2);

        // Find the closest palindrome, preferring the smaller one in case of a tie
        long long closest = LLONG_MAX;
        
        auto updateClosest = [&](long long candidate) {
            if (candidate != originalNum) {
                if (abs(originalNum - candidate) < abs(originalNum - closest) || 
                    (abs(originalNum - candidate) == abs(originalNum - closest) && candidate < closest)) {
                    closest = candidate;
                }
            }
        };

        updateClosest(num1);
        updateClosest(num2);
        updateClosest(num3);
        updateClosest(edge1);
        updateClosest(edge2);

        return to_string(closest);
    }
};
