#include <iostream>
#include <vector>

using namespace std;

int left(int i){
    return (i << 1) + 1;
}

int right(int i){
    return (i << 1) + 2;
}

int parent(int i){
    return (i - 1) >> 1;
}



void maxHeapify(vector<int> & nums, int i, int len){
    int largest = i, lb = left(i), ub = right(i);
    if(lb <= len && nums[lb] > nums[largest])
        largest = lb;
    if(ub <= len && nums[ub] > nums[largest])
        largest = ub;
    if(largest != i){
        swap(nums[largest], nums[i]);
        maxHeapify(nums, largest, len);
    }
}

void buildMaxHeap(vector<int> & nums){
    int len = nums.size();
    for(int i = parent(len - 1); i >= 0; i--){
        maxHeapify(nums, i, len - 1);
    }
}

void deleteMax(vector<int> & nums){
    if(nums.empty())
        return;
    int len = nums.size();
    swap(nums[0], nums[len - 1]);
    maxHeapify(nums, 0, len - 2);
    nums.pop_back();
}

void insert(vector<int> & nums, int num){
    nums.push_back(num);
    int pre = nums.size() - 1;
    int cur = parent(pre);
    while(cur >= 0 && nums[cur] < nums[pre]){
        swap(nums[cur], nums[pre]);
        pre = cur;
        cur = parent(pre);
    }
}



int main(){
    vector<int> vec = {5,6,-1,4,55,28,4322,44,352,678,-6,2,3};

    for(int i = 0;i < vec.size(); i++)
        cout << vec[i]<<" ";
    cout<<endl;

    buildMaxHeap(vec);

    for(int i = 0;i < vec.size(); i++)
        cout << vec[i]<<" ";
    cout<<endl;

    insert(vec, 10000);

    for(int i = 0;i < vec.size(); i++)
        cout << vec[i]<<" ";
    cout<<endl;

    deleteMax(vec);

    for(int i = 0;i < vec.size(); i++)
        cout << vec[i]<<" ";
    cout<<endl;   
    return 0;
}












/*
int left(int i){
    return (i << 1) + 1;
}

int right(int i){
    return (i << 1) + 2;
}

int parent(int i){
    return (i - 1) >> 1;
}

void maxHeapify(vector<int> & nums, int i, int len){
    int largest = i, lb = left(i), ub = right(i);
    if(lb < len && nums[lb] > nums[largest]){
        largest = lb;
    }
    if(ub < len && nums[ub] > nums[largest]){
        largest = ub;
    }
    if(largest != i){
        swap(nums[largest], nums[i]);
        maxHeapify(nums, largest, len);
    }
}

void deleteMax(vector<int> & nums){
    int len = nums.size();
    swap(nums[0], nums[len - 1]);
    maxHeapify(nums, 0, len - 1);
    nums.pop_back();
}

void insert(vector<int> & nums, int val){
    nums.push_back(val);
    int pre = nums.size() - 1;
    int cur = parent(pre);
    while(cur >= 0){
        if(nums[cur] < nums[pre]){
            swap(nums[cur], nums[pre]);
            pre = cur;
            cur = parent(pre);
        }
        else
            break;
    }
}

void buildMaxHeap(vector<int> & nums){
    int len = nums.size();
    for(int i = parent(len - 1); i >= 0; i--){
        maxHeapify(nums, i, len);
    }
}

*/