ERL_INCLUDE_PATH = /usr/lib/erlang/usr/include

SRC_DIR = src
PRIV_DIR = priv

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
TARGETS := $(patsubst $(SRC_DIR)/%.cpp,$(PRIV_DIR)/%.so,$(SOURCES))

all: $(TARGETS)

$(PRIV_DIR)/%.so: $(SRC_DIR)/%.cpp
	@mkdir -p $(PRIV_DIR)
	g++ -I$(ERL_INCLUDE_PATH) -fPIC -shared -o $@ $<

clean:
	rm -f $(PRIV_DIR)/*.so
