fn main() {
    // Heterogeneous, immutable
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    println!("{}, {}, {}", tup.0, tup.1, tup.2);
    let (x, y, z) = tup;
    println!("{}, {}, {}", x, y, z);

    // Homogeneous, immutable
    let a = [1, 2, 3, 4, 5];
    println!("{}, {}, {}", a[0], a[1], a[2]);

    for e in a.iter() {
        println!("{}", e);
    }
}
