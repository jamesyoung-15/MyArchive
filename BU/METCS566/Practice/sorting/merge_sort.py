def merge_sort(nums):
    if len(nums)>1:
        # split array
        left_arr = nums[:len(nums)//2]
        right_arr = nums[len(nums)//2:]

        # recursion
        merge_sort(left_arr)
        merge_sort(right_arr)

        # merge array
        i, j, k = 0,0,0 # left, right, merged idx
        while i<len(left_arr) and j<len(right_arr):
            if left_arr[i] < right_arr[j]:
                nums[k] = left_arr[i]
                i+=1
            else:
                nums[k] = right_arr[j]
                j+=1
            k+=1
        
        # add left-over to merged
        while i<len(left_arr): 
            nums[k] = left_arr[i]
            i+=1

        while j<len(right_arr):
            nums[k] = right_arr[j]
            j+=1
    return nums
    
test = [4,2,3,1,7,5]

print(merge_sort(test))