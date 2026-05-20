# [11]. [Container With Most Water]
**Category:** Two Pointers | **Difficulty:** 🟡

## 🧠 Brainstorming & Dictation
*   (No specific dictation for this one - solved quickly in ~45 mins!)

## ❌ The Graveyard (Failed Attempts)
*   None! Solved on the first clean logic attempt.

## ✅ The "Aha!" Moment
*   **The Trick:** Use two pointers starting at the extremes. The width is at its maximum at the start. To find a larger area, we must find a taller line. Since the area is limited by the shorter of the two lines, we always move the pointer pointing to the shorter line inward.
*   **Time Complexity:** $O(N)$ since we traverse the array once.
*   **Space Complexity:** $O(1)$ as we only use two pointers and a few variables.
