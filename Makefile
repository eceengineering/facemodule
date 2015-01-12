CC := arm-linux-gnueabihf-gcc

CFLAGS := -O3 -Wall -Wextra -Wno-unused-parameter -std=c99
LDFLAGS := -Wl,--as-needed
GFLAGS := $(shell pkg-config --cflags --libs opencv)
override CFLAGS += -D_GNU_SOURCE

all:
armTestApp: main.o facemodule.o cammodule.o v4l2cam.o 
bins += armTestApp

all: $(bins)

ifndef V
QUIET_CC    = @echo '   CC         '$@ $<;
QUIET_LINK  = @echo '   LINK       '$@ 'from' $^ $(LIBS);
QUIET_CLEAN = @echo '   CLEAN      '$@;
QUIET_DLL   = @echo '   DLLCREATE  '$@;
endif


%.o:: %.c
	$(QUIET_CC)$(CC) $(CFLAGS) $(GFLAGS) -MMD -o $@ -c $<

armTestApp:
	$(QUIET_LINK)$(CC) $(LDFLAGS) -o $@ $^ $(LIBS) $(GFLAGS) -lpthread

clean:
	$(QUIET_CLEAN)$(RM) $(bins) *.o *.d

-include *.d
