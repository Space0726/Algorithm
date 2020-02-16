// This Macro makes printing struct easy
#[derive(Debug)]
struct Rectangle {
    length: u32,
    width: u32,
}

// Implement methods
impl Rectangle {
    fn area(&self) -> u32 {
        self.length * self.width
    }
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.length > other.length && self.width > other.width
    }
    // Associated function
    fn square(size: u32) -> Rectangle {
        Rectangle { length: size, width: size }
    }
}

fn main() {
    let rect1 = Rectangle { length: 50, width: 30 };
    let rect2 = Rectangle::square(30);

    println!("rect1: {:?}", rect1);
    println!("rect2: {:#?}", rect2);
    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
}
