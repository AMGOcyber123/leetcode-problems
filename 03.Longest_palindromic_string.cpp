class Solution {
public:
    string longestPalindrome(string s) {
        int n  = s.length();
        if(n<=1) return s;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++)
        {
            int mid = palindrome(s,i,i); //racecar
            int mid2 = palindrome(s,i,i+1); //aabbaa
            int midMax = max(mid,mid2);
            if(midMax > end-start) 
            {
                start = i-(midMax-1)/2;
                end = i+(midMax/2);
            }
        }
        return s.substr(start,end-start+1) ;
    }
    
    int palindrome(string s, int l,int r)
    {
        int n = s.size();
	    while(l >=0 && r < n && s[l] == s[r])  l--, r++;
	    return r-l-1;
    }
};