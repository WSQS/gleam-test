import gleam/io
import gleam/list
import gleam/result
import gleam/string

@external(erlang, "niftest", "hello")
fn hello() -> Int

@external(erlang, "niftest", "read_file")
fn read_file(path: String) -> List(Int)

pub fn ascii_list_to_string(codes: List(Int)) -> Result(String, Nil) {
  codes
  |> list.try_map(string.utf_codepoint)
  |> result.map(string.from_utf_codepoints)
}

pub fn main() {
  io.println("Hello from test_app!")
  let _ = hello()
  let result =
    read_file("make_output.txt")
    |> ascii_list_to_string
  case result {
    Ok(string) -> io.println("content:" <> string)
    Error(_) -> io.println("F")
  }
}
