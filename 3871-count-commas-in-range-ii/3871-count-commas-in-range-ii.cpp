// class Solution {
// public:
//     long long countCommas(long long n) {
//         if(n<1000) return 0;
//         long long count=0;
        
//         while(n>=1000){
//             if(n==1e15){
//                 count+=5;
//                 n=1e15-1;
//             }
//             if(n<=1e15-1 && n>=1e12){
//                 count+=((n-1e12)+1)*4;
//                 n=1e12-1;
//             }
//             if(n<=1e12-1 && n>=1e9){
//                 count+=((n-1e9)+1)*3;
//                 n=1e9-1;
//             }
//             if(n<=1e9-1 && n>=1e6){
//                 count+=((n-1e6)+1)*2;
//                 n=1e6-1;
//             }
//             if(n<=1e6-1 && n>=1e3){
//                 count+=((n-1e3)+1)*1;
//                 n=999;
//             }
            
//         }
//         return count;
//     }
// };
class Solution {
public:
      long long countCommas(long long n) {
        long long res = 0, p;
        for (p = 1000; p <= n; p *= 1000)
            res += n - p + 1;
        return res;
    }
};