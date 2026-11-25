// Geek's Destination with Special Jump
/*
 *    1. Compute the normal time required to reach destination 'd'
 *       without using the special jump.
 *       - getTime(x, a, b) calculates the minimum time to reach
 *         position x considering forward movement and backward slips.
 *
 *    2. If a jump of length 'j' is used, Geek first reaches:
 *           x = d - j
 *       and then performs the jump in 1 second.
 *
 *    3. Convert the jump range:
 *           j ∈ [l, r]
 *       into:
 *           x ∈ [d-r, d-l]
 *       where x is the position before using the jump.
 *
 *    4. Use Binary Search on the range [L, R] to find the largest
 *       position 'p' such that:
 *           1 + getTime(x) <= normalTime
 *       for every x <= p.
 *
 *    5. Positions [L, p]:
 *       - Using the jump is beneficial or equal.
 *       - Total contribution:
 *             Σ (1 + getTime(x))
 *
 *    6. Positions [p+1, R]:
 *       - Using the jump is not beneficial.
 *       - Contribution for each position is simply:
 *             normalTime
 *
 *    7. To efficiently evaluate:
 *           Σ getTime(x)
 *       observe:
 *           getTime(x) =
 *           x + 2*b*ceil((x-a)/(a-b))
 *
 *    8. sumK(L, R, a, c) computes:
 *           Σ ceil((x-a)/c)
 *       over a range efficiently by grouping values according
 *       to the same remainder modulo c.
 *
 *    9. Arithmetic progression formulas are used to calculate:
 *       - Sum of positions.
 *       - Sum of cycle counts.
 *       Thus avoiding iteration over every value.
 *
 *   10. Return the final answer modulo 1e9+7.
 *
 *   Time Complexity:
 *       O((a - b) + log(d))
 *
 *   Space Complexity:
 *       O(1)
 */
class Solution {
    using ll = long long;
    static const ll MOD = 1000000007LL;

    ll ceilDiv(ll x, ll y) {
        if (x >= 0)
            return (x + y - 1) / y;
        return x / y;
    }

    ll getTime(ll x, ll a, ll b) {
        ll c = a - b;
        ll k = max(0LL, ceilDiv(x - a, c));
        return x + 2 * b * k;
    }

    ll sumK(ll L, ll R, ll a, ll c) {
        if (L > R)
            return 0;

        ll ans = 0;

        for (ll rem = 0; rem < c; rem++) {
            ll first = L + (rem - L % c + c) % c;

            if (first > R)
                continue;

            ll cnt = (R - first) / c + 1;
            ll t = (first - rem) / c;

            ll offset = ceilDiv(rem - a, c);

            ll sumT = cnt * (2 * t + cnt - 1) / 2;

            ans += sumT + cnt * offset;
        }

        return ans;
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        ll normal = getTime(d, a, b);

        ll L = d - r;
        ll R = d - l;

        ll low = L, high = R;
        ll p = L - 1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (1 + getTime(mid, a, b) <= normal) {
                p = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        ll ans = 0;

        if (L <= p) {
            ll cnt = p - L + 1;

            ll sumX = (L + p) * cnt / 2;

            ll sumCycles =
                sumK(max(L, (ll)a + 1), p, a, a - b);

            ans += cnt + sumX + 2LL * b * sumCycles;
        }

        if (p < R) {
            ll cnt = R - max(L, p + 1) + 1;
            ans += cnt * normal;
        }

        return ans % MOD;
    }
};

// Key Points
// 1. Converts jump lengths into equivalent pre-jump positions.
// 2. Computes the normal travel time using getTime().
// 3. Uses Binary Search to find where the jump remains beneficial.
// 4. Splits positions into beneficial and non-beneficial ranges.
// 5. Uses arithmetic series formulas instead of iterating through ranges.
// 6. sumK() efficiently evaluates the ceiling-function contribution.
// 7. Achieves O((a-b) + log d) time with O(1) extra space.