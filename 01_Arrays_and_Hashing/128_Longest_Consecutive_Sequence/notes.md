# [128]. [Longest Consecutive Sequence]
**Category:** Arrays & Hashing | **Difficulty:** 🟡

## 🧠 Brainstorming & Dictation
*   

## ❌ The Graveyard (Failed Attempts)
*   

## ✅ The "Aha!" Moment
*   **The Trick:** I don't need a massive loop to find the "minimum" or the start of a streak. I can just ask the Hash Set!
*   If `curr - 1` exists in the set, `curr` is NOT the start of a streak. Skip it.
*   If `curr - 1` does NOT exist, it's the bottom of a streak. Run the inner while loop to count upwards.
*   **Time Complexity:** Because of that one `if (!set.count(curr - 1))` check, the inner loop only ever touches each number once across the entire program. Outer loop + Inner loop = O(N).
