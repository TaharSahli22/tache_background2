all:
	gcc   -c main.c pres.c background.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; 
	gcc    main.o pres.o background.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; 
