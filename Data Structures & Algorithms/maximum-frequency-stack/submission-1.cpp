class FreqStack {
public:

    unordered_map<int,int> freq;

    priority_queue<vector<int>> pq;

    int idx = 0;

    FreqStack() {
        
    }
    
    void push(int val) {

        freq[val]++;

        pq.push({freq[val], idx, val});

        idx++;
    }
    
    int pop() {

        int val = pq.top()[2];
        pq.pop();

        freq[val]--;

        return val;
    }
};