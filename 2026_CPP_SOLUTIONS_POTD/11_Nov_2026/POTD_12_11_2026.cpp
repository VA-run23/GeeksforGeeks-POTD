// Minimum Difference Between BST Node and Target

/*
 *    1. The problem asks to find the minimum absolute difference between
 *       a given target value k and any node's value in a BST.
 *    2. Perform an in-order traversal of the BST to visit all nodes.
 *    3. Store the values of all nodes in a dynamic array (vector).
 *    4. Initialize a variable with the maximum integer value to track the minimum difference.
 *    5. Iterate through the array and calculate the absolute difference between k and each element.
 *    6. Update the minimum difference if the current difference is smaller.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	void getInorder(Node* root, vector<int> &arr) {
		if (root == NULL)
			return ;
		getInorder(root->left, arr) ; arr.push_back(root->data) ;
		getInorder(root->right, arr) ;
	}
	int minDiff(Node *root, int k) {
		
		vector<int> arr ;
		getInorder(root, arr) ;
		int numElements = arr.size() ;
		int minDifference = INT_MAX ;
		for (int i = 0; i<numElements; i++) {
			int currentDiff = abs(k - arr[i]) ;
			minDifference = min(minDifference, currentDiff) ;
		}
		return minDifference ;
	}
};

// Key Points
// 1. Uses an in-order traversal to extract all BST elements into an array.
// 2. Iterates linearly through the flattened array to compute differences.
// 3. Difference is calculated as abs(k - arr[i]).
// 4. Maintains a running minimum of the absolute differences found.
// 5. Does not utilize the BST property for optimization (checks all nodes instead of binary search).
// 6. Requires O(n) extra space to store the tree values.
// 7. Runs in O(n) time with O(n) extra space.