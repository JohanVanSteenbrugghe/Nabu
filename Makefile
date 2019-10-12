all: clean libraries models helpers collections main release

release: build\sqlite3.o build\Dictionary.o build\Word.o build\CommandHelper.o build\SQLiteHelper.o build\StringHelper.o build\DictionaryCollection.o build\WordCollection.o build\Main.o
	g++ -g build\Sqlite3.o build\Dictionary.o build\Word.o build\CommandHelper.o build\SQLiteHelper.o build\StringHelper.o build\DictionaryCollection.o build\WordCollection.o build\Main.o -o bin\Main.exe

main: src\Main.cpp
	g++ -c src\Main.cpp -o build\Main.o

collections: src\Collections\DictionaryCollection.cpp src\Collections\WordCollection.cpp
	g++ -c src\Collections\DictionaryCollection.cpp -o build\DictionaryCollection.o && g++ -c src\Collections\WordCollection.cpp -o build\WordCollection.o

helpers: src\Helpers\CommandHelper.cpp src\Helpers\SQLiteHelper.cpp src\Helpers\StringHelper.cpp
	g++ -c src\Helpers\CommandHelper.cpp -o build\CommandHelper.o && g++ -c src\Helpers\SQLiteHelper.cpp -o build\SQLiteHelper.o && g++ -c src\Helpers\StringHelper.cpp -o build\StringHelper.o

models: src\Models\Dictionary.cpp src\Models\Word.cpp
	g++ -c src\Models\Dictionary.cpp -o build\Dictionary.o && g++ -c src\Models\Word.cpp -o build\Word.o

libraries: lib\sqlite3.c lib\sqlite3.h
	gcc -c lib\sqlite3.c -o build\Sqlite3.o

clean:
	del bin\*.exe 2>nul
	del build\*.o 2>nul