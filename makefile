SOURCES = dp/uva1220.cc

main: $(SOURCES)
	g++ -DXDebug=1 -std=c++11 $< -o app
