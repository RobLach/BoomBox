CXX		= gcc
CXXINCLUDE	= -I. -I../../include/
CXXFLAGS	= -O2 -fno-exceptions -D_REENTRANT

NAME = ex07_movement

SRCDIR=./
OBJDIR=../temp/$(NAME)
LIBDIR=../../lib/linux

SRVSRCS		= $(SRCDIR)/server.cpp $(SRCDIR)/nodeobj.cpp $(SRCDIR)/client.cpp $(SRCDIR)/common.cpp $(SRCDIR)/demorec.cpp $(SRCDIR)/main.cpp
SRVOBJS		= $(subst $(SRCDIR), $(OBJDIR), $(SRVSRCS:.cpp=.o))
LIBS		= -L$(LIBDIR) `allegro-config --shared` -lzoidcom -lpthread -lstdc++ 

all: $(NAME)

$(NAME).run:
	-@rm ../bin/linux/$@
	@echo "#!/bin/sh" > ../bin/linux/$@
	@echo "export LD_LIBRARY_PATH=../../../lib/linux" >> ../bin/linux/$@
	@echo "./$(NAME)" >> ../bin/linux/$@
	@chmod +x ../bin/linux/$@

$(NAME):$(SRVOBJS) $(NAME).run
	$(CC) $(SRVOBJS) $(LIBS) -o ../bin/linux/$@
	

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp	
	-@mkdir $(dir $@) -p
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDE) $< -o $@
	
clean:
	@rm -rf $(OBJDIR)/*
	@rm -rf ../bin/linux/$(NAME)*
	@echo Cleaned.
	
	
    
