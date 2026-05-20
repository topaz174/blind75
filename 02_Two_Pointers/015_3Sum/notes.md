# [15]. [3Sum]
**Category:** Two Pointers | **Difficulty:** 🟡

## 🧠 Brainstorming & Dictation
ok interesting so first of all we're given the target number of 0 its not dynamic, that doesnt make it any easier tho obv
we gotta do it in O(n^2)
and we gotta make them distinct
no hash sets, we have to use two pointers somehow...
lets think 1 pointer first. if we point to 0, we know we need the absolute value of the next two numbers to be equal.
so 
0 x y
x, y can be (-1, 1), (-2, 2), (0, 0) etc
now lets think 1. if we get 1 x y, we can get 1 -2 1, 1 -1 0
we need the difference in the absolute values of the two to be 1!
ah but no cause 1 1 0 wouldnt work
rather than absolute value,
-2+1 = -1
its the negative of the required sum of the next two numbers?
so for 2 x y
2 -4 2
yeah that works too, 2=-(-4+2)
and for 0, 0=-(-1+1)
ok... so for every number we need to find two other numbers in the array that sum to its negative
sounds like two sum!
and 2 sum is O(n), so we do n O(n) operations to get O(n^2) no?
anyway lets recap 2 sum, so for a target u iterate through the rest of the array and for a certain iteration element u compute its 'dist' from the target, dump everything else into a hash map with value as key and index as value, then u lookup target in O(1) and get its index. then boox u have the 3 numbers
only question is how do we do the distinct part, and one thing i thought of is just using more hashsets. u make each triplet a hash set, then make a hash set of those hash sets and just get the size of that. that will sort it out for us
hmm but we have to return an array of arrays not a hashset of hashsets so its not that clean
ohh i got an idea we can just pop on each outer iteration maybe?
so for smth like 
0 -1 1 -2 2
on 0 u would wanna find both of its pairs, then add those triplets to array
0:
    -1:
        dist = 0-(-1) = 1
        hash map: 1:2, -2:3, 2:4
        1 found -> get value = 2, i=0,j=1,k=2 -> [nums[0],nums[1],nums[2]]
    1: 
        dist = 0-1 = -1
ok the issue is we're overcounting here
but we cant just pop -1 from the original array cause it could be used for later outer (i) loops...
so how would we know to skip this
or i guess we dont? if we do the 'hash map of hash maps' approach we can safely overcount and then build the array there no?
imma just do that for now lol fuck it. if it works it works

shit, mid implementation update, u cant make a hash set of hash sets i just remembered
so we gotta either do a hash set of sorted arrays or smth else more clever entirely...
sorted arrays would be... well usually n log n, then n times would be like n^2logn which aint good right, BUT its only 3 elements so maybe its fine
but at that point im thinking theres a better way, a more elegant way to skip the duplicates
OH WAIT
what if, for a given j, if you match with a k that comes earlier than the current j, then you can abort the j iteration entirely, since youve already seen this pairing when this k was j
so we put a condition that not only is nums[k] a match, k is also strictly greater than j
only issue is i dont think i can just rebuild the hashmap excluding i and j every time... i think we'd wanna use one hash map, just put another and condition that the index found in the dist if is not i or j
k is just map[dist]
so the condition is like 'dist in map AND map[dist] > j AND map[dist] != i'
ok sounds good... this satisfies i != j != k right, since we're doing continue on i==j as well... cool
and i and j are our 'two pointers' eh, lets write nums[x] as *x

so:
0 -1 1 -2 2
hash map: 0:0, -1:1, 1:2, -2:3, 2:4
i=0, *i=0:
    target = 0

    j=0: i=j -> skip
    j=1, *j=-1:
        dist = 0-(-1) = 1
        1 in map, map[1]=2 > 1, 2 != 0 -> good
        so we add [*i, *j, dist] = [0, -1, 1]
    j=2, *j=1: 
        dist = 0-1 = -1
        -1 in map, map[-1]=1 !> 2 -> abort (continue)
    j=3, *j=-2:
        dist = 0-(-2) = 2
        2 in map, map[2]=4 > 3, 4 != 0 -> good
        so we add [0, -2, 2]
    j=4, *j=2:
        dist = 0-2 = -2
        -2 in map, map[-2]=3, 3!>4 -> continue

and thats the whole loop for i=0!
it seems to be good for this. lets check i=1

0 -1 1 -2 2
hash map: 0:0, -1:1, 1:2, -2:3, 2:4
i=1, *i=-1
    target = 1
    j=0, *j=0:
        dist = 1-0 = 1
        1 in map, map[1]=2 > 0, 2 != 1 -> good... except it isnt

so we have a missing condition since -1, 0, 1 is duplicate... how do we detect this? it should be similar idea
maybe theres a strict i<j<k thing going on? not just j<k?
hmmmmm that would mean we start the j loop from i+1, not 0... damn
and that would make sense!!! since if we've seen a i,j pair then we would see a j,i pair!
thats it thats gotta be the last insight
imma code now

[-1,0,1,2,-1,-4]
-1: 

## ❌ The Graveyard (Failed Attempts)

### Attempt 1: Hash Map with strict index condition
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            nums_map.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                int dist = target - nums[j];
                if ((nums_map.find(dist) != nums_map.end()) && 
                    (nums_map[dist] > j) &&
                    (nums_map[dist] != i)) {
                    res.push_back({nums[i], nums[j], dist});
                }
            }
        }
        return res;
    }
};
```

### Attempt 2: Hash Map storing indices vector (Trying to handle duplicates)
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> nums_map;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums_map.count(nums[i])) nums_map.insert({nums[i], {i}});
            else nums_map[nums[i]].push_back(i);
        }
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                int dist = target - nums[j];
                if (nums_map.count(dist)) {
                    for (int x = 0; x < nums_map[dist].size(); ++x) {
                        if (nums_map[dist][x] > j && nums_map[dist][x] != i) {
                            res.push_back({nums[i], nums[j], dist});
                            nums_map.erase(dist);
                            nums_map.erase(-dist);
                            break;
                        }
                    }
                }
            }
            // This was flawed
        }
        return res;
    }
};
```

### Attempt 3: Frequency Map (Subtracting counts)
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums_map.count(nums[i])) nums_map.insert({nums[i], 1});
            else nums_map[nums[i]]++;
        }
        for (auto& [a, afreq] : nums_map) {
            int target = -a;
            if (afreq <= 0) continue;
            afreq--;
            for (auto& [b, bfreq] : nums_map) {
                int dist = target - b;
                if (bfreq <= 0) continue;
                bfreq--;
                if (nums_map.count(dist)) {
                    if (nums_map[dist] <= 0) continue;
                    res.push_back({a, b, dist});
                }
                bfreq++;
            }
            nums_map.erase(a);
        }
        return res;
    }
};
```

## ✅ The "Aha!" Moment
*   **The Trick:** Sort the array first ($O(N \log N)$). Then iterate through with an outer pointer `i`. For each `i`, use the **Two Sum II** (Two Pointers) approach on the remainder of the array (`i + 1` to `end`).
*   **Duplicate Handling:** This was the hardest part. 
    1.  Skip duplicates in the outer loop: `if (i > 0 && nums[i] == nums[i-1]) continue;`.
    2.  After finding a valid triplet, move both `l` and `r` pointers past any identical values to avoid adding the same triplet again.
*   **Final Insight:** Sorting makes everything manageable. The pointers `l` and `r` can intelligently move based on whether the current sum is too high or too low.
