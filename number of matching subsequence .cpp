792. Number of Matching Subsequences
Medium

3442

163

Add to List

Share
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
Accepted
148,635
Submissions
291,572
  
  
class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    int ans = 0;
    // pair (i, j) := words[i] and the character words[i][j] waiting for
    vector<vector<pair<int, int>>> bucket(26);

    // for each word, it's waiting for word[0]
    for (int i = 0; i < words.size(); ++i)
      bucket[words[i][0] - 'a'].emplace_back(i, 0);

    for (const char c : s) {
      // let prevBucket = bucket[c] and clear bucket[c]
      vector<pair<int, int>> prevBucket;
      swap(prevBucket, bucket[c - 'a']);
      for (auto& [i, j] : prevBucket)
        if (++j == words[i].length())  // all characters in words[i] are matched
          ++ans;
        else
          bucket[words[i][j] - 'a'].emplace_back(i, j);
    }

    return ans;
  }
};
  
  
