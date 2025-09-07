#include <iostream>
#include <vector>
using namespace std;

vector <int> solution(vector<int> nums) {
    int size = nums.size();

    for (int gap = size/2; gap>0; gap/=2) {
        for (int j=gap; j < size; j++) {
            int temp = nums[j];
            int i = 0;

            for (i=j; i>=gap && nums[i-gap]>temp; i-=gap) {
                nums[i] = nums[i-gap];
            }
            nums[i] = temp;

        }
    }

    return nums;
}

vector<int> solve_using_cpp_methods(vector<int> nums) {
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<int> nums = {1,2,3,10,5};
    vector<int> ans = solution(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}