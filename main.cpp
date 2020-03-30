#include "mainHead.h"
#include "glog/logging.h"
#define GOOGLE_GLOG_DLL_DECL


int main(int argc, char *argv[])
{
#if 0
    vector<int> nums(5, 0);
    nums[1] = 1;
    nums[2] = 1;
    nums[3] = 4;
    nums[4] = 4;
    Solution solution;
    cout << solution.removeDuplicates(nums) << endl;
#endif
    google::InitGoogleLogging(argv[0]);
    //google::SetLogDestination(google::GLOG_INFO, "d:\\Logs\\INFO_");
    string ss = "abacbacabccbb";
    Solution solution;
    solution.longestPalindrome(ss);
    system("pause");
    google::ShutdownGoogleLogging();
    return 0;
}