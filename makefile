CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++17
BUILD_DIR = ./build
TARGET = $(BUILD_DIR)/SPICE

# Složky
HEADER_DIR = ./header
SOURCE_DIR = ./source

# Seznam všech zdrojových souborů
SOURCES = $(SOURCE_DIR)/main.cpp \
          $(SOURCE_DIR)/Resistor.cpp \
          $(SOURCE_DIR)/Capacitor.cpp \
          $(SOURCE_DIR)/Inductor.cpp \
          $(SOURCE_DIR)/DCVoltage.cpp \
          $(SOURCE_DIR)/ACVoltage.cpp \
          $(SOURCE_DIR)/CircuitElement.cpp \
          $(SOURCE_DIR)/MatrixGenerator.cpp \
          $(SOURCE_DIR)/ConjugateGradientSolver.cpp

# Převedení zdrojových souborů na objektové soubory ve složce build
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))

# Výchozí cíl
all: prepare_build_dir $(TARGET)
	@echo "Build finished successfully"

# Pravidlo pro překlad cíle s debugovacími informacemi
$(TARGET): $(OBJECTS)
	@echo "Linking $(OBJECTS) to create $(TARGET)"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Pravidlo pro překlad zdrojových souborů do objektových souborů
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "Compiling $< into $@"
	$(CXX) $(CXXFLAGS) -I $(HEADER_DIR) -c -o $@ $<

# Cíl pro vytvoření adresáře pro build, pokud neexistuje
prepare_build_dir:
	@echo "Creating build directory: $(BUILD_DIR)"
	@mkdir -p $(BUILD_DIR)

# Cíl pro ladění (debugging)
debug: $(TARGET)
	gdb $(TARGET)

# Vyčištění projektu
clean:
	rm -f $(TARGET) $(OBJECTS)
	rm -rf $(BUILD_DIR)

.PHONY: all prepare_build_dir debug clean
