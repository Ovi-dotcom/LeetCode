class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        int s1Len=haystack.size();
        int s2Len=needle.size();
        while(i<s1Len){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==s2Len) return i-j;
            } else {
                i = i-j+1;
                j=0;
            }
             
        }
        return -1;
    }
};
