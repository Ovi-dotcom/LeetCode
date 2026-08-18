class Solution {
public:
    int calPoints(vector<string>& operations) {
        int len = operations.size();
        int result = 0;
        vector<int> res;
        for(int i=0;i<len;i++){
            if(operations[i] == "+"){
                int sum = res[res.size()-1] + res[res.size()-2];
                res.push_back(sum);
            } else if(operations[i] == "D"){
                int dou_ble = res[res.size()-1] * 2;
                res.push_back(dou_ble);
            } else if(operations[i] == "C"){
                res.pop_back();
            } else {
                int val = stoi(operations[i]);
                res.push_back(val);
            }
        }
        for(int num:res){
            result += num;
        }
        return result;
    }
};
