#include"BracketMatch.c"
#include<stdlib.h>
#include<string.h>


void TestBracket(){
    const char* Seqs[] = {
        "(())abc{[(])}",
        "(()))abc{[]}",
        "(()()abc{[]}",
        "(())abc{[]()}"
    };

    for(int i = 0; i < 4; i++){
        BracketMatch(Seqs[i], strlen(Seqs[i]));
    }
}


int main(){
    TestBracket();

    return 0;
}
