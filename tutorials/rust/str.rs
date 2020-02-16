use std::io;

fn main() {
    let mut string = String::from("");
    println!("Input string: ");
    io::stdin().read_line(&mut string);
    println!("Your string: {}", string);
}
