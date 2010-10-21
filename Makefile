build: build/blinz/graphics/Graphics.o build/blinz/input/Input.o
	g++ -shared -o build/blinz/libBlinzCore.so build/blinz/graphics/Graphics.o
build/blinz/graphics/Graphics.o: build/blinz/graphics
	g++ -fPIC -c src/blinz/graphics/Graphics.cpp -o build/blinz/graphics/Graphics.o
build/blinz/input/Input.o: build/blinz/input
	g++ -fPIC -c src/blinz/input/Input.cpp -o build/blinz/input/Input.o
build/blinz/graphics/ResourceManager.o:
	g++ -fPIC -c src/blinz/graphics/ResourceManager.cpp -o build/blinz/graphics/ResourceManager.o
build/blinz/graphics:
	mkdir -p build/blinz/graphics;
build/blinz/input:
	mkdir -p build/blinz/input;
clean:
	rm -r build;
