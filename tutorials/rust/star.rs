use std::io;

fn square(num: u32) -> u32 {
    num*num
}

fn print_stars(num: u32) {
    for i in 1..num + 1 {
        for j in 0..i {
            print!("*");
        }
        println!();
    }
}

fn main() {
    let mut string = String::new();
    println!("Input number: ");
    io::stdin().read_line(&mut string).expect("Error!");
    let mut num: u32 = match string.trim().parse(){
        Ok(n) => n,
        Err(_) => 0,
    };
    num = square(num);
    println!("Squared: {}", num);
    print_stars(num);
}

