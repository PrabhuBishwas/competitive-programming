#include<bits/stdc++.h>
using namespace std;

bool isVertical(char crossword[10][10],string word,int i,int j){
    int count=0;
    for(int k=0;k<word.length() && i<10;i++,k++){
        if(crossword[i][j]=='-' || crossword[i][j]==word[k]){
            count++;
        }
        else{
            return false;
        }
    }
    if(count!=word.length()){
        return false;
    }
    return true;
}
bool isHorizantal(char crossword[10][10],string word,int i,int j){
    int count=0;
    for(int k=0;j<10 && k<word.length();j++,k++){
        if(crossword[i][j]=='-' || crossword[i][j]==word[k]){
            count++;
        }
        else{
            return false;
        }
    }
    if(count!=word.length()){
        return false;
    }
    return true;
}
void setVertical(char crossword[10][10],bool helperArray[],string word,int i,int j){
    int start=i;
    for(int k=0;i<10 && k<word.length();i++,k++){
        if(crossword[i][j]=='-' || crossword[i][j]==word[k]){
            helperArray[k]=true;
            crossword[i][j]=word[k];
            // cout<<crossword[i][j];
        }
    }
}
void setHorizantal(char crossword[10][10],bool helperArray[],string word,int i,int j){
    int start=j;
    for(int k=0;j<10 && k<word.length();j++,k++){
        if(crossword[i][j]=='-'){
            helperArray[k]=true;
            crossword[i][j]=word[k];
            // cout<<crossword[i][j];
        }
    }
}
void resetVertical(char crossword[10][10],bool helperArray[],string word,int i,int j){
    int start=i;
    for(int k=0;i<10 && k<word.length();i++,k++){
        // cout<<helperArray[i-start]<<endl;
        if(helperArray[k]){
            crossword[i][j]='-';
            helperArray[k]=false;
        }
    }
}
void resetHorizantal(char crossword[10][10],bool helperArray[],string word,int i,int j){
    int start=j;
    for(int k=0;j<10 && k<word.length();j++,k++){
        // cout<<helperArray[j-start]<<endl;
        if(helperArray[k]){
            crossword[i][j]='-';
            helperArray[k]=false;
        }
    }
}
bool crosswordHelper(char crossword[10][10],vector<string> words,int index){
    //basecase can be reaching last index or words in vector becomes o
    // print the crossword
    if(words.size()==index){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        return true;
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(crossword[i][j]=='-' || crossword[i][j]==words[index][0]){
                if(isVertical(crossword,words[index],i,j)){
                    bool helperArrayVertical[words[index].length()]={false};    
                    setVertical(crossword,helperArrayVertical,words[index],i,j);
                    // cout<<"\n\n";
                    // print(crossword);
                    if(!crosswordHelper(crossword,words,index+1)){
                        resetVertical(crossword,helperArrayVertical,words[index],i,j);
                    }
                    else{
                        return true;
                    }
                }
                if(isHorizantal(crossword,words[index],i,j)){
                    // cout<<"line97";
                    bool helperArrayHorizantal[words[index].length()]={false};
                    setHorizantal(crossword,helperArrayHorizantal,words[index],i,j);
                    if(!crosswordHelper(crossword,words,index+1)){
                        resetHorizantal(crossword,helperArrayHorizantal,words[index],i,j);
                    }
                    else{
                        return true;
                    }
                }
            }
        }
    }

    return false;





}

int main() {
    // Write your code here
    //intializing the crossword
    char crossword[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>crossword[i][j];
        }
    }
    string inputwords;
    cin>>inputwords;
    inputwords+=';';
    //cout<<inputwords;
    int j=0;
    //string words[100];
    vector<string> words;
    string word="";
    for(int i=0;i<inputwords.length();i++){
        if(inputwords[i]!=';')
            word=word+inputwords[i];
        else{
            words.push_back(word);
            j++;
            word="";
        }        
    }
    // for(int i=0;i<words.size();i++){
    //     cout<<words[i]<<endl;
    // }
    crosswordHelper(crossword,words,0);


}
