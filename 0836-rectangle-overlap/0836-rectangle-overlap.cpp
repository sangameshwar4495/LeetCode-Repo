class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // // O(1) la try 
        // // first case (ex1 laga untadi))
        // if(rec2[0]<rec1[3] && rec2[0]>rec1[0]) return 1; // bl corner is rec2
        // else if(rec2[3]>rec1[0] && rec2[3]<rec1[3]) return 1;
        // // edges overlap partially
        // if(rec1[0]==rec2[0] && rec1[3]==rec2[3]){
        //     // check if tr is btw the edge
        //     if(rec1[3]>rec2[1] && rec1[3]<rec2[3]) return 1;
        // }
        // return 0;

        int x1 = rec1[0];
        int y1 =  rec1[1];
        int x2 = rec1[2];
        int y2 =  rec1[3];

        int x3 = rec2[0];
        int y3 =  rec2[1];
        int x4 = rec2[2];
        int y4 =  rec2[3];


        if(x3>=x2 || y3>=y2 || x4<=x1 || y4<=y1) return false;
        return true;
    }
};