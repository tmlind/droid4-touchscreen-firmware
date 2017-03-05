#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "qtouch_obp_ts_firmware.h"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

int main(int argc, char **argv)
{
	struct touch_fw_entry *fw;
	FILE *f;
	int i;

	for (i = 0; i < ARRAY_SIZE(touch_fw_table); i++) {
		fw = &touch_fw_table[i];
		printf("Checking firmware%i family: %i variant: %i..\n", i,
		       fw->family_id, fw->variant_id);

		if ((fw->family_id == 129) && (fw->variant_id == 1)) {
			printf("Found match\n");
			break;
		}
	}

	f = fopen("maxtouch.fw", "wb");
	if (!f) {
		printf("Could not open file\n");
		return 1;
	}

	fwrite(fw->image, fw->size, 1, f);

	fclose(f);

	return 0;
}
