
# Find a triplet having maximum product in a given list

def findTriplet(A):

	# Sort the given list in natural order
	A.sort()

	n = len(A)

	# wrong input
	if n <= 2:
		print("No triplet exists since the list has less than 3 elements")

	# Consider maximum of last three elements or
	# first two element and last element
	if A[n - 1] * A[n - 2] * A[n - 3] > A[0] * A[1] * A[n - 1]:
		print("Triplet is", (A[n - 1], A[n - 2], A[n - 3]))
	else:
		print("Triplet is", (A[0], A[1], A[n - 1]))


if __name__ == '__main__':

	A = [-4, 1, -8, 9, 6]
	findTriplet(A)
