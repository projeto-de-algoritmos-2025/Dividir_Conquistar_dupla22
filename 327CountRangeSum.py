class Solution:
    def countRangeSum(self, nums: list[int], lower: int, upper: int) -> int:
        
        prefix_sums = [0]
        current_sum = 0
        for num in nums:
            current_sum += num
            prefix_sums.append(current_sum)
            
        def mergeSortAndCount(low, high):
            if low >= high:
                return 0

            mid = (low + high) // 2
            
            count = 0
            count += mergeSortAndCount(low, mid)
            count += mergeSortAndCount(mid + 1, high)
            
            i = low
            k = mid + 1
            j = mid + 1
            
            while i <= mid:
                while k <= high and prefix_sums[k] < prefix_sums[i] + lower:
                    k += 1
                
                while j <= high and prefix_sums[j] <= prefix_sums[i] + upper:
                    j += 1
                
                count += (j - k)
                i += 1

            prefix_sums[low:high+1] = sorted(prefix_sums[low:high+1])
            
            return count

        return mergeSortAndCount(0, len(prefix_sums) - 1)