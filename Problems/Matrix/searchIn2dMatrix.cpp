/*
S1-> O(mn)
S2-> O(m+logn) 
S3-> O(logm+n)
S4-> O(min(m, n)*log(max(m, n)))
S5-> O(logm+logn)
S6-> O(mn+logmn) time, O(mn) extra space
S7-> O(logmn)
*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

/*Solution1 - 
By traversing the whole matrix*/
class Solution { //O(mn) time
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(matrix[i][j]==target) return true;
        return false;
    }
};

/*Solution2 - Since the rows are sorted, so apply binary search in each row*/
class Solution { //O(m+logn)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), low, high, mid;
        int n = matrix[0].size();
        for(int i = 0; i<m; i++) {
            low = 0; high = n-1;
            while(low<=high) {
                mid = low+(high-low)/2;
                if(matrix[i][mid]==target) return true;
                if(matrix[i][mid]>target) high = mid-1;
                else low = mid+1;
            }
        }
        return false;
    }
};

/*Solution3 - Since the columns are sorted, so apply binary search in each column*/
class Solution { //O(logm+n)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), low, high, mid;
        int n = matrix[0].size();
        for(int j = 0; j<n; j++) {
            low = 0; high = m-1;
            while(low<=high) {
                mid = low+(high-low)/2;
                if(matrix[mid][j]==target) return true;
                if(matrix[mid][j]>target) high = mid-1;
                else low = mid+1;
            }
        }
        return false;
    }
};

/*Solution4 - We can combine Solution2 and Solution3, apply binary search on the dimension which is maximum, it will minimize the complexity*/
class Solution { //O(min(m, n)*log(max(m, n)))
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), low, high, mid;
        int n = matrix[0].size();
        int maxDimension = max(m, n);
        int minDimension = min(m, n);
        for(int i = 0; i<minDimension; i++) {
            low = 0; high = maxDimension-1;
            if(maxDimension==n) {
                while(low<=high) {
                    mid = low+(high-low)/2;
                    if(matrix[i][mid]==target) return true;
                    if(matrix[i][mid]>target) high = mid-1;
                    else low = mid+1;
                }
            } else {
                while(low<=high) {
                mid = low+(high-low)/2;
                if(matrix[mid][i]==target) return true;
                if(matrix[mid][i]>target) high = mid-1;
                else low = mid+1;
                }
            }
        }
        return false;
    }
};

/*Solution5 - Since both dimensions are sorted, so apply binary search on the rows and column
complexity will be (logm+logn) but in worst case it will be O(mlogn)*/
class Solution { //O(logm+logn)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), low, high, cMid;
        int n = matrix[0].size();
        int start = 0, end = m-1,rMid;
        while(start<=end) {
            rMid = start+(end-start)/2;
            if(matrix[rMid][0]==target) return true;
            if(matrix[rMid][0]<target) {
                low = 0, high = n-1;
                while(low<=high) {
                    cMid = low+(high-low)/2;
                    if(matrix[rMid][cMid]==target) return true;
                    if(matrix[rMid][cMid]>target) high = cMid-1;
                    else low = cMid+1;
                }
                start = rMid+1;
            } else end = rMid-1;
        }
        return false;
    }
};

/*Solution6 - Make an 1D array of size mn and store the elements of matrix in the array, and now apply binary search on the array*/
class Solution { //O(mn+logmn) time, O(mn) extra space
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        vector<int> arr(m * n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                arr[n * i + j] = matrix[i][j];

        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) return true;
            if (arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return false;
    }
};

/*Solution7 - Instead of creating an array we can take an imaginary 1d array and work with it, we can locate the (i)th element of the array in the matrix*/
class Solution { //O(logmn)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(!m || !n) return false;

        int low = 0, high = m*n-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            int ri = mid/n;
            int ci = mid%n;
            if(matrix[ri][ci]==target) return true;
            if(matrix[ri][ci]>target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};
