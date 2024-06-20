
use std::collections::HashSet;

struct Member {
    id: u32,
    books: HashSet<Book>
}

struct Date {
    day: u32,
    month: u32,
    year: u32
}

enum Status {
    Shelved,
    Borrowed(Date, MemberId)
}

struct Book {
    id: u32,
    borrowed: Status,
    name: String,
}

fn main() {
    println!("Hello, world!");

    let mut overdue = HashSet::new();

    // let mut overdue_on = HashMap::new();
    
    let book1 = Book {
        id: 69,
        borrowed: Shelved,
        name: "Adventures of Men"
    };

    overdue.insert(book1);
}

// HAVE A BOOK TREE ORDERED BY TIMESTAMP
