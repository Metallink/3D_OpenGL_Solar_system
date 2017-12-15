NAME = glm-va
BINARY = ../../binary/gcc/$(NAME)
SOURCE = ../../source/$(NAME)
BUILD = ../../build/gcc/$(NAME)
EXTERNAL_INCLUDE = -I../../external/include
EXTERNAL_LIBRARY = -L../../external/library/gcc -L/usr/X11R6/lib -L/usr/contrib/X11R6/lib -lX11 -lXext -lGL -lGLU -lSDL

OPTION = -O2 -Wall #-pedantic

OBJECT = \
	$(BUILD)/main.o\
	$(BUILD)/sample.o

all: object $(BINARY) clean

object:
	mkdir $(BUILD)

clean:
	rm -R $(BUILD)

$(BINARY): $(OBJECT)
	g++ -s -o $(BINARY) $^ $(EXTERNAL_LIBRARY)

$(BUILD)/%.o: $(SOURCE)/%.cpp
	g++ $(EXTERNAL_INCLUDE) -o $@ -c $< $(OPTION)

