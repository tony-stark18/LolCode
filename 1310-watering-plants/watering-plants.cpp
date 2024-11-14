class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int steps=0;
        int i=0;
        int water=capacity;
        while(i<=n-1)
        {
            if(water-plants[i]>=0)
            {
                water=water-plants[i];
                i++;
                steps++;
            }
            else
            {
                steps=steps+(2*i);
                water=capacity;
            }
        }
        return steps;
    }
};