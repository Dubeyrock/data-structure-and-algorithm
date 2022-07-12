473. Matchsticks to Square
Medium

2006

158

Add to List

Share
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
  
  /* code */
  
  class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size()< 4)
            return false;
        const int perimeter = accumulate(begin(matchsticks), end(matchsticks),0);
        if(perimeter % 4 != 0)
            return false;
        
        sort(begin(matchsticks),end(matchsticks), greater<int>());
        return dfs(matchsticks , 0, vector<int>(4, perimeter /4));
        
    }
    private :
    bool dfs(const vector<int>& matchsticks, int selected, vector<int>&& edges) {
    if (selected == matchsticks.size())
      return all_of(begin(edges), end(edges),
                    [](int edge) { return edge == 0; });
        for (int i = 0; i < 4; i++){
            if (matchsticks[selected]>edges[i])
                continue;
            edges[i] -= matchsticks[selected];
      if (dfs(matchsticks, selected + 1, move(edges)))
        return true;
      edges[i] += matchsticks[selected];
    }

    return false;
  }
        };

  
  
  
  
