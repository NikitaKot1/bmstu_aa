

#
# QuickSort
#

def partition(arr, low, high):
    p = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= p:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick(arr, low, pi - 1)
        quick(arr, pi + 1, high)

# def quick_sort(arr):
# 	if len(arr) <= 1:
# 		return arr
# 	return quick([l for l in arr[1:] if l < arr[0]]) + arr[0:1] + quick([g for g in arr[1:] if g >= arr[0]])

def quick_sort(arr):
	return quick(arr, 0, len(arr) - 1)

#
# ShakerSort
#

def shaker_sort(arr):
	swapped = True
	st = 0
	end = len(arr) - 1
	
	while (swapped):
		swapped = False
		
		for i in range(st, end):
			if (arr[i] > arr[i + 1]):
				arr[i], arr[i + 1] = arr[i + 1], arr[i]
				swapped = True
		
		if (not swapped):
			break
		
		swapped = False
		end -= 1

		for i in range(end - 1, st - 1, -1):
			if (arr[i] > arr[i + 1]):
				arr[i], arr[i + 1] = arr[i + 1], arr[i]
				swapped = True
			
		st += 1
	return arr


#
# CountingSort
#

def counting_sort_help(arr, largest):
    c = [0]*(largest + 1)
    for i in range(len(arr)):
        c[arr[i]] += 1
 
    c[0] -= 1 
    for i in range(1, largest + 1):
        c[i] += c[i - 1]
 
    result = [0]*len(arr)
 
    for x in reversed(arr):
        result[c[x]] = x
        c[x] -= 1
 
    return result

def counting_sort(arr):
	largest = max(arr)
	return counting_sort_help(arr, largest)
