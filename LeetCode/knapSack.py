#Recrusive O(2^n) solution
def knapSack(capacity, weights, values, items):
	if items == 0 or capacity == 0:
		return 0;

	if weights[items-1] > capacity:
		knapSack(capacity, weights, values, items-1)

	else:
		return max(knapSack(values[items-1]+knapSack(capacity-weights[items-1], weights, values, items-1)), knapSack(capacity, weights, values, items-1))


#Dynmaic Porgramming solution O(nC), C is capacity of knapsack
def knapSack(capacity, weights, values, items):
	K = [[0 for x in range(capacity+1)] for x in range(items+1)]
 
	for i in range(items+1):
	    for w in range(capacity+1):
	        if i == 0 or w == 0:
	            K[i][w] = 0
	        elif weights[i-1] <= w:
	            K[i][w] = max(values[i-1] + K[i-1][w-weights[i-1]],  K[i-1][w])
	        else:
	            K[i][w] = K[i-1][w]
    return K[n][w]