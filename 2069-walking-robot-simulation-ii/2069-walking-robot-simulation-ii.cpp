class Robot {
private:
    int x, y, width, height;
    string dir;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        dir = "East";
    }
    
    void step(int num) {
        int perimeter = 2 * (width + height) - 4;
        num %= perimeter;

        // edge case
        if(num == 0 && (x == 0 && y == 0)) {
            dir = "South";
            return;
        }

        while(num--) {
            if(dir == "East") {
                if(x + 1 < width) x++;
                else {
                    dir = "North";
                    y++;
                }
            }
            else if(dir == "North") {
                if(y + 1 < height) y++;
                else {
                    dir = "West";
                    x--;
                }
            }
            else if(dir == "West") {
                if(x - 1 >= 0) x--;
                else {
                    dir = "South";
                    y--;
                }
            }
            else { // South
                if(y - 1 >= 0) y--;
                else {
                    dir = "East";
                    x++;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dir;
    }
};