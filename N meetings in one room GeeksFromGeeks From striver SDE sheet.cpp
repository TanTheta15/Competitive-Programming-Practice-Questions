/*    N meetings in one room
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/
class meeting{
        public : 
        int starting;
        int ending;
    };
    
    static bool cmp(meeting a, meeting b){
        return a.ending < b.ending;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        meeting meet[n];
        for(int i = 0; i < n; i++){
            meet[i].starting = start[i];
            meet[i].ending = end[i];
        }
        sort(meet, meet + n, cmp);
        
        int ans = 1;
        int limit = meet[0].ending;
        for(int i = 1; i < n; i++){
            if(meet[i].starting > limit){
                ans++;
                limit = meet[i].ending;
            }
        }
        return ans;
    }
