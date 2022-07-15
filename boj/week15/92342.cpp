#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);
    long long iterations = 0L;
    int maxDifference = 0;
    
    for(int i0 = 0; i0<=n; i0++) {
        for(int i1=0; i1<=n-i0;i1++) {
            for(int i2=0; i2<=n-i0-i1;i2++) {
                for(int i3=0; i3<=n-i0-i1-i2;i3++) {
                    for(int i4=0; i4<=n-i0-i1-i2-i3;i4++) {
                        for(int i5=0; i5<=n-i0-i1-i2-i3-i4;i5++) {
                            for(int i6=0; i6<=n-i0-i1-i2-i3-i4-i5;i6++) {
                                for(int i7=0; i7<=n-i0-i1-i2-i3-i4-i5-i6;i7++) {
                                    for(int i8=0; i8<=n-i0-i1-i2-i3-i4-i5-i6-i7;i8++) {
                                        for(int i9=0; i9<=n-i0-i1-i2-i3-i4-i5-i6-i7-i8;i9++) {
                                            int i10 = n - (i0+i1+i2+i3+i4+i5+i6+i7+i8+i9);
                                            iterations++;
                                            int lion = 0, apeach = 0;
                                            vector<int> temp = {i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};

                                            for(int i=0; i<10; i++) {
                                                if(info[i] < temp[i]) lion += 10-i;
                                                else {
                                                    if(info[i] == temp[i] && info[i] == 0) continue;
                                                    apeach += 10-i;
                                                }
                                            }

                                            int d = lion - apeach;
                                            if(d > maxDifference) {
                                                maxDifference = d;
                                                temp.swap(answer);
                                            }else if(d == maxDifference) {
                                                for(int i=0; i<11; i++) {
                                                    if(temp[10-i] > answer[10-i]) {
                                                        temp.swap(answer);
                                                        break;
                                                    }else if(temp[10-i] < answer[10-i]) {
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //cout<<iterations <<' '<< maxDifference;
    return maxDifference == 0 ? vector<int>(1, -1) : answer;
}