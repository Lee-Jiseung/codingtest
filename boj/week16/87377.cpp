#include <string>
#include <vector>
#include <set>
#include <climits>
#define ll long long

using namespace std;

vector<string> solution(vector<vector<int>> line) {

    ll minx = LLONG_MAX, maxx = LLONG_MIN;
    ll miny = LLONG_MAX, maxy = LLONG_MIN;
    set<pair<ll, ll>> v;
    ll a, b, c, x, y;
    
    for(int i=0; i<line.size(); i++) {
        for(int j=i+1; j<line.size(); j++) {
            a = (long long)line[i][0]*line[j][1] - (long long)line[i][1]*line[j][0];
            if(a == 0L) continue;
            
            b = (long long)line[i][1]*line[j][2] - (long long)line[i][2]*line[j][1];
            c = (long long)line[i][2]*line[j][0] - (long long)line[i][0]*line[j][2];
            if((b/a)*a == b && (c/a)*a==c) {
                x = b/a;
                y = c/a;
               
                v.insert({x, y});
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);
            }
        }
    }
    
    string temp = "";
    for(ll j=0L; j<=maxx-minx; j++) {
        temp += '.';
    }
    
    vector<string> answer(maxy-miny+1L, temp);
    for(set<pair<ll, ll>>::iterator iter = v.begin(); iter != v.end(); iter++) {
        answer[maxy - iter->second][iter->first - minx] = '*';
    }
    
    return answer;
}