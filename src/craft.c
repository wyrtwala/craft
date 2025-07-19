#include "lib/lexer.h"
#include "lib/error.h"




int main() {
	//system check
	uint64_t required = 0;
	required += system("which curl > /dev/null 2>&1");
	if (required != 0) {
		log_error("[REQUIRED] curl");
	}
	required += system("which fasm > /dev/null 2>&1");
	if (required != 0) {
		log_error("[REQUIRED] fasm");
		destroy_craft();
	}

}
