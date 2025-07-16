/*
    1. This code counts how many numbers ≤ n have exactly 9 divisors, leveraging number theory patterns.
    2. It uses the Sieve of Eratosthenes to generate all primes up to sqrt(n) efficiently.
    3. Numbers with 9 divisors must follow specific prime factorizations like p⁸ or p²·q², where p and q are distinct primes.
    4. The first loop counts all p⁸ ≤ n using the list of primes.
    5. The second loop counts all p²·q² ≤ n, ensuring q ≠ p and both primes satisfy the condition.
    6. 'upper_bound' ensures efficient lookup of valid q values, avoiding unnecessary iteration.
    7. Time Complexity: O(√n·log log n + π(√n)²) ≈ O(√n·log log n), Space Complexity: O(√n) for storing primes.
*/

class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        int max_prime = sqrt(n) + 1;
        vector<bool> is_prime(max_prime + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= max_prime; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max_prime; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= max_prime; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
        
        int count = 0;
        for (int p : primes) {
            long long p8 = 1LL * p * p * p * p * p * p * p * p;
            if (p8 > n) break;
            count++;
        }
    
        for (int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            long long p2 = 1LL * p * p;
            if (p2 > n) break; 
            long long max_q2 = n / p2;
            int max_q = sqrt(max_q2);
            auto it = upper_bound(primes.begin() + i + 1, primes.end(), max_q);
            count += distance(primes.begin() + i + 1, it);
        }
        
        return count;
    }
};