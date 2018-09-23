ifeq ($(OS), Windows_NT)
	TARGET = main.exe
	CLEAN = -del *.o $(TARGET)
else
	TARGET = main
	CLEAN = rm *.o $(TARGET)
endif

all: $(TARGET)

$(TARGET): main.o getFileList.o
	 g++ -o $(TARGET) main.o getFileList.o

main.o: src/main.cpp
	 g++ -std=c++11 -O3 -c src/main.cpp
	 
getFileList.o: src/utils/getFileList.cpp
	 g++ -std=c++11 -O3 -c src/utils/getFileList.cpp
	 
clean:
	 $(CLEAN)