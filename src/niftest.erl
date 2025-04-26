-module(niftest).

-export([init/0, hello/0, hello_erl/0, read_file/1]).

% -nifs([hello/0]).
-nifs([hello/0, read_file/1 ]).

-on_load(init/0).

init() ->
      erlang:load_nif("priv/niftest", 0).

hello() ->
      erlang:nif_error("NIF library not loaded").

read_file(path) ->
      erlang:nif_error("NIF library not loaded").

hello_erl() ->
      logger:info("This is an info message").