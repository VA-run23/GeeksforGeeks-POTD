class Solution {
	public:
	int solve(int n, string s) {
		// code here
		vector<int> pres(26, false) ;
		int res = 0 ;
		int cnt = n ;
		
		for (int i = 0 ; i<s.size() ; i++) {
			int idx = s[i] - 'A' ;
			if (pres[idx] == 1) {
				pres[idx] = 0;
				cnt++;
			} else if (pres[idx] == 0) {
				if (cnt > 0) {
					cnt--;
					pres[idx] = 1 ;
				} else {
					res++;
					pres[idx] = -1 ;
				}
			}
		}
		
		return res ;
	}
};