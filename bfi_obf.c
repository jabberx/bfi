/* usage bfi ">[brainfuckcode]<.,+-\"\n" */
#define b break
#define e case
#define u unsigned
#define l else
#define r return
#define w switch
main(int c,char **v) {int i,p=0; u char d[1<<16]; u short j[1<<16];for
(i=0;;i++){if(!v[1][i])b;if(v[1][i]=='['){int o=i,s=0;for(;;){i++;if(v
[1][i]=='[')s++;l if(v[1][i]==']'){if(s>0)s--;l{j[o]=i;j[i]=o;i=o;b;}}
}}}for(i=0;;i++){w(v[1][i]){e 62:p++;b;e 60:p--;b;e 43:d[p]++;b;e 45:d
[p]--;b;e 91:if(!d[p])i=j[i];b;e 93:if(d[p])i=j[i];b;e 46:putchar(d[p]
);b;e 44:d[p]=getchar();d[p]=d[p]==13?10:d[p];b;e 0:r 0;}}}
