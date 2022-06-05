Initially take the gap as (m+n)/2;
Take as a pointer1 = 0 and pointer2 = gap.
Run a loop from pointer1 &  pointer2 to  m+n and whenever arr[pointer2]<arr[pointer1], just swap those.
After completion of the loop reduce the gap as gap=gap/2.
Repeat the process until gap>0.
Time complexity: O((m+n)*log(m+n))
Space Complexity: O(1)
Best approach will be like taversing the whole array and updating new array using two pointer approach
TC O(m+n)
SC O(m+n)
​
We can do in O(1) sc and O(m+n) tc
using two pointer approach reversely
It relies on the simple observation that once all of the numbers from nums2 have been merged into nums1, the rest of the numbers in nums1 that were not moved are already in the correct place.
​
​
​
​
​
​