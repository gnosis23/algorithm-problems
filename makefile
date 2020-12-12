SOURCES = Codeforces/689/E.cc

main: $(SOURCES)
	g++ -DXDebug=1 -std=c++11 $< -o app
