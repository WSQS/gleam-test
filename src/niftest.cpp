/* niftest.c */
#include <erl_nif.h>
#include <string>
#include <iostream>

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    enif_fprintf(stderr, "Hello from cpp %s\n", __FUNCTION__);
    return enif_make_string(env, (std::string("Hello from cpp ") + __FUNCTION__).c_str(), ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] =
{
    {"hello", 0, hello}
};

ERL_NIF_INIT(niftest,nif_funcs,NULL,NULL,NULL,NULL)