class Solution {
public:
    double angleClock(int hour, int minutes) {

        double angleOfHour = (hour%12)*30 + (double)minutes/2;
        double angleOfMin = minutes*6;
        double x = max(angleOfHour, angleOfMin) - min(angleOfHour, angleOfMin);
        return min(x, 360-x);

    }
};
