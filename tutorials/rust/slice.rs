use std::io;

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}

fn main() {
    let mut s = String::new();
    println!("Input string: ");
    io::stdin().read_line(&mut s).expect("Error!");
    // string literal("abcde") == string slice(&str)
    println!("First word: {}", first_word(&s[..]));
}
