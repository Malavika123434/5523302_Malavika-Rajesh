#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* caesarCipher(char* s, int k) {
    int len = strlen(s);
    k = k%26; 
    for (int i=0;i<len;i++) {
        if (s[i]>='a'&& s[i]<='z') {
            
            s[i]='a'+(s[i]-'a'+k)%26;
        } else if (s[i]>='A' && s[i]<='Z') {
            
            s[i]='A'+(s[i]-'A'+k)%26;
        }
        
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    char* s = (char*)malloc(10240 * sizeof(char));
    scanf("%s", s);
    int k;
    scanf("%d", &k);

    char* result=caesarCipher(s, k);
    printf("%s\n", result);

    free(s); 
    return 0;
}
