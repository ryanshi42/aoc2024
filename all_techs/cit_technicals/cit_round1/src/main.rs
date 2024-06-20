use std::collections::HashSet;



struct Fruit<'a> {
    name: &'a str, 
    weight: i32,
    price: i32,
    descriptors: Vec<&'a str>,
}

#[derive(Debug, Eq, PartialEq, Clone, PartialOrd, Ord)]
enum FruitField<'a> {
    Name(&'a str),
    Weight(i32),
    Price(i32),
    Descriptors(&'a Vec<&'a str>) 
}

trait Combinator<'a> {
    fn satisfies(&self, fruit: &'a Fruit, command: &'a Command) -> bool;
}

struct Or<'a> { 
    left: Box<dyn Combinator<'a>>,
    right: Box<dyn Combinator<'a>>
}

impl<'a> Combinator<'a> for Or<'a> {
    fn satisfies(&self, fruit: &'a Fruit, command: &'a Command) -> bool {
        self.left.satisfies(fruit, &command) || self.right.satisfies(fruit, &command)
    }
}

impl<'a> Combinator<'a> for And<'a> {
    fn satisfies(&self, fruit: &'a Fruit, command: &'a Command) -> bool {
        self.left.satisfies(fruit, &command) && self.right.satisfies(fruit, &command)
    }
}

impl<'a> Combinator<'a> for Normal {
    fn satisfies(&self, fruit: &'a Fruit, command: &'a Command) -> bool {
        command.allows(&fruit)
    }
}

struct And<'a> { 
    left: Box<dyn Combinator<'a>>,
    right: Box<dyn Combinator<'a>>
}

struct Normal {

}

// struct MyError<'a> {
//     msg: &'a str,
// }

impl<'a> Command<'a> {
    fn allows(&self, fruit: &'a Fruit) -> bool {
        let field = match self.field {
            "name" => FruitField::Name(fruit.name),
            "weight" => FruitField::Weight(fruit.weight),
            "price" => FruitField::Price(fruit.price),
            "descriptors" => FruitField::Descriptors(&fruit.descriptors),
            _ => panic!("Unknown fruit field"),
        };

        match self.op {
            Operator::Equals => {
                field == self.value
            },
            Operator::Greater => {
                if self.field == "name" || self.field == "descriptors" {
                    false
                } else {
                    field > self.value
                }
            },
            Operator::Less => {
                if self.field == "name" || self.field == "descriptors" {
                    false
                } else {
                    field < self.value
                }
            },
            Operator::Contains => {
                if let FruitField::Descriptors(arr) = self.value {
                    let mut desc: HashSet<&&str> = HashSet::from_iter(arr.iter());
                    for child in &fruit.descriptors {
                        if let Some(_) = desc.get(&child) {
                            desc.remove(&child);
                        }
                    }
                    match desc.len() {
                        0 => true,
                        _ => false
                    }
                } else {
                    false
                }
            }
        }
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Operator {
    Less,
    Greater,
    Equals,
    Contains
}

struct Command<'a> {
    field: &'a str,
    op: Operator,
    value: FruitField<'a>,
}



fn main() {
    // println!("Hello, world!");

    let Apple : Fruit = Fruit {
        name: "Apple",
        weight: 1,
        price: 69,
        descriptors: vec!["red", "green"],
    };

    let Pear : Fruit = Fruit {
        name: "Pear",
        weight: 2,
        price: 32,
        descriptors: vec!["red", "green"],
    };

    let fruit_vec = vec!{Apple, Pear};

    let command = Command {
        field: "weight",
        op: Operator::Less,
        value: FruitField::Weight(2)
    };

    for f in fruit_vec.iter() {
        if command.allows(&f) {
            println!("Fruit {} satisfies command!", f.name);
        }
    }
}

