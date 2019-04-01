
SRCS = $(wildcard *.c)

CFLAGS += -DSELECTION

OBJS := $(patsubst %.cpp,%.o,$(patsubst %.c,%.o,$(SRCS)))
OUT := sort

all: $(OUT) $(OBJS) 

$(OUT): $(OBJS) 
	$(CC) $(LDFLAGS) $(CFLAGS)  $^ -o $@
%.o: %.c
	echo $(CC) $(CFLAGS) $<
	$(CC) -c $(CFLAGS) $< -o $*.o

clean:
	rm -f $(OBJS) $(OUT) 
