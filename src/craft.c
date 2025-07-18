#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "error.h"




int main() {
	//system check
	uint64_t required = 0;
	required += system("which curl > /dev/null 2>&1");
	if (required != 0) {
		log_error("[REQUIRED] curl");
		timber();
	}



}
