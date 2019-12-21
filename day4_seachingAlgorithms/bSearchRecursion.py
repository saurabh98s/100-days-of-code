def binarySearch(array,key,low,high):
	if high<low:
		return False
	else:
		mid=(low+high)//2
		if key==array[mid]:
			return True
		elif key<array[mid]:
			return binarySearch(array,key,low,high-1)
		else:
			return binarySearch(array,key,mid-1,high)
array=[1,2,3,45,56,67,79]
found=binarySearch(array,2,0,6)
print(found)