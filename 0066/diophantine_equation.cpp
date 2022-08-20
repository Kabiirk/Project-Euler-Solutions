#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int result = 0;
    uint64_t pmax = 0;

    for(int D = 2; D <= 1000; D++){
        uint64_t limit = (int)sqrt(D);
        if (limit * limit == D){continue;}

        uint64_t m = 0;
        uint64_t d = 1;
        uint64_t a = limit;

        uint64_t numm1 = 1;
        uint64_t num = a;

        uint64_t denm1 = 0;
        uint64_t den = 1;

        while(num*num - D*den*den != 1){
            m = d * a - m;
            d = (D - m * m) / d;
            a = (limit + m) / d;

            uint64_t numm2 = numm1;
            numm1 = num;
            uint64_t denm2 = denm1;
            denm1 = den;

            num = a*numm1 + numm2;
            den = a * denm1 + denm2;
        }

        if (num > pmax) {
            pmax = num;
            result = D;
        }
    }

    cout<<result<<endl;
}
