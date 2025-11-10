class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        
        def mergeSortAndCount(arr, low, high):
            if low >= high:
                return 0

            mid = (low + high) // 2
            
            count = 0
            count += mergeSortAndCount(arr, low, mid)
            count += mergeSortAndCount(arr, mid + 1, high)
            
            temp = []
            l, r = low, mid + 1
            
            while l <= mid and r <= high:
                if arr[l] > 2 * arr[r]:
                    count += (mid - l + 1)
                    temp.append(arr[r])
                    r += 1
                elif arr[l] <= arr[r]:
                    temp.append(arr[l])
                    l += 1
                else:
                    temp.append(arr[r])
                    r += 1

            while l <= mid:
                temp.append(arr[l])
                l += 1
            while r <= high:
                temp.append(arr[r])
                r += 1

            for k in range(len(temp)):
                arr[low + k] = temp[k]
                
            return count

        return mergeSortAndCount(nums, 0, len(nums) - 1)