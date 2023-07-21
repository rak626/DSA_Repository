class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.size();
        // find max of True
        int maxT = 0;
        int s = 0, e = 0;
        int cnt = 0;
        while(e < n){
            if(answerKey[e] == 'F') cnt++;

            while(s <= e and cnt > k){
                if(answerKey[s] == 'F') cnt--;
                s++;
            }
            maxT = max(maxT, e - s + 1)
            e++;
        }
        // find max of false

        int maxF = 0;
        s = 0, e = 0;
        cnt = 0;
        while (e < n){
            if(answerKey[e] == 'T') cnt++;

            while(s <= e and cnt > k){
                if(answerKey[s] == 'T') cnt--;
                s++;
            }
            maxF = max(maxF, e - s + 1);
            e++;
        }

        return max(maxF, maxT);
        
    }
};