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
| 121 | [Best Time to Buy and Sell Stock](./03_Sliding_Window/121_Best_Time_To_Buy_And_Sell_Stock/) | May 22 | 🟢 | ✅ | 🧠 | - | 3.5 | 7 | Track minPrice so far, update maxProfit. |
| 003 | [Longest Substring Without Repeating Characters](./03_Sliding_Window/003_Longest_Substring_Without_Repeating_Characters/) | May 23 | 🟡 | ✅ | 🧠 | < 2hrs | 5 | 8 | Sliding window + Set; move `l` past duplicate. |
| 424 | [Longest Repeating Character Replacement](./03_Sliding_Window/424_Longest_Repeating_Character_Replacement/) | May 24 | 🟡 | ✅ | 🧠 | 7hrs | 9 | 10 | Window valid if (size - maxFreq) <= k. |
| 076 | [Minimum Window Substring](./03_Sliding_Window/076_Minimum_Window_Substring/) | May 24 | 🔴 | ✅ | 🧠 | 5hrs | 8 | 9.5 | Score variable + Negative frequencies for surplus. |

