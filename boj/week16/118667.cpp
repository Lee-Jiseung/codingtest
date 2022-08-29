#include <string>
#include <vector>
#include <deque>

#define ll long long
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 1000000000;
    int n = queue1.size();
    deque<ll> d;
    ll sum1 = 0L, sum2 = 0L;
    
    for(int i=0; i<n; i++) {
        d.push_back((ll) queue1[i]);
        sum1 += queue1[i];
    }
    for(int i=0; i<n; i++) {
        d.push_back((ll) queue2[i]);
        sum2 += queue2[i];
    }
    
    if((sum1+sum2) %2 == 1) return -1;
    else if(sum1==sum2) return 0;
    ll mid = (sum1+sum2) /2;
   
    int j=n;
    ll sum = 0L;
    for(int i=0; i<n; i++) {
        for(;j<n+n;j++) {
            if(sum1+sum == mid) {
                answer = min(answer, i+j-n+i);
                break;
            }else if(sum1+sum>mid) {
                if(sum==0) {
                    break;
                }
                sum -=d[j-1];
                j--;
                break;
            }
            sum += d[j];
        }
        
        ll temp = d.front();
        d.pop_front();
        sum1 -= temp;
        sum2 += temp;
        d.push_back(temp);
        j--;
    }
    
    deque<ll>().swap(d);
    sum1 = 0L, sum2 = 0L;
    for(int i=0; i<n; i++) {
        d.push_back((ll) queue2[i]);
        sum1 += queue2[i];
    }
    for(int i=0; i<n; i++) {
        d.push_back((ll) queue1[i]);
        sum2 += queue1[i];
    }
    j=n;
    sum = 0L;
    for(int i=0; i<n; i++) {
        for(;j<n+n;j++) {
            if(sum1+sum == mid) {
                answer = min(answer, i+j-n+i);
                break;
            }else if(sum1+sum>mid) {
                if(sum==0) {
                    break;
                }
                sum -=d[j-1];
                j--;
                break;
            }
            sum += d[j];
        }
        
        ll temp = d.front();
        d.pop_front();
        sum1 -= temp;
        sum2 += temp;
        d.push_back(temp);
        j--;
    }
    return answer==1000000000?-1:answer;
}