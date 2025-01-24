def heapify(nums, n, i):
    # implement heapifyz
    left = 2*i+1
    right = 2*i+2
    largest = i
    if left < n and nums[left]>nums[largest]:
        largest = left
    if right < n and nums[right]>nums[largest]:
        largest = right
    if largest != i:
        nums[largest], nums[i] = nums[i], nums[largest]
        heapify(nums,n,largest)

def create_heap(ls):
    n = len(ls)
    for i in range(n//2,-1,-1):
        heapify(ls,n,i)

    return ls

def heap_sort(ls):
    ls = create_heap(ls)
    for i in range(len(ls)-1,0,-1):
        ls[i],ls[0] = ls[0],ls[i]
        heapify(ls,i,0)

    return ls

print(heap_sort([3,1,5,2,6]))