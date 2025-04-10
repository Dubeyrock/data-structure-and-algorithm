public class Solution {
    public long NumberOfPowerfulInt(long start, long finish, int limit,
                                    string s) {
        string low = start.ToString();
        string high = finish.ToString();
        int n = high.Length;
        low = low.PadLeft(n, '0');   // align digits
        int pre_len = n - s.Length;  // prefix length
        long[] memo = new long[n];
        Array.Fill(memo, -1);

        return Dfs(0, true, true, low, high, limit, s, pre_len, memo);
    }

    private long Dfs(int i, bool limitLow, bool limitHigh, string low,
                     string high, int limit, string s, int preLen,
                     long[] memo) {
        // recursive boundary
        if (i == low.Length) {
            return 1;
        }
        if (!limitLow && !limitHigh && memo[i] != -1) {
            return memo[i];
        }
        int lo = limitLow ? low[i] - '0' : 0;
        int hi = limitHigh ? high[i] - '0' : 9;
        long res = 0;
        if (i < preLen) {
            for (int digit = lo; digit <= Math.Min(hi, limit); digit++) {
                res += Dfs(i + 1, limitLow && digit == lo,
                           limitHigh && digit == hi, low, high, limit, s,
                           preLen, memo);
            }
        } else {
            int x = s[i - preLen] - '0';
            if (lo <= x && x <= Math.Min(hi, limit)) {
                res = Dfs(i + 1, limitLow && x == lo, limitHigh && x == hi, low,
                          high, limit, s, preLen, memo);
            }
        }

        if (!limitLow && !limitHigh) {
            memo[i] = res;
        }
        return res;
    }
}
