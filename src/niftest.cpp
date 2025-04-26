/* niftest.c */
#include <erl_nif.h>
#include <string>
#include <sstream>
#include <fstream>

static ERL_NIF_TERM hello(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  enif_fprintf(stdout, "Hello from cpp!\n");
  return enif_make_int(env, 0);
}

static ERL_NIF_TERM read_file(ErlNifEnv *env, int argc,
                              const ERL_NIF_TERM argv[]) {
  if (argc != 1) {
    return enif_make_badarg(env);
  }

  if (!enif_is_binary(env, argv[0])) {
    return enif_make_badarg(env);
  }

  ErlNifBinary bin;
  if (!enif_inspect_binary(env, argv[0], &bin)) {
    return enif_make_badarg(env);
  }

  // bin.data 是指向字符串数据的指针
  // bin.size 是字符串的长度

  // 你可以拷贝到 std::string 里
  std::string filepath((const char *)bin.data, bin.size);

  enif_fprintf(stdout, "read_file:Read file path: %s\n", filepath.c_str());

	std::ifstream file(filepath);

	if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filepath);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();

	return enif_make_string(env, buffer.str().c_str(), ERL_NIF_LATIN1);
}

static ErlNifFunc nif_funcs[] = {{"hello", 0, hello},
                                 {"read_file", 1, read_file}};

ERL_NIF_INIT(niftest, nif_funcs, NULL, NULL, NULL, NULL)