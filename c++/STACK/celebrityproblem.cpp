// int findCelebrityInOutDegree(vector<vector<int>>& M, int n) {
//     vector<int> indegree(n, 0);
//     vector<int> outdegree(n, 0);

//     // Build indegree and outdegree arrays
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (M[i][j] == 1) {
//                 outdegree[i]++;  // i knows j
//                 indegree[j]++;   // j is known by i
//             }
//         }
//     }

//     // Check for celebrity
//     for (int i = 0; i < n; i++) {
//         if (indegree[i] == n - 1 && outdegree[i] == 0)
//             return i;  // celebrity found
//     }

//     return -1; // no celebrity
// }


// Celebrity Problem: Find the celebrity in a group of people
//   stack approach
  

// int findCelebrityStack(vector<vector<int>>& M, int n) {
//     stack<int> s;
//     for (int i = 0; i < n; i++) s.push(i);

//     while (s.size() > 1) {
//         int a = s.top(); s.pop();
//         int b = s.top(); s.pop();

//         if (M[a][b] == 1) s.push(b); // a can't be celeb
//         else s.push(a);              // b can't be celeb
//     }

//     int candidate = s.top();

//     // Verify candidate
//     for (int i = 0; i < n; i++) {
//         if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
//             return -1;
//     }

//     return candidate;
// }

//two pointer approach
// int findCelebrityTwoPointer(vector<vector<int>>& M, int n) {
//     int a = 0, b = n - 1;
//     while (a < b) {
//         if (M[a][b] == 1) a++; // a knows b -> a can't be celeb
//         else b--;              // a doesn't know b -> b can't be celeb
//     }

//     // Verify candidate a
//     for (int i = 0; i < n; i++) {
//         if (i != a && (M[a][i] == 1 || M[i][a] == 0))
//             return -1;
//     }
//     return a;
// }

