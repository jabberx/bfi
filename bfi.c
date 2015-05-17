#include <stdio.h>

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("usage %s \">[brainfuckcode]<.,+-\"\n", argv[0]);
		return 0;
	} else if (argc == 2) {
		int i,ptr=0;
		unsigned char data[65536];
		unsigned int jump[65536];
		
		for (i=0;;i++) {
			if (!argv[1][i]) break;
			if (argv[1][i] == '[') {					
				int o = i, skip = 0;
				for(;;) {
					i++;
					if (argv[1][i] == '[') skip++;
					else if (argv[1][i] == ']') {
						if (skip > 0) {
							skip--;
						} else {
							jump[o] = i;
							jump[i] = o;
							i = o;
							break;
						}
					}
				}
			}
		}
		
		for (i = 0; ; i++) {
			switch(argv[1][i]) {
				case '>': ptr++; break;
				case '<': ptr--; break;
				case '+': data[ptr]++; break;
				case '-': data[ptr]--; break;
				case '[': if (data[ptr] == 0) i = jump[i]; break;
				case ']': if (data[ptr] != 0) i = jump[i]; break;
				case '.': printf("%c", data[ptr]); break;
				case ',': data[ptr] = getc(stdin); if (data[ptr] == 13) data[ptr] = 10; break;
				case 0: return 0;
			}
		}
	}
	
	return 1;
}
