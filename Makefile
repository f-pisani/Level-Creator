# Level Creator Makefile
# A 2D level editor built with Qt5 and SFML

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -fPIC
LDFLAGS =

# Qt5 configuration
QT5_CFLAGS = $(shell pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets)
QT5_LIBS = $(shell pkg-config --libs Qt5Core Qt5Gui Qt5Widgets)
MOC = $(shell pkg-config --variable=host_bins Qt5Core)/moc
UIC = $(shell pkg-config --variable=host_bins Qt5Core)/uic

# SFML configuration
SFML_CFLAGS = $(shell pkg-config --cflags sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
SFML_LIBS = $(shell pkg-config --libs sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

# Combined flags
CPPFLAGS = $(QT5_CFLAGS) $(SFML_CFLAGS) -I.
LIBS = $(QT5_LIBS) $(SFML_LIBS)

# Directories
SRCDIR = .
BUILDDIR = build
OBJDIR = $(BUILDDIR)/obj
MOCDIR = $(BUILDDIR)/moc
UIDIR = $(BUILDDIR)/ui

# Target executable
TARGET = $(BUILDDIR)/level-creator

# Source files
SOURCES = main.cpp \
          Editor.cpp \
          EditorRender.cpp \
          GUI.cpp \
          GUI_AssetsManager.cpp \
          GUI_LevelSettings.cpp \
          GUI_StatusBar.cpp \
          GUI_ToolBar.cpp \
          GUI_ToolBox.cpp \
          DAT/DAT.cpp \
          QSFML/QSFML.cpp \
          Engine/ArtObject.cpp \
          Engine/Binarizable.cpp \
          Engine/Collider.cpp \
          Engine/Level.cpp \
          Engine/Marker.cpp \
          Engine/Point.cpp \
          Engine/Size.cpp \
          Engine/Trigger.cpp

# Headers that need MOC processing
MOC_HEADERS = Editor.hpp \
              GUI.hpp \
              GUI_AssetsManager.hpp \
              GUI_LevelSettings.hpp \
              GUI_StatusBar.hpp \
              GUI_ToolBar.hpp \
              GUI_ToolBox.hpp \
              QSFML/QSFML.hpp

# UI files
UI_FILES = GUI.ui \
           GUI_AssetsManager.ui \
           GUI_LevelSettings.ui \
           GUI_ToolBox.ui

# Generate lists of object files and MOC sources
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))
MOC_SOURCES = $(patsubst %.hpp,$(MOCDIR)/moc_%.cpp,$(notdir $(MOC_HEADERS)))
MOC_OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(MOC_SOURCES)))
UI_HEADERS = $(patsubst %.ui,$(UIDIR)/ui_%.h,$(notdir $(UI_FILES)))

# All objects
ALL_OBJECTS = $(OBJECTS) $(MOC_OBJECTS)

# Default target
all: $(TARGET)

# Create directories
$(BUILDDIR) $(OBJDIR) $(MOCDIR) $(UIDIR) $(OBJDIR)/DAT $(OBJDIR)/QSFML $(OBJDIR)/Engine:
	@mkdir -p $@

# Link executable
$(TARGET): $(ALL_OBJECTS) | $(BUILDDIR)
	@echo "Linking $@..."
	@$(CXX) $(LDFLAGS) -o $@ $(ALL_OBJECTS) $(LIBS)

# Compile source files
$(OBJDIR)/%.o: %.cpp $(UI_HEADERS) | $(OBJDIR) $(OBJDIR)/DAT $(OBJDIR)/QSFML $(OBJDIR)/Engine
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I$(UIDIR) -c $< -o $@

# Compile MOC generated files
$(OBJDIR)/moc_%.o: $(MOCDIR)/moc_%.cpp | $(OBJDIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -I$(UIDIR) -c $< -o $@

# Generate MOC files
$(MOCDIR)/moc_%.cpp: %.hpp | $(MOCDIR)
	@echo "MOC $<..."
	@$(MOC) $< -o $@

$(MOCDIR)/moc_%.cpp: */%.hpp | $(MOCDIR)
	@echo "MOC $<..."
	@$(MOC) $< -o $@

# Generate UI headers
$(UIDIR)/ui_%.h: %.ui | $(UIDIR)
	@echo "UIC $<..."
	@$(UIC) $< -o $@

# Clean build files
clean:
	@echo "Cleaning..."
	@rm -rf $(BUILDDIR)

# Run the application
run: $(TARGET)
	@echo "Running Level Creator..."
	@$(TARGET)

# Debug build
debug: CXXFLAGS = -std=c++11 -Wall -Wextra -g -O0 -fPIC -DDEBUG
debug: clean all

# Help
help:
	@echo "Level Creator - Build System"
	@echo ""
	@echo "Targets:"
	@echo "  all     - Build the level creator (default)"
	@echo "  clean   - Remove all build artifacts"
	@echo "  run     - Build and run the application"
	@echo "  debug   - Build with debug symbols"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Requirements:"
	@echo "  - Qt5 (Core, Gui, Widgets)"
	@echo "  - SFML 2.x (graphics, window, system, audio, network)"
	@echo "  - pkg-config"
	@echo "  - g++ with C++11 support"

.PHONY: all clean run debug help

# Dependencies
-include $(OBJECTS:.o=.d)
-include $(MOC_OBJECTS:.o=.d)
