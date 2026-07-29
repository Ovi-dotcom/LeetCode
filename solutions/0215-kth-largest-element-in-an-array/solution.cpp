class minHeap{
    public:
        vector<int> arr;
        int size;
    
    minHeap(){
        size=-1;
    }
    
    void insert(int val){
        arr.push_back(val);
        size++;
        int index = size;
        while(index>0){
            int parent = (index-1)/2;
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void deleteRoot(){
        swap(arr[0],arr[size]);
        arr.pop_back();
        size--;
        int parent = 0;

        while(true){
            int left = parent*2+1;
            int right = parent*2+2;
            int smallest = parent;

            if(left<=size && arr[left]<arr[smallest]) smallest = left;
            if(right<=size && arr[right]<arr[smallest]) smallest = right;
            if(smallest == parent) break;

            swap(arr[parent],arr[smallest]);
            parent = smallest;
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        minHeap p;
        for(int i=0; i<k; i++){
            p.insert(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(nums[i]>p.arr[0]){
                p.deleteRoot();
                p.insert(nums[i]);
            }
        }
        return p.arr[0];
    }
};
