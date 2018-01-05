CXX = cl
CXXFLAGS = /EHsc /nologo
LD = link
LDFLAGS = /nologo
LDLIBS =
RM = del

MAIN_EXECUTABLE = main.exe

all: $(MAIN_EXECUTABLE)
.PHONY: all

clean:
	$(RM) *.obj
.PHONY: clean

distclean: clean
	$(RM) $(MAIN_EXECUTABLE)
.PHONY: distclean

$(MAIN_EXECUTABLE): main.obj sort.obj
	$(LD) $(LDFLAGS) $(LDLIBS) $^ /OUT:$@

%.obj: %.cpp %.h
	$(CXX) $(CXXFLAGS) /c $<