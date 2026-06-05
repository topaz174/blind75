## Chapter 1: Arrays & Hashing
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 217 | [Contains Duplicate](./01_Arrays_and_Hashing/217_Contains_Duplicate/) | Mar 18 | 🟢 | ✅ | 💡 | - | - | - | Use `unordered_set`. |
| 242 | [Valid Anagram](./01_Arrays_and_Hashing/242_Valid_Anagram/) | Mar 18 | 🟢 | ✅ | 💡 | - | - | - | Count frequency of characters. |
| 001 | [Two Sum](./01_Arrays_and_Hashing/001_Two_Sum/) | Mar 18 | 🟢 | ✅ | 💡 | - | - | - | `unordered_map` lookup. |
| 049 | [Group Anagrams](./01_Arrays_and_Hashing/049_Group_Anagrams/) | Mar 18 | 🟡 | ✅ | 💡 | - | - | - | Use sorted string as key. |
| 347 | [Top K Frequent Elements](./01_Arrays_and_Hashing/347_Top_K_Frequent_Elements/) | Mar 19 | 🟡 | ✅ | 💡 | - | - | - | Bucket sort or priority queue. |
| 271 | [Encode and Decode Strings](./01_Arrays_and_Hashing/271_Encode_And_Decode_Strings/) | Mar 19 | 🟡 | ✅ | 💡 | - | - | - | Store length of string + delimiter. |
| 238 | [Product of Array Except Self](./01_Arrays_and_Hashing/238_Product_Of_Array_Except_Self/) | Mar 20 | 🟡 | ✅ | 💡 | - | - | - | Prefix and suffix products. |
| 128 | [Longest Consec](./01_Arrays_and_Hashing/128_Longest_Consecutive_Sequence/) | May 13 | 🟡 | ✅ | 💡 | 7hrs | 9 | 9 | Ask HashSet if `curr - 1` exists to skip middle pieces. Pure O(N). |

## Chapter 2: Two Pointers
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 125 | [Valid Palindrome](./02_Two_Pointers/125_Valid_Palindrome/) | May 14 | 🟢 | ✅ | 🧠 | 3hrs | 6 | 6.5 | Two pointers skip non-alnum + `f < b`. |
| 015 | [3Sum](./02_Two_Pointers/015_3Sum/) | May 16 | 🟡 | ✅ | 💡 | 7hrs | 9 | 8 | Sort + Two Pointers skip duplicates. |
| 011 | [Container With Most Water](./02_Two_Pointers/011_Container_With_Most_Water/) | May 21 | 🟡 | ✅ | 🧠 | 45m | 3 | 7.5 | Two pointers, move smaller height. |

## Chapter 3: Sliding Window
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 121 | [Best Time to Buy and Sell Stock](./03_Sliding_Window/121_Best_Time_To_Buy_And_Sell_Stock/) | May 22 | 🟢 | ✅ | 🧠 | 45m | 3.5 | 7 | Track minPrice so far, update maxProfit. |
| 003 | [Longest Substring Without Repeating Characters](./03_Sliding_Window/003_Longest_Substring_Without_Repeating_Characters/) | May 23 | 🟡 | ✅ | 🧠 | < 2hrs | 5 | 8 | Sliding window + Set; move `l` past duplicate. |
| 424 | [Longest Repeating Character Replacement](./03_Sliding_Window/424_Longest_Repeating_Character_Replacement/) | May 24 | 🟡 | ✅ | 🧠 | 7hrs | 9 | 10 | Window valid if (size - maxFreq) <= k. |
| 076 | [Minimum Window Substring](./03_Sliding_Window/076_Minimum_Window_Substring/) | May 24 | 🔴 | ✅ | 🧠 | 4.5hrs | 8 | 9.5 | Score variable + Negative frequencies for surplus. |

## Chapter 4: Stack
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 020 | [Valid Parentheses](./04_Stack/020_Valid_Parentheses/) | May 25 | 🟢 | ✅ | 🧠 | 15m | 2 | 7 | Push matching closing bracket to the stack. |

