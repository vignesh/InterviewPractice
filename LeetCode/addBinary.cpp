class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        //add c = 1 in codintion for case where we have to add carry to front 11 + 1  = 100
        while(i >= 0 || j >= 0 || c == 1)
        {
            //add last digit, if not set carry to zero
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            //can be a value between 0-3, can also use bitwise operator (c & 1)
            s = char(c % 2 + '0') + s;
            //compute carry
            c /= 2;
        }
        
        return s;
    }
};