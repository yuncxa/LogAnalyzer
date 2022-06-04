main:installSo installFunction installMain

installSo:
	gcc Structure.c -fPIC -shared -o libStructure.so

installFunction:
	gcc -c ReadFile.c
	ar -r libReadFile.a ReadFile.o
	gcc -c TimeList.c
	ar -r libTimeList.a TimeList.o
	gcc -c RegionList.c
	ar -r libRegionList.a RegionList.o
	gcc -c IPLocator.c
	ar -r libIPLocator.a IPLocator.o

installMain:
	# export LD_LIBRARY_PATH=/usr/local/lib:D_LIBRARY_PATH
# gcc -c main.c
# gcc -o LogAnalyzer main.o libStructure.so libIPLocator.a libReadFile.a libTimeList.a 
	# gcc -o LogAnalyzer main.c -L./usr/lib/ -lStructure -static -L. -lIPLocator -static -L. -lReadFile -static -L. -lRegionList -static -L. -lTimeList
	gcc main.c Structure.c TimeList.c -static ReadFile.c -static RegionList.c -static IPLocator.c -static -o LogAnalyzer

install:
	sudo cp libStructure.so /usr/local/lib/
	# [sudo] password for yunxi-server: 
	sudo cp libReadFile.a /usr/local/lib/
	sudo cp libTimeList.a /usr/local/lib/
	sudo cp libRegionList.a /usr/local/lib/
	sudo cp libIPLocator.a /usr/local/lib/
