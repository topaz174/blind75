# [3]. [Longest Substring Without Repeating Characters]
**Category:** Sliding Window | **Difficulty:** 🟡

## 🧠 Brainstorming & Dictation
*   Thought of the main idea in the shower, then realized I needed to change to a for loop while taking a shit.
*   The core idea: sliding window with a set to track characters. When a repeat is found, move the left pointer past the first occurrence of that repeating character.

## ❌ The Graveyard (Failed Attempts)
*   Initial attempt at the `if` condition for skipping was a bit flawed: `(chars.count(s[r]) && (l == 0 || (s[l - 1] != s[l] && s[l - 1] != s[r])))`.

## ✅ The "Aha!" Moment
*   **The Trick:** When `s[r]` is already in the set, you don't just increment `l`. You need to slide the left boundary `l` all the way past the previous occurrence of `s[r]` so the window becomes valid again.
*   **Time Complexity:** $O(N)$. Even though there is a loop inside the `while`, the left pointer `l` only ever moves forward. Each character is visited at most twice (once by `r`, once by `l`).
*   **Space Complexity:** $O(min(n, m))$ where $m$ is the size of the character set (e.g., 256 for ASCII).
