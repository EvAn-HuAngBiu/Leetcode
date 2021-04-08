#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            switch(c) {
                case 'U': y -= 1; break;
                case 'D': y += 1; break;
                case 'L': x -= 1; break;
                default: x += 1;
            }
        }
        return x == 0 && y == 0;
    }
};

int main()
{
    return 0;
}