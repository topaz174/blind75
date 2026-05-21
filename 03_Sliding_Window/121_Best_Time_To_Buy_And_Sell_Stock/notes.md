# [121]. [Best Time to Buy and Sell Stock]
**Category:** Sliding Window | **Difficulty:** 🟢

## 🧠 Brainstorming & Dictation
*   (Solved in one go!)

## ❌ The Graveyard (Failed Attempts)
*   None.

## ✅ The "Aha!" Moment
*   **The Trick:** Keep track of the `minPrice` seen so far. As you iterate through the prices, calculate the potential profit (`currentPrice - minPrice`) and update the `maxProfit`.
*   **Time Complexity:** $O(N)$
*   **Space Complexity:** $O(1)$
