// class Solution {
//   private:
//       int f(int mid, int a[], int n, int d){
//           int wt_added=0;
//           int days=1;
//           for(int i=0;i<n;i++){
//               wt_added+=a[i];
//               if(wt_added>mid){
//               days++;
//               wt_added=a[i];
//               }
//           }
//           if(days>=d) return 0;
//           return 1;
//       }
//   public:
//     int leastWeightCapacity(int arr[], int N, int D) {
//         // code here
//         int l=*max_element(arr,arr+N);
//         int r=accumulate(arr, arr+N, r);
//         //return r;
//         if(D>=N) return *max_element(arr,arr+N);
//         while(l+1<r){
//             int mid=l+(r-l)/2;
//             if(f(mid,arr,N,D)==0) l=mid;
//             else r=mid;
//         }
//         return r;
//     }
// };