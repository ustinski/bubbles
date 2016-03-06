OBJECTS_LOCAL= color.o matrix.o app.o texture.o vector.o bubble.o background.o program.o 
color.o: $(SRC_DIR)/color.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/color.cpp
matrix.o: $(SRC_DIR)/matrix.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/matrix.cpp
app.o: $(SRC_DIR)/app.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/app.cpp
texture.o: $(SRC_DIR)/texture.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/texture.cpp
vector.o: $(SRC_DIR)/vector.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/vector.cpp
bubble.o: $(SRC_DIR)/bubble.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/bubble.cpp
background.o: $(SRC_DIR)/background.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/background.cpp
program.o: $(SRC_DIR)/program.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/program.cpp