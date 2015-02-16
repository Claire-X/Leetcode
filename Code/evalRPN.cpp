class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> stk;
		for (auto it : tokens) {
			if (isdigit(it[0]) || (it.size() > 1 && isdigit(it[1]))) {
				stk.push(stoi(it, nullptr));
				continue;
			}
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			int c;

			if (it == "*")
				c = b * a;
			if (it == "/")
				c = b / a;
			if (it == "-")
				c = b - a;
			if (it == "+")
				c = b + a;

			stk.push(c);

		}
		return stk.top();
	}
};
