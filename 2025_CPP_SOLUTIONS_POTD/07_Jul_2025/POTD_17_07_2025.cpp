/*
    1. The function 'maxKPower(n, k)' computes the maximum power 'x' such that k^x divides n!.
    2. It first factorizes 'k' into its prime components using 'primeFactorize(k)'.
    3. For each prime factor 'p' with exponent 'e', it calculates how many times 'p' appears in 'n!' using 'countPrimeInFactorial(n, p)'.
    4. The number of times 'k' divides 'n!' is limited by the least ratio of (count of p in n!) / e across all prime factors.
    5. 'primeFactorize(k)' uses trial division up to √k, so its time complexity is O(√k).
    6. 'countPrimeInFactorial(n, p)' runs in O(log_p(n)) time for each prime, making the overall complexity O(√k + log(n) * number of prime factors).
    7. Space complexity is O(log k) for storing prime factors in the map.
*/


class Solution {
  public:
    int maxKPower(int n, int k) {
        // code here
     unordered_map<int, int> primeFactors = primeFactorize(k);
        int result = INT_MAX;

        for (auto& entry : primeFactors) {
            int prime = entry.first;
            int exponent = entry.second;

            int count = countPrimeInFactorial(n, prime);

            result = min(result, count / exponent);
        }

        return result;
    }
    private:
     unordered_map<int, int> primeFactorize(int k) {
        unordered_map<int, int> primeFactors;

        while (k % 2 == 0) {
            primeFactors[2]++;
            k /= 2;
        }

        for (int i = 3; i * i <= k; i += 2) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }

        if (k > 2) {
            primeFactors[k]++;
        }

        return primeFactors;
    }

    // Count number of times prime appears in n!
    int countPrimeInFactorial(int n, int prime) {
        int count = 0;
        for (long long power = prime; power <= n; power *= prime) {
            count += n / power;
        }
        return count;
    }

};