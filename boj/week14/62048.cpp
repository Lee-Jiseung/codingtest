#include <cmath>
#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w*h;
    
    
    long long prev = 0L;
    for(int i=1;i<=w;i++) {
        double d = (double) h * i / w;
        
        answer -= (long long) ceil(d) - prev;
        prev = floor(d);
    }
    return answer;
}