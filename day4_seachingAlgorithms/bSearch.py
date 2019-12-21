def binarySearch(A,key):
	low=0
	high=len(A)-1
	while high>low:
		mid=(high+low)//2
		if key==A[mid]:
			return True
		elif key<A[mid]:
			high=mid-1
		else:
			low=mid+1
A=[1,2,4,5,6,7,9]
found=binarySearch(A,2)
print(found)
