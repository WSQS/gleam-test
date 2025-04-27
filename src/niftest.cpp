/* niftest.c */
#include <cassert>
#include <erl_nif.h>
#include <string>
#include <sstream>
#include <fstream>
#include "assert.h"

static ERL_NIF_TERM hello(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  enif_fprintf(stdout, "Hello from cpp!\n");
  return enif_make_int(env, 0);
}

static ERL_NIF_TERM read_file(ErlNifEnv *env, int argc,
                              const ERL_NIF_TERM argv[]) {
  ASSERT(argc == 1);
  ASSERT(enif_is_binary(env, argv[0]));

  ErlNifBinary bin;
  ASSERT(enif_inspect_binary(env, argv[0], &bin));

  // bin.data 是指向字符串数据的指针
  // bin.size 是字符串的长度

  // 你可以拷贝到 std::string 里
  std::string filepath((const char *)bin.data, bin.size);

  enif_fprintf(stdout, "file path: %s\n", filepath.c_str());

	std::ifstream file(filepath);

  ASSERT(file.is_open());

	std::stringstream buffer;
	buffer << file.rdbuf();
	return enif_make_string(env, buffer.str().c_str(), ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] = {{"hello", 0, hello},
                                 {"read_file", 1, read_file}};

ERL_NIF_INIT(niftest, nif_funcs, NULL, NULL, NULL, NULL)