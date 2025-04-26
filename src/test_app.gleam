import gleam/io

@external(erlang, "niftest", "hello")
fn hello() -> String

// @external(erlang, "niftest", "init")
// pub fn init() -> Nil

pub fn main() {
  io.println("Hello from test_app!")
  echo hello()
}
