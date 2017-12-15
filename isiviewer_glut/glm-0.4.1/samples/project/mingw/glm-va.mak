NAME = glm-va
BINARY = ../../binary/mingw/$(NAME).exe
SOURCE = ../../source/$(NAME)
BUILD = ../../build/mingw/$(NAME)
EXTERNAL_INCLUDE = -I../../external/include
EXTERNAL_LIBRARY = -L../../external/library/mingw -lmingw32 -mwindows -lSDLmain -lSDL -lopengl32 -lglu32

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

