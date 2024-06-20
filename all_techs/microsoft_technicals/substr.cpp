
#include <iostream>
#include <unordered_set>
#include <assert.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// int longest_non_repeating_substring(string s) {
//     unordered_set<char> seen;

//     if (s.empty()) {
//         return 0;
//     }

//     int l = 0;
//     int ans = 0;

//     for (int r = 0; r < s.size(); ++r) {
//         if (seen.find(s[r]) == seen.end()) {
//             seen.insert(s[r]);
//         } else {
//             while (s[l] != s[r]) {
//                 seen.erase(s[l]);
//                 l++;
//             }
//             l++;
//         }
//         ans = max(ans, r - l + 1);
//     }

//     return ans;
// }

size_t longest_non_repeating_substring(std::string const &s) {
    size_t l = 0, res = 0;
    unordered_map<char, int> counts;
    for (int r = 0; r < s.size(); r++) {
        counts[s[r]]++;
        while (counts[s[r]] > 1) {
            counts[s[l++]]--;
        }
        res = max(res, r - l + 1);
    }
    return res;
}

int main() {

    assert(longest_non_repeating_substring("abcad") == 4);
    assert(longest_non_repeating_substring("abcabcbb") == 3);
    assert(longest_non_repeating_substring("bbbbb") == 1);
    assert(longest_non_repeating_substring("pwwkew") == 3);
    assert(longest_non_repeating_substring("abcdefghijklmnabcdefghijklmn") == 14);
    assert(longest_non_repeating_substring("") == 0);

}