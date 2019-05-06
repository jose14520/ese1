#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

include sources.mk

# Platform Specific Flags
PLATFORM = HOST
LINKER_FILE = ../msp432p401r.lds

COMMON_FLAGS = -Wall -Werror -g -O0 -std=c99
DFLAGS = -D$(PLATFORM)
CPU = cortex-m4
ARCH = armv7e-m
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs


# Compile Defines
TARGET = c1m2

ifeq ($(PLATFORM),HOST)
	CFLAGS = $(DFLAGS)
	CC = gcc $(COMMON_FLAGS)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size
endif

ifeq ($(PLATFORM),MSP432)
	CFLAGS = $(DFLAGS) -mcpu=$(CPU) -mthumb -march=$(ARCH) \
	-mfloat-abi=$(FLOAT) -mfpu=$(FPU) --specs=$(SPECS)
	CC = arm-none-eabi-gcc $(COMMON_FLAGS)
	LDFLAGS = -T $(LINKER_FILE) -Wl,-Map=$(TARGET).map
	SIZE = arm-none-eabi-size
endif


OBJS = $(SOURCES:.c=.o)
LINKS = $(SOURCES:.c=.i)
ASMS = $(SOURCES:.c=.s)
DEPS = $(SOURCES:.c=.d)

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(INCLUDES) $(CFLAGS)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) $(INCLUDES) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.asm : %.c
	$(CC) -S $< $(INCLUDES) $(CFLAGS)


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out $(DEPS)

$(TARGET).out: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(CFLAGS)  $(LDFLAGS) -o $@
	$(SIZE) -Atd $(OBJS) $(TARGET).out

.PHONY: compile-all
compile-all:
	$(CC) $(INCLUDES) -c $(SOURCES) $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ASMS) $(OBJS) $(DEPS) $(LINKS) $(TARGET).map $(TARGET).out

