TARGET = auto-turtle-feeder

OBJ_DIR = obj
CXXSOURCES = $(shell find . -name "*.cpp")
OBJS = $(addprefix $(OBJ_DIR)/,$(CXXSOURCES:.cpp=.o))
DEPFILES = $(OBJS:.o=.d)

MMCU = atmega16
F_CPU = 1000000UL
CXXFLAGS = -O -Wall -mmcu=$(MMCU) -DF_CPU=$(F_CPU)
CXX = avr-g++

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(OBJ_DIR)/%.d: %.cpp
	@mkdir -pv $(dir $@)
	@$(CXX) -MM -MT "$(OBJ_DIR)/$(<:.cpp=.o) $(OBJ_DIR)/$(<:.cpp=.d)" "$<" > "$@"

sinclude $(DEPFILES)

flash: $(TARGET).hex
	avrdude -p m16 -c usbasp -e -U flash:w:$<

clean: 
	rm -rf $(OBJ_DIR) $(TARGET).elf $(TARGET).hex

.PHONY: flash clean all
