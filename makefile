SOURCES = 688/D.cc

main: $(SOURCES)
	g++ -DXDebug=1 -std=c++11 $< -o app
