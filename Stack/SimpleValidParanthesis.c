// Only for round brackets
// Increment counter when encounter ( and decrement when encounter ) if count==0 then it is valid

#include <stdio.h>
#include <string.h>



int isValidParanthesis(char ch[]){
      int count=0;
      for(int i=0;i<strlen(ch);i++){
          if(ch[i]=='(') count++;
          else if(ch[i]==')') count--;
      }

      return count==0;
}

int main(){

    char exp[10]="((()))";

    if(isValidParanthesis(exp)){
        printf("Valid Paranthesis\n");
    }
    else{
        printf("Not an Valid Paranthesis");
    }


    return 0;
}