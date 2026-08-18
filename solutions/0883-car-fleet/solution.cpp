class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        map<int,double> ps;
        for(int i=0;i<len;i++){
            double time = (double)(target - position[i]) / speed[i];
            ps[position[i]] = time;
        }
        auto iti = prev(ps.end());
        auto itj = prev(iti);
        int count = 1;
        while(true){
            if(itj->second <= iti->second){
                if(itj == ps.begin()) break;
                itj--;
            } else {
                count++;
                iti = itj;
                if(itj == ps.begin()) break;
                itj--;
            }
        }
        return count;
    }
};
