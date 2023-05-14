OPT	:= #-O2
DEBUG	:= -g
CXX	:= g++ $(DEBUG) $(OPT)
LIBS	:= -lwebp -lfreetype

# textformatter: textformatter.cc
#	$(CXX) $< -o $@ -lwebp

# these are the objects that make up the program
OBJ	:= font.o font_face.o glyph.o color.o main.o bitmap.o bound_box.o
testformatter: $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LIBS)

main.o: main.cc font.hh font_face.hh bound_box.hh bitmap.hh glyph.hh color.hh 
	$(CXX) -c $<  # just compile and build the .o file

font.o: font.cc font.hh
	$(CXX) -c $<  # just compile and build the .o file

font_face.o: font_face.cc font_face.hh
	$(CXX) -c $<  # just compile and build the .o file
	
bound_box.o: bound_box.cc bound_box.hh
	$(CXX) -c $<  # just compile and build the .o file

bitmap.o: bitmap.cc	bitmap.hh
	$(CXX) -c $<  # just compile and build the .o file
	
glyph.o: glyph.cc glyph.hh 
	$(CXX) -c $<  # just compile and build the .o file

color.o: color.cc color.hh 
	$(CXX) -c $<  # just compile and build the .o file


