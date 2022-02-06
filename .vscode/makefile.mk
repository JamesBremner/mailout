#source file search paths
VPATH = ./src

static_link_flags = -static-libstdc++ -static-libgcc -static

# folder for .o files
ODIR=./.vscode/obj

OPT = -O2

# sources
_TST = main_james.o smtpclientbase.o smtpclient.o messageaddress.o \
	plaintextmessage.o message.o stringutils.o credential.o errorresolver.o \
	attachment.o base64.o
TST = $(patsubst %,$(ODIR)/%,$(_TST))

$(ODIR)/%.o: %.cpp
	g++ $(OPT)  -std=c++17 -D_mingw_ \
	-c -o $@ $< $(INC)

mailout: $(TST)
	g++ $(OPT) -s  \
	-o ./bin/mailout.exe $^  \
	$(static_link_flags) -lws2_32 -lwsock32

.PHONY: clean
clean:
	del /q .\.vscode\obj\*.o

