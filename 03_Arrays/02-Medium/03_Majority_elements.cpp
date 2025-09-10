// 🔹 Problem: Majority Element (LeetCode 169)
// https://leetcode.com/problems/majority-element/

/*  
Approach 1: Brute Force  
- For each element, count its occurrences in the array.  
- If count > n/2, return that element.  

Time Complexity: O(n²)  
Space Complexity: O(1)  
*/
class SolutionBrute {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) cnt++;
            }
            if (cnt > n / 2) return nums[i];
        }
        return -1;
    }
};

/*  
Approach 2: Hashing  
- Store frequency of each element in a map.  
- Return the element whose frequency > n/2.  

Time Complexity: O(n)  
Space Complexity: O(n)  
*/
class SolutionHashing {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto it : freq) {
            if (it.second > nums.size() / 2) return it.first;
        }
        return -1;
    }
};

/*  
Approach 3: Boyer-Moore Voting Algorithm (Optimal)  
- Maintain a candidate and a counter.  
- If counter == 0 → pick current element as candidate.  
- If element == candidate → increase counter else decrease counter.  
- At the end, candidate is the majority element.  

Time Complexity: O(n)  
Space Complexity: O(1)  
*/
class SolutionBoyerMoore {
public:
    int majorityElement(vector<int>& nums) {
        int el = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                el = num;
                cnt = 1;
            }
            else if (num == el) cnt++;
            else cnt--;
        }
        return el;
    }
};
