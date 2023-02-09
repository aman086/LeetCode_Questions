class Solution {
public:

// when we been specified some row and column.......

bool func(int row , int col , vector<vector<int>>& grid , vector<vector<int>>& finalArr){
    for(int i = row;i<=(row+2);i++){
        vector<int>cur;
        for(int j=col;j<=(col+2);j++){
            if(grid[i][j] > 9) return false;
            cur.push_back(grid[i][j]);
        }
        finalArr.push_back(cur);
    }
    return true;
}   
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
    vector<vector<int>> fir = {{4,3,8} , {9 , 5 , 1} , {2,7,6}};
    vector<vector<int>> sec = {{4,9,2} , {3,5,7} , {8,1,6}};
    vector<vector<int>> third = {{6,7,2} , {1,5,9} , {8,3,4}};
    vector<vector<int>> fourth = {{6,1,8} , {7,5,3} , {2,9,4}};

    vector<vector<int>> fifth = {{8,1,6} , {3,5,7} , {4,9,2}};
    vector<vector<int>> six = {{8,3,4} , {1,5,9} , {6,7,2}};
    vector<vector<int>> seven = {{2,9,4} , {7,5,3} , {6,1,8}};
    vector<vector<int>> eight = {{2,7,6} , {9,5,1} , {4,3,8}};

        int cnt=0;
       for(int rw=0;rw<(row-2);rw++){
           for(int cl=0;cl<(column-2);cl++){
               vector<vector<int>> finalArr;
               if(func(rw , cl , grid , finalArr)){
                      if(finalArr == fir || finalArr == sec || finalArr == third || finalArr == fourth || finalArr == fifth || finalArr == six || finalArr == seven || finalArr == eight)
                           cnt++;
                    }
           }
       }
        return cnt;    
    }
};
