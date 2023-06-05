no_dependency_c_file := 1768 151 283
CFLAGS = -g

All: $(no_dependency_c_file)

.PHONY: All 

$(no_dependency_c_file): % : %.c
	cc $(CFLAGS) $@.c -o $@

clean:
	rm $(no_dependency_c_file)