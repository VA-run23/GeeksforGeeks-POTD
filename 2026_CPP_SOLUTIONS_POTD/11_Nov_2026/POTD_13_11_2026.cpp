// Find Common Nodes in Two BSTs

/*
 *    1. The problem asks to find all common elements between two Binary Search Trees.
 *    2. Implement a custom BST Iterator using a stack for controlled in-order traversal.
 *    3. Initialize two iterators, one for each BST, to process elements in ascending order.
 *    4. Compare the current elements (peek) of both iterators.
 *    5. If they match, push the value to the result array and advance both iterators.
 *    6. If they differ, advance the iterator pointing to the smaller value.
 *    7. Time Complexity: O(n1 + n2), Space Complexity: O(h1 + h2).
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
	class IteratorBST {
		stack<Node*> st;
		void expand(Node* root) {
			while (root) {
				st.push(root);
				root = root->left;
			}
		}
		public:
		IteratorBST(Node* root) {
			expand(root);
		}
		bool hasNext() {
			return !st.empty();
		}
		int next() {
			Node* node = st.top();
			int val = node->data;
			st.pop();
			expand(node->right);
			return val;
		}
		int peek() {
			return st.top()->data;
		}
	};
	public:
	vector<int> findCommon(Node* r1, Node* r2) {
		// code here
		IteratorBST itr1(r1), itr2(r2);
		vector<int> res;
		while (itr1.hasNext() && itr2.hasNext()) {
			if (itr1.peek() == itr2.peek()) {
				res.push_back(itr1.peek());
				itr1.next();
				itr2.next();
			}
			else if (itr1.peek() < itr2.peek())
				itr1.next();
			else
				itr2.next();
		}
		return res;
	}
};

// Key Points
// 1. Uses a custom BST iterator for O(h) space per tree instead of O(n).
// 2. In-order traversal guarantees nodes are visited in sorted ascending order.
// 3. Compares elements using logic identical to merging two sorted arrays.
// 4. Advances both iterators upon finding a matched element.
// 5. Advances the smaller element's iterator to catch up.
// 6. Terminates as soon as either iterator is completely exhausted.
// 7. Runs in O(n1 + n2) time with O(h1 + h2) auxiliary space limit.