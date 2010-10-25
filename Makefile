build: build/blinz/graphics/Graphics.o build/blinz/input/Input.o build/blinz/graphics/Image.o
	g++ -shared -o build/blinz/libBlinzCore.so build/blinz/graphics/Graphics.o build/blinz/input/Input.o
clean:
	rm -r build
install: build
	su -c 'cp build/blinz/libBlinzCore.so /usr/lib64; cp -r src/blinz /usr/include'
build/blinz/graphics/Graphics.o: src/blinz/graphics/Graphics.cpp src/blinz/graphics/Graphics.hpp src/blinz/util/ResourceManager.hpp
	mkdir -p build/blinz/graphics
	g++ -fPIC -c src/blinz/graphics/Graphics.cpp -o build/blinz/graphics/Graphics.o
build/blinz/graphics/Image.o: src/blinz/graphics/Image.cpp
	mkdir -p build/blinz/graphics
	g++ -fPIC -c src/blinz/graphics/Image.cpp -o build/blinz/graphics/Image.o
build/blinz/input/Input.o: src/blinz/input/Input.cpp src/blinz/input/Input.hpp src/blinz/input/Key.hpp
	mkdir -p build/blinz/input
	g++ -fPIC -c src/blinz/input/Input.cpp -o build/blinz/input/Input.o
