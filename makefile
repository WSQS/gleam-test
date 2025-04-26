ERL_INCLUDE_PATH = /usr/lib/erlang/usr/include

all:
	g++ -I$(ERL_INCLUDE_PATH) -fPIC -shared -o priv/niftest.so src/niftest.cpp
