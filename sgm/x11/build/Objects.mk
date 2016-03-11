OBJECTS_LOCAL=vector.o program.o background.o texture.o bubble.o app.o 
vector.o : $(SRC_DIR)/vector.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/vector.cpp
program.o : $(SRC_DIR)/program.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/program.cpp
background.o : $(SRC_DIR)/background.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/background.cpp
texture.o : $(SRC_DIR)/texture.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/texture.cpp
bubble.o : $(SRC_DIR)/bubble.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/bubble.cpp
app.o : $(SRC_DIR)/app.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $(SRC_DIR)/app.cpp