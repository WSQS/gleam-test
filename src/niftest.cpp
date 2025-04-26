/* niftest.c */
#include <erl_nif.h>

static ERL_NIF_TERM hello(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  enif_fprintf(stdout, "Hello from cpp!\n");
  return enif_make_int(env, 0);
}

static ErlNifFunc nif_funcs[] = {{"hello", 0, hello}};

ERL_NIF_INIT(niftest, nif_funcs, NULL, NULL, NULL, NULL)