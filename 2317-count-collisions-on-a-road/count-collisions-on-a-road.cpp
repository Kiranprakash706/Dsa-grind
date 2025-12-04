#include <string>
using std::string;

class Solution {
public:
    int countCollisions(const string &directions) {
        int collisions = 0;
        int pendingR = 0;              // count of consecutive 'R' seen and not yet resolved
        bool hasCollisionOccurred = false; // true once we have seen an 'S' or a resolved "R...L" collision

        for (char c : directions) {
            if (c == 'R') {
                // accumulate right-moving cars to be potentially collided later
                ++pendingR;
            } else if (c == 'L') {
                if (pendingR > 0) {
                    // an 'L' meets pending 'R's -> all those R's collide and L also collides
                    hasCollisionOccurred = true;
                    collisions += (pendingR + 1); // pending R's + this L
                    pendingR = 0;
                } else if (hasCollisionOccurred) {
                    // no pending R, but previous collisions produced a stationary car -> this L will hit it
                    ++collisions;
                }
            } else /* c == 'S' */ {
                // stationary car: any pending R's will collide into it
                hasCollisionOccurred = true;
                collisions += pendingR;
                pendingR = 0;
            }
        }

        return collisions;
    }
};