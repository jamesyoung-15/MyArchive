def selection_sort(nums):
    for i in range(len(nums)-1):
        min_idx = i
        for j in range(i+1, len(nums)):
            if nums[min_idx] > nums[j]:
                min_idx = j
            
        nums[i], nums[min_idx] = nums[min_idx], nums[i]
        
    return nums

test = [3,4,1,5,2]

print(selection_sort(test))