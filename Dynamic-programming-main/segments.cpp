/*
Вам дан 2D-целочисленный массив событий с индексом 0, где events[i] = [startTimei, endTimei, valuei]. 
Событие i начинается в startTimei и заканчивается в endTimei, и если вы посетите это событие, вы получите значение valuei. 
Вы хотите выбрать непересекающиеся события для посещения, чтобы сумма их значений была максимальной.

Верните эту максимальную сумму.

Обратите внимание, что время начала и время окончания являются включительными: 
то есть вы не можете посетить два события, одно из которых начинается, а другое заканчивается в одно и то же время.
Более конкретно, если вы посещаете событие со временем окончания t, следующее событие должно начаться в t + 1 или позже.
*/

struct sum {
    int val, end;
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<sum> dp = {{0, 0}};
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];   
        });
        for (vector<int> event: events) {
            printf("{%d,%d,%d}\t", event[0], event[1], event[2]);
        }
        printf("\n");
        int l, r, mid;
        for (vector<int> event: events) {
            l = 0, r = dp.size();
            while (l+1 < r) {
                mid = (l+r)/2;
                (dp[mid].end >= event[0]? r: l) = mid;
            }
            if (dp.back().val < dp[l].val + event[2]) {
                dp.push_back({dp[l].val+event[2], event[1]});
            }
        }
        return dp.back().val;
    }
};
