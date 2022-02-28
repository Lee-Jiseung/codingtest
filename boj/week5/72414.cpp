#include <string>
#include <vector>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    vector<int> clockToint = { 10 * 60 * 60, 60 * 60, 0, 10 * 60, 60, 0, 10, 1 };

    int playtime = 0;
    int advtime = 0;
    for (int i = 0; i < 8; i++) {
        if (i % 3 == 2) continue;
        playtime += (play_time[i] - 48) * clockToint[i];
        advtime += (adv_time[i] - 48) * clockToint[i];
    }
    
    vector<int> sum(playtime, 0);
    for (int i = 0; i < logs.size(); i++) {
        int starttime = 0, endtime = 0;
        for (int j = 0; j < 8; j++) {
            if (j % 3 == 2) continue;
            starttime += (logs[i][j] - 48) * clockToint[j];
            endtime += (logs[i][j + 9] - 48) * clockToint[j];
        }
        
        for (int j = starttime; j < endtime; j++) {
            sum[j]++;
        }
    }

    long long max = 0;
    int index = 0;
    for (int i = 0; i < advtime; i++) {
        max += sum[i];
    }

    long long prev = max;
    for (int i = 1; i <= sum.size()-advtime; i++) {
        long long temp = prev - sum[i-1] + sum[i + advtime -1];
        if (temp > max) {
            max = temp;
            index = i;
        }
        prev = temp;
    }
    
    string answer = "";
    for (int i = 0; i < 8; i++) {
        if (i % 3 == 2) {
            answer += ':';
            continue;
        }
        int temp = index / clockToint[i];
        answer += temp + 48;
        index = index % clockToint[i];
    }
    return answer;
}