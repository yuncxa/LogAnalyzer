main:installSo installFunction
	gcc -o LogAnalyzer main.c -Iinclude installFunction.a -I ./include/ -L ./ -l Structure
installSo:
	gcc Structure.c -fPIC -shared -o libStructure.so
	# gcc -c Structure.c
	# ar -r Structure.a Structure.o
installFunction:
	gcc -c ReadFile.c
	gcc -c TimeList.c
	gcc -c RegionList.c
	gcc -c IPLocator.c
	ar -r libinstallFunction.a IPLocator.o ReadFile.o TimeList.o RegionList.o
installMain:
	# export LD_LIBRARY_PATH=/usr/local/lib:D_LIBRARY_PATH
# gcc -c main.
# gcc -o LogAnalyzer main.o libStructure.so libIPLocator.a libReadFile.a libTimeList.a 
	# gcc -o LogAnalyzer main.c -L./usr/lib/ -lStructure -static -L. -lIPLocator -static -L. -lReadFile -static -L. -lRegionList -static -L. -lTimeList	
install:
	sudo cp libStructure.so /usr/lib/
	sudo cp libinstallFunction.a ./lib/
	