funcional:
	g++ src/*.cpp test/funcional/*.cpp -o build/funcionalTests

unit:
	g++ src/*.cpp test/unit/*.cpp -o build/unitTests

clean: 
	rm -f *.o main

run:
	./main