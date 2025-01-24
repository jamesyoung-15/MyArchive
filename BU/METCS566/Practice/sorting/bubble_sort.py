def bubble_sort(nums):
    n = len(nums)
    for i in range(n):
        for j in range(0, n-1-i):
            if nums[j]>nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    

    return nums


test_nums = [4,2,3,1,7,5]
print(bubble_sort(test_nums))