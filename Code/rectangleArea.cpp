//generalized calculation
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        int h = max(0,min(D,H)-max(B,F));
        int w = max(0,min(C,G)-max(E,A)); 
        int overlap = h*w;
        return area1- overlap +area2;
    }
};
//original
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        if(E>=C || G<=A || B>=H || D<=F) return area1+area2;
        int h = D>=H? H-max(B,F):D-max(F,B);
        int w = A<=E? min(C,G)-E:min(G,C)-A; 
        return area1+area2 - h*w;
    }
};
