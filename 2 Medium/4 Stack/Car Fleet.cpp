/*
    n cars 1 road, diff pos/speeds, faster cars slow down -> car fleet, return # fleets
    Ex. target = 12, pos = [10,8,0,5,3], speeds = [2,4,1,1,3] -> 3 (10 & 8, 0, 5 & 3)

    Sort by start pos, calculate time for each car to finish, loop backwards
    If car behind finishes faster then catches up to fleet, else creates new fleet

    Time: O(n log n)
    Speed: O(n)
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        //creates a vector of pair
        //int is the cars starting position and the double is the time it takes for the car to reach the target
        vector<pair<int, double>> cars;
        //goes through all the cars and adds their position and arrival time
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({ position[i], time });
        }
        //sorts the cars from their starting location
        sort(cars.begin(), cars.end());

        double maxTime = 0.0;
        int result = 0;
        //loops through the vector of pairs from the right
        for (int i = n - 1; i >= 0; i--) {
            //creates a variable to store the arrival time of the car
            double time = cars[i].second;
            //if the current car gets there slower than the car in front of it then they never link and never becomes part of the fleet
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }

        return result;
    }
};