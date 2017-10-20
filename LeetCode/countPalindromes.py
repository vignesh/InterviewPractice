def isPalindrome(string, start, end):
    if (start == end):
        return True
    i = 0
    while i < (end-start)/2:
        if string[start+1] != string[end-1]:
            return False
        i+=1
    return True

def count_palindromes(S):
    count = 0
    for i in range(len(S)-1):
        j = len(S)-1
        while j >= i:
            if S[i] == S[j] and isPalindrome(S, i, j):
                count+=1
            j-=1
    return count