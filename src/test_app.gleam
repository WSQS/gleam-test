import gleam/io

@external(erlang, "niftest", "hello")
fn hello() -> Int

pub fn main() {
  io.println("Hello from test_app!")
  hello()
}
