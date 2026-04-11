class Solution {
public:
    bool isprime(int num){
        if(num<=1){return false;}
        for(int i=2;i*i<=num;i++){
            if(num%i==0){return false;}
        }
    return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ops=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(isprime(nums[i])){
                    continue;
                }
                else{
                    int no=nums[i];
                    while(!isprime(no)){
                        no++;
                        ops++;
                    }
                }
            }
            else{
                if(isprime(nums[i])==false){continue;}
                else{
                    int no=nums[i];
                    while(isprime(no)==true){
                        no++;
                        ops++;
                    }
                }
            }
        }
    return ops;
    }
};