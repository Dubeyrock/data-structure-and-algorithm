
# Approach 1: Binary Indexed Tree
#Intuition
#If i,j,k satisfy 0≤i<j<k<n and 0≤pos2 nums1[i]<pos2 nums1[j] <pos2 nums1[k] <n, then nums1[i], nums1[j], nums1[k] form a good triplet. 
#Because both nums1 and nums2 are permutations of 0 to n−1, we can count the number of good triplets by calculating the number of triplets i,j,k that meet the conditions.
#An array indexMapping is used to express the above relationship, where indexMapping[i]=pos2 nums1[i], and indexMapping is also a permutation of 0 to n−1.
#When calculating the number of triplets i,j,k that meet the conditions, we can first fix j, then count how many numbers are less than indexMapping[j] in the indexMapping array to the left of index j, and denote it as left. 
#Next, count how many numbers are greater than indexMapping[j] to the right of index j, and denote it as right. Thus, left×right represents the number of triplets with the middle element as j. By traversing all j, the answer can be calculated.

#The above calculation process can be referred to 315. Count of Smaller Numbers After Self, using a binary indexed tree to solve.
#The binary indexed tree can complete increment and prefix sum operations for a certain index in O(logn) time.
#When applying the binary indexed tree, we need to traverse the values in indexMapping from small to large, and calculate the prefix sum for the current index pos, which represents how many numbers are less than indexMapping[pos] to the left of index pos. We can also calculate how many numbers are greater than indexMapping[pos] to the right of index pos, and then add 1 to the value of the current index.
#Since we are traversing according to the value size, we need another array reversedIndexMapping to save the indices of each value in indexMapping.
#In the code, the variable indexMapping can be omitted. The result can be returned after the traversal is completed.

# implementations

class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def update(self, index, delta):
        index += 1
        while index <= len(self.tree) - 1:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        index += 1
        res = 0
        while index > 0:
            res += self.tree[index]
            index -= index & -index
        return res


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        pos2, reversedIndexMapping = [0] * n, [0] * n
        for i, num2 in enumerate(nums2):
            pos2[num2] = i
        for i, num1 in enumerate(nums1):
            reversedIndexMapping[pos2[num1]] = i
        tree = FenwickTree(n)
        res = 0
        for value in range(n):
            pos = reversedIndexMapping[value]
            left = tree.query(pos)
            tree.update(pos, 1)
            right = (n - 1 - pos) - (value - left)
            res += left * right
        return res
