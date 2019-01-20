
GPP = g++ 

CSOURCEFILES = $(wildcard *.cpp)
COBJECTFILES = $(notdir $(patsubst %.cpp,%.o,$(CSOURCEFILES)))

all : dot11



dot11 : $(CSOURCEFILES)
	$(GPP) -o $@ $^ -lpcap

clean:
	rm -f *.o
	rm -f dot11

