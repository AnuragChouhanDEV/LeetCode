// https://leetcode.com/problems/walking-robot-simulation-ii/description/

class Robot {
public:
    // vector of width*2 + (height-2)*2 = entire perimeter
    // pair<direction, pair<x,y>>
    /*
        0   0   0   0   0   0
        0   0   0   0   0   0
        0   0   0   0   0   0
        6*2 * (3-2)*2 = 14
    
    */
    vector<pair<string,pair<int,int>>> vec;
    // current position
    int pos;
    int size;
    bool start;
    Robot(int width, int height) {
        vec.resize(width*2 + ((height-2)*2));
        pos = 0;
        int tmp = 1;
        size = width*2 + ((height-2)*2);
        vec[0] = {"South", {0,0}};
        start = false;
        for(int i=1; i < width; i++){
            vec[tmp++] = {"East",{i,0}};
        }
        for(int i=1; i<height; i++){
            vec[tmp++] = {"North",{width-1,i}};
        }
        for(int i=width-2; i>=0; i--){
            vec[tmp++] = {"West",{i,height-1}};
        }

        for(int i=height-2; i>0; i--){
            vec[tmp++] = {"South",{0,i}};
        }
    }
    
    void step(int num) {
        start = true;
        pos = pos + num;
        pos = pos % size;
    }
    
    vector<int> getPos() {
        return {vec[pos].second.first, vec[pos].second.second};
    }
    
    string getDir() {
        if (!start) return "East";
        return vec[pos].first;
    }
#if 0 // TLE
    int x, y, width, height;
    int dir;
    vector<string> vec = {"East","North","West","South"};
    vector<int> d = {1,1,-1,-1};
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x=0;
        y=0;
        dir = 0;
    }
    
    void step(int num) {
        while(num--) {
            dir = dir % 4;
            if (dir == 0) {
                if (x + d[dir] < width) x++;
                else {dir++;y++;}
                cout << x << " " << y << " " << dir << endl;
                continue;
            } else if (dir == 1) {
                if (y + d[dir] < height) y++;
                else {dir++;x--;}
                cout << x << " " << y << " " << dir << endl;
                continue;
            } else if (dir == 2) {
                if (x + d[dir] >= 0) x--;
                else {dir++;y--;}
                cout << x << " " << y << " " << dir << endl;
                continue;
            } else if (dir == 3) {
                if (y + d[dir] >= 0) y--;
                else {dir++;x++;}
                cout << x << " " << y << " " << dir << endl;
                continue;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return vec[dir%4];
    }
#endif
};

/*
    0   0   0   0   0   0   0   0
    0   0   0   0   0   0   0   0

    6+6+1+1
*/

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */