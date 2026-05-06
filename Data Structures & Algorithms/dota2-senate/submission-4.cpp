class Solution {
public:
    int n;

    void remove(string &senate, vector<bool>& removed, char ch, int idx) {

        while(true) {

            if(senate[idx] == ch && removed[idx] == false) {
                removed[idx] = true;
                break;
            }

            idx = (idx + 1) % n;
        }
    }

    string predictPartyVictory(string senate) {

        n = senate.size();   // IMPORTANT

        int R_count = count(begin(senate), end(senate), 'R');
        int D_count = n - R_count;

        int idx = 0;

        vector<bool> removed(n, false);

        while(R_count > 0 && D_count > 0) {

            if(!removed[idx]) {

                if(senate[idx] == 'R') {

                    remove(senate, removed, 'D', (idx+1)%n);
                    D_count--;

                } else {

                    remove(senate, removed, 'R', (idx+1)%n);
                    R_count--;
                }
            }

            idx = (idx + 1) % n;
        }

        return R_count == 0 ? "Dire" : "Radiant";
    }
};