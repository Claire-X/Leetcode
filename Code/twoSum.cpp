//hash
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		unordered_map<int,int> mapping;
		for(size_t i =0 ;i<numbers.size();i++){
		    //mapping.insert(make_pair(numbers[i],i));
		    mapping[numbers[i]]=i;
		}
	    for(size_t i =0 ;i<numbers.size();i++){
	        int add = target - numbers[i];
	        if(mapping.find(add)!=mapping.end()&&mapping[add]!=i){
	            result.push_back(i+1);
	            result.push_back(mapping[add]+1);
	            break;
	        }
	    }
	    return result;
	}
};

//binary_search
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result, tmp = numbers;
		sort(tmp.begin(), tmp.end());
		for (size_t i = 0; i < tmp.size() && tmp[i] <= target / 2; i++) {
			int add = target - tmp[i];
			if (binary_search(tmp.begin() + i + 1, tmp.end(), add)) {
				auto it = find(numbers.begin(), numbers.end(), tmp[i]);
				int index1 = distance(numbers.begin(),
						find(numbers.begin(), numbers.end(), tmp[i])) + 1;
				int index2;
				if (add == tmp[i])
					index2 = distance(numbers.begin(),
							find(it + 1, numbers.end(), add)) + 1;
				else
					index2 = distance(numbers.begin(),
							find(numbers.begin(), numbers.end(), add)) + 1;
				result.push_back(index1);
				if (index1 > index2)
					result.insert(result.begin(), index2);
				else
					result.push_back(index2);
				break;
			}
		}
		return result;
	}
