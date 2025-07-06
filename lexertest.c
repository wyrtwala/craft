#include "lexer.h"
#include <stdio.h>





int main() {
	FILE *fd = fopen("example.anvl", "r+");
	token tiktak = get_tok(fd);
	while (true) {
		if (tiktak.TOK != TOK_EOF) {
			printf("type: %lu :: element: %s\n", tiktak.TOK, tiktak.ELEMENT);
			tiktak = get_tok(fd);
		} else {
			printf("type: %lu :: element: EOF\n", tiktak.TOK);
			break;
		}
	}
}
