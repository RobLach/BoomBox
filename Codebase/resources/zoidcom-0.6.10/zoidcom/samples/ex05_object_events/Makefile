CXX		= gcc
CXXINCLUDE	= -I. -I../../include/
CXXFLAGS	= -O2 -fno-exceptions -D_REENTRANT

NAME = ex05_object_events

SRCDIR=./
OBJDIR=../temp/$(NAME)
LIBDIR=../../lib/linux

SRVSRCS		= $(SRCDIR)/server.cpp $(SRCDIR)/gameobject.cpp $(SRCDIR)/objecthandler.cpp
SRVOBJS		= $(subst $(SRCDIR), $(OBJDIR), $(SRVSRCS:.cpp=.o))
CLISRCS		= $(SRCDIR)/client.cpp $(SRCDIR)/gameobject.cpp $(SRCDIR)/objecthandler.cpp
CLIOBJS		= $(subst $(SRCDIR), $(OBJDIR), $(CLISRCS:.cpp=.o))
LIBS		= -L$(LIBDIR) -lzoidcom -lpthread -lstdc++ 

all: $(NAME)_server $(NAME)_client

$(NAME)_server.run:
	-@rm ../bin/linux/$@
	@echo "#!/bin/sh" > ../bin/linux/$@
	@echo "export LD_LIBRARY_PATH=../../../lib/linux" >> ../bin/linux/$@
	@echo "./$(NAME)_server" >> ../bin/linux/$@
	@chmod +x ../bin/linux/$@

$(NAME)_client.run:
	-@rm ../bin/linux/$@
	@echo "#!/bin/sh" > ../bin/linux/$@
	@echo "export LD_LIBRARY_PATH=../../../lib/linux" >> ../bin/linux/$@
	@echo "./$(NAME)_client" >> ../bin/linux/$@
	@chmod +x ../bin/linux/$@

$(NAME)_server:	$(SRVOBJS) $(NAME)_server.run
	$(CC) $(SRVOBJS) $(LIBS) -o ../bin/linux/$@
	
$(NAME)_client:	$(CLIOBJS) $(NAME)_client.run
	$(CC) $(CLIOBJS) $(LIBS) -o ../bin/linux/$@
	

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp	
	-@mkdir $(dir $@) -p
	$(CXX) -c $(CXXFLAGS) $(CXXINCLUDE) $< -o $@
	
clean:
	@rm -rf $(OBJDIR)/*
	@rm -rf ../bin/linux/$(NAME)*
	@echo Cleaned.
	
	
    
