TARGET   = wireless

CC       = gcc
CFLAGS   = -Wall -I.

LIBS     =

LINKER   = gcc -o
LFLAGS   = -Wall -I. -lm

SRCDIR   = .
OBJDIR   = obj
BINDIR   = .

SOURCES  := $(wildcard $(SRCDIR)/*.c $(SRCDIR)/wi_linux/*.c $(SRCDIR)/wi_linux/radiotap/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h $(SRCDIR)/wi_linux/*.h $(SRCDIR)/wi_linux/radiotap/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS) $(LIBS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC)  $(CFLAGS) -c $< -o $@ $(LIBS)
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