## Chapter 5: Binary Search
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 153 | [Find Minimum in Rotated Sorted Array](./05_Binary_Search/153_Find_Minimum_in_Rotated_Sorted_Array/) | May 27 | 🟡 | ✅ | 🧠 | 1.5hrs | 6.5 | 8 | Mid > Right means min is in right half; else left half. |
| 033 | [Search in Rotated Sorted Array](./05_Binary_Search/033_Search_in_Rotated_Sorted_Array/) | May 28 | 🟡 | ✅ | 🧠 | 30m | 4 | 8.5 | Check which half is perfectly sorted, then check if target is inside it. |

## Chapter 6: Linked List
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 206 | [Reverse Linked List](./06_Linked_List/206_Reverse_Linked_List/) | May 28 | 🟢 | ✅ | 🧠 | 50m | 6 | 6 | Three pointers (prev, curr, next) to flip pointers in-place. |
| 021 | [Merge Two Sorted Lists](./06_Linked_List/021_Merge_Two_Sorted_Lists/) | May 30 | 🟢 | ✅ | 🧠 | 20m | 2 | 7 | Use a dummy node to anchor the list and a ternary to attach the remainder. |
| 141 | [Linked List Cycle](./06_Linked_List/141_Linked_List_Cycle/) | May 30 | 🟢 | ✅ | 🧠 | 15m | 4 | 8.5 | Tortoise & Hare (Fast/Slow pointers) or destructive "visited" marking. |
| 143 | [Reorder List](./06_Linked_List/143_Reorder_List/) | May 30 | 🟡 | ✅ | 🧠 | 1hr | 6 | 8 | Find middle, reverse second half, then merge both halves. |
| 019 | [Remove Nth Node From End of List](./06_Linked_List/019_Remove_Nth_Node_From_End_of_List/) | May 31 | 🟡 | ✅ | 🧠 | 20m | 4 | 8 | Two pointers (ahead/behind) separated by $n$ nodes; one-pass $O(N)$. |
| 023 | [Merge k Sorted Lists](./06_Linked_List/023_Merge_K_Sorted_Lists/) | Jun 01 | 🔴 | ✅ | 🧠 | 3hrs | 6 | 8 | Use a min-heap or divide & conquer with 2-way merges. |

## Chapter 7: Trees
| ID  | Problem | Date | Diff | Status | Solo? | Time | Diff (10) | Fun (10) | The Core Trick |
| :-- | :--- | :---: | :--: | :----: | :---: | :--: | :---: | :---: | :--- |
| 226 | [Invert Binary Tree](./07_Trees/226_Invert_Binary_Tree/) | Jun 05 | 🟢 | ✅ | 🧠 | 5m | 2 | 7 | Swap `left` and `right` pointers via post-order traversal. |
| 104 | [Maximum Depth of Binary Tree](./07_Trees/104_Maximum_Depth_Of_Binary_Tree/) | Jun 05 | 🟢 | ✅ | 🧠 | 1m | 1 | 7 | Recursive `1 + max(left, right)`. |
| 100 | [Same Tree](./07_Trees/100_Same_Tree/) | Jun 05 | 🟢 | ✅ | 🧠 | 10m | 3 | 7 | Structural equality: compare roots, then recurse left and right. |
| 572 | [Subtree of Another Tree](./07_Trees/572_Subtree_Of_Another_Tree/) | Jun 05 | 🟢 | ✅ | 🧠 | 1hr | 6 | 8 | For each node, check if it's identical to the subRoot tree. |
| 235 | [Lowest Common Ancestor of a BST](./07_Trees/235_Lowest_Common_Ancestor_Of_A_Binary_Search_Tree/) | Jun 05 | 🟡 | ✅ | 🧠 | 1.5hr | 6.5 | 8 | Use BST property: if both are `< cur` move left, if both `> cur` move right. |
