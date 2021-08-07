#include <stdio.h>
#include <stdlib.h>

#include "ape.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: %s file [args...]\n", argv[0]);
        return 1;
    }
    ape_t *ape = ape_make();

    ape_object_t args_array = ape_object_make_array(ape);
    for (int i = 1; i < argc; i++) {
        ape_object_add_array_string(args_array, argv[i]);
    }
    ape_set_global_constant(ape, "args", args_array);

    FILE *f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, f);
    fclose(f);

    string[fsize] = 0;

    ape_execute(ape, string);
    bool ok = !ape_has_errors(ape);
    if (!ok) {
        int count = ape_errors_count(ape);
        for (int i = 0; i < count; i++) {
            const ape_error_t *err = ape_get_error(ape, i);
            char *err_str = ape_error_serialize(ape, err);
            fprintf(stderr, "%s", err_str);
            ape_free_allocated(ape, err_str);
        }
    }
    ape_destroy(ape);
    if(!ok)
        return 1;
    else
        return 0;
}