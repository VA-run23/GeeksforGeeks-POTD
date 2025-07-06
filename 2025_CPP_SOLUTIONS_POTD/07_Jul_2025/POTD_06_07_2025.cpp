/*
    1. This class maintains two integer arrays: nums1 and nums2, with a frequency map (freq) for values in nums2.
    2. The constructor initializes nums1 and nums2 and builds the frequency map for fast lookup in count().
    3. The add() function updates an element at index i in nums2 by adding val, maintaining freq accordingly.
    4. The count() method finds how many pairs (one element from nums1 and one from nums2) sum up to tot.
    5. It uses freq map for efficient lookup of the complement (tot - nums1[i]), reducing nested loop overhead.
    6. Time complexity: add() is O(1); count() is O(n), where n = size of nums1; constructor is O(m), where m = size of nums2.
    7. Space complexity is O(m) due to the freq map, which stores count of each unique number in nums2.
*/


class FindSumPairs {
public:
    vector<int>nums1,nums2;
    unordered_map<int,int>freq;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        this->nums1=n1;
        this->nums2=n2;
        for(int n: nums2)
        {
            freq[n]++;
        }
    }

    
    void add(int i, int val) {
        --freq[nums2[i]];
        nums2[i]+=val;
        ++freq[nums2[i]];
    }
    
    int count(int tot) {
        int cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            int second=tot-nums1[i];
            if(freq.count(second))
            {
                cnt+=freq[second];
            }
        }
        return cnt;
    }
};