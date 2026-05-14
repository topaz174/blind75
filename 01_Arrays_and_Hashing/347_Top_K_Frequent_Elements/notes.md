# [347]. [Top K Frequent Elements]
**Category:** Arrays & Hashing | **Difficulty:** 🟡

## 🧠 Brainstorming & Dictation
*   hmmm ok so immediately im thinking we create a hash map of all the unique elements as the keys and the counts as the values
so for [1,1,1,2,2,3] it would be
{1:3,2:2,3:1}
to do this we would simply iterate throguh the list and increment its value in the hash map by one
then we would create a sorted array of the hashmap keys
interesting so we gotta sort the hashmap by value... i wonder if theres an easy way to do that
but after that we just iterate through it and actually we dont even gotta array it we just take the first k keys
so i guess the question is how do u sort a hash map
ah wait but hash maps arent something u rearrange cause ordre doesmt matter
so arrays woud have to be invovled
so i guess u put the keys in an array and sosrt them by value somehow...
* so now we have a freq map
        {1:3,2:2,3:1}
        how would we sort to get [1, 2, 3]
        one strat im thinking of is to iterate from a huge number to one and add matching keys gradually
        but thats hella slow
        hmmmm
        another idea is to turn it into two arrays
        [1,2,3],[3,2,1] then treat the indexes as the bindings
        then u would find the max val in the freq array, get its index and corresponding key, then add that to results array and pop it and its key, then repeat k times
        so we dont even gotta sort
        wait i wonder if we can do this directly in the hash map. like find the max value, get its key, pop, repeat
        how would u find the max value in a hm tho.
        
        ok apparently u gotta use a priority queue so lets do that
* iterate through every pair in freqs

## ❌ The Graveyard (Failed Attempts)
*   

## ✅ The "Aha!" Moment
*
