SHELL = /bin/bash
FLAGS = -Wall -std=gnu99 -g
.PHONY: test_trim test_trcount clean

all: trim trcount

%.o: %.c 
	gcc ${FLAGS} -c $<

trim : trim.c
	gcc ${FLAGS} -o $@ $^ 

trcount : trcount.c
	gcc ${FLAGS} -o $@ $^

test_trim: trim
	@test_trim_output=`./trim sample-full-simple.tr sample-marker-simple | cmp sample-trim-output`; \
	if [ -z "$$test_trim_output" ]; then \
		echo "Compiled and trim check passed :)"; \
	else \
	 	echo "Failed trim check"; \
	fi

test_trcount: trcount
	@test_trcount_output=`./trcount sample-trim-output | cmp sample-trcount-output`; \
	if [ -z "$$test_trcount_output" ]; then \
		echo "Compiled and trcount check passed :)"; \
	else \
	 	echo "Failed trcount check"; \
	fi

clean:
	-rm -f *.o trim trcount
