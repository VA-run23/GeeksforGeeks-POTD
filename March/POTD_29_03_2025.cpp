/*
    This function aims to maximize job profit given deadlines and profit arrays.
    Jobs are sorted in descending order of profit for optimal selection.
    The maximum deadline is determined to create an array for scheduling slots.
    Each job is scheduled in the latest available slot before its deadline.
    If a slot is free, the job is added, profit updated, and count of jobs increases.
    The priority queue is unused; its declaration has no impact in this code.
    Finally, the function returns total jobs performed and their cumulative profit.
*/

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        if (n == 0) return {0, 0};

        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]}; 
        }

        sort(jobs.rbegin(), jobs.rend());

        int maxDL = *max_element(deadline.begin(), deadline.end());
        vector<int> slot(maxDL + 1, -1);
        priority_queue<pair<int, int>> pq;

        int totalPro = 0,count = 0;

        for (const auto &job : jobs) {
            int jobPro = job.first;
            int jobDL = job.second;
            for (int j = jobDL; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = jobPro;
                    totalPro += jobPro;
                    count++;
                    break;
                }
            }
        }
        return {count, totalPro};
    }
};