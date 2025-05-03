/*
1. The Solution class initializes an array primes to mark prime numbers using the Sieve of Eratosthenes for numbers up to 100,000.
2. The help vector stores all prime numbers for quick access using lower_bound in the primeList function.
3. The primeList function iterates through the linked list and finds the nearest prime number for each node value.
4. Using lower_bound, it determines the closest smaller or equal prime (primeBefore) and the closest greater or equal prime (primeAfter).
5. It replaces the current node's value with the prime that has the minimum absolute difference from the original value.
6. The Sieve of Eratosthenes runs in O(N log log N) time, and iterating through the linked list runs in O(L log N), where L is the number of nodes.
7. Space complexity is O(N) for storing prime numbers in primes and O(K) for storing all primes in help, where K is the number of primes ≤ N.
*/



class Solution {
private:
    vector<bool> primes;
    vector<int> help;

public:
    Solution() {
        int N = 100000;
        primes.resize(N + 1, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= N; i++) { 
            if (primes[i]) { 
                for (int j = i * i; j <= N; j += i) {
                    primes[j] = false;
                }
            }
        }

        for (int i = 0; i <= N; i++) {
            if (primes[i]) help.push_back(i);
        }
    }

    Node* primeList(Node* head) {
        // code here
        Node* temp = head;
    
        while (temp != NULL) {
            auto it = lower_bound(help.begin(), help.end(), temp->val);
    
            int primeBefore = (it == help.begin()) ? *it : *(it - 1);
            int primeAfter = (it == help.end()) ? help.back() : *it;
    
            temp->val = (abs(temp->val - primeBefore) <= abs(temp->val - primeAfter)) 
                        ? primeBefore 
                        : primeAfter;
    
            temp = temp->next;
        }
    
        return head;
    }
};