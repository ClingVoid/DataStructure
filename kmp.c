#include<stdio.h>
#include<string.h>
char s[]= "ABCABABCABX";
char p[]= "ABCABY";
int next[100];
int Next(char* p, int* next) {
	int i = 1;
	int j = 0;
	next[0] = 0;
	int len = strlen(p);
	for (i; i < len; i++) {
		while (p[i] != p[j] && j > 0) {
			j = next[j - 1];
		}
		if (p[i] == p[j]) {
			j++;
		}
		next[i] = j;
	}
	return 1;
}
int position(char* s, char* p) {
	int i = 0;
	int j = 0;
	int len = strlen(s);
	int lenp = strlen(p);
	while (i < len) {
		if (s[i] == p[j]) {
			i++;
			j++;
			if (j == lenp) {
				return i - j;
			}
		}
		if (j == 0) {
			i++;
		}
		else{
			j = next[j - 1];
		}
	}
	return -1;
}