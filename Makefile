CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -std=c++17

SRC_DIR := src
BUILD_DIR := build
CXX_SRC := $(wildcard $(SRC_DIR)/*.cpp)
HEADERS := $(wildcard $(SRC_DIR)/*.h)
CXX_OBJ := $(subst $(SRC_DIR),$(BUILD_DIR),$(subst .cpp,.o,$(CXX_SRC)))

BINARY := drozdma6

.PHONY: all
all: compile doc

.PHONY: run
run: compile
		./$(BINARY)

.PHONY: compile
compile: $(BUILD_DIR) $(BINARY)


doc: Doxyfile $(HEADERS)
	doxygen Doxyfile


$(BINARY): $(CXX_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	 rm -rf $(BUILD_DIR) $(BINARY) doc/ 2>/dev/null



# Dependencies
# g++ -MM src/*.cpp | sed -e 's|^\(.*\)\.o|build/\1\.o|'

build/CAction.o: src/CAction.cpp src/CAction.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CItem.h src/CZombie.h \
 src/CActionGenerator.h src/CCharacter.h src/CPlayer.h src/CInventory.h \
 src/SPlayerProperties.h
build/CApplication.o: src/CApplication.cpp src/CApplication.h src/CGame.h \
 src/CMap.h src/EField.h src/CCoords.h src/EDirection.h src/CItem.h \
 src/CZombie.h src/CActionGenerator.h src/CAction.h src/CCharacter.h \
 src/CPlayer.h src/CInventory.h src/SPlayerProperties.h src/CInterface.h \
 src/EApplicationInputs.h src/EGameInputs.h src/CExecutor.h src/SRandom.h \
 src/CZombieSpawnGenerator.h src/CItemGenerator.h src/CGun.h src/CBomb.h \
 src/CZombieWalker.h
build/CBomb.o: src/CBomb.cpp src/CBomb.h src/CItem.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CZombie.h \
 src/CActionGenerator.h src/CAction.h src/CCharacter.h src/CPlayer.h \
 src/CInventory.h src/SPlayerProperties.h
build/CCharacter.o: src/CCharacter.cpp src/CCharacter.h src/CCoords.h \
 src/EDirection.h
build/CCoords.o: src/CCoords.cpp src/CCoords.h src/EDirection.h
build/CExecutor.o: src/CExecutor.cpp src/CExecutor.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CItem.h src/CZombie.h \
 src/CActionGenerator.h src/CAction.h src/CCharacter.h src/CPlayer.h \
 src/CInventory.h src/SPlayerProperties.h src/CInterface.h \
 src/EApplicationInputs.h src/EGameInputs.h src/SActions.h
build/CGame.o: src/CGame.cpp src/CGame.h src/CMap.h src/EField.h src/CCoords.h \
 src/EDirection.h src/CItem.h src/CZombie.h src/CActionGenerator.h \
 src/CAction.h src/CCharacter.h src/CPlayer.h src/CInventory.h \
 src/SPlayerProperties.h
build/CGun.o: src/CGun.cpp src/CGun.h src/CItem.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CZombie.h \
 src/CActionGenerator.h src/CAction.h src/CCharacter.h src/CPlayer.h \
 src/CInventory.h src/SPlayerProperties.h
build/CInterface.o: src/CInterface.cpp src/CInterface.h src/SPlayerProperties.h \
 src/EApplicationInputs.h src/EGameInputs.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CItem.h src/CZombie.h \
 src/CActionGenerator.h src/CAction.h src/CCharacter.h src/CPlayer.h \
 src/CInventory.h
build/CInventory.o: src/CInventory.cpp src/CInventory.h src/CItem.h src/CGame.h \
 src/CMap.h src/EField.h src/CCoords.h src/EDirection.h src/CZombie.h \
 src/CActionGenerator.h src/CAction.h src/CCharacter.h src/CPlayer.h \
 src/SPlayerProperties.h
build/CItem.o: src/CItem.cpp src/CItem.h src/CGame.h src/CMap.h src/EField.h \
 src/CCoords.h src/EDirection.h src/CZombie.h src/CActionGenerator.h \
 src/CAction.h src/CCharacter.h src/CPlayer.h src/CInventory.h \
 src/SPlayerProperties.h
build/CItemGenerator.o: src/CItemGenerator.cpp src/CItemGenerator.h \
 src/CAction.h src/CGame.h src/CMap.h src/EField.h src/CCoords.h \
 src/EDirection.h src/CItem.h src/CZombie.h src/CActionGenerator.h \
 src/CCharacter.h src/CPlayer.h src/CInventory.h src/SPlayerProperties.h \
 src/SActions.h src/SRandom.h src/CGun.h src/CBomb.h
build/CMap.o: src/CMap.cpp src/CMap.h src/EField.h src/CCoords.h \
 src/EDirection.h
build/CPlayer.o: src/CPlayer.cpp src/CPlayer.h src/CCharacter.h src/CCoords.h \
 src/EDirection.h src/CInventory.h src/CItem.h src/CGame.h src/CMap.h \
 src/EField.h src/CZombie.h src/CActionGenerator.h src/CAction.h \
 src/SPlayerProperties.h src/CGun.h src/CBomb.h
build/CZombie.o: src/CZombie.cpp src/CZombie.h src/CActionGenerator.h \
 src/CGame.h src/CMap.h src/EField.h src/CCoords.h src/EDirection.h \
 src/CItem.h src/CPlayer.h src/CCharacter.h src/CInventory.h \
 src/SPlayerProperties.h src/CAction.h
build/CZombieSpawnGenerator.o: src/CZombieSpawnGenerator.cpp \
 src/CZombieSpawnGenerator.h src/CAction.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CItem.h src/CZombie.h \
 src/CActionGenerator.h src/CCharacter.h src/CPlayer.h src/CInventory.h \
 src/SPlayerProperties.h src/SActions.h src/SRandom.h src/CZombieWalker.h
build/CZombieWalker.o: src/CZombieWalker.cpp src/CZombieWalker.h src/CZombie.h \
 src/CActionGenerator.h src/CGame.h src/CMap.h src/EField.h src/CCoords.h \
 src/EDirection.h src/CItem.h src/CPlayer.h src/CCharacter.h \
 src/CInventory.h src/SPlayerProperties.h src/CAction.h src/SActions.h \
 src/SRandom.h
build/SActions.o: src/SActions.cpp src/SActions.h src/CAction.h src/CGame.h \
 src/CMap.h src/EField.h src/CCoords.h src/EDirection.h src/CItem.h \
 src/CZombie.h src/CActionGenerator.h src/CCharacter.h src/CPlayer.h \
 src/CInventory.h src/SPlayerProperties.h
build/SRandom.o: src/SRandom.cpp src/SRandom.h src/EDirection.h src/CCoords.h
build/main.o: src/main.cpp src/CApplication.h src/CGame.h src/CMap.h \
 src/EField.h src/CCoords.h src/EDirection.h src/CItem.h src/CZombie.h \
 src/CActionGenerator.h src/CAction.h src/CCharacter.h src/CPlayer.h \
 src/CInventory.h src/SPlayerProperties.h src/CInterface.h \
 src/EApplicationInputs.h src/EGameInputs.h src/SRandom.h
