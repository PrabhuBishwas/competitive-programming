/* Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.” */

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int num_codes_i(int* n, int size){
    int* output = new int[size+1];
    output[0]=1;
    output[1]=1;
    for(int i=2; i<=size; i++){
        if(n[i-1]>0)
            output[i] = output[i-1]%MOD;
        else
            output[i]=0;
        if(n[i-2]*10 + n[i-1]>9 && n[i-2]*10 + n[i-1]<=26){
            output[i] = (output[i]%MOD + output[i-2]%MOD)%MOD;
        }
    }
    int ans = output[size];
    delete [] output;
    return ans;
}

int main()
{
    string s;
    while(1){
        cin>>s;
        if(s=="0"){
            break;
        }
        int size = s.size();
        int* n = new int[size];
        for(int i=0; i<size; i++){
            n[i] = s[i]-'0';
        }
        cout<<num_codes_i(n, size)<<endl;
         
    }
    return 0;
}
