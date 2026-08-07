class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        set<long long> arr;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long num = stoll(s.substr(i,j-i+1));
                if(isPrime(num)){
                    arr.insert(num);
                }

            }
        }
        // sort(arr.begin(),arr.end());
        int arrn = arr.size();
        long long sum = 0;
        if(arrn<3){
            for(auto k:arr){
                sum += k;
            }
            return sum;
        }
        if(arrn == 0) return 0;
        auto it = arr.rbegin();
        sum += *it;
        it++;
        sum += *it;
        it++;
        sum += *it;
        return sum;

    }

    bool isPrime(long long num){
        if(num<=1) return false;
        
        if(num<=3) return true;
        
        if(num%2==0 || num%3==0) return false;
        
        for(long long i=5; i*i<=num; i+=6){
            if(num%i==0 || num%(i+2)==0) return false;
        }
        
        return true;
    }
};
