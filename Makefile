CC=gcc
FILES = Chortke.c Libs/Processing.c Libs/Processing.h Libs/Stack.c Libs/Stack.h Libs/UI.c Libs/UI.h Libs/bitmap_ploter.c Libs/bitmap_ploter.h

Chortke: Makefile $(FILES)
	$(CC) -o $@ $(FILES) -lm

clean:
	rm -f Chortke *~
